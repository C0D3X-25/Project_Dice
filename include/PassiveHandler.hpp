//#pragma once 
//
//#include "IPassive.hpp"
//#include "PassiveModifierDTO.hpp"
////#include "ICharacterSystem.hpp""
//
//#include <string>
//#include <vector>
//#include <memory>
//#include <iostream>
//
//namespace passive {
//
//    using character::Icharacter;
//
//    /// <summary>
//    /// Facade Design for handling passive abilities.
//    /// </summary>
//    class PassiveHandler {
//    public:
//        PassiveHandler() = default;
//        ~PassiveHandler() = default;
//
//        void initializePassiveHandler(Icharacter& source_character) {
//            m_source_character = std::shared_ptr<Icharacter>(&source_character, [](Icharacter*) {});  // Non-owning wrapper
//        }
//
//        //void addPassive(IPassive& passive) {
//        ////void addPassive(std::shared_ptr<IPassive> sp_passive) {
//			
//        //    //m_persistent_passives.push_back(sp_passive);
//        //    m_persistent_passives.push_back(std::make_shared<IPassive>(passive));
//        //}
//        
//        void addPassive(IPassive& passive) {
//            // Create a non-owning wrapper, similar to how you handle entities
//            m_persistent_passives.push_back(std::shared_ptr<IPassive>(&passive, [](IPassive*) {}));
//        }
//
//        PassiveModifierDTO executePersistentPassives() {
//            PassiveModifierDTO passive_mod;
//            passive_mod.m_source_character = m_source_character;
//
//            for (const auto& passive : m_persistent_passives) {
//                passive->executePassive(passive_mod);
//            }
//
//            return passive_mod;
//        }
//
//        PassiveModifierDTO executeGettingHitPassives(Icharacter& target_character) {
//            PassiveModifierDTO passive_mod;
//            passive_mod.m_source_character = m_source_character;
//            passive_mod.m_destination_character = std::shared_ptr<Icharacter>(&target_character, [](Icharacter*) {});
//
//            for (const auto& passive : m_persistent_passives) {
//                passive->executePassive(passive_mod);
//            }
//
//            return passive_mod;
//        }
//
//        void printListPassives() const {
//            PassiveModifierDTO passive_mod;
//            passive_mod.m_source_character = m_source_character;
//
//            for (const auto& passive : m_persistent_passives) {
//                passive->printPassive();
//            }
//        }
//
//    private:
//        std::vector<std::shared_ptr<IPassive>> m_persistent_passives;
//        std::shared_ptr<Icharacter> m_source_character;
//    };
//}