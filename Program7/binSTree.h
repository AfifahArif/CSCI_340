/*
Afifah Arif
Program 7 (Binary Search Tree and Tree Sort)
Due date: 11/08/2018
*/

#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"

template < class T >
class binSTree : public binTree < T >
{
	public:
		void insert ( const T& x );  //inserts node with x value
		bool search ( const T& x );  //searches leaf with x value
		bool remove ( const T& x );  //removes leaf with x value

	private:
		void insert ( Node < T >*&, const T& );  //private version of insert
		bool search ( Node < T >*, const T& ) const; //private version of search
		void remove ( Node < T >*&, const T& ); //private version of remove
		bool leaf ( Node < T >* node ) const; //check if node is leaf
};

template < class T >  //inserts node with x value
void binSTree<T>::insert ( const T& x )
{
	insert(this -> root, x);
}

template < class T > //searches leaf with x value
bool binSTree<T>::search ( const T& x )
{
	return search (this -> root, x);
}

template < class T > //removes leaf with x value
bool binSTree<T>::remove ( const T& x )
{
	if(this->size() == -1)
	{
		this -> root = NULL;
		return false;
	}
	if(this->size() > 0)
	{
		if(search(x))
		remove(this->root, x);
		return true;
	}
	else
	{
		return false;
	}
}

template < class T > //private version of insert
void binSTree<T>::insert ( Node <T>*& p, const T& v)
{
	if(p == NULL)
	{
		p = new Node<T>(v);
	}
	else if( v < p->data)
	{
		insert(p->left, v);
	}
	else if(v > p->data)
	{
		insert(p->right, v);
	}
	else
	{
		return;
	}
}

// private version of search
template <class T>
bool binSTree<T>::search ( Node <T>* p, const T& v ) const
{
	if(p == NULL)
		return false;
	else
	{
		if(v == p->data)
		{
			if(leaf(p))
			return true;
			else
			return false;
		}
		else if(v < p->data)
			return search(p->left, v);
		else
			return search(p->right, v);
	}
}

template < class T > //private version of remove
void binSTree<T>::remove ( Node <T>*& p, const T& v )
{
	Node<T>* curr;
	Node<T>* parent;
	curr = p;

	while(curr != NULL)
	{
		if(curr->data == v)
		{
			break;
		}
		else
		{
			parent = curr;
			if(v > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if(curr != NULL)
	{
		if(parent->right == curr) parent->right = NULL;
		else parent->left = NULL;
		delete curr;
		curr = NULL;
	}
}

// checks if node is leaf
template <class T>
bool binSTree<T>::leaf ( Node <T>* p ) const
{
	if(p->left == NULL && p->right == NULL)
	{
		return true; //node is a leaf
	}
	else
	{
		return false; //node is not a leaf
	}
}
#endif
