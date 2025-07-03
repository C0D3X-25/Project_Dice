#pragma once

namespace helper {
	namespace calculate {


		template<typename T, typename... Args>
		inline T getBestValue(T start, Args... others) {
			int best = start;
			((best = (others > best ? others : best)), ...);

			return T(best);
		}


		template<typename T, typename... Args>
		inline T getWorstValue(T start, Args... others) {
			int worst = start;
			((worst = (others < worst ? others : worst)), ...);

			return T(worst);
		}
	}
}
