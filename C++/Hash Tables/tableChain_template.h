// NAME:	Nusra Ahmed
// DATE:	11/17/17
// FILE:	tableChain_template.h
// DESCR:	Modified for Lab 11 (implemented the remove function)
// Written by: Michael Main (main@colorado.edu)
// TEMPLATE CLASS IMPLEMENTED: Table (see tableChain.h for documentation)
// INVARIANT for the Table ADT:
//   1. The number of records in the Table is in the member variable
//      total_records.
//   2. The actual records of the table are stored in a chained hash table.
//      An entry with key i is stored on the linked list with the head
//      pointer at data[hash(i)].

#include <cassert> // Provides assert
#include <cstdlib> // Provides size_t
#include "hashNode.h"  // Provides the hashNode struct and toolkit

template <class RecordType>
tableChain<RecordType>::tableChain()
// Library facilities used: cstdlib
{
	size_t i;

	total_records = 0;
	for (i = 0; i < TABLE_SIZE; i++)
		data[i] = nullptr;
}

template <class RecordType>
tableChain<RecordType>::tableChain(const tableChain<RecordType>& source)
// Library facilities used: hashNode.h, cstdlib 
{
	size_t i;
	hashNode<RecordType>* tail_ptr; // Needed for list_copy

	for (i = 0; i < TABLE_SIZE; i++)
		list_copy(source.data[i], data[i], tail_ptr);
	total_records = source.total_records;
}

template <class RecordType>
tableChain<RecordType>::~tableChain()
// Library facilities used: hashNode.h
{
	size_t i;

	total_records = 0;
	for (i = 0; i < TABLE_SIZE; i++)
		list_clear(data[i]);
}

template <class RecordType>
void tableChain<RecordType>::insert(const RecordType& entry)
// Library facilities used: cassert, hashNode.h
{
	hashNode<RecordType>* cursor; // set to point to existing hashNode with given key

	assert(entry.key >= 0);

	// Set cursor to point to existing hashNode with given key (if there is one)
	cursor = find_node(entry.key);
	if (cursor != nullptr)
	{   // Add in existing spot
		cursor->data = entry;
	}
	else
	{   // Add in a new spot
		list_head_insert(data[hash(entry.key)], entry);
		total_records++;
	}
}

template <class RecordType>
void tableChain<RecordType>::remove(int key)
// Library facilities used: cassert, hashNode.h
{
	// TO BE IMPLEMENTED
	// See tableChain.h for description

	//first ensure the key exists
	hashNode<RecordType> *node_ptr;
	node_ptr = find_node(key);
	if (node_ptr == nullptr)
		return; //table is unchanged

	//create a pointer to point to the head of the list
	hashNode<RecordType> *cursor;
	cursor = data[hash(key)];

	//check to see if the key is equal to the head pointer of the hash index
	if ((cursor->data).key == key) { //if the key values match
		list_head_remove(data[hash(key)]); //remove the first item
	}
	else {
		//traverse the list until the cursor-link's key is equal to the key that needs to be deleted
		while ((cursor != nullptr) && ((cursor->link->data).key != key)) 
			cursor = cursor->link;
		list_remove(cursor); //passes the pointer that precedes the key that needs to be deleted
	}
	total_records--; //decrement the amount of records
}

template <class RecordType>
void tableChain<RecordType>::operator =(const tableChain<RecordType>& source)
// Library facilities used: hashNode.h, cstdlib 
{
	size_t i;
	hashNode<RecordType>* tail_ptr; // Needed for list_copy

	if (this == &source)
		return; // Avoid self-assignment

	for (i = 0; i < TABLE_SIZE; i++)
	{
		list_clear(data[i]);
		list_copy(source.data[i], data[i], tail_ptr);
	}
	total_records = source.total_records;
}

template <class RecordType>
bool tableChain<RecordType>::is_present(int key) const
// Library facilities used: cassert, cstdlib
{
	assert(key >= 0);

	return (find_node(key) != nullptr);
}

template <class RecordType>
void tableChain<RecordType>::find(int key, bool& found, RecordType& result) const
// Library facilities used: cstdlib
{
	hashNode<RecordType> *cursor;

	cursor = find_node(key);
	found = (cursor != nullptr);
	if (found)
		result = cursor->data;
}

template <class RecordType>
size_t tableChain<RecordType>::hash(int key) const
// Library facilities used: cstdlib
{
	return (key % TABLE_SIZE);
}

