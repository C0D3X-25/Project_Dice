#pragma once

#include "Attribute.hpp"

#include <memory>

namespace passive {

    using attribute::Attribute;

    /// <summary>
    /// Data Transfer Object for Passive
    /// </summary>
    struct PassiveModifierDTO {
        //std::shared_ptr<Icharacter> m_source_character;
        //std::shared_ptr<Icharacter> m_destination_character;
        Attribute m_bonus_attributes;
        int32_t m_modifier_value{ 0 };
    };
}