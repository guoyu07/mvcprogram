/*
 * This class is a Program State Handler.
 * It implements the APIs that are allowed in MAIN_MENU state.
 */
#ifndef MAINMENUSTATEHANDLER_H_
#define MAINMENUSTATEHANDLER_H_

#include "ProgramStateHandler.h"
#include <iostream>

class MainMenuStateHandler: public ProgramStateHandler {
	public:

		MainMenuStateHandler(std::shared_ptr<ProgramModel> programModelPtr);
		virtual ~MainMenuStateHandler();
		virtual void startProgram();
		virtual void gotoHelpMenu();
		virtual void exit();
};

#endif /* MAINMENUSTATEHANDLER_H_ */
