#include <iostream>
#include <memory>
#include "PegRow.h"
#include "Peg.h"
#include "ProgramModel.h"
#include "ProgramView.h"
#include "ProgramController.h"
#include "mytypes.h"
#include "TLNetTraffic.h"
#include "Composite.h"
#include <sys/types.h>
#include "LargeInteger.h"
#include <stdint.h>
//#include "BTree.h"
#include "btree.h"
#include "ABTree.h"
#include "linkedlist.h"
#include "prime.h"
#include "primesieve.h"
#include "ChainOfResp.h"
#include "Command.h"
int abtree_test();
int main_cor();
int command();
//#define MAX_PRIME 900002
//#define MAX_PRIME 999983
#define MAX_PRIME 1000000
#define IS_BIG_ENDIAN (*(uint16_t *)"\0\xff" < 0x100)
LONG_INT1 find_prime_at(int* idx, int maxPrime);
unsigned int generateRandom(unsigned int l, unsigned int u);
unsigned int generateRandom(unsigned int l, unsigned int u)
{
   unsigned int r = rand() % ((u - l) + 1);
   r = l + r;

   return r;
}

void sleep( clock_t wait );
void sleep( clock_t wait )
{
        clock_t goal;
        goal = wait + clock();
        while( goal > clock() );
}
//int BTree::countDeleted = 0;
int main(int argc,char** argv)
{
#if 0
unsigned int x = 0x76543210;
  char *c = (char*) &x;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. IS_BIG_ENDIAN =%d\n", IS_BIG_ENDIAN );
  }
  else
  {
     printf ("Underlying architecture is big endian. IS_BIG_ENDIAN  =%d\n", IS_BIG_ENDIAN );
  }
#endif
#if 0
 TLNetTraffic netTraffic;

                int count = 0, i=0;
                int seconds;

                while(i<=8)
                {
                        if (i%3==0)
                                printf("---------\nSession %d\n---------\n", ((i+1)/3)+1 );

                        if (count == 0) seconds =6, count = 1;
                        else if (count == 1) seconds = 4, count = 2;
                        else if (count == 2) seconds = 5, count = 0;

                        sleep( (clock_t)seconds * CLOCKS_PER_SEC );
                        netTraffic.Handle();
                        i++;
                }
#endif
#if 0
	// Create Program Model
	std::shared_ptr<ProgramModel> programModelPtr = std::make_shared<ProgramModel>(MAX_GUESS_NUM,PNUM);
	

	// Create Program Controller
	std::shared_ptr<ProgramController> programControllerPtr = std::make_shared<ProgramController>(programModelPtr);
	programControllerPtr->init();
	
	// Create Program View
	std::shared_ptr<ProgramView> programViewObj = std::make_shared<ProgramView>(programModelPtr, programControllerPtr);
	programModelPtr->attach(programViewObj);
	
	// Start the Program
	programViewObj->render();
#endif
#if 0
Composite containers[4];
	int i;
  for (i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      containers[i].add(new Leaf(i *3+j));

  for (i = 1; i < 4; i++)
    containers[0].add(&(containers[i]));

  for (i = 0; i < 4; i++)
  {
    containers[i].traverse();
    cout << endl;
  }
#endif
/*#define START_NUM 1000
#define APRIME 7919
#define OFFSET 919*/
#if 0
#define START_NUM 10000
#define APRIME 171
#define END_NUM (START_NUM + APRIME - 1)
#define TRYTIME_MAX 200
#define FAIL_NUM (APRIME*2)

	BTree b ;int i=0;
	//b.countDeleted = 0;
#if 0
	char* arr[ ] = { "1234", "12312323", "63245634253467", "54732879342", "1", "9999999", "321312", "132131232", "1321312321" } ;
//	int sz = sizeof ( arr ) / sizeof ( int ) ;
	int sz = 9;
	for ( int i = 0 ; i < sz ; i++ )
		b.insert ( LONGINT(arr[i]) ) ;
#endif
	int totalKey = 0;int fail = 0;
#if 1
   	srand(time(NULL));
	LONGINT0 tempptr;
	while (i < TRYTIME_MAX) {
		i++;
		//tempptr = generateRandom(START_NUM, END_NUM);
		tempptr = START_NUM+i;
		if (b.insert (tempptr)==0 ) fail++;
		if ( fail > FAIL_NUM ) {
				break;
		}
	}
#endif
	cout << "B-tree of order "<< (MAX+1) << endl ;
//	b.show( ) ;a
	tempptr =  10019;
	b.del ( tempptr ) ;
	tempptr =  10002;
//	b.del ( tempptr ) ;
//	b.show( ) ;
	//totalKey = 0;
	cout << "\n\nB-tree after deletion of values:(total key number=(0)Try number("<< i <<")fail="<<fail<< endl ;
#endif
#if 0
btree b ;
	int arr[ ] = { 27, 42, 22, 47, 32, 2, 51, 40, 13 } ;
	int sz = sizeof ( arr ) / sizeof ( int ) ;
	for ( int i = 0 ; i < sz ; i++ )
		b.insert ( arr[i] ) ;
	cout << "B-tree of order 5:" << endl ;
	b.show( ) ;
	b.del ( 22 ) ;
	b.del ( 11 ) ;
	for ( int i = 0 ; i < sz ; i++ )
		b.del ( arr[i] ) ;
	cout << "\n\nB-tree after deletion of values:" << endl ;
	b.show( ) ;
#endif
//	abtree_test();
#if 0
	int idx = 0;
	int maxprime = MAX_PRIME;
	if (argc == 2) {
	//	cout<<"maxprime="<< argv[1] <<endl;
		 maxprime = atoi(argv[1]);
	}
	cout<<"Result=[ "<< find_prime_at(&idx, maxprime ) <<" ]";
	cout<<"Of Prime("<< idx <<")"<< endl;
#endif
#if 0
	int maxprime = MAX_PRIME;
	if (argc == 2) {
		 maxprime = atoi(argv[1]);
	}
	get_prime(maxprime);
#else
	//primesieve(argc,argv);
	//main_cor();
	command();
#endif
	return 0;
}
int main_cor()
{
  srand(time(0));
  Handler1 root;
  Handler2 two;
  Handler3 thr;
  root.add(&two);
  root.add(&thr);
  thr.setNext(&root);
  for (int i = 1; i < 10; i++)
  {
    root.handle(i);
    cout << '\n';
  }
}

