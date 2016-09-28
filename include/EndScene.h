#ifndef ENDSCENE_H_
#define ENDSCENE_H_

#include "Scene.h"

class EndScene: public Scene {
	public:
		EndScene();
		virtual ~EndScene();
		bool render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr);
};

#endif /* ENDSCENE_H_ */
