#pragma once 

#include "IPassive.hpp"
#include "PassiveModifierDTO.hpp"
#include "IEntity.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace passive {

    using entity::IEntity;

    /// <summary>
    /// Facade Design for handling passive abilities.
    /// </summary>
    class PassiveHandler {
    public:
        PassiveHandler() = default;
        ~PassiveHandler() = default;

        void initializePassiveHandler(IEntity& source_entity) {
            m_source_entity = std::shared_ptr<IEntity>(&source_entity, [](IEntity*) {});  // Non-owning wrapper
        }

        //void addPassive(IPassive& passive) {
        ////void addPassive(std::shared_ptr<IPassive> sp_passive) {
			
        //    //m_persistent_passives.push_back(sp_passive);
        //    m_persistent_passives.push_back(std::make_shared<IPassive>(passive));
        //}
        
        void addPassive(IPassive& passive) {
            // Create a non-owning wrapper, similar to how you handle entities
            m_persistent_passives.push_back(std::shared_ptr<IPassive>(&passive, [](IPassive*) {}));
        }

        PassiveModifierDTO executePersistentPassives() {
            PassiveModifierDTO passive_mod;
            passive_mod.m_source_entity = m_source_entity;

            for (const auto& passive : m_persistent_passives) {
                passive->executePassive(passive_mod);
            }

            return passive_mod;
        }

        PassiveModifierDTO executeGettingHitPassives(IEntity& target_entity) {
            PassiveModifierDTO passive_mod;
            passive_mod.m_source_entity = m_source_entity;
            passive_mod.m_target_entity = std::shared_ptr<IEntity>(&target_entity, [](IEntity*) {});

            for (const auto& passive : m_persistent_passives) {
                passive->executePassive(passive_mod);
            }

            return passive_mod;
        }

        void printListPassives() const {
            PassiveModifierDTO passive_mod;
            passive_mod.m_source_entity = m_source_entity;

            for (const auto& passive : m_persistent_passives) {
                passive->printPassive();
            }
        }

    private:
        std::vector<std::shared_ptr<IPassive>> m_persistent_passives;
        std::shared_ptr<IEntity> m_source_entity;
    };
}