#pragma once 

#include "BaseCapacity.hpp"
#include "CapacityDTO.hpp"
#include "Attribute.hpp"
#include "EAttribute.hpp"
#include "IEntity.hpp"
#include "PassiveHandler.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <string_view>

namespace entity {

    using capacity::BaseCapacity;
    using capacity::CapacityDTO;
    using attribute::Attribute;
    using attribute::EAttribute;
    using passive::PassiveHandler;

    /// <summary>
    /// Base Class for any entity.
    /// </summary>
    class BaseEntity : public IEntity {
    public:
        BaseEntity(const std::string& name);
        BaseEntity(const std::string& name, const int16_t max_life, const int16_t max_armor);
        virtual ~BaseEntity(void) = default;

        virtual void initializeEntity(void);
        virtual void printEntity(void) const;

        // IEntity implementation
        void updateAttributes(const Attribute& update_attributes) override;
        void addPassive(std::shared_ptr<passive::IPassive> sp_passive) override { m_passive.addPassive(sp_passive); }

        std::string_view getEntityName(void) const override { return m_name; }
        int16_t getMaxLife(void) const override { return m_max_life; }
        int16_t getCurrentLife(void) const override { return m_current_life; }
        int16_t getMaxArmor(void) const override { return m_max_armor; }
        int16_t getCurrentArmor(void) const override { return m_current_armor; }
        int8_t getAttribute(const EAttribute attribute_type) const override { return m_attributes.getAttribute(attribute_type); }

        void setEntityName(const std::string& name) override { m_name = name; }
        void setMaxLife(int16_t life) override { m_max_life = life; }
        void setCurrentLife(int16_t life) override { m_current_life = life; }
        void setMaxArmor(int16_t armor) override { m_max_armor = armor; }
        void setCurrentArmor(int16_t armor) override { m_current_armor = armor; }

        void executePassives(void) {
            m_bonus_attributes = m_passive.executePersistentPassives().m_bonus_attributes;
        }

    protected:
        virtual void updateEntity(void);

    protected:
        PassiveHandler m_passive;
        // TODO: StatusHandler m_status;
        // TODO: FeatHandler m_feat;
        Attribute m_attributes;
		Attribute m_bonus_attributes;
        std::string m_name      { "N/A" };
        int16_t m_max_life      { 0 };
        int16_t m_current_life  { 0 };
        int16_t m_max_armor     { 0 };
        int16_t m_current_armor { 0 };
    };
}