template <class RecordType>
hashNode<RecordType>* tableChain<RecordType>::find_node(int key) const
// Postcondition: The return value is a pointer to the record with the
// specified key (if there is one). If there is no such hashNode, the return value
// is the nullptr pointer.
// Library facilities used: hashNode.h, cstdlib
{
	hashNode<RecordType>* cursor;

	cursor = data[hash(key)];
	while ((cursor != nullptr) && ((cursor->data).key != key))
		cursor = cursor->link;

	return cursor;
}

//***DISPLAY Member function***
template <class RecordType>
void tableChain<RecordType>::display_all()
{
	cout << "\n\n***DISPLAY ALL TABLE ENTRIES***" << endl;
	//loop through each array element
	for (size_t i = 0; i < TABLE_SIZE; i++) {
		//see if element is not empty
		if (data[i] != nullptr) {
			cout << "Index = " << i << endl;
			//display all values in location
			for (hashNode<RecordType> *cursor = data[i]; cursor != nullptr; cursor = cursor->link) {
				cout << '\t' << cursor->data << endl;
			}	
		}
	}
}

/*OUTPUT
I have initialized an empty table. Each record in the table
has an integer key and a real number as data.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 33.2
33.2 has been read.
Please enter a non-negative integer for a key: 4058
4058 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 22.2
22.2 has been read.
Please enter a non-negative integer for a key: 2
2 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 11.4
11.4 has been read.
Please enter a non-negative integer for a key: 1
1 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 100
100 has been read.
Please enter a non-negative integer for a key: 811
811 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 11.3
11.3 has been read.
Please enter a non-negative integer for a key: 1623
1623 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 22.1
22.1 has been read.
Please enter a non-negative integer for a key: 2435
2435 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 11.2
11.2 has been read.
Please enter a non-negative integer for a key: 3245
3245 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 11.1
11.1 has been read.
Please enter a non-negative integer for a key: 5678
5678 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: i
Please enter a real number for a record's data: 33.1
33.1 has been read.
Please enter a non-negative integer for a key: 3
3 has been read.
The record has been inserted.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: s
The table size is 9

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: d


***DISPLAY ALL TABLE ENTRIES***
Index = 0
KEY=811 DATA=100
Index = 1
KEY=5678 DATA=11.1
KEY=3245 DATA=11.2
KEY=1623 DATA=11.3
KEY=1 DATA=11.4
Index = 2
KEY=2435 DATA=22.1
KEY=2 DATA=22.2
Index = 3
KEY=3 DATA=33.1
KEY=4058 DATA=33.2

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: r
Please enter a non-negative integer for a key: 3245
3245 has been read.
Remove has been called with that key.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: s
The table size is 8

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: d


***DISPLAY ALL TABLE ENTRIES***
Index = 0
KEY=811 DATA=100
Index = 1
KEY=5678 DATA=11.1
KEY=1623 DATA=11.3
KEY=1 DATA=11.4
Index = 2
KEY=2435 DATA=22.1
KEY=2 DATA=22.2
Index = 3
KEY=3 DATA=33.1
KEY=4058 DATA=33.2

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: r
Please enter a non-negative integer for a key: 2
2 has been read.
Remove has been called with that key.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: s
The table size is 7

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: d


***DISPLAY ALL TABLE ENTRIES***
Index = 0
KEY=811 DATA=100
Index = 1
KEY=5678 DATA=11.1
KEY=1623 DATA=11.3
KEY=1 DATA=11.4
Index = 2
KEY=2435 DATA=22.1
Index = 3
KEY=3 DATA=33.1
KEY=4058 DATA=33.2

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: r
Please enter a non-negative integer for a key: 3
3 has been read.
Remove has been called with that key.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: s
The table size is 6

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: d


***DISPLAY ALL TABLE ENTRIES***
Index = 0
KEY=811 DATA=100
Index = 1
KEY=5678 DATA=11.1
KEY=1623 DATA=11.3
KEY=1 DATA=11.4
Index = 2
KEY=2435 DATA=22.1
Index = 3
KEY=4058 DATA=33.2

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: r
Please enter a non-negative integer for a key: 811
811 has been read.
Remove has been called with that key.

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: s
The table size is 5

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: d


***DISPLAY ALL TABLE ENTRIES***
Index = 1
KEY=5678 DATA=11.1
KEY=1623 DATA=11.3
KEY=1 DATA=11.4
Index = 2
KEY=2435 DATA=22.1
Index = 3
KEY=4058 DATA=33.2

The following choices are available:
S   Print the result from the size( ) function
I   Insert a new record with the insert(...) function
R   Remove a record with the remove(...) function
?   Check whether a particular key is present
F   Find the data associated with a specified key
D   Display all entries in hash table
Q   Quit this test program
Enter choice: q
Ridicule is the best test of truth.
Press any key to continue . . .
*/