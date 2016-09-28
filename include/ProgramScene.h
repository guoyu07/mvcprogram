/*
 * This class represents the Active Program screen i.e. Program screen in
 * case of state PROGRAM_IN_PROGRESS
 */
#ifndef PROGRAMSCENE_H_
#define PROGRAMSCENE_H_

#include "Scene.h"
#include <iterator>
#include <map>
#include <algorithm>
#include <string>

class ProgramScene: public Scene {
	bool m_programStoped;
	std::map< std::string, PegColor> m_MapOfStates;
	std::map<  PegColor, std::string> m_MapOfColors;
	public:
	ProgramScene();
	std::vector<std::string> getAllPegNames();
	void init();
	virtual ~ProgramScene(){}
	bool getPegColor(std::string color, PegColor & pegColor);
	bool render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr);
	private:
	void addPegData(int row, int pegNum, std::shared_ptr<ProgramController> programControllerPtr,
			std::shared_ptr<ProgramModel> programModelPtr);
	void addPegDataAuto(int row, int pegNum, std::shared_ptr<ProgramController> programControllerPtr,
			std::shared_ptr<ProgramModel> programModelPtr, std::string aColor);
};

#endif /* PROGRAMSCENE_H_ */