LONG_INT1 find_prime_at(int* idx, int maxPrime) {
   	srand(time(NULL));
	LONG_INT1 tempptr, retval(0);
	int i,t,k,sz,d;
	do {
    	ABTree b(10); // A B-Tree with minium degree 3
	i = 1;
	while (i < maxPrime) {
		tempptr = ++i;
		b.insert ( tempptr ) ;
	}
//	cout << "\n\nB-tree initialization (size="<<b.size() <<"at(1)="<<b.at(1)<< endl ;
//	b.traverse( ) ;
	k = 1;d=0;
	do {
	i = 2;
	t = b.at(0);
	while (i*t <= maxPrime) {
		b.remove ( t*i ) ;
		i++;
	}
		b.remove (  b.at(0) ) ;
		d++;
	k++;
	} while(k*k<maxPrime);
		sz = b.size();
		*idx = sz + d;
		retval = b.at(sz - 1);
		break;
	} while (1); 
 
	//cout << "\nB-tree["<<(k-1)<<"].Size=("<<b.size()<<").at(79)=[ "<< b.at(79) <<" ]"<< endl ;
	//b.traverse( ) ;
	return retval;
} 


// Driver program to test above functions
int abtree_test()
{
    ABTree t(3); // A B-Tree with minium degree 3
 
    t.insert(1);
    t.insert(3);
    t.insert(7);
    t.insert(10);
    t.insert(11);
    t.insert(13);
    t.insert(14);
    t.insert(15);
    t.insert(18);
    t.insert(16);
    t.insert(19);
    t.insert(24);
    t.insert(25);
    t.insert(26);
    t.insert(21);
    t.insert(4);
    t.insert(5);
    t.insert(20);
    t.insert(22);
    t.insert(2);
    t.insert(17);
    t.insert(12);
    t.insert(6);
 
    cout << "Traversal of tree constructed is\n";
    t.traverse();
    cout << endl;
 
    t.remove(6);
    cout << "Traversal of tree after removing 6\n";
    t.traverse();
    cout << endl;
 
    t.remove(13);
    cout << "Traversal of tree after removing 13\n";
    t.traverse();
    cout << endl;
 
    t.remove(7);
    cout << "Traversal of tree after removing 7\n";
    t.traverse();
    cout << endl;
 
    t.remove(4);
    cout << "Traversal of tree after removing 4\n";
    t.traverse();
    cout << endl;
 
    t.remove(2);
    cout << "Traversal of tree after removing 2\n";
    t.traverse();
    cout << endl;
 
    t.remove(16);
    cout << "Traversal of tree after removing 16\n";
    t.traverse();
    cout << endl;
 
    return 0;
}

int command()
{
  // Fred will "execute" Barney which will result in a call to passOn()
  // Barney will "execute" Betty which will result in a call to gossip()
  // Betty will "execute" Wilma which will result in a call to listen()
  Person wilma("Wilma", Command());
  // 2. Instantiate an object for each "callback"
  // 3. Pass each object to its future "sender"
  Person betty("Betty", Command(&wilma, &Person::listen));
  Person barney("Barney", Command(&betty, &Person::gossip));
  Person fred("Fred", Command(&barney, &Person::passOn));
  fred.talk();
}
