#pragma once

#include <string_view>

namespace item {

	/// <summary>
	/// Slot an item can occupy or block on an entity.
	/// </summary>
	enum EItemSlot {
		HELMET,
		BODY_ARMOR,
		SHOULDER_ARMOR,
		LEG_ARMOR,
		RING_LEFT,
		RING_RIGHT,
		AMULET,
		ARM_GUARDS,
		BOOTS,
		ONE_HANDED_LEFT,
		ONE_HANDED_RIGHT,
		TWO_HANDED,
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