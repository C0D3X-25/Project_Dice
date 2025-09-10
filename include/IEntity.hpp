//#pragma once
//
//#include "AttributeData.hpp"
//#include "EAttribute.hpp"
//
//#include <string_view>
//#include <memory>
//
//namespace passive {
//    class IPassive;
//}
//
//namespace character {
//
//    class Icharacter {
//    public:
//        virtual ~Icharacter() = default;
//
//        // Core character methods
//        virtual void updateAttributes(const attribute::AttributeData& update_attributes) = 0;
//        virtual void addPassive(passive::IPassive& sp_passive) = 0;
//
//        // Getters
//        virtual std::string_view getcharacterName() const = 0;
//        virtual int16_t getMaxLife() const = 0;
//        virtual int16_t getCurrentLife() const = 0;
//        virtual int16_t getMaxArmor() const = 0;
//        virtual int16_t getCurrentArmor() const = 0;
//        virtual int8_t getAttribute(const attribute::EAttribute attribute_type) const = 0;
//
//        // Setters
//        virtual void setcharacterName(const std::string& name) = 0;
//        virtual void setMaxLife(int16_t life) = 0;
//        virtual void setCurrentLife(int16_t life) = 0;
//        virtual void setMaxArmor(int16_t armor) = 0;
//        virtual void setCurrentArmor(int16_t armor) = 0;
//    };
//}