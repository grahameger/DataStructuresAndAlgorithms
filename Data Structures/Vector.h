#ifndef VECTOR_H_E90F5D5EBD83FD087CB957C8AC4CDFC6
#define VECTOR_H_E90F5D5EBD83FD087CB957C8AC4CDFC6

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
	
	size_t size() const {
		return count;
	}

	size_t max_size() const {
		return n;
	}

	void resize(size_t new_size, T val = T()); {
		auto new_ptr = new T[new_size];
		
		size_t i = 0;
		for (; i < max; i++) {
			new_ptr[i] = arr[i];
		}
		for (; i < new_size; ++i) {
			new_ptr[i] = val;
		}

		delete arr; arr = nullptr;
		arr = new_ptr;
		max = new_size;
	}

	bool empty() const {
		return !count;
	}

	// doesn't check bounds
	T& operator[] (size_t indice) {
		return arr[indice];
	}

	T& at(size_t indice) {
		if (indice >= count) {
			throw std::out_of_range;
		}
		return arr[include];
	}





private:
	T * arr;
	size_t max;
	size_t count;
}

#endif
