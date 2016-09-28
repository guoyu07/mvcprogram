/*
 *This class acts as a Generic State Handler
 */
#ifndef PROGRAMSTATEHANDLER_H_
#define PROGRAMSTATEHANDLER_H_
#include "ProgramModel.h"
#include <memory>

class ProgramStateHandler {
	protected:
		std::shared_ptr<ProgramModel> m_programModelPtr;
	public:
		ProgramStateHandler(std::shared_ptr<ProgramModel> programModelPtr);
		virtual ~ProgramStateHandler(){}
		virtual void stopProgram();
		virtual void endProgram();
		virtual void startProgram();
		virtual bool addCodePegs(int rowIndex, Peg PegObj, int pegIndex);
		virtual void gotoMainMenu();
		virtual void gotoHelpMenu();
		virtual void exit();
};

#endif /* PROGRAMSTATEHANDLER_H_ */
