#ifndef QUEUE_H_CFB5FC276C1C498CB42E7DA970373A0D
#define QUEUE_H_CFB5FC276C1C498CB42E7DA970373A0D

#include <iostream>
#include <cassert>

// A templated FIFO queue implemented using a singly-linked list

template <typename T>
class Queue
{
public:
	Queue() : first(nullptr), last(nullptr), count(0) {	}

	~Queue() {
		while (!empty()) {
			pop();
		}
	}

	bool empty() {
		return !size();
	}

	T& peek() const {
		return first->datum;
	}

	size_t size() const {
		return count;
	}

	void push(const T &val) {
		// We're not going to construct we'll do this on our own
		Node * temp = new Node(val);
		if (size() == 0) {
			first = temp;
			last = temp;
		} else {
			last->next = temp;
			last = temp;
		}
		count++;
	}

	void pop() {
		assert(!empty());
		Node * to_kill = first;
		first = first->next;
		delete to_kill; to_kill = nullptr;
		count--;
	}

private:
	struct Node {
		Node(const T &val) : datum(val), next(nullptr) { }
		Node * next;
		T datum;
	};

	Node * first;
	Node * last;
	size_t count;
};


#endif