/*
 * Stack data struture implemented
 * using a std::vector
 *
 * Graham Eger
 * 
 *
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>

template <typename T>
class Stack {
public:
	
	void reserve(size_t n) {
		v.reserve(v);
	}
	
	void push(const T &datum) {
		v.push_back(datum);
	}
	
	void pop() {
		assert(v.size() != 0, "Tried to pop a stack of size 0\n");
		v.pop_back();
	}
	
	T& top() const {
		assert(v.size() != 0, "Tried to get top of a stack of size 0\n");
		return v.back();
	}

	size_t size() const {
		return v.size();
	}

	bool empty() const {
		return !v.size();
	}
	
private:
	std::vector<T> v;
};


#endif
