#include "HelpStateHandler.h"
/*
 * Destructor
 */
HelpStateHandler::~HelpStateHandler() {
}
/*
 * Constructor
 */
HelpStateHandler::HelpStateHandler(std::shared_ptr<ProgramModel> programModelPtr) : ProgramStateHandler(programModelPtr)
{

}
/*
 * This API is allowed to be called by View in PROGRAM_IN_PROGRESS state.
 * It sets the Model state to MAIN_MENU.
 */
void HelpStateHandler::gotoMainMenu()
{
	m_programModelPtr->setState(MAIN_MENU);
}
