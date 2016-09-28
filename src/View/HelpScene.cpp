#include "HelpScene.h"

/*
 * COnstructor
 */
HelpScene::HelpScene() {
	// TODO Auto-generated constructor stub

}
/*
 * Destructor
 */
HelpScene::~HelpScene() {
}
/*
 * Renders the current scene
 * Shows the Help Data for the Program.
 */
bool HelpScene::render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr)
{

	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************HELP MENU*****************************************"<<std::endl;
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;

	std::cout<<"Here should be the text realted to Program Help"<<std::endl<<std::endl<<std::endl;

	std::cout<<"Press any alphabet key to enter Main Menu"<<std::endl;
	std::string str;
	std::cin>>str;
	programControllerPtr->gotoMainMenu();
	return true;


}
