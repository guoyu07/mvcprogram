/*
 * This file acts as a Program Model for the Program.
 * It contains all the settings of Program and also contains
 * the Board associated with the Program
 */

#ifndef PROGRAMMODEL_H_
#define PROGRAMMODEL_H_

#include "Board.h"
#include "Subject.h"
#include <memory>
#include "linkedlist.h"
#include "mmind.h"

enum ProgramState
{
	MAIN_MENU = 0,
	PROGRAM_IN_PROGRESS,
	PROGRAM_ENDED,
	HELP_MODE,
};
class ProgramModel : public Subject
{
	int m_retVal;
	int m_rowCount;
	int m_pegsInRow;
	Board m_programBoard;
	ProgramState m_state;
	LinkedListT *m_outlist;
	int a[PNUM];
	public:
	ProgramModel(int rowCount, int pegsInRow);
	virtual ~ProgramModel();
	Board & getProgramBoard();
	void startProgram();
	void initProgram();
	ProgramState getState() const;
	void setState(ProgramState state);
	int getPegsInRow() const;
	int getRowCount() const;
	void printCodeBreaker() const;
	LinkedListT *getLinkedList() const;
	private:
	int getCodeBreaker();
};



#endif /* PROGRAMMODEL_H_ */
