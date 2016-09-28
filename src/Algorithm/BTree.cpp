#include "BTree.h"
#include <cstring>
using namespace std;
BTree :: BTree( )
{
	root = NULL ;
}

int BTree :: insert ( LONGINT1 val )
{
	LONGINT0 i ;
	BTNode *c, *n ;
	int flag ;int k;
	//if ( root!=NULL && searchnode ( val, root, &k ) ){
	//	return 0;
	//}
	flag = setval ( val, root, &i, &c ) ;
	if ( flag )
	{
		n = new BTNode ;
		n -> count = 1 ;
		/*	for (int i = 0; i <= n -> count; i++) {
			(n ->value).push_back( vector<LONGINT0>() );
			(n ->value).at((n ->value).size()-1).push_back( 0 );	
			}*/

		n -> value[1][0] = i ;
		n -> child[0] = root ;
		n -> child[1] = c ;
		root = n ;
		return 1;
	}
	return 0;
}
int BTree :: setval ( LONGINT1 val, BTNode *n, LONGINT0 *p, BTNode **c )
{
	int k ;
	if ( n == NULL )
	{
		*p = val ;
		*c = NULL ;
		return 1 ;
	}
	else
	{
		if ( searchnode ( val, n, &k ) ){
			//	cout << endl << "Key value already exists." << endl ;
		} 
		if ( setval ( val, n -> child[k], p, c ) )
		{
			if ( n -> count < MAX )
			{
				fillnode ( *p, *c, n, k ) ;
				return 0 ;
			}
			else
			{
				split ( *p, *c, n, k, p, c ) ;
				return 1 ;
			}
		}
		return 0 ;
	}
}
BTNode * BTree :: search ( LONGINT1 val, BTNode *root, int *pos )
{
	if ( root == NULL )
		return NULL ;
	else
	{
		if ( searchnode ( val, root, pos ) )
			return root ;
		else
			return search ( val, root -> child[*pos], pos ) ;
	}
}
int BTree :: searchnode ( LONGINT1 val, BTNode *n, int *pos )
{
	if ( val < n -> value[1][0] )
	{
		*pos = 0 ;
		return 0 ;
	}
	else
	{
		*pos = n -> count ;
		while ( ( val < n -> value[*pos][0] ) && *pos > 1 )
			( *pos )-- ;
		if ( val == n -> value[*pos][0] )
			return 1 ;
		else
			return 0 ;
	}
}
void BTree :: fillnode ( LONGINT1 val, BTNode *c, BTNode *n, int k )
{
	for (int i = n -> count ; i > k ; i-- )
	{
		n -> value[i + 1][0] = n -> value[i][0] ;
		n -> child[i + 1] = n -> child[i] ;
	}
	/*(n ->value).push_back( vector<LONGINT0>() );
	  (n ->value).at((n ->value).size()-1).push_back( 0 );	*/
	n -> value[k + 1][0] = val ;
	n -> child[k + 1] = c ;
	n -> count++ ;
}
void BTree :: split ( LONGINT1 val, BTNode *c, BTNode *n,
		int k, LONGINT0 *y, BTNode **newnode )
{
	int  mid ;

	if ( k <= MIN )
		mid = MIN ;
	else
		mid = MIN + 1 ;

	*newnode = new BTNode ;
	( *newnode ) -> count = MAX - mid ;
	/*for (int i = 0; i <=  ( *newnode )  -> count; i++) {
	  (( *newnode ) ->value).push_back( vector<LONGINT0>() );
	  (( *newnode ) ->value).at((( *newnode ) ->value).size()-1).push_back( 0 );	
	  }*/

	for (int i = mid + 1 ; i <= MAX ; i++ )
	{
		( *newnode ) -> value[i - mid][0] = n -> value[i][0] ;
		( *newnode ) -> child[i - mid] = n -> child[i] ;
	}

	n -> count = mid ;
	/*for (int i = 0; i <=  n  -> count; i++) {
	  (n ->value).push_back( vector<LONGINT0>() );
	  (n ->value).at((n ->value).size()-1).push_back( 0 );	
	  }*/

	if ( k <= MIN ) {
		fillnode ( val, c, n, k ) ;
	}
	else {
		fillnode ( val, c, *newnode, k - mid ) ;
	}
	*y = n -> value[n -> count][0] ;
	( *newnode ) -> child[0] = n -> child[n -> count] ;
	/*	(n ->value).at((n ->value).size()-1).pop_back();	
		(n ->value).pop_back();*/
	n -> count-- ;
}
void BTree::emptyBTNode(BTNode* temp) {
	/*		while(temp && !(temp->value).empty()) {
			(temp ->value).at((temp ->value).size()-1).pop_back();
			(temp ->value).pop_back();
			}*/
}
void BTree :: del ( LONGINT1 val )
{
	BTNode * temp ;
	cout<<"deleting..."<<val<<endl;
	if ( ! delhelp ( val, root ) )
		cout << endl << "1.Value " << val << " not found." ;
	else
	{

		if ( root -> count == 0 )
		{
			//cout << endl << "1.Value " << val << " found." ;
			temp = root ;
			root = root -> child[0] ;
			emptyBTNode(temp);
			delete temp ;
		}
	}
}
int BTree :: delhelp ( LONGINT1 val, BTNode *root )
{
	int i ;
	int flag ;

	if ( root == NULL )
		return 0 ;
	else
	{
		flag = searchnode ( val, root, &i ) ;
		if ( flag )
		{
			if ( root -> child[i - 1] )
			{
				copysucc ( root, i ) ;
				flag = delhelp ( root -> value[i][0], root -> child[i] ) ;
				if ( !flag ) {
					cout << endl << "2.Value " << val << " not found." ;
				} else {
					//cout << endl << "2.Value " << val << "  found." ;
				}
			}
			else {
				clear ( root, i ) ;
			}
		}
		else {
			flag = delhelp ( val, root -> child[i] ) ;
		}
		if ( root -> child[i] != NULL )
		{
			//cout << endl << "3.Value " << val << "  found." ;
			if ( root -> child[i] -> count < MIN ) {
				//	cout << endl << "3a.Value " << val << "  found." ;
				restore ( root, i ) ;
			}
		}
		return flag ;
	}
}
void BTree :: clear ( BTNode *root, int k )
{
	for (int i = k + 1 ; i <= root -> count ; i++ )
	{
		root -> value[i - 1][0] = root -> value[i][0] ;
		root -> child[i - 1] = root -> child[i] ;
	}
	/*	(root ->value).at((root ->value).size()-1).pop_back();
		(root ->value).pop_back();*/
	root -> count-- ;
}
void BTree :: copysucc ( BTNode *root, int i )
{
	BTNode *temp = root -> child[i] ;

	while ( temp -> child[0] )
		temp = temp -> child[0] ;

	root -> value[i][0] = temp -> value[1][0] ;
}
void BTree :: restore ( BTNode *root, int i )
{
	if ( i == 0 )
	{
		if ( root -> child [1] -> count > MIN )
			leftshift ( 1 ) ;
		else
			merge ( 1 ) ;
	}
	else
	{
		if ( i == root -> count )
		{
			if ( root -> child[i - 1] -> count > MIN )
				rightshift ( i ) ;
			else
				merge ( i ) ;
		}
		else
		{
			if ( root -> child[i - 1] -> count > MIN )
				rightshift ( i ) ;
			else
			{
				if ( root -> child[i + 1] -> count > MIN )
					leftshift ( i + 1 ) ;
				else
					merge ( i ) ;
			}
		}
	}
}
void BTree :: rightshift ( int k )
{
	BTNode *temp ;
	temp = root -> child[k] ;
	/*(temp ->value).push_back( vector<LONGINT0>() );
	  (temp ->value)[(temp ->value).size()-1].push_back( 0 );*/
	for (int i = temp -> count ; i > 0 ; i-- )
	{
		temp -> value[i + 1][0] = temp -> value[i][0] ;
		temp -> child[i + 1] = temp -> child[i] ;
	}
	temp -> child[1] = temp -> child[0] ;
	temp -> count++ ;
	temp -> value[1][0] = root -> value[k][0] ;
	temp = root -> child[k - 1] ;
	root -> value[k][0] = temp -> value[temp -> count][0] ;
	root -> child[k] -> child [0] = temp -> child[temp -> count] ;
	/*	(temp ->value).at((temp ->value).size()-1).pop_back();
		(temp ->value).pop_back();*/
	temp -> count-- ;
}
void BTree :: leftshift ( int k )
{
	BTNode *temp ;
	temp = root -> child[k - 1] ;
	/*(temp ->value).push_back( vector<LONGINT0>() );
	  (temp ->value).at((temp ->value).size()-1).push_back( 0 );*/
	temp -> count++ ;
	temp -> value[temp -> count][0] = root -> value[k][0] ;
	temp -> child[temp -> count] = root -> child[k] -> child[0] ;
	temp = root -> child[k] ;
	root -> value[k][0] = temp -> value[1][0] ;
	temp -> child[0] = temp -> child[1] ;

	temp -> count-- ;
	for ( int i = 1 ; i <= temp -> count ; i++ )
	{
		temp -> value[i][0] = temp -> value[i + 1][0] ;
		temp -> child[i] = temp -> child[i + 1] ;
	}
	/*	(temp ->value).at((temp ->value).size()-1).pop_back();	
		(temp ->value).pop_back();*/
}
void BTree :: merge ( int k )
{
	BTNode *temp1, *temp2 ;
	temp1 = root -> child[k] ;
	temp2 = root -> child[k - 1] ;
	/*(temp2 ->value).push_back( vector<LONGINT0>() );
	  (temp2 ->value).at((temp2 ->value).size()-1).push_back( 0 );*/
	temp2 -> count++ ;
	temp2 -> value[temp2 -> count][0] = root -> value[k][0] ;
	temp2 -> child[temp2 -> count] = root -> child[0] ;

	for ( int i = 1 ; i <= temp1 -> count ; i++ )
	{
		/*(temp2 ->value).push_back( vector<LONGINT0>() );
		  (temp2 ->value).at((temp2 ->value).size()-1).push_back( 0 );*/
		temp2 -> count++ ;
		temp2 -> value[temp2 -> count][0] = temp1 -> value[i][0] ;
		temp2 -> child[temp2 -> count] = temp1 -> child[i] ;
	}
	for (int i = k ; i < root -> count ; i++ )
	{
		root -> value[i][0] = root -> value[i + 1][0] ;
		root -> child[i] = root -> child[i + 1] ;
	}
	/*	(root ->value).at((root ->value).size()-1).pop_back();
		(root ->value).pop_back();*/
	root -> count-- ;
	emptyBTNode(temp1);
	delete temp1 ;
}
void BTree :: show( )
{
	display ( root ) ;
}
void BTree :: display ( BTNode *root )
{
	if ( root != NULL )
	{
		cout<<endl;int i;
		for ( i = 0 ; i < root -> count ; i++ )
		{
			display ( root -> child[i] ) ;
			cout << root -> value[i + 1][0] << " " ;
		}
		display ( root -> child[i] ) ;
	}
}
void BTree :: deltree ( BTNode *root )
{
	if ( root != NULL )
	{	int i;
		if(  root -> count >= MAX+1 ) {
			return;
		}
		//cout<<"deltree:"<<root -> count <<endl;
		for ( i = 0 ; i < root -> count ; i++ )
		{
			deltree ( root -> child[i] ) ;
			emptyBTNode( root -> child[i] );
			if (root && root -> child[i]) {
				delete ( root -> child[i] ) ;
				root -> child[i] = NULL ;
			}
		}
		deltree ( root -> child[i] ) ;
		emptyBTNode( root -> child[i] );
		if(root && root -> child[i]) {
			delete ( root -> child[i] ) ;
			root -> child[i] = NULL ;
		}
	}
}

BTree :: ~BTree( )
{
	deltree ( root ) ;
	emptyBTNode( root  );
	if (root) {
		delete ( root ) ;
		root =  NULL;
	}
}
