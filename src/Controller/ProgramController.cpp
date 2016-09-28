#include "ProgramController.h"

/*
 * Constructor
 */
ProgramController::ProgramController(std::shared_ptr<ProgramModel> programModelPtr)
	:m_programModelPtr(programModelPtr)
{

}
/*
 * Initializes a Map of State and State Event Handlers
 */
void ProgramController::init()
{
	m_mapOfProgramStateHandlerPtr[MAIN_MENU] = std::shared_ptr<ProgramStateHandler>(new MainMenuStateHandler(m_programModelPtr) );
	m_mapOfProgramStateHandlerPtr[PROGRAM_IN_PROGRESS] = std::shared_ptr<ProgramStateHandler>(new ProgramInProgressHandler(m_programModelPtr) );
	m_mapOfProgramStateHandlerPtr[PROGRAM_ENDED] = std::shared_ptr<ProgramStateHandler>(new ProgramEndedStateHandler(m_programModelPtr) );
	m_mapOfProgramStateHandlerPtr[HELP_MODE] = std::shared_ptr<ProgramStateHandler>(new HelpStateHandler(m_programModelPtr) );
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void ProgramController::stopProgram()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->stopProgram();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void ProgramController::startProgram()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->startProgram();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
bool ProgramController::addCodePegs(int rowIndex, Peg PegObj, int pegIndex)
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			return m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->addCodePegs(rowIndex, PegObj, pegIndex);
		}
	}
	return false;
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void ProgramController::gotoMainMenu()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->gotoMainMenu();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void ProgramController::gotoHelpMenu()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->gotoHelpMenu();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void ProgramController::exit()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->exit();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void ProgramController::endProgram()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramStateHandlerPtr.find(m_programModelPtr->getState()) != m_mapOfProgramStateHandlerPtr.end())
		{
			m_mapOfProgramStateHandlerPtr[m_programModelPtr->getState()]->endProgram();
		}
	}
}
