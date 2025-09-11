#pragma once
//#include "BaseCapacity.hpp"
//#include "CharacterSystem.hpp"

//using character::CharacterSystem;
//using capacity::CapacityDTO;

namespace resolution_capacity {
    // TODO: Choose between:
	// 1. Chain of responsibility pattern
    //  ? How to contruct the chain in dynamic 
    //  + Easy to resolve in order
    // 
	// 2. Strategy pattern
    //  + Easy to resolve in order
    //  + Easy to create in dynamic
    //  - Only 1 choice for each resolution
    // 
	// 3. Composite pattern <- I like that
    //  + Throw composites in a box and resolve
    //  + Easy to create in dynamic
	//  - Hard to know what is in the box
	//  - Hard to resolve in order
	//  ? Add weight to each resolution for having an order of resolution

	// How a capacity is resolved when received
	class IResolutionCapacity {
	public:
		virtual ~IResolutionCapacity(void) = default;
		//virtual void resolveCapacity(CapacityDTO& capacity_comp, CharacterSystem& target) = 0;
	};
}
