#include "ProgramEndedStateHandler.h"
/*
 * Constructor
 */
ProgramEndedStateHandler::~ProgramEndedStateHandler()
{}

/*
 * Destructor
 */
ProgramEndedStateHandler::ProgramEndedStateHandler(std::shared_ptr<ProgramModel> programModelPtr) : 	ProgramStateHandler(programModelPtr)
{}

/*
 * This API is allowed to be called by View in PROGRAM_ENDED state.
 * It sets the Model State to MAIN_MENU.
 */
void ProgramEndedStateHandler::gotoMainMenu()
{
	m_programModelPtr->setState(MAIN_MENU);
}

