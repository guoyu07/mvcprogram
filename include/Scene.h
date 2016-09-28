/*
 * It's an abstract class represents the Program Scenes.
 * Client of this class can render it.
 */
#ifndef SCENE_H_
#define SCENE_H_
#include "ProgramModel.h"
#include "ProgramController.h"
#include <memory>

class Scene {
	public:
		Scene();
		virtual ~Scene();
		virtual bool render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr) = 0;
		virtual void init(){}
};

#endif /* SCENE_H_ */
