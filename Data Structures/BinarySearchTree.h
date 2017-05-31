#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/*
 * Binary search tree data structure
 * Templated
 *
 *
 */


#include <cassert>
#include <iostream>
#include <functional>
#include <algorithm>

template<typename T, typename COMPARE = std::less<T> >
class BinarySearchTree
{

private:
	struct Node {
		Node(const T &datum_in, Node * left_in, Node * right_in) {
			datum = datum_in;
			left = left_in;
			right = right_in;
		}
		T datum;
		Node * left;
		Node * right;
	};
public:
	BinarySearchTree() {
		root = nullptr;
	}

	// Copy constructor
	// TODO

	// Assignement operator
	// TODO

	// Destructor
	~BinarySearchTree() {
		clear(root);
	}

	// O(n)
	size_t size(Node * node) const {
		if (!node) {
			return 0;
		} else {
			return size(node->left) + size(node->right) + 1;
		}
	}

	bool empty() const {
		return !count;
	}
private:
	// Deletes all nodes below node
	void clear(Node * node) {
		if (node != nullptr) {
			clear(node->left);
			clear(node->right);
			delete node; node = nullptr;
		}
	}

	Node * root;
	COMPARE less;
	size_t count;
};

#endif
