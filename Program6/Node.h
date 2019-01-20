#ifndef NODE_H
#define NODE_H

template <class T> class binTree;

template <class T> class Node
{
	friend class binTree <T>;
	public:
		//The node defualt constructor
		Node ( const T& =T ( ), Node <T>* = 0, Node <T>* = 0 );

	private:
		T nodeContent;
		Node <T> *left, *right;
};

// default constructor
template <class T>
Node <T>:: Node( const T& temp, Node <T>* newLeft, Node <T>* newRight )
{
	nodeContent = nod;
	left = newLeft;
	right = newRight;
}
#endif
