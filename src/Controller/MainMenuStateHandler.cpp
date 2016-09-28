#include "MainMenuStateHandler.h"
/*
 * Destructor
 */
MainMenuStateHandler::~MainMenuStateHandler() {
}
/*
 * Constructor
 */
MainMenuStateHandler::MainMenuStateHandler(std::shared_ptr<ProgramModel> programModelPtr) : 	ProgramStateHandler(programModelPtr)
{

}
/*
 * This API is allowed to be called by View in MAIN_MENU state.
 * It starts the Program in Model
 */
void MainMenuStateHandler::startProgram()
{
	m_programModelPtr->startProgram();
}
/*
 * This API is allowed to be called by View in MAIN_MENU state.
 * It starts the Model state to HELP_MODE
 */
void MainMenuStateHandler::gotoHelpMenu()
{
	m_programModelPtr->setState(HELP_MODE);
}
/*
 * This API is allowed to be called by View in MAIN_MENU state.
 * It exits the application.
 */
void MainMenuStateHandler::exit()
{
	abort();
}
