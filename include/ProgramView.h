/*
 * This class represents the View from MVC Design.
 * It fetches the information from Model and generates the User Interface
 * It's shows the program data to use and accepts input from it.
 */
#ifndef PROGRAMVIEW_H_
#define PROGRAMVIEW_H_
#include "Observer.h"
#include "Scene.h"
#include "MainMenuScene.h"
#include "ProgramModel.h"
#include "ProgramController.h"
#include "ProgramScene.h"
#include "EndScene.h"
#include "HelpScene.h"
#include <list>
#include <memory>
#include <functional>
#include <algorithm>
#include <map>

using namespace std::placeholders;
class ProgramView : public Observer
{
	std::shared_ptr<Scene> m_activeScene;
	std::shared_ptr<ProgramModel> m_programModelPtr;
	std::shared_ptr<ProgramController> m_programControlletPtr;
	std::map<ProgramState, std::shared_ptr<Scene> > m_mapOfProgramScenes;
	public:
	ProgramView(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programCtrlPtr);
	virtual ~ProgramView(){}
	void update();
	void render();
};

#endif /* PROGRAMVIEW_H_ */
