// Class : BTNode.hpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : Implementation of a binary tree node.

#include "BTNode.h"
#include <cstdlib>
#include <iostream>

template <typename value_type>
BTNode<value_type>::BTNode()
{
	parent = NULL;
	left = NULL;
	right = NULL;
	data = NULL;
}


template <typename value_type>
BTNode<value_type>::BTNode( const value_type& initial_data, BTNode* initParent, BTNode* initLeft, BTNode* initRight ) 
{	
	parent = initParent;
	left = initLeft;
	right = initRight;
	data = initial_data;
}

template <typename value_type>
BTNode<value_type>::~BTNode()
{
	parent = NULL;
	left = NULL;
	right = NULL;
}

// This function allows setting of data.
template <typename value_type>
void BTNode<value_type>::set_data( const value_type& new_data )
{
	data = new_data;
}

// This function allows setting of the left node.
template <typename value_type>
void BTNode<value_type>::set_left( BTNode<value_type>* new_left )
{
	left = new_left;
}

// This function allows setting of the parent node.
template <typename value_type>
void BTNode<value_type>::set_parent( BTNode<value_type>* new_parent )
{
	parent = new_parent;
}

// This function allows setting of the right node.
template <typename value_type>
void BTNode<value_type>::set_right( BTNode<value_type>* new_right )
{
	right = new_right;
}

// This function allows returning of the data in the node.
template <typename value_type>
value_type BTNode<value_type>::get_data()
{
	return data;
}

// This function allows returning of the constant data in the node.
template <typename value_type>
const value_type BTNode<value_type>::get_data() const
{
	return data;
}

// This function allows returning of the parent node.
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_parent()
{
	return parent;
}

// This function allows returning of the constant parent node.
template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_parent() const
{
	return parent;
}

// This function allows returning of the left node.
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_left()
{
	return left;
}

// This function allows returning of the constant left node.
template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_left() const
{
	return left;
}

// This function allows returning of the right node.
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_right()
{
	return right;
}

// This function allows returning of the constant right node.
template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_right() const
{
	return right;
}

// This function returns the node data.
template <typename value_type>
ostream& operator << ( ostream& out, const BTNode<value_type>& BTNode ) 
{
	return BTNode.get_data();
}

// This function removes the data in the node.
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::remove( value_type data, BTNode<value_type>* parent )
{
	if ( data < this->data )
	{
		if ( left != NULL )
		{
			return left->remove( data, this );
		}
		else
		{
			return NULL;
		}
	}
	else if ( data > this->data )
	{
		if ( right != NULL )
		{
			return right->remove( data, this );
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		if ( left != NULL && right != NULL )
		{
			this->data = right->minimum_value();
			return right->remove( this->data, this );
		}
		else if ( parent->left == this )
		{
			if ( left != NULL )
			{
				parent->left = left;
			}
			else
			{
				parent->left = right;
			}
			return this;
		}
		else if ( parent->right == this )
		{
			if ( left != NULL )
			{
				parent->right = left;
			}
			else
			{
				parent->right = right;
			}
			return this;
		}
	}
	return this;
}