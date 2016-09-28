#ifndef MAINMENUSCENE_H_
#define MAINMENUSCENE_H_

#include "Scene.h"

class MainMenuScene: public Scene {
	public:
		MainMenuScene();
		virtual ~MainMenuScene();
		bool render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr);

};

#endif /* MAINMENUSCENE_H_ */
