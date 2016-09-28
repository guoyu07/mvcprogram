
#include "ProgramView.h"


/*
 * Constructor
 * It initializes the Scene map based on the Program State
 * Also initializes the active scene.
 */
ProgramView::ProgramView(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programCtrlPtr): m_programModelPtr(programModelPtr), m_programControlletPtr(programCtrlPtr)
{
	m_mapOfProgramScenes[MAIN_MENU] = std::shared_ptr<Scene>(new MainMenuScene());
	m_mapOfProgramScenes[PROGRAM_IN_PROGRESS] = std::shared_ptr<Scene>(new ProgramScene());
	m_mapOfProgramScenes[PROGRAM_ENDED] = std::shared_ptr<Scene>(new EndScene());
	m_mapOfProgramScenes[HELP_MODE] = std::shared_ptr<Scene>(new HelpScene());

	m_activeScene = m_mapOfProgramScenes[MAIN_MENU];



}
/*
 * This function will be invoked by Subject, to notify the state change.
 * On notification it changes the active scene and render it.
 */
void ProgramView::update()
{
	if(m_programModelPtr)
	{
		if(m_mapOfProgramScenes.find(m_programModelPtr->getState()) != m_mapOfProgramScenes.end())
			m_activeScene = m_mapOfProgramScenes[m_programModelPtr->getState()];
	}
	m_activeScene->init();
	//render();
}
/*
 * This function renders the active scene i.e. make it visible
 */
void ProgramView::render()
{
	while(!!m_activeScene )
	{
		system("clear");
		if( m_activeScene->render(m_programModelPtr, m_programControlletPtr) == false)
		{
			std::cout<<std::endl<<"***Thanks For Playing..., TRAN VAN PHUOC***"<<std::endl;
			break;
		}
	}
}
