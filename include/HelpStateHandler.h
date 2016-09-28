/*
 * This class is a Program State Handler.
 * It implements the APIs that are allowed in HELP state.
 */
#ifndef HELPSTATEHANDLER_H_
#define HELPSTATEHANDLER_H_

#include "ProgramStateHandler.h"

class HelpStateHandler: public ProgramStateHandler {
	public:
		HelpStateHandler(std::shared_ptr<ProgramModel> programModelPtr);
		virtual ~HelpStateHandler();
		virtual void gotoMainMenu();
};

#endif /* HELPSTATEHANDLER_H_ */
