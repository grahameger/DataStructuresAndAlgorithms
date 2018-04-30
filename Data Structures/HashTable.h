#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/*
 * Hash Table Data Structure
 * Templated
 * Graham Eger
 * eger@umich.edu
 */

#include <vector>
#include <utility>
#include <cstdint>
#include <cassert>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <iterator>

/* Overload std::hash<KeyType> if necessary */
template<typename Key, typename Value>
class HashTable 
{
public:
    // simplified typedefs
    using key_type = Key;
    using mapped_type = Mapped;
    using value_type = std::pair<Key, Mapped>;
    using size_type = std::size_t;

private:
    struct Node {
        KeyType k;
        ValueType v;
    };
    Node **table;
}

#endif