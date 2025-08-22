#pragma once 

#include "BaseCapacity.hpp"
#include "CapacityActionDamage.hpp"
#include "Attribute.hpp"
#include "BaseEntity.hpp" 
#include "SFind.hpp"

#include <vector>

namespace capacity {

	using namespace entity;
	using namespace attribute;
	using namespace capacity_action;

	/// <summary>
	/// This class is a library for all the capacities.
	/// 1 method = 1 Capacity
	/// A method must return a BaseCapacity object.
	/// </summary>
	class CapacityFactory {
	public:

		CapacityFactory(void) {}
		~CapacityFactory(void) = default;


		BaseCapacity nothing(void) {
			BaseCapacity capacity;
			capacity.setCapacityName("Nothing");
			capacity.setCapacityDescription("Just skip your turn");
			return capacity;
		}


		BaseCapacity attackSingle(const BaseEntity& source_entity) {
			BaseCapacity capacity;
			capacity.setCapacityName("1 Attack");
			capacity.setCapacityDescription("Attack a single ennemy with STR or DEX");
			capacity.setCapacityPurposes({ ATTACK_PHYSICAL });
			capacity.setCapacityTriggers({ USED_WHEN_TURN_END });
			capacity.setCapacityAttribute({ STRENGTH, DEXTERITY });

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 3 };
				int8_t total_damage = base_damage + helper::find::getHighestValue(source_entity.getAttribute(STRENGTH), source_entity.getAttribute(DEXTERITY), min_damage);
				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityDTO(attack.doAction());
			}
			return capacity;
		}


		BaseCapacity attackRandom(const BaseEntity& source_entity) {
			BaseCapacity capacity;
			capacity.setCapacityName("1 Attack and 1 Random Attack");
			capacity.setCapacityDescription("Attack a single ennemy with worst STR or DEX, then attack another random ennemy with best STR or DEX");
			capacity.setCapacityPurposes({ ATTACK_PHYSICAL });
			capacity.setCapacityTriggers({ USED_WHEN_TURN_END });
			capacity.setCapacityAttribute({ STRENGTH, DEXTERITY });

			// Take the best between dexterity and strength 
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };

				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 3 };
				int8_t total_damage = base_damage + helper::find::getLowestValue(source_entity.getAttribute(STRENGTH), source_entity.getAttribute(DEXTERITY), min_damage);

				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityDTO(attack.doAction());
			}

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENNEMY };

				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 5 };
				int8_t total_damage = base_damage + helper::find::getHighestValue(source_entity.getAttribute(STRENGTH), source_entity.getAttribute(DEXTERITY), min_damage);

				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityDTO(attack.doAction());
			}
			return capacity;
		}

		BaseCapacity attackEnnemyTeam(const BaseEntity& source_entity) {
			BaseCapacity capacity;
			capacity.setCapacityName("Strike the ennemy team once");
			capacity.setCapacityDescription("Attack all ennemy with best INT, WIS or CHA");
			capacity.setCapacityPurposes({ ATTACK_PHYSICAL });
			capacity.setCapacityTriggers({ USED_WHEN_TURN_END });
			capacity.setCapacityAttribute({ INTELLIGENCE, WISDOM, CHARISMA });

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_TEAM, TARGET_ENNEMY };
				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 2 };
				int8_t total_damage = base_damage + helper::find::getHighestValue(source_entity.getAttribute(CHARISMA), source_entity.getAttribute(WISDOM), source_entity.getAttribute(INTELLIGENCE), min_damage);
				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityDTO(attack.doAction());
			}
			return capacity;
		}


		BaseCapacity protectSelf(const BaseEntity& source_entity) {
			BaseCapacity capacity;
			capacity.setCapacityName("Protect self");
			capacity.setCapacityDescription("Protect yourself with your armor");
			capacity.setCapacityPurposes({ DEFENSE });
			capacity.setCapacityTriggers({ USED_WHEN_TURN_END });
			capacity.setCapacityAttribute({ STRENGTH, DEXTERITY });

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_SELF };
				constexpr int8_t min_armor{ 1 };
				constexpr int8_t base_armor{ 3 };
				int8_t total_armor = base_armor + helper::find::getHighestValue(source_entity.getAttribute(STRENGTH), source_entity.getAttribute(WISDOM), min_armor);
				CapacityActionDamage protect(total_armor, targets);
				capacity.queueCapacityDTO(protect.doAction());
			}
			return capacity;
		}


		BaseCapacity fastHeal(const BaseEntity& source_entity) {
			BaseCapacity capacity;
			capacity.setCapacityName("Fast heal");
			capacity.setCapacityDescription("Heal directly a single ally with best INT, WIS or CHA");
			capacity.setCapacityPurposes({ HEALING });
			capacity.setCapacityTriggers({ USED_WHEN_ASSIGNED });
			capacity.setCapacityAttribute({ INTELLIGENCE, WISDOM, CHARISMA });

			// Take the best between INT, WIS or CHA
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ALLY };
				constexpr int8_t min_heal{ 0 };
				constexpr int8_t base_heal{ 1 };
				int8_t total_heal = base_heal + helper::find::getHighestValue(source_entity.getAttribute(CHARISMA), source_entity.getAttribute(WISDOM), source_entity.getAttribute(INTELLIGENCE), min_heal);
				CapacityActionDamage heal(total_heal, targets);
				capacity.queueCapacityDTO(heal.doAction());
			}
			return capacity;
		}
	};
} // namespace capacity
