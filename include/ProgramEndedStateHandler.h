/*
 * This class is a Program State Handler.
 * It implements the APIs that are allowed in PROGRAM_ENDED state.
 */
#ifndef PROGRAMENDEDSTATEHANDLER_H_
#define PROGRAMENDEDSTATEHANDLER_H_
#include "ProgramStateHandler.h"

class ProgramEndedStateHandler : public ProgramStateHandler {
	public:
		ProgramEndedStateHandler(std::shared_ptr<ProgramModel> programModelPtr);
		virtual ~ProgramEndedStateHandler();
		virtual void gotoMainMenu();

};

#endif /* PROGRAMENDEDSTATEHANDLER_H_ */
