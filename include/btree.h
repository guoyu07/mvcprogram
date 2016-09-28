#ifndef _BTREE_H__
#define _BTREE_H__

#include <iostream>
#include <stdlib.h>
const int MAX = 4 ;
const int MIN = ((MAX/2)) ;
struct btnode
{
	int count ;
	int value[MAX + 1] ;
	btnode *child[MAX + 1] ;
	btnode(){
		count = 0;
		for (int i = 0;i < MAX+1;i++) {
			value[i] = 0;
			child[i] = NULL;
		}
	}
} ;
class btree
{
	private :
		btnode *root ;
	public :
		btree( ) ;
		void insert ( int val ) ;
		int setval ( int val, btnode *n, int *p, btnode **c ) ;
		static btnode * search ( int val, btnode *root, int *pos ) ;
		static int searchnode ( int val, btnode *n, int *pos ) ;
		void fillnode ( int val, btnode *c, btnode *n, int k ) ;
		void split ( int val, btnode *c, btnode *n,
				int k, int *y, btnode **newnode ) ;
		void del ( int val ) ;
		int delhelp ( int val, btnode *root ) ;
		void clear ( btnode *root, int k ) ;
		void copysucc ( btnode *root, int i ) ;
		void restore ( btnode *root, int i ) ;
		void rightshift ( int k ) ;
		void leftshift ( int k ) ;
		void merge ( int k ) ;
		void show( ) ;
		static void display ( btnode *root ) ;
		static void deltree ( btnode *root ) ;
		~btree( ) ;
} ;
#endif
