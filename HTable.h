// Class : HTable.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : Header of a hash table.

#ifndef BROCK_HTABLE
#define BROCK_HTABLE
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename value_type>
class HTable
{
	public:
		
		// Constructors
		HTable();
		
		// Destructor
		~HTable();
		
		// Functions
		bool add( const value_type& data );
		void remove( const value_type& data );
		std::string displayTable();
		HTable<value_type>& operator+=( const HTable<value_type> &HT );
		int calculateParts();
		int calculateInventory();
		
		// Constant integer
        static const int TABLE_SIZE = 5000;
		
	private:
		
		// Variable to store data
        int CAPACITY;

        // Hash table function
        int hashfun( const value_type& value );

        // Integer for hash table initial capacity
        value_type hash_table[TABLE_SIZE];

        // Integer for occupied table initial capacity
        bool occupied_table[TABLE_SIZE];
		
		// Current number of hashes
		int current_hashes;
};

	template<typename value_type>
    std::ostream& operator << ( std::ostream& s, HTable<value_type> &HT );

#include "HTable.hpp"
#endif