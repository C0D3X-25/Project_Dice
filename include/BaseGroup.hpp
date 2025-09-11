#pragma once

#include "CharacterSystem.hpp""

#include <array>
#include <memory>
#include <string>
#include <iostream>
#include <optional>
#include <string_view>

namespace group {

    using character::CharacterSystem;

    inline constexpr uint8_t GROUP_MAX_SIZE{ 20U };

    class BaseGroup {
    public:
        BaseGroup(uint8_t group_max_size, std::string group_name)
            : m_group_max_size(group_max_size), m_group_name(group_name) {}
        virtual ~BaseGroup(void) = default;


        virtual bool addcharacter(std::unique_ptr<CharacterSystem> character, const uint8_t index_character) {

            if (isGroupComplete()) {
                return false;
            }

            if (index_character < m_group_max_size) {
                if (!m_group.at(index_character).has_value()) {
                    m_group.at(index_character) = std::move(character);
                    m_group_current_size++;
                    return true;
                }
            }

            // Find first empty slot
            for (size_t i = 0; i < m_group_max_size; i++) {
                if (!m_group.at(i).has_value()) {
                    m_group.at(i) = std::move(character);
                    m_group_current_size++;
                    return true;
                }
            }
            return false;
        }


        virtual bool removecharacter(uint8_t index_character) {
            if (index_character < m_group_max_size && m_group.at(index_character).has_value()) {
                m_group.at(index_character).reset();
                m_group_current_size--;
                return true;
            }
            return false;
        }


        virtual bool transfercharacterTo(BaseGroup& target_group, const uint8_t source_index_character,  const uint8_t target_index_character = 0) {

            if (!m_group.at(source_index_character).has_value()) {
                std::cerr << "Source character doesn't exist\n";
                return false;
            }
            if (target_group.isGroupComplete()) {
                std::cerr << "Group is complete\n";
                return false;
            }

            //auto character = std::move(m_group[source_index_character].value());

            if (target_group.addcharacter(std::move(m_group.at(source_index_character).value()), target_index_character)) {
                removecharacter(source_index_character);
                return true;
            }
            return false;
        }

        // WITHOUT PTR
        //virtual bool addcharacter(CharacterSystem& character, const uint8_t index_character) {
        //    if (isGroupComplete()) {
        //        return false;
        //    }

        //    if (index_character < m_group_max_size) {
        //        if (!m_group.at(index_character).has_value()) {
        //            m_group.at(index_character) = std::move(character);
        //            m_group_current_size++;
        //            return true;
        //        }
        //    }

        //    // Find first empty slot
        //    for (size_t i = 0; i < m_group_max_size; i++) {
        //        if (!m_group.at(i).has_value()) {
        //            m_group.at(i) = std::move(character);
        //            m_group_current_size++;
        //            return true;
        //        }
        //    }
        //    return false;
        //}


        // WITHOUT PTR
        //virtual bool transfercharacterTo(const uint8_t source_index_character, BaseGroup& target_group, const uint8_t target_index_character = 0) {

        //    if (source_index_character >= m_group_max_size || !m_group[source_index_character].has_value()) {
        //        return false;
        //    }

        //    if (target_group.isGroupComplete()) {
        //        return false;
        //    }

        //    auto character = std::move(m_group[source_index_character].value());
        //    if (target_group.addcharacter(character, target_index_character)) {
        //        removecharacter(source_index_character);
        //        return true;
        //    }

        //    // If transfer failed, restore the character
        //    m_group[source_index_character] = std::move(character);
        //    return false;
        //}

        virtual CharacterSystem& getcharacter(uint8_t index_character) {
            if (index_character >= m_group_max_size || !m_group.at(index_character).has_value()) {
                throw std::out_of_range("Invalid character index or empty slot");
            }
            return *m_group.at(index_character).value();
        }


        //virtual CharacterSystem& operator[](uint8_t index_character) {
        //    return getcharacter(index_character);
        //}


        virtual void printGroup(void) const {
            std::cout << "========================================================\n";
            std::cout << m_group_name << " (" << static_cast<int>(getGroupCurrentSize()) 
                      << "/" << static_cast<int>(getGroupMaxSize()) << ")\n";
            std::cout << "========================================================\n\n";
            
            if (isGroupEmpty()) {
                std::cout << "Group is empty\n";
                return;
            }

            for (const auto& character_opt : m_group) {
                if (character_opt.has_value()) { // Only print if the optional contains an character
                    character_opt.value()->printcharacter();
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                }
            }
        }

        bool isGroupComplete(void) const { return m_group_current_size >= m_group_max_size; }
        bool isGroupEmpty(void) const { return m_group_current_size == 0; }

		std::string_view getGroupName(void) const { return m_group_name; }
        uint8_t getGroupCurrentSize(void) const { return m_group_current_size; }
        uint8_t getGroupMaxSize(void) const { return m_group_max_size; }

    private:
        std::array<std::optional<std::unique_ptr<CharacterSystem>>, GROUP_MAX_SIZE> m_group;
        std::string m_group_name{ "N/A" };
        uint8_t m_group_current_size{ 0 };
        uint8_t m_group_max_size{ GROUP_MAX_SIZE };
    };
}
