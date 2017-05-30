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

	// O(logn), tail recursive
	void fixUp(size_t index) {
		// base case
		if (index == 0) {
			return;
		}

		//initialize the parent index for reuse sake
		size_t indexParent = (index - 1) / 2;

		if (this->compare(data[indexParent], data[index])) {
			std::swap(data[index], data[indexParent]);
			fixUp(indexParent);
		} 
	}
	// O(logn), iterative, why not try both methods
	void fixDown(size_t index) {
		size_t j = index * 2 + 1;

		while (j < size()) {
			size_t k = j;
			if (k < size() - 1 && this->compare(data[j], data[j + 1])) {
				k++;
			}
			if (this->compare(data[index], data[k])) {
				std::swap(data[index], data[k]);
				index = k;
				j = index * 2 + 1;
				continue;
			}
			break;
		}
	}

protected:
	COMP_FUNCTOR compare;
	
};