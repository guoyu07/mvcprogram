#ifndef __MMIND_H__
#define __MMIND_H__
#include "mytypes.h"
#include "linkedlist.h"

#define INPUT_CODE (get_obj(*mylist, k)->input_code)
#define G_CODE (get_obj(*mylist, k)->g_code)
#define A_CODE (get_obj(*mylist, k)->a_code)
#define SOLUTION (get_obj(*mylist, k)->solution)
#define CHECKED (get_obj(*mylist, k)->checked)
#define INCORRECT (get_obj(*mylist, k)->incorrect)
#define RANDNUM  (get_obj(*mylist, k)->randNum)
#define GUESSED_CODE  (get_obj(*mylist, k)->guessed_code)
#define GUESSED_NUM  (get_obj(*mylist, k)->guessed_num)
int main_test();
extern int code_breaker(LinkedListT** mylist, char* a);
#endif
