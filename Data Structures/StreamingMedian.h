#ifndef MEDIAN_H
#define MEDIAN_H

// A templated streaming median class, push values and grab the median at any point
// uses std::less and std::greater

#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>


// Type must eb a numeric type
template <typename T>
class StreamingMedian {
public:
	// Seed the queues
	StreamingMedian() {
		upper.push(std::numeric_limits<T>::max());
		lower.push(std::numeric_limits<T>::min());
	}

	void push(const T &val) {
		if (val >= upper.top()) {
			upper.push(val);
		} else {
			lower.push(val);
		}

		// rebalance if necessary
		// upper queue is larger
		if (upper.size() - lower.size() == 2) {
			lower.push(upper.top);
			upper.pop();
		} else if (lower.size() - upper.size() == 2) {
			upper.push(lower.top());
			lower.pop();
		}
	}

	T& median() {
		if (upper.size() == lower.size()) {
			return (upper.top() + lower.top()) / 2.0;
		} else if (upper.size() > lower.size()) {
			return upper.top();
		} else {
			return lower.top();
		}
	}
private:
	std::priority_queue<T, std::vector<T> std::greater<T> > upper;
	std::priority_queue<T, std::vector<T>, std::less<T> >    lower;
};

#endif

int main() {
	StreamingMedian<int> sm;
	for (int i = 0; i < 11; ++i)
	{
		sm.push(i);
	}
	std::cout << sm.median() << '\n';
}