// Class : BTNode.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : Header of a binary tree node.

#ifndef BROCK_BTNODE
#define BROCK_BTNODE
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename value_type>
class BTNode
{
	public:
		
		// Constructors
		BTNode();
		BTNode( const value_type& initial_data = value_type(), BTNode* initParent = NULL, BTNode* initLeft = NULL, BTNode* initRight = NULL ); 
		
		//Destructors
		~BTNode();
		
		// Setters
		void set_data( const value_type& new_data );
		void set_parent( BTNode<value_type>* new_parent );
		void set_left( BTNode<value_type>* new_left );
		void set_right( BTNode<value_type>* new_right );
		
		// Getters
		const value_type get_data() const;
		value_type get_data();
		BTNode<value_type>* get_parent();
		const BTNode<value_type>* get_parent() const;
		BTNode<value_type>* get_right();
		const BTNode<value_type>* get_right() const;
		BTNode<value_type>* get_left();
		const BTNode<value_type>* get_left() const;
		
		// Functions
		BTNode<value_type>* remove( value_type data, BTNode<value_type>* parent );
		
	private:
		
		value_type data;
		BTNode<value_type>* parent;
		BTNode<value_type>* right;
		BTNode<value_type>* left;
};

template <typename value_type>
ostream& operator << ( ostream& out, const BTNode<value_type>& BTNode );

#include "BTNode.hpp"
#endif