/*
	Name:	Nusra Ahmed
	File:   tableMultiChain.h
	Descr:
	Derived template class (from tableChain) to allow multiple hash keys
	with different data values.
*/
#ifndef tableMultiChain_H
#define tableMultiChain_H
#include <cstdlib>    // Provides size_t
#include "hashNode.h"    // Provides the hashNode struct and toolkit
#include "tableChain.h"  // Provides base hash table class with chaining

// derived template class
template <class RecordType>
class tableMultiChain : public tableChain <RecordType> {
public:
	// override since duplicates allowed
	// add entry at *end* of duplicate keys
	void insert(const RecordType& entry);
	// additional method to count number of entries for given key
	std::size_t count(int key) const;
	// additional method to display all entries for given key
	void display_key_values(int key) const;
	// additional method to remove all entries for given key
	void remove_all(int key);
};

// ***ADD METHOD DEFINITIONS HERE***
template<class RecordType>
void tableMultiChain<RecordType>::insert(const RecordType & entry)
{
	hashNode<RecordType>* cursor; // set to point to existing hashNode with given key

	assert(entry.key >= 0);

	// Set cursor to point to existing hashNode with given key (if there is one)
	cursor = find_node(entry.key);
	if (cursor != nullptr)
	{   // Append after the last key
		while (cursor->link != nullptr && cursor->link->data.key == entry.key)
			cursor = cursor->link;
		list_insert(cursor, entry);
		total_records++;
	}
	else
	{   // Add in a new spot
		list_head_insert(data[hash(entry.key)], entry);
		total_records++;
	}
}

template<class RecordType>
size_t tableMultiChain<RecordType>::count(int key) const
{
	size_t num = 0;
	if (data[hash(key)] != nullptr) {
		for (hashNode<RecordType>* cursor = data[hash(key)]; cursor != nullptr; cursor = cursor->link) {
			if (cursor->data.key == key)
				num++;
		}
	}
	return num;
}

template<class RecordType>
void tableMultiChain<RecordType>::display_key_values(int key) const
{
	if (data[hash(key)] != nullptr) {
		for (hashNode<RecordType>* cursor = data[hash(key)]; cursor != nullptr; cursor = cursor->link) {
			if (cursor->data.key == key)
				cout << '\t' << cursor->data << endl;
		}
	}
}

template<class RecordType>
void tableMultiChain<RecordType>::remove_all(int key)
{
	size_t numToDelete = count(key);

	for (size_t i = 0; i < numToDelete; i++) {
		remove(key);
	}
}

#endif


/*OUTPUT
The table size is 9

***DISPLAY ALL TABLE ENTRIES***
Index = 1
KEY=1623 DATA=11
KEY=1 DATA=11.1
KEY=1 DATA=11.2
KEY=1 DATA=11.3
KEY=5678 DATA=99
Index = 2
KEY=2435 DATA=22
KEY=2 DATA=22.1
KEY=2 DATA=22.2
Index = 3
KEY=3 DATA=33.1

The number of entries with KEY=1 is 3
KEY=1 DATA=11.1
KEY=1 DATA=11.2
KEY=1 DATA=11.3

The number of entries with KEY=2 is 2
KEY=2 DATA=22.1
KEY=2 DATA=22.2

The number of entries with KEY=3 is 1
KEY=3 DATA=33.1


Removing one element with KEY=2
The table size is 8

***DISPLAY ALL TABLE ENTRIES***
Index = 1
KEY=1623 DATA=11
KEY=1 DATA=11.1
KEY=1 DATA=11.2
KEY=1 DATA=11.3
KEY=5678 DATA=99
Index = 2
KEY=2435 DATA=22
KEY=2 DATA=22.2
Index = 3
KEY=3 DATA=33.1


Removing all elements with KEY=1
The table size is 5

***DISPLAY ALL TABLE ENTRIES***
Index = 1
KEY=1623 DATA=11
KEY=5678 DATA=99
Index = 2
KEY=2435 DATA=22
KEY=2 DATA=22.2
Index = 3
KEY=3 DATA=33.1

The number of entries with KEY=1 is 0

The number of entries with KEY=2 is 1
KEY=2 DATA=22.2

The number of entries with KEY=3 is 1
KEY=3 DATA=33.1
Press any key to continue . . .*/