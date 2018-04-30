//
//  md5.hpp
//  md5
//
//  Created by Graham Eger on 4/29/18.
//  Copyright © 2018 Graham Eger. All rights reserved.
//  Based off of RFC 1321
//

#ifndef merge_sort_grahameger
#define merge_sort_grahameger

#include <vector>

// For integral types only:
namespace grahameger {
	// For integral types only:
	template<typename T>
	typename std::enable_if<std::is_integral<T>::value>::type f(T t)
	{
		void merge_sort(std::vector<T> vec) {
			if (vec.size() < 2)
			{
				return;
			} else {
				auto middle = vec.begin() + (vec.size() / 2);
				merge_sort()
			}
		}
	}
}

