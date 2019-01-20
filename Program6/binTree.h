#ifndef BINTREE_H
#define BINTREE_H

#include "/home/cs340/progs/18f/p6/Node.h"

template <class T> class binTree
{
	public:
		binTree ( ); //default constuctor
		int  height( ) const; //returns height of tree
		virtual void insert ( const T& ); //inserts node in tree
		void inorder ( void ( * ) (const T& )); //inorder traversal of tree

	protected:
		Node <T>* root; //root of tree

	private:
		int height ( Node <T>* ) const; //private version of height( )
		void insert ( Node <T>*&, const T& ); //private version of insert( )
		void inorder ( Node <T>*, void ( * ) (const T& )); //private version of inorder( )
};

//function definitions
template <class T>
binTree <T>::binTree( )
{
	//set + initialize the root
	root = 0;
}

//returns height of tree
template <class T>
int binTree <T>::height( ) const
{
	return height( root );	//calls recursive
}

//inserts node in the binary tree - recursive function
template <class T>
void binTree <T>::insert( const T& temp )
{
	insert( root, temp );
}

//performs inorder traversal of tree
template <class T>
void binTree <T>::inorder( void ( *print ) (const T& ) )
{
	inorder( root, print );
}

// private version of height
template <class T>
int binTree <T>::height( Node <T>* ptr ) const
{
	if( ptr == 0 )
	{
		return 0;
	}
	else
	{
		int hLeft = height( ptr->left );
		int hRight = height( ptr->right );

		if( hLeft > hRight )
		{
			return 1 + hLeft;
		}
		else
		{
			return 1 + hRight;
		}
	}
}

//randomly selects the subtree
typedef enum { left_side, right_side } SIDE;
SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }

//private version of insert
template <class T>
void binTree <T>::insert( Node <T>*& nod, const T& temp )
{
	if( nod == NULL )
	{
		Node <T> * newNode;
		newNode = new Node <T>( temp ); //new node with new value
		nod = newNode; //set ptr to new node
	}
	else
	{
		if(rnd()==left_side)
		{
			insert( nod->left,temp );
		}
		else
		{
			insert( nod->right, temp );
		}
	}
}

//private version of inorder
template <class T>
void binTree <T>::inorder( Node <T>* nod, void ( *print ) (const T& ) )
{
	if( nod != NULL )
	{
		inorder( nod->left, print );
		print( nod->data );
		inorder( nod->right, print );
	}
}
#endif
