#include "ProgramInProgressHandler.h"

/*
 * Destructor
 */
ProgramInProgressHandler::~ProgramInProgressHandler() {

}

/*
 * Constructor
 */
ProgramInProgressHandler::ProgramInProgressHandler(std::shared_ptr<ProgramModel> programModelPtr) : 	ProgramStateHandler(programModelPtr)
{}
/*
 * This API is allowed to be called by View in PROGRAM_IN_PROGRESS state.
 * It Initializes the Model
 */
void ProgramInProgressHandler::stopProgram()
{
	m_programModelPtr->initProgram();
}
/*
 * This API is allowed to be called by View in PROGRAM_IN_PROGRESS state.
 * It adds the Code Pegs in Model.
 */
bool ProgramInProgressHandler::addCodePegs(int rowIndex, Peg PegObj, int pegIndex)
{
	if(m_programModelPtr)
	{
		m_programModelPtr->getProgramBoard().addCodePegInRow(rowIndex, PegObj, pegIndex);
		if(m_programModelPtr->getProgramBoard().getVecOfPegRows()[rowIndex].IsCodePegsAndKeyPegsAreEqual())
		{
			m_programModelPtr->setState(PROGRAM_ENDED);
			return true;
		}
	}
	return false;
}
/*
 * This API is allowed to be called by View in PROGRAM_IN_PROGRESS state.
 * It sets the Model state to PROGRAM_ENDED.
 */
void ProgramInProgressHandler::endProgram()
{
	m_programModelPtr->setState(PROGRAM_ENDED);
}
