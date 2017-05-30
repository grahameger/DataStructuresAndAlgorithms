#ifndef BINARY_PQ_H
#define BINARY_PQ_H

/*
 * A templated heap that takes
 * a comparator, defaults to a min-heap using std::less
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T, typename COMP_FUNCTOR = std::less<TYPE>>
class BinaryPQ
{
public:
	// Construct an empty pq
	BinaryPQ(COMP_FUNCTOR comp = COMP_FUNCTOR()) {
		size = 0;
		this->compare = comp;
	}
	
	// Construct a pq from an input range
	template <typename InputIterator>
	BinaryPQ(InputIterator begin, InputIterator end, COMP_FUNCTOR comp = COMP_FUNCTOR()) {

		// set up the vector for adding
		data.reserve(std::distance(start, end));
		size = 0;

		// initialize the comp functor
		this->compare = comp;

		// push all the data in
		for (; start < end; ++start)
		{
			data.push_back(*start);
			++size;
		}

		// update all the priorities
		updatePriorities();
	}
	
	// Destruct the pq
	~BinaryPQ();
	
	void push(const T& val) {
		data.push_back(val);

		// fix up the node
		fixUp(data.size() - 1);

		++size;
	}
	
	// O(log n)
	void pop() {
		// swap the front and back to remove the root 
		std::swap(data[0], data.back());
		data.pop_back();

		--size;

		// fix the new top which was the bottom
		fixDown(0);
	}
	
	T& top() const {
		return data[0];
	}
	
	size_t size() const {
		return size;
	}
	
	bool empty() const {
		return !size;
	}
	
	void updatePriorities() {
		for (size_t i = 0; i < data.size(); ++i) {
			fixUp(i);
		}
	}

private:

	std::vector<TYPE> data;

	size_t size;
	void fixUp(size_t index);
	void fixDown(size_t index);

protected:
	COMP_FUNCTOR compare;
	
};