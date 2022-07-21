// Class : HTable.hpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : Implementation of a hash table.

#ifndef HTABLE_IMPLEMENTATION
#define HTABLE_IMPLEMENTATION

#include "HTable.h"
#include "BSTree.h"
#include "MechPart.h"
#include <iostream>
#include <string>
#include <cstdlib>

template<typename value_type>
HTable<value_type>::HTable()
{
    CAPACITY = TABLE_SIZE;
	current_hashes = 0;
    for ( int i = 0; i < CAPACITY; i++ )
    {
        occupied_table[i] = false;
		hash_table[i] = value_type();
    }
}

template<typename value_type>
HTable<value_type>::~HTable()
{
	// IDK?
}

template <typename value_type>
int HTable<value_type>::hashfun( const value_type& value )
{
	int position = 0;
	string temp = value.get_code();
	
	for (int i=0; i<( int )temp.length(); i++)
	{
		position += ( i+1 ) * ( i+1 ) * temp.at( i );
	}
	return position % TABLE_SIZE;
}

// This function adds data to the hash table.
template<typename value_type>
bool HTable<value_type>::add( const value_type& data )
{
    int position = hashfun( data );
    if (occupied_table[position])
    {
		return false;
    }
    else
    {
        occupied_table[position] = true;
		current_hashes++;
		hash_table[position] = data;
        return true;
    }
}

// This function removes data from the hash table.
template<typename value_type>
void HTable<value_type>::remove( const value_type& data )
{
    int position = hashfun( data );
    if ((occupied_table[position]) && (hash_table[position] == data))
    {
        hash_table[position] = value_type();
        occupied_table[position] = false;
		current_hashes--;
    }
}

// Thsi function returns the codes in the hash table.
template<typename value_type>
std::string HTable<value_type>::displayTable()
{
    std::string s = "";
    for (int i = 0; i < CAPACITY; i++)
    {
        if ( occupied_table[i] == true )
        {
            s += hash_table[i].get_code();
			s += " ";
        }
    }
    return s;
}

// This function returns the data in current hashes.
template<typename value_type>
int HTable<value_type>::calculateParts()
{
	return current_hashes;
}

// This function concatenates the quantity that hash_table holds for every integer [i].
template<typename value_type>
int HTable<value_type>::calculateInventory()
{
	int sum = 0;
	for( int i = 0; i < CAPACITY; i++)
	{
		sum += hash_table[i].get_quantity();
	}
	return sum;
}

// This function outputs the displayTable function.
template<typename value_type>
std::ostream& operator << ( std::ostream &s, HTable<value_type> &HT )
{
    s << HT.displayTable();
	return s;
}

// This function allows concatenation.
template<typename value_type>
HTable<value_type>& HTable<value_type>::operator += ( const HTable<value_type> &HT )
{
    return *this;
}

#endif