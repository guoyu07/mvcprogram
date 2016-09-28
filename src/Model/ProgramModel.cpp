#include "ProgramModel.h"
#include <stdlib.h> 
#include <time.h>  

/*
 * Constructor
 */
ProgramModel::ProgramModel(int rowCount, int pegsInRow) : m_rowCount(rowCount), m_pegsInRow(pegsInRow), m_programBoard(m_rowCount, m_pegsInRow)
{
	m_state  = MAIN_MENU;
	m_outlist = NULL;
	srand (time(NULL));
}

ProgramModel::~ProgramModel(){	
	destroy_linkedlist(&m_outlist);
}
/*
 * Returns the associated Program Board Object
 */
Board & ProgramModel::getProgramBoard() {
	return m_programBoard;
}


/*
 * Starts the Program by initializing Program Board and also
 * setting the Program State to PROGRAM_IN_PROGRESS
 */
void ProgramModel::startProgram()
{
	m_programBoard = Board(m_rowCount, m_pegsInRow);
	setState(PROGRAM_IN_PROGRESS);
	a[0] = rand() % 6;
	a[1] = rand() % 6;
	a[2] = rand() % 6;
	a[3] = rand() % 6;
	m_programBoard.addPegInShield(Peg((PegColor)(a[0]), CODE), 0);
	m_programBoard.addPegInShield(Peg((PegColor)(a[1]), CODE), 1);
	m_programBoard.addPegInShield(Peg((PegColor)(a[2]), CODE), 2);
	m_programBoard.addPegInShield(Peg((PegColor)(a[3]), CODE), 3);
	if(1== getCodeBreaker()) {
		//printCodeBreaker();
	}
}

/*
 * This function will initialize the Program Model by setting the
 * state to MAIN_MENU and also notifies all observers that
 * state has changed.
 *
 */
void ProgramModel::initProgram() {
	m_state = MAIN_MENU;
	notifyAllObservers();
}

/*
 * This function returns the current state of the Program
 *
 */
ProgramState ProgramModel::getState() const {
	return m_state;
}

/*
 * This function sets the state and notify all observers
 * that state of subject had been changed
 *
 */
void ProgramModel::setState(ProgramState state) {
	m_state = state;
	notifyAllObservers();
}

/*
 * This function returns the count of Code/Key Pegs in a row
 *
 */
int ProgramModel::getPegsInRow() const {
	return m_pegsInRow;
}

/*
 * This function returns the total number of rows in a Board
 * for the program.
 *
 */
int ProgramModel::getRowCount() const {
	return m_rowCount;
}

int ProgramModel::getCodeBreaker(){
	m_retVal = 1;char b[PNUM];
	b[0] = (char)a[0];
	b[1] = (char)a[1];
	b[2] = (char)a[2];
	b[3] = (char)a[3];
	m_retVal = code_breaker(&m_outlist, (char*)b );
	return m_retVal;
}

void ProgramModel::printCodeBreaker() const{
	print_linkedlist(m_outlist);
}

LinkedListT* ProgramModel::getLinkedList() const{
	return m_outlist;
}
