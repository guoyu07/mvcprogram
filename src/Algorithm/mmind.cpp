#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mmind.h"
using namespace std;

//----------------------------------------------------------
// Function for returning the results of guess
//    0 - INCORRECT
//    1 - correct
//    2 - misplaced
//----------------------------------------------------------
void checkIfCorrect(char guess[], char result[], char code[])
{

	result[0] = 0;
	result[1] = 0;
	char blacks[PNUM] = {0};
	char whites[PNUM] = {0};


	for(int i=0; i<PNUM; i++)
	{
		if(guess[i] == code[i])
			blacks[i]=1;
		else
			blacks[i]=0;
	}

	for(int i=0; i<PNUM; i++)
	{
		if(blacks[i]!=1)
		{
			for(int f=0; f<PNUM; f++)
			{
				if(f==i) continue;
				if((guess[i] == code[f] && blacks[f] != 1))
					if(whites[f] == 0)
					{
						whites[f]=1;
						break;
					}
			}
		}
	}

	for(int i=0; i<PNUM; i++)
	{
		result[0] += blacks[i];
		result[1] += whites[i];
	}

}


//----------------------------------------------------------
//  Function for making the best prediction what color
//  should be put in corresponding slot
//----------------------------------------------------------
void makeAGuess(int index)
{
#if 0
	if(SOLUTION[index] == -1) //Checks if current slot has been solved
	{
		G_CODE[index] = -1;
		while(G_CODE[index] == -1) //If none of the misplaced can be put in this slot, make a random guess
		{
			RANDNUM = rand() % 6;
			if((CHECKED[index] & (1<<RANDNUM)) == 0) //Check if this color has been guessed previously
			{
				//CHECKED[index] |=(1<<RANDNUM);
				G_CODE[index] = RANDNUM;
			}
		}
	}
	else
		G_CODE[index] = SOLUTION[index];
#endif
}

int scoreCalculator(int black, int white)
{
	if(black == 0 && white == 0) return 0;
	if(black == 0 && white == 1) return 1;
	if(black == 1 && white == 0) return 2;
	if(black == 0 && white == 2) return 3;
	if(black == 1 && white == 1) return 4;
	if(black == 2 && white == 0) return 5;
	if(black == 0 && white == 3) return 6;
	if(black == 1 && white == 2) return 7;
	if(black == 2 && white == 1) return 8;
	if(black == 3 && white == 0) return 9;
	if(black == 0 && white == 4) return 10;
	if(black == 1 && white == 3) return 11;
	if(black == 2 && white == 2) return 12;
	if(black == 4 && white == 0) return 13;
}

void base6counter(char num[PNUM])
{
	num[3]++;
	if(num[3] == 6)
	{
		num[2]++;
		if(num[2] == 6)
		{
			num[1]++;
			if(num[1] == 6)
			{
				num[0]++;
				if(num[0]==6) num[0] = 0;
				num[1] = 0;
			}
			num[2] = 0;
		}
		num[3] = 0;
	}
}
/* Frans van Gool's MasterMind algorithm */
int main_test() {
	char mycode[PNUM]={0};int retval;
	LinkedListT* outlist = NULL;
	mycode[0] = 5;
	mycode[1] = 4;
	mycode[2] = 1;
	mycode[3] = 0;
	retval = code_breaker(&outlist, mycode);
	destroy_linkedlist(&outlist);
	return retval;
}

