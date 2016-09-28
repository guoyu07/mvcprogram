/*******************************************************************************
 *
 *  File name:              linkedlist.h
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

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "mytypes.h"

/*extern LinkedListT* mylist;*/

ObjectT *new_object(int x);
ObjectT *append_obj(LinkedListT** plist, ObjectT *obj);
ObjectT *remove_obj(LinkedListT** plist, int ref);

int detach_list(LinkedListT** plist,LinkedListT* item);
int append_list(LinkedListT** plist, int size);

ObjectT *get_obj(LinkedListT* plist, int ref);

void modify_mylist(LinkedListT* plist);
void print_linkedlist(LinkedListT* plist);
void destroy_linkedlist(LinkedListT** plist);


char* itoa(int value, char* result, int base);

#endif
