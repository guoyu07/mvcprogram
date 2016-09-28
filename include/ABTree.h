/* The following program performs deletion on a B-Tree. It contains functions
   specific for deletion along with all the other functions provided in the
   previous articles on B-Trees. See http://www.geeksforgeeks.org/b-tree-set-1-introduction-2/
   for previous article.

   The deletion function has been compartmentalized into 8 functions for ease
   of understanding and clarity

   The following functions are exclusive for deletion
   In class ABTreeNode:
   1) remove
   2) removeFromLeaf
   3) removeFromNonLeaf
   4) getPred
   5) getSucc
   6) borrowFromPrev
   7) borrowFromNext
   8) merge
   9) findKey

   In class ABTree:
   1) remove

   The removal of a key from a B-Tree is a fairly complicated process. The program handles
   all the 6 different cases that might arise while removing a key.

Testing: The code has been tested using the B-Tree provided in the CLRS book( included
in the main function ) along with other cases.

Reference: CLRS3 - Chapter 18 - (499-502)
It is advised to read the material in CLRS before taking a look at the code. */

#ifndef __ABTREE_H__
#define __ABTREE_H__

#include<iostream>
#include "LargeInteger.h"
#define LONG_INT0 int&
#define LONG_INT1 int

//#define LONG_INT0 LargeInteger&
//#define LONG_INT1 LargeInteger

using namespace std;

// A ABTree node
class ABTreeNode
{
	LONG_INT1 *keys;  // An array of keys
	int t;      // Minimum degree (defines the range for number of keys)
	ABTreeNode **C; // An array of child pointers
	int n;     // Current number of keys
	bool leaf; // Is true when node is leaf. Otherwise false
	void getSize(int *psize);
	void atIndex(int *psize, int idx, LONG_INT1* ovalue);
	public:

	ABTreeNode(int _t, bool _leaf);   // Constructor
	~ABTreeNode();	
	// A function to traverse all nodes in a subtree rooted with this node
	void traverse();

	// A function to search a key in subtree rooted with this node.
	ABTreeNode *search(LONG_INT0 k);   // returns NULL if k is not present.

	// A function that returns the index of the first key that is greater
	// or equal to k
	int findKey(LONG_INT0 k);

	// A utility function to insert a new key in the subtree rooted with
	// this node. The assumption is, the node must be non-full when this
	// function is called
	void insertNonFull(LONG_INT0 k);

	// A utility function to split the child y of this node. i is index
	// of y in child array C[].  The Child y must be full when this
	// function is called
	void splitChild(int i, ABTreeNode *y);

	// A wrapper function to remove the key k in subtree rooted with
	// this node.
	void remove(LONG_INT0 k);

	// A function to remove the key present in idx-th position in
	// this node which is a leaf
	void removeFromLeaf(int idx);

	// A function to remove the key present in idx-th position in
	// this node which is a non-leaf node
	void removeFromNonLeaf(int idx);

	// A function to get the predecessor of the key- where the key
	// is present in the idx-th position in the node
	LONG_INT1 getPred(int idx);

	// A function to get the successor of the key- where the key
	// is present in the idx-th position in the node
	LONG_INT1 getSucc(int idx);

	// A function to fill up the child node present in the idx-th
	// position in the C[] array if that child has less than t-1 keys
	void fill(int idx);

	// A function to borrow a key from the C[idx-1]-th node and place
	// it in C[idx]th node
	void borrowFromPrev(int idx);

	// A function to borrow a key from the C[idx+1]-th node and place it
	// in C[idx]th node
	void borrowFromNext(int idx);

	// A function to merge idx-th child of the node with (idx+1)th child of
	// the node
	void merge(int idx);
	int size(){ 
		int rsize = 0;
		getSize(&rsize);
		return rsize;
	}
	LONG_INT1 at(int idx) {
		int rsize = 0;
		LONG_INT1 ovalue = 0;

		atIndex(&rsize, idx, &ovalue);
		return ovalue;
	}
	// Make ABTree friend of this so that we can access private members of
	// this class in ABTree functions
	friend class ABTree;
};

class ABTree
{
	ABTreeNode *root; // Pointer to root node
	int t;  // Minimum degree
	public:

	// Constructor (Initializes tree as empty)
	ABTree(int _t)
	{
		root = NULL;
		t = _t;
	}

	void traverse()
	{
		if (root != NULL) root->traverse();
	}

	// function to search a key in this tree
	ABTreeNode* search(LONG_INT0 k)
	{
		return (root == NULL)? NULL : root->search(k);
	}

	// The main function that inserts a new key in this B-Tree
	void insert(LONG_INT1 k);

	// The main function that removes a new key in thie B-Tree
	void remove(LONG_INT1 k);
	int size() {
		return (root==NULL)?0: root->size();
	}

	LONG_INT1 at(int idx) {
		if (root==NULL) {
			return LONG_INT1(0);
		} else {
			if (idx >= size()) {
				return LONG_INT1(0);
			}
			return root->at(idx);
		}
	}

};
#endif
