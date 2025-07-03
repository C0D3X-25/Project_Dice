#pragma once

#include "BaseEntity.hpp"

#include <array>
#include <memory>
#include <string>
#include <iostream>
#include <optional>
#include <string_view>

namespace group {

    using entity::BaseEntity;

    inline constexpr uint8_t GROUP_MAX_SIZE{ 20U };

    class BaseGroup {
    public:
        BaseGroup(uint8_t group_max_size, std::string group_name)
            : m_group_max_size(group_max_size), m_group_name(group_name) {}
        virtual ~BaseGroup(void) = default;


        virtual bool addEntity(std::unique_ptr<BaseEntity> entity, const uint8_t index_entity) {

            if (isGroupComplete()) {
                return false;
            }

            if (index_entity < m_group_max_size) {
                if (!m_group.at(index_entity).has_value()) {
                    m_group.at(index_entity) = std::move(entity);
                    m_group_current_size++;
                    return true;
                }
            }

            // Find first empty slot
            for (size_t i = 0; i < m_group_max_size; i++) {
                if (!m_group.at(i).has_value()) {
                    m_group.at(i) = std::move(entity);
                    m_group_current_size++;
                    return true;
                }
            }
            return false;
        }


        virtual bool removeEntity(uint8_t index_entity) {
            if (index_entity < m_group_max_size && m_group.at(index_entity).has_value()) {
                m_group.at(index_entity).reset();
                m_group_current_size--;
                return true;
            }
            return false;
        }


        virtual bool transferEntityTo(BaseGroup& target_group, const uint8_t source_index_entity,  const uint8_t target_index_entity = 0) {

            if (!m_group.at(source_index_entity).has_value()) {
                std::cerr << "Source entity doesn't exist\n";
                return false;
            }
            if (target_group.isGroupComplete()) {
                std::cerr << "Group is complete\n";
                return false;
            }

            //auto entity = std::move(m_group[source_index_entity].value());

            if (target_group.addEntity(std::move(m_group.at(source_index_entity).value()), target_index_entity)) {
                removeEntity(source_index_entity);
                return true;
            }
            return false;
        }

        // WITHOUT PTR
        //virtual bool addEntity(BaseEntity& entity, const uint8_t index_entity) {
        //    if (isGroupComplete()) {
        //        return false;
        //    }

        //    if (index_entity < m_group_max_size) {
        //        if (!m_group.at(index_entity).has_value()) {
        //            m_group.at(index_entity) = std::move(entity);
        //            m_group_current_size++;
        //            return true;
        //        }
        //    }

        //    // Find first empty slot
        //    for (size_t i = 0; i < m_group_max_size; i++) {
        //        if (!m_group.at(i).has_value()) {
        //            m_group.at(i) = std::move(entity);
        //            m_group_current_size++;
        //            return true;
        //        }
        //    }
        //    return false;
        //}


        // WITHOUT PTR
        //virtual bool transferEntityTo(const uint8_t source_index_entity, BaseGroup& target_group, const uint8_t target_index_entity = 0) {

        //    if (source_index_entity >= m_group_max_size || !m_group[source_index_entity].has_value()) {
        //        return false;
        //    }

        //    if (target_group.isGroupComplete()) {
        //        return false;
        //    }

        //    auto entity = std::move(m_group[source_index_entity].value());
        //    if (target_group.addEntity(entity, target_index_entity)) {
        //        removeEntity(source_index_entity);
        //        return true;
        //    }

        //    // If transfer failed, restore the entity
        //    m_group[source_index_entity] = std::move(entity);
        //    return false;
        //}

        virtual BaseEntity& getEntity(uint8_t index_entity) {
            if (index_entity >= m_group_max_size || !m_group.at(index_entity).has_value()) {
                throw std::out_of_range("Invalid entity index or empty slot");
            }
            return *m_group.at(index_entity).value();
        }


        //virtual BaseEntity& operator[](uint8_t index_entity) {
        //    return getEntity(index_entity);
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

            for (const auto& entity_opt : m_group) {
                if (entity_opt.has_value()) { // Only print if the optional contains an entity
                    entity_opt.value()->printEntity();
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
        std::array<std::optional<std::unique_ptr<BaseEntity>>, GROUP_MAX_SIZE> m_group;
        std::string m_group_name{ "N/A" };
        uint8_t m_group_current_size{ 0 };
        uint8_t m_group_max_size{ GROUP_MAX_SIZE };
    };
}
