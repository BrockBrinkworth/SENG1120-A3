// Class : BSTree.hpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : Implementation of a binary hash table.

#include "BSTree.h"
#include <cstdlib>
#include <iostream>

template <typename value_type>
BSTree<value_type>::BSTree()
{
	root_node = NULL;
	size = 0;
}

template <typename value_type>
BSTree<value_type>::~BSTree()
{
	remove_nodes( root_node );
}

// This function removes all nodes.
template <typename value_type>
void BSTree<value_type>::remove_nodes( BTNode<value_type>* node ) 
{
	if ( node == NULL ) 
	{ 
		return;
	}
	
	remove_nodes( node->get_left() );
	remove_nodes( node->get_right() );
	
	delete node;
	size--;
}

// This function adds a new node to the tree.
template <typename value_type>
void BSTree<value_type>::add( const value_type& data )
{
	if ( root_node == NULL )
	{
		root_node = new BTNode<value_type>( data );
		size++;
		return;
	}
	else
	{
		add( data, root_node );
	}
	
}

// This function adds data to the tree.
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::add( const value_type& data, BTNode<value_type>* node )
{
	if ( data < node->get_data() ) 
	{
		if ( node->get_left() ) 
		{
			node->set_left( add( data, node->get_left() ) );
		} 
		else 
		{
			node->set_left( new BTNode<value_type>( data, node ) );
			size++;
		}
	} 
	
	if ( data > node->get_data() ) 
	{
		if ( node->get_right() ) 
		{
			node->set_right( add( data, node->get_right() ) );
		} 
		else 
		{
			node->set_right( new BTNode<value_type>( data, node ) );
			size++;
		}
	}
	return node;
}

// This function removes the node from the tree.
template <typename value_type>
void BSTree<value_type>::remove( const value_type& data ) 
{
	BTNode<value_type>* root = root_node;
	root = remove( data, root );
}

// This function removes data from the tree.
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::remove( const value_type& data, BTNode<value_type>* node ) 
{
	BTNode<value_type>* temp;
	if ( node == NULL ) 
	{
		return NULL;
	} 
	
	if ( data < node->get_data() ) 
	{
		node->set_left( remove( data, node->get_left() ) );

		if ( node->get_left() ) 
		{
			node->get_left()->set_parent( node );
		}
	} 
	else if ( data > node->get_data() ) 
	{
		node->set_right( remove( data, node->get_right() ) );

		if ( node->get_right() ) 
		{
			node->get_right()->set_parent( node );
		}
	} 
	else 
	{
		if ( node->get_left() && node->get_right() ) 
		{
			temp = find_min( node->get_right() );
			node->set_data( temp->get_data() );
			node->set_right( remove( node->get_data(), node->get_right() ) );
		} 
		else
		{
			temp = node;
			if ( node->get_left() == NULL ) 
			{
				node = node->get_right();
			} 
			else if ( node->get_right() == NULL ) 
			{
				node = node->get_left();
			}
			delete temp;
			size--;
		}
	}

	if ( !node ) 
	{
		return node;
	}
	return node;
}

// This function calls recursion on printTable.
template <typename value_type>
ostream& BSTree<value_type>::printTable( ostream& out )
{
	BTNode<value_type>* root = root_node;
	return printTable( out, root );
}

// This function prints the data in order.
template <typename value_type>
ostream& BSTree<value_type>::printTable( ostream& out, const BTNode<value_type>* node )
{
	if ( node != NULL ) 
	{
		printTable( out, node->get_left() );
		out << node->get_data() << " ";
		printTable( out, node->get_right() );
	}
	return out;
}

// This function returns the data in size.
template <typename value_type>
int BSTree<value_type>::calculateParts()
{
	return size;
}

// This function returns the data in root_node.
template <typename value_type>
int BSTree<value_type>::calculateInventory()
{
	if( root_node == NULL )
	{
		return 0;
	}
	return calculateInventory( root_node );
}

// This function concatenates the node quantity, the left node and the right node.
template <typename value_type>
int BSTree<value_type>::calculateInventory( BTNode<value_type>* node )
{
	if( node == NULL )
	{
		return 0;
	}
	return node->get_data().get_quantity() + calculateInventory( node->get_left() ) + calculateInventory( node->get_right() );
}

// This function returns find_max on the right node.
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::find_max( BTNode<value_type>* const node ) const 
{
	if ( node == NULL ) 
	{
		return NULL;
	}
	
	if ( node->get_right() == NULL ) 
	{
		return node;
	}
		
	return find_max( node->get_right() );
	
}

// This function returns find_min on the left node.
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::find_min( BTNode<value_type>* const node ) const 
{
	if ( node == NULL ) 
	{
		return NULL;
	}
	
	if ( node->get_left() == NULL ) 
	{
		return node;
	}
	
	return find_min( node->get_left() );
}

// This function prints out the tree.
template <typename value_type>
ostream& operator << ( ostream& out, BSTree<value_type>& tree ) 
{
	return tree.printTable( out );
}