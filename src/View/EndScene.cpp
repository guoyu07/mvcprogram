#include "EndScene.h"
/*
 * Constructor
 */
EndScene::EndScene() {
}
/*
 * Destructor
 */
EndScene::~EndScene() {
}
/*
 * Renders the current scene
 * Shows the Data Related to End Scene on screen i.e. Either Program Won or Lost
 */
bool EndScene::render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr)
{

	std::cout<<"----------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************PROGRAM ENDED*****************************"<<std::endl;
	std::cout<<"----------------------------------------------------------------"<<std::endl;
	std::vector<PegRow > pegRows = programModelPtr->getProgramBoard().getVecOfPegRows();
	bool programWon = false;
	for(int i = 0; i < pegRows.size(); i++)
	{
		if(pegRows[i].IsCodePegsAndKeyPegsAreEqual())
		{
			programWon = true;
			break;
		}
	}
	std::cout<<std::endl;
	if(programWon)
		std::cout<<"**Computer Won**"<<std::endl;
	else
		std::cout<<"**Program Lost**"<<std::endl;

	std::cout<<std::endl;

	std::cout<<"Press any alphabet key to enter Main Menu"<<std::endl;
	std::string str;
	std::cin>>str;
	programControllerPtr->gotoMainMenu();
	return true;


}
