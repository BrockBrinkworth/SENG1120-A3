// Class : BSTree.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : Header of a binary search table.

#ifndef BROCK_BSTREE
#define BROCK_BSTREE
#include <iostream>
#include <cstdlib>
#include <string>
#include "BTNode.h"
#include "HTable.h"

using namespace std;

template <typename value_type>
class BSTree
{
	public:
		
		// Constructors
		BSTree();
		
		// Destructor
		~BSTree();
		
		// Functions
		void remove_nodes( BTNode<value_type>* node );
		void add( const value_type& data );
		void remove( const value_type& data );
		ostream& printTable( ostream& out );
		int calculateParts();
		int calculateInventory();
		int calculateInventory( BTNode<value_type>* node );
		
	private:
		
		BTNode<value_type>* root_node;
		int size;
		
		// Recursing helper methods
		BTNode<value_type>* add( const value_type& data, BTNode<value_type>* node );
		BTNode<value_type>* remove( const value_type& data, BTNode<value_type>* node );
		BTNode<value_type>* find_max( BTNode<value_type>* const node ) const;
		BTNode<value_type>* find_min( BTNode<value_type>* const node ) const;
		ostream& printTable( ostream& out, const BTNode<value_type>* node );
};

	template <typename value_type>
	ostream& operator << ( ostream& out, BSTree<value_type>& tree );

#include "BSTree.hpp"
#endif