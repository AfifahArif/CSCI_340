/*
Afifah Arif
Program 7 (Binary Search Trees and Tree Sort)
Due date: 11/08/2018
*/

#ifndef BINTREE_H
#define BINTREE_H

#include "/home/cs340/progs/18f/p7/Node.h"

template < class T > class binTree
{
	public:
		binTree ( ); //default constructor
		bool empty ( ) const; //checks if tree empty
		int size ( ) const; //returns no of nodes
		int height ( ) const; //returns height of tree
		virtual void insert ( const T& ); //inserts a node in shortest subtree
		binTree ( const binTree <T>& ); //copy constructor
		binTree <T>& operator = ( const binTree <T>& ); //assignment operator
		virtual ~binTree ( ); //destructor
		void clear ( ); //destroys tree
		void inorder ( void ( * ) ( T& )); //inorder traversal of tree

	protected:
		Node <T>* root; //root of tree

	private:
		int size ( Node <T>* ) const; //private version of size
		int height ( Node <T>* ) const; //private version of height
		void insert ( Node <T>*&, const T& ); //private version of insert
		void inorder ( Node <T>*, void ( * ) ( T& )); //private version of inorder
		void clear ( Node <T>*& ); //private version of clear
		Node <T>* copy ( const Node <T>* ); //creates clone of tree
};

template <class T> binTree <T>::binTree() //default constructor
{
	root = 0; //initialize root
}

template <class T> //checks if tree empty
bool binTree<T>::empty( ) const
{
	if( root == 0 )
	{
		return true; // empty tree
	}
	else
	{
		return false;
	}
}

template <class T> //returns num of nodes
int binTree <T>::size( ) const
{
	return size( root ); // call recursive
}

template <class T> //returs height
int binTree <T>::height( ) const
{
	return height( root ); // call recursive
}

template <class T> //inserts node in shortest subtree
void binTree <T>::insert( const T& v )
{
	insert( root, v ); //call recursive
}

template <class T> //inorder transversal of tree
void binTree <T>::inorder( void ( *fn ) ( T& ) )
{
	inorder( root, fn ); //call recursive
}

template <class T> //private version of size
int binTree <T>::size( Node <T>* ptr ) const
{
	if( ptr != 0 ) // if not empty
	{
		return 1 + size( ptr->left ) + size( ptr->right );
	}
	else
	{
		return 0; // emtpy tree
	}
}

template <class T> //private version of height
int binTree <T>::height( Node <T>* ptr ) const
{
	if( ptr == 0 )
	{
		return 0; // empty tree
	}
	else
	{
		int lHeight = height( ptr->left ); // left side
		int rHeight = height( ptr->right ); // right side
		if( lHeight > rHeight ) // which is greater
		{
			return 1 + lHeight; // return left
		}
		else
		{
			return 1 + rHeight; // return right
		}
	}
}

template <class T> //private version of interest
void binTree <T>::insert( Node <T>* & p, const T& v )
{
	if( p == 0 )
	{
		Node <T> * newNode;
		newNode = new Node <T>( v );
		p = newNode;
	}
	else
	{
		int lHeight = height( p->left );
		int rHeight = height( p->right );
		if( lHeight <= rHeight )
		{
			insert( p->left, v );
		}
		else
		{
			insert( p->right, v );
		}
	}
}

template <class T> //private version of inorder
void binTree <T>::inorder( Node <T>* p, void ( *fn ) ( T& ) )
{
	if( p != NULL )
	{
		inorder( p->left, fn );
		fn( p->data );
		inorder( p->right, fn );
	}
}

template <class T> //copy constructor
binTree <T>::binTree ( const binTree <T>& t)
{
	root = copy( t.root );
}

template <class T> //assignment operator
binTree<T>& binTree<T>::operator= (const binTree<T>& p)
{
	if( this != &p )
	{
		clear(root); // clear tree
		root = copy(p.root); // copy tree
	}
	return *this;
}

template <class T> //destructor
binTree <T>::~binTree ( )
{
	clear();
}

template <class T> //destroys tree
void binTree <T>::clear ( )
{
	clear( this->root );
	root = NULL;
}

template <class T>
void binTree <T>::clear ( Node <T>*& p )
{
	if( p != NULL )
	{
		clear( p->left );
		clear( p->right );
		delete p;
	}
}

template <class T> //create clone of a tree
Node <T>* binTree<T>::copy ( const Node <T>* p )
{
	Node<T> * newNode;
	if(p != NULL)
	{
		newNode = new Node<T>( p->data );
		newNode->left = copy( p->left );
		newNode->right = copy( p->right );
		return newNode;
	}
	else
	{
		return NULL;
	}
}
#endif