int code_breaker(LinkedListT** mylist, char* a) 
{
	int size=PNUM;int k=1;char reply[2];
	int retval = 1; /*Computer win*/
	int g[PNUM];
	do {
		if ( 1 == append_list( mylist, size )) {
			srand(time(NULL));
			memset(INPUT_CODE,0,PNUM);
			memset(G_CODE,0,PNUM);
			memset(A_CODE,0,PNUM);
			memset(SOLUTION,255,PNUM);
			memset(CHECKED,0,PNUM);
			memset(INCORRECT, 255, PNUM);
			//			cout << "Put 4 number code in with values from 0 to 5! (with spaces)" << endl << "For example: 0 3 4 2. User give a code:" << endl;
			INPUT_CODE[0] = a[0];
			INPUT_CODE[1] = a[1];
			INPUT_CODE[2] = a[2];
			INPUT_CODE[3] = a[3];
			int guesses = 0;
			char result[] = {0, 0};

			G_CODE[0] = 0; G_CODE[1] = 0; G_CODE[2] = 1; G_CODE[3] = 1;
			A_CODE[0] = 0; A_CODE[1] = 0; A_CODE[2] = 1; A_CODE[3] = 1;
			char previous_answers[10][PNUM];
			char previous_scores[10];
			while(guesses < MAX_GUESS_NUM)
			{
				guesses++;
				/*
				   if (guesses ==1) {
				   printf("Computer guesses at the %dst times:", guesses);
				   } else if (guesses ==2) {
				   printf("Computer guesses at the %dnd times:", guesses);
				   } else	if (guesses ==3) {
				   printf("Computer guesses at the %drd times:", guesses);
				   } else	if (guesses > 3) {
				   printf("Computer guesses at the %dth times:", guesses);
				   } */
				memcpy(GUESSED_CODE[guesses-1], G_CODE, 4);
				//printf(" [%d %d %d %d]",G_CODE[0],G_CODE[1],G_CODE[2],G_CODE[3]);
				//reset the misplaced variables
				checkIfCorrect(G_CODE, result, INPUT_CODE); //Check how if the guess was correct
				int score = scoreCalculator(result[0],result[1]);

				previous_answers[guesses-1][0] = G_CODE[0];
				previous_answers[guesses-1][1] = G_CODE[1];
				previous_answers[guesses-1][2] = G_CODE[2];
				previous_answers[guesses-1][3] = G_CODE[3];

				previous_scores[guesses-1] = score;

				if(result[0] == 4)
					break;

				bool anySolutions = true;

				while(anySolutions)
				{
					bool consistent = true;            
					for(int i=0; i<guesses; i++)
					{
						checkIfCorrect(A_CODE, result, previous_answers[i]);
						int test_score = scoreCalculator(result[0],result[1]);
						if(test_score != previous_scores[i])
						{
							consistent = false;
							break;
						}
					}
					if(consistent)
						break;

					base6counter(A_CODE);
					if(A_CODE[0] == 0 && A_CODE[1] == 0 && A_CODE[2] == 1 && A_CODE[3] == 1)
					{
						anySolutions = false;
						//	printf("ERROR: No SOLUTION possible!\n");
					}
				}


				G_CODE[0] = A_CODE[0];
				G_CODE[1] = A_CODE[1];
				G_CODE[2] = A_CODE[2];
				G_CODE[3] = A_CODE[3];

				//printf("--> [ %d ; %d ]\n", result[0],result[1]);
				GUESSED_CODE[guesses-1][4] = result[0];
				GUESSED_CODE[guesses-1][5] = result[1];

				if(guesses == MAX_GUESS_NUM) {
					//	printf("\n-- %d %d %d %d -- \n",INPUT_CODE[0],INPUT_CODE[1],INPUT_CODE[2],INPUT_CODE[3]);
				}


			}

			if(result[0] == PNUM)
			{
				GUESSED_CODE[guesses-1][4] = PNUM;
				GUESSED_CODE[guesses-1][5] = 0;
				GUESSED_NUM = guesses;
				//printf("--> [ %d ; %d ]\n", PNUM, 0);
				//cout << "\nComputer won the program, in " << guesses << " turns!" << endl << "Your code was: ";
				//	printf("[%d %d %d %d]\n", G_CODE[0],G_CODE[1],G_CODE[2],G_CODE[3]);
				retval = 1;
			}
			else {
				//cout << "\n\nComputer lost this program!" << endl;
				retval = 0;
			}
		}
		/*printf("Do you want to continue(y/n):");
		  scanf("%s", reply);*/
		break;
		if(strcmp(reply,"n")==0) { 
			break;
		} else 
			if(strcmp(reply,"y")==0) { 
				k++;
				continue;
			} else { k++;}


	} while(1);
	/*print_linkedlist(mylist); // program history showing here */

	return retval;
}


