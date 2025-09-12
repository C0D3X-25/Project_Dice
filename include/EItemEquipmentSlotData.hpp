#pragma once

#include <string_view>

namespace item {

	/// <summary>
	/// Slot an item can occupy or block on an character.
	/// </summary>
	enum EItemEquipmentSlotData {
		HELMET,
		BODY_ARMOR,
		SHOULDER_ARMOR,
		LEG_ARMOR,
		RING_RIGHT,
		RING_LEFT,
		AMULET,
		ARM_GUARDS,
		GLOVES,
		BOOTS,
		ONE_HANDED_RIGHT,
		ONE_HANDED_LEFT,
		TWO_HANDED
	};

	constexpr std::string_view toString(EItemSlot item_slot) {
		switch (item_slot) {
		case HELMET:			return "HELMET";
		case BODY_ARMOR:		return "BODY_ARMOR";
		case SHOULDER_ARMOR:	return "SHOULDER_ARMOR";
		case LEG_ARMOR:			return "LEG_ARMOR";
		case RING_LEFT:			return "RING_LEFT";
		case RING_RIGHT:		return "RING_RIGHT";
		case AMULET:			return "AMULET";
		case ARM_GUARDS:		return "ARM_GUARDS";
		case BOOTS:				return "BOOTS";
		case ONE_HANDED_LEFT:	return "ONE_HANDED_LEFT";
		case ONE_HANDED_RIGHT:	return "ONE_HANDED_RIGHT";
		case TWO_HANDED:		return "TWO_HANDED";
		default:				return "N/A";
		}
	}
}