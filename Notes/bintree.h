#ifndef BINTREE_H
#define BINTREE_H

#include "node.h"

template <class T> class binTree
{
   public:
       binTree();
       int height() const;
       virtual void insert ( const T& );
       void inorder ( void ( * ) ( T& ));
   protected:
       Node <T>* root;
   private:
       int height ( Node <T>* ) const;
       void insert ( Node <T>*&, const T& );
       void inorder ( Node <T>*, void ( * ) ( T& ));
};

//function definitions
template <class T>
binTree <T>::binTree( )
{
   //set the root
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
void binTree <T>::inorder( void ( *print ) ( T& ) )
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
       int heightleft = height( ptr->leftChild );
       int heightRight = height( ptr->childRight );
  
       if( heightleft > heightRight )
       {
           return 1 + heightleft;
       }
       else
       {
           return 1 + heightRight;
       }
   }
}

template <class T>
void binTree <T>::insert( Node <T>* & nod, const T& temp )
{
   if( nod == 0 )
   {
       Node <T> * newNode;
       newNode = new Node <T>( temp );
       nod = newNode;
   }     
   else
   {
       int heightleft = height( nod->leftChild );
       int heightRight = height( nod->childRight );
       typedef enum { left_side, right_side } SIDE;
SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }
  
       if( heightleft <= heightRight )
       {
           insert( nod->leftChild, temp );
       }
       else
       {
           insert( nod->childRight, temp );
       }
   }
}

template <class T>
void binTree <T>::inorder( Node <T>* nod, void ( *print ) ( T& ) )
{
   if( nod != NULL )
   {
       inorder( nod->leftChild, print );
       print( nod->nodeContent );
       inorder( nod->childRight, print );
   }
}

#endif
