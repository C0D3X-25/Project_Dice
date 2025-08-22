#pragma once

#include "Attribute.hpp"
#include "IEntity.hpp"

#include <memory>

namespace passive {

    using entity::IEntity;
    using attribute::Attribute;

    /// <summary>
    /// Data Transfer Object for Passive
    /// </summary>
    struct PassiveModifierDTO {
        std::shared_ptr<IEntity> m_source_entity;
        std::shared_ptr<IEntity> m_target_entity;
        Attribute m_bonus_attributes;
        int32_t m_modifier_value{ 0 };
    };
}