/*******************************************************************************
 *
 *  File name:              linkedlist.c
 *
 *  Version:                1
 *
 *  Author:                 PHUOC
 *
 *  Date created:           2010/11/11
 *
 *  Copyright 2012 COMPEX Pte, Singapore. All rights reserved.
 *
 *  Module Description:
 *
 *  This is the source code file for Application. It contains function implementations
 *  of external prototypes which are declared in its header file.
 *
 *  Revision History:
 *
 *  Rev:  Date:       Author:  Comments:
 *  1     2010/11/11  PHUOCTV  Creation
 *
 *******************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h> 
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"
/*LinkedListT* mylist = NULL;*/

ObjectT *new_object(int x){
	ObjectT* retobj = (ObjectT*) malloc( sizeof(ObjectT));
	if(retobj == NULL) return NULL;
	if (x > 0) {
		/*		char* bx = (char*) malloc(x);*/
		char* ax = (char*) malloc(x);
		if (ax) {
			memset(ax, '1', x);
		}
		retobj->buf = (char*) ax;

		retobj->input_code = (char*) malloc(x);
		if(retobj->input_code) {
			memset(retobj->input_code, '1', x);
		}
		ax = (char*) malloc(x);
		if (ax) 
		memset(ax, 0, x);
		retobj->g_code = (char*) ax;
		ax = (char*) malloc(x);
		if (ax) 
		memset(ax, 0, x);
		retobj->a_code = (char*) ax;
		ax = (char*) malloc(x);
		if (ax) 
		memset(ax, 0, x);
		retobj->solution = (char*) ax;
		ax = (char*) malloc(x);
		if (ax) 
		memset(ax, 0, x);
		retobj->checked = (char*) ax;
		ax = (char*) malloc(x);
		if (ax) 
		memset(ax, 0, x);
		retobj->incorrect = (char*) ax;
		retobj->randNum = '0';

		/*	
			int** x;
			int* temp;

			x = malloc(dimension1_max * sizeof(int*));
			temp = malloc(dimension1_max * dimension2_max * sizeof(int));
			for (int i = 0; i < dimension1_max; i++) {
			x[i] = temp + (i * dimension2_max);
			}

			[...]

			free(temp);
			free(x);
		 */
		retobj->guessed_code= (char**)malloc( MAX_GUESS_NUM * sizeof(char*));
		retobj->temp_code= (char*)malloc( MAX_GUESS_NUM * (PNUM+2) * sizeof(char));
		if (retobj->guessed_code && retobj->temp_code) {
		for (int i = 0; i < MAX_GUESS_NUM; i++) {
			retobj->guessed_code[i] =  retobj->temp_code + (i *  (PNUM+2) );
		}
		for (int i = 0; i < MAX_GUESS_NUM; i++) {
			for (int j = 0; j < PNUM+2; j++) {
				retobj->guessed_code[i][j] = 0;
			}
		}
		}

		retobj->guessed_num = 0;
	} else {
		retobj->buf = NULL;
	}
	retobj->len = x;
	retobj->ref = 0; /*default value*/
	return retobj;
}
ObjectT *append_obj(LinkedListT** plist, ObjectT *obj){
	LinkedListT* new_item = (LinkedListT*) malloc(sizeof(LinkedListT));
	ObjectT* retobj;
	LinkedListT* thelist = *plist;
	LinkedListT* prelist = NULL;
	if (new_item == NULL) {
		retobj = NULL;
	} else {
		new_item->data = obj;
		new_item->next = NULL;
		if (thelist == NULL) {
			*plist = new_item;
			/*new_item->data->ref = 1;*/ /* index of first element */
		} else {
			while (thelist != NULL) {
				prelist = thelist;
				thelist = thelist->next;
			}
			/*new_item->data->ref = prelist->data->ref + 1;*/ /*Update new reference number*/
			prelist->next = new_item;
		}
		retobj = obj;
	}
	return retobj;
}

