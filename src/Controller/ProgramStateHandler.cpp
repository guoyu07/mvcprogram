#include "ProgramStateHandler.h"

/*
 * Constructor
 */
ProgramStateHandler::ProgramStateHandler(std::shared_ptr<ProgramModel> programModelPtr) : m_programModelPtr(programModelPtr)
{}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void ProgramStateHandler::stopProgram()
{
	std::cout<<"stopProgram Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void ProgramStateHandler::endProgram()
{
	std::cout<<"startProgram Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void ProgramStateHandler::startProgram()
{
	std::cout<<"startProgram Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
bool ProgramStateHandler::addCodePegs(int rowIndex, Peg PegObj, int pegIndex)
{
	std::cout<<"addCodePegs Not Allowed in this state"<<std::endl;
	return false;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void ProgramStateHandler::gotoMainMenu()
{
	std::cout<<"gotoMainMenu Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void ProgramStateHandler::gotoHelpMenu()
{
	std::cout<<"gotoHelpMenu Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void ProgramStateHandler::exit()
{
	std::cout<<"exit Not Allowed in this state"<<std::endl;
}
