/*******************************************************************************
 *
 *  File name:              mytypes.h
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
#ifndef __MYTYPES_H__
#define __MYTYPES_H__
#define PNUM 4 /* number of positions needed to be guessed */
#define MAX_GUESS_NUM 5

typedef struct object_m ObjectT;
struct object_m {
	int ref;
	int len;
	char* buf;
	char* input_code;
	char* g_code;
	char* a_code;
	char* solution;
	char* checked;
	char* incorrect;
	char randNum;
	char** guessed_code;
	char* temp_code;
	char guessed_num;
};

typedef struct linkedlist_m LinkedListT;
struct linkedlist_m {
	ObjectT* data;
	LinkedListT* next;
};

#endif

