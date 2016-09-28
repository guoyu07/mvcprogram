/*
 * This class acts as Controller in MVC Design.
 * It provides the APIs to modify the Model Based on active State
 */
#ifndef PROGRAMCONTROLLER_H_
#define PROGRAMCONTROLLER_H_
#include "ProgramModel.h"
#include "ProgramStateHandler.h"
#include "ProgramInProgressHandler.h"
#include "HelpStateHandler.h"
#include "ProgramEndedStateHandler.h"
#include "MainMenuStateHandler.h"
#include <memory>
#include <map>

class ProgramController {
	std::shared_ptr<ProgramModel> m_programModelPtr;
	std::map<int, std::shared_ptr<ProgramStateHandler> > m_mapOfProgramStateHandlerPtr;

	public:
	ProgramController(std::shared_ptr<ProgramModel> programModelPtr);
	void init();
	virtual ~ProgramController(){}
	void stopProgram();
	void startProgram();
	bool addCodePegs(int rowIndex, Peg PegObj, int pegIndex);
	void gotoMainMenu();
	void gotoHelpMenu();
	void exit();
	void endProgram();
};

#endif /* PROGRAMCONTROLLER_H_ */
