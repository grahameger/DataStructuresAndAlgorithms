#ifndef LIST_H
#define LIST_H

/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Graham Eger
 */

#include <iostream>
#include <cassert>
#include <cstddef>

template <typename T>
class List
{
public:

	// default constructor
	List() {
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	// Destructor
	~List() {
		clear();
	}

	// copy constructor
	List(const List &list_in) {
		// do everything normal
		first = nullptr;
		last = nullptr;
		size. = 0;
		// then just copy it in
		copy_in(list_in);

		// The destructor will run
		// if the other lists lifetime is over
	}

	// assignement operator
	List &operator=(const List &list_in) {
		size = 0;
		clear();
		copy_in(list_in);
		return *this;
	}

	bool empty() const {
		return !first;
	}

	size_t size() const {
		return size;
	}

	T & front() const {
		assert(!empty());
		return first->datum;
	}

	T & back() const {
		assert(!empty());
		return last->datum;
	}

	void push_front(const T &datum) {
		// Make a new node
		Node * temp = new Node;
		temp->datum = datum;
		// Assign it to the front
		if (empty()) {
			temp->next = nullptr;
			temp->prev = nullptr;
			first = last = temp;
		}
		else {
			temp->next = first;
			temp->prev = nullptr;
			first = temp;
		}
		++size;
	}

    void push_back(const T &datum) {
        // Make a new node
        Node * temp = new Node;
        //Set the data to the parameter
        temp->datum = datum;
        
        //now the pointer work
        temp->next = nullptr;
        if (empty()) {
            temp->next = nullptr;
            temp->prev = nullptr;
            first = last = temp;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
        ++size;
    }

    void pop_front() {
    	assert(!empty());
    	
    	// Get the node to kill on the stack
    	Node * kill = first;

    	if (size() > 1) {
    		// do the transfer of first
    		first = first->next;
    		first->prev = nullptr;
    	} else {
    		// if size is one just set everything to null
    		first = nullptr;
    		last = nullptr;
    	}
    	delete kill; kill = nullptr;
    	--size;
    }

    void pop_back() {
    	assert(!empty());

    	// Get the node to kill on the stack
    	Node * kill = back;

    	if (size() > 1) {
    		// do the transfer of back
    		last = last->prev;
    		last->next = nullptr;
    	} else {
    		// if the size is one just set everything to null 
    		first = nullptr;
    		last = nullptr;
    	}
    	delete kill; kill = nullptr;
    	--size;
    }
	
private:

	// The node type
	struct Node
	{
		Node *next;
		Node *prev;
		T datum;
	};

	// private clear implementation
	void clear() {
		while (!empty()) {
			pop_front();
		}
	}

	void copy_in(const List<T> &other) {
		for (Node * i = other.first; i != nullptr; i = i->next) {
			push_back(i->datum);
		}
	}

	Node *first;
	Node *last;
	size_t size;

public:
// The ITERATOR for the linked list
class Iterator {

	// Iterator interface to list
public:
	Iterator() {
		ptr = nullptr;
	}
	
	~Iterator();

	// copy constructor
	Iterator(Iterator const &input) {
		ptr = input.ptr;
	}

	// decrement operator
	Iterator& operator--() {
		assert(ptr);
		ptr = ptr->prev;
		return *this;
	}

	T& operator*() const {
		assert(ptr);
		return ptr->datum;
	}

	bool operator!= (Iterator rhs) const {
		return ptr != rhs.ptr;
	}

	bool operator== (Iterator rhs) const {
		return ptr == rhs.ptr;
	}
 
private:
	// The current position of the iterator
	Node * ptr;

	// let us use the list private functions
	friend class List;

	// construct an iterator at a specific position
	Iterator(Node *p) {
		ptr = p;
	}
	
};

// List iterator functions

Iterator begin() const {
	return Iterator(first);
}

// an end iterator is null
Iterator end() const {
	return Iterator();
}

void erase(Iterator i) {
	//make sure it exists
    assert(i.node_ptr);
        
    //get the node to kill
    Node* kill = i.ptr;
        
    if (kill == first) {
        pop_front();
    } else if (kill == last) {
        pop_back();
    } else {
        //make them point to eachother instead of two if not an edge case
        kill->prev->next = kill->next;
        kill->next->prev = kill->prev;
        delete kill; kill = nullptr;
    }
}

void insert(Iterator i, const T &datum) {
    Node* current = i.node_ptr;
        
    if (current == first) {
        push_front(datum);
    } else if (current == nullptr) {
        push_back(datum);
    } else {
       //make a new node and set its datum
        Node* fresh = new Node;
        fresh->datum = datum;
            
        //fix the pointers to point correctly
        fresh->next = current;
        fresh->prev = current->prev;
        current->prev = fresh;
        fresh->prev->next = fresh;
    }
}



};
