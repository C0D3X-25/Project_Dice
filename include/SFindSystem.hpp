#pragma once

namespace helper {
	namespace find {

		/// <summary>
		/// Find the highest value between any number of value of the same datatype passed as parameter
		/// </summary>
		/// <typeparam name="T">A numerical datatype</typeparam>
		/// <typeparam name="...Args">A non-determined number of value</typeparam>
		/// <param name="first_value"></param>
		/// <param name="...others_values"></param>
		/// <returns>The highest value between the one passed</returns>
		template<typename T, typename... Args>
		static inline T getHighestValue(T first_value, Args... others_values) {
			T highest = first_value;
			((highest = (others_values > highest ? others_values : highest)), ...);

			return T(highest);
		}

		/// <summary>
		/// Find the lowest value between any number of value of the same datatype passed as parameter
		/// </summary>
		/// <typeparam name="T">A numerical datatype</typeparam>
		/// <typeparam name="...Args">A non-determined number of value</typeparam>
		/// <param name="first_value"></param>
		/// <param name="...others_values"></param>
		/// <returns>The lowest value between the one passed</returns>
		template<typename T, typename... Args>
		static inline T getLowestValue(T first_value, Args... others_values) {
			T lowest = first_value;
			((lowest = (others_values < lowest ? others_values : lowest)), ...);

			return T(lowest);
		}

		/// <summary>
		/// Clamps a value to ensure it falls within the specified minimum and maximum range.
		/// </summary>
		/// <typeparam name="T">The type of the value and range boundaries.</typeparam>
		/// <param name="value">The value to be clamped.</param>
		/// <param name="min_range">The minimum allowable value.</param>
		/// <param name="max_range">The maximum allowable value.</param>
		/// <returns>The value, limited to the specified range. 
		/// Returns min_range if value is less than or equal to min_range, 
		/// max_range if value is greater than or equal to max_range, 
		/// or value itself if it is within the range.</returns>
		template<typename T>
		static inline T getValueInRange(const T value, const T min_range, const T max_range) {
			if (value >= max_range) {
				return max_range;
			}
			if (value <= min_range) {
				return min_range;
			}
			return value;
		}
	}
}