ObjectT *remove_obj(LinkedListT** plist, int ref){
	LinkedListT* thelist = *plist;
	ObjectT *myobj = NULL;
	while (thelist != NULL) {
		if (thelist->data->ref == ref) {
			myobj = thelist->data;
			detach_list(plist, thelist);
			break;
		}
		thelist = thelist->next;
	}

	return myobj;
}

ObjectT *get_obj(LinkedListT* plist, int ref){
	LinkedListT* thelist = plist;
	ObjectT *myobj = NULL;
	while (thelist != NULL) {
		if (thelist->data->ref == ref) {
			myobj = thelist->data;
			break;
		}
		thelist = thelist->next;
	}

	return myobj;
}
#if 0
char *a2x(int a, int b) {
	return &(get_obj(a+1)->buf[ b ]);
}
#endif
int detach_list(LinkedListT** plist, LinkedListT* item) {
	LinkedListT* thelist = *plist;
	LinkedListT* prelist = NULL;
	LinkedListT* nextlist = NULL;
	if (item == *plist) {
		/*Remove first item*/
		prelist = *plist;
		*plist = (*plist)->next;
		free(prelist);
		return 1;
	}
	do {

		if ( item == thelist->next ) {
			prelist = thelist;
			nextlist = thelist->next->next;
			free(thelist->next);
			prelist->next = nextlist;
			break;
		} else {
			thelist = thelist->next;
			if (thelist == NULL ) {
				return 0;	
			}
		}
	} while(1);

	return 1;
}

int append_list(LinkedListT** plist, int size) {
	int listnum = size, i;
	ObjectT*  myobj;
	for(i = 0 ; i < 1; i++) {
		myobj = new_object(listnum);
		if(append_obj(plist , myobj)==NULL) {
			break;
		}
	}
	if (i == 1) {
		return 1;
	} else {
		return 0;
	}
}
void modify_mylist(LinkedListT* plist) {
	int j;
	ObjectT *myobj;
	LinkedListT* thelist = plist;
	while (thelist != NULL) {
		myobj = thelist->data;
		for(j=0; j<myobj->len; j++) {
			myobj->input_code[ j ] = j;
		}
		thelist = thelist->next;
	}
}

void print_linkedlist(LinkedListT* plist){
	int i,j ;
	LinkedListT* thelist = plist;
	ObjectT *myobj;
	while (thelist != NULL) {
		myobj = thelist->data;
		printf("CODE GUES TF\n");
		for(i = 0; i < MAX_GUESS_NUM; i++) {
			if ( i + 1> myobj->guessed_num) {
				break;
			}
			for(j=0; j<myobj->len; j++) {
				printf("%c",myobj->input_code[j]+'0');
			}
			printf(" ");
			for(j=0; j<myobj->len; j++) {
				printf("%c",myobj->guessed_code[i][j]+'0');
			}
			printf(" ");
			for(j=myobj->len; j<myobj->len+2; j++) {
				printf("%c",myobj->guessed_code[i][j]+'0');
			}
#if 0
			printf(" ");
			for(j=0; j<myobj->len; j++) {
				printf("%c",myobj->solution[j]+'0');
			}
			printf(" ");
			for(j=0; j<myobj->len; j++) {
				printf("%c",myobj->checked[j]+'0');
			}
			printf(" ");
			for(j=0; j<myobj->len; j++) {
				printf("%c",myobj->incorrect[j]+'0');
			}
#endif
			printf("\n");
		}
		thelist = thelist->next;
	}
}

void destroy_linkedlist(LinkedListT** plist){
	ObjectT *myobj;
	int i;
	i = 0;
	do {
		if(  (myobj = remove_obj(plist, i+1)) !=NULL) {
			free(myobj->buf);
			free(myobj->input_code);
			free(myobj->g_code);
			free(myobj->a_code);
			free(myobj->solution);
			free(myobj->checked);
			free(myobj->incorrect);
			free(myobj->temp_code); 
			free(myobj->guessed_code);
			free(myobj);
		} else {
			break;
		}
		i++;
	} while(1);
}
/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.

 */
char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

