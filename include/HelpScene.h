
#ifndef HELPSCENE_H_
#define HELPSCENE_H_

#include "Scene.h"

class HelpScene: public Scene {
	public:
		HelpScene();
		virtual ~HelpScene();
		bool render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr);
};

#endif /* HELPSCENE_H_ */
