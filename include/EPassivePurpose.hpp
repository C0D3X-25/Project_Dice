#pragma once 

#include <string>

namespace passive {

	/// <summary>
	/// Give the purpose of the passive, used by the PassiveHandler to determine how to handle the passive
	/// Like when to execute it, or if it should be executed at all.
	/// </summary>
	enum EPassivePurpose {
		STAT_MODIFIER,
	};
}