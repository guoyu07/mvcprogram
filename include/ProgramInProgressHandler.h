/*
 * This class is a Program State Handler.
 * It implements the APIs that are allowed in PROGRAM_IN_PROGRESS state.
 */
#ifndef PROGRAMINPROGRESSHANDLER_H_
#define PROGRAMINPROGRESSHANDLER_H_

#include "ProgramStateHandler.h"
#include <iostream>
class ProgramInProgressHandler: public ProgramStateHandler {
	public:
		ProgramInProgressHandler(std::shared_ptr<ProgramModel> programModelPtr);
		virtual ~ProgramInProgressHandler();
		virtual void stopProgram();
		virtual bool addCodePegs(int rowIndex, Peg PegObj, int pegIndex);
		virtual void endProgram();
};

#endif /* PROGRAMINPROGRESSHANDLER_H_ */
