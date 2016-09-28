#include "ProgramScene.h"
#include "Peg.h"
#include <iostream>
#include <cstdint>
#include <cstring>

/*
 * Constructor
 * Initializes the internal maps.
 */
ProgramScene::ProgramScene()
{
	m_programStoped = false;
	m_MapOfStates["RED"] = RED;
	m_MapOfStates["YELLOW"]= YELLOW;
	m_MapOfStates["GREEN"]= GREEN;
	m_MapOfStates["ORANGE"]= ORANGE;
	m_MapOfStates["VOILET"]= VOILET;
	m_MapOfStates["BLUE"]= BLUE;
	m_MapOfStates["WHITE"]= WHITE;
	m_MapOfStates["BLACK"]= BLACK;
	m_MapOfStates["EMPTY"]= EMPTY;

	for(std::map< std::string, PegColor>::iterator it = m_MapOfStates.begin(); it != m_MapOfStates.end(); it++)
	{
		m_MapOfColors[it->second] = it->first;
	}

}
/*
 * Returns a list of all possible Peg Names.
 */
std::vector<std::string> ProgramScene::getAllPegNames()
{
	std::vector<std::string> vecOfStrs;
	for(std::map< std::string, PegColor>::iterator it = m_MapOfStates.begin(); it != m_MapOfStates.end(); it++)
	{
		if(it->first != "EMPTY" && it->first != "BLACK" && it->first != "WHITE" )
			vecOfStrs.push_back(it->first);

	}
	return vecOfStrs;
}
/*
 * Initializes the Program
 */
void ProgramScene::init()
{
	m_programStoped = false;
}
/*
 * Fetch the PegColor based on passed string.
 * Also check if it's correct string or not.
 */
bool ProgramScene::getPegColor(std::string color, PegColor & pegColor)
{
	if(color == "EMPTY" || color == "WHITE" || color == "BLACK")
		return false;

	if(m_MapOfStates.find(color) != m_MapOfStates.end())
	{

		pegColor = m_MapOfStates[color];
		return true;
	}

	return false;
}
/*
 * Render the Current Scene.
 * It displays the Program Information and accepts input from user for all the rows in Board
 */
bool ProgramScene::render(std::shared_ptr<ProgramModel> programModelPtr, std::shared_ptr<ProgramController> programControllerPtr)
{
	std::cout<<"-----------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************PROGRAM STARTED****************************"<<std::endl;
	std::cout<<"-----------------------------------------------------------------"<<std::endl;

	//std::cout<<"Program Status :: \n";
	std::cout<<"This is Frans van Gool's MasterMind algorithm \nfor guessing Code with maximum "<<MAX_GUESS_NUM<<" times" <<std::endl;
	std::cout<<"Colors allowed are :: \n\t";
	std::vector<std::string>  allColorNames = getAllPegNames();
	for(int i = 0; i < allColorNames.size(); i++)
	{
		std::cout<<allColorNames[i];
		if(i < allColorNames.size() -1 ) {
			std::cout<<" , ";
		}
	}
	std::cout<<std::endl;
	std::cout<<"-------------------------STARTING....-------------------------"<<std::endl;
	std::cout<<"----FOUR COLORS ARE CHOSEN BY USER RANDOMLY-------------\n----NOW COMPUTER DOES GUESS THESE COLORS-----------------"<<std::endl;
	PegColor pgColor[PNUM];
	char* strColor[PNUM+2] = { "RED", "YELLOW", "GREEN", "ORANGE", "VOILET", "BLUE" };
	std::string color;
	for( int i = 0; i < programModelPtr->getRowCount() ; i++)
	{
		pgColor[0] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[i][0];
		pgColor[1] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[i][1];
		pgColor[2] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[i][2];
		pgColor[3] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[i][3];
		for(int k = 0; k < programModelPtr->getPegsInRow(); k++)
		{
			color = (std::string)strColor[(int)pgColor[k]];
			addPegDataAuto(i,k, programControllerPtr, programModelPtr, color);
			//	if(m_programStoped)
			//		return true;
		}
		std::cout<<"-----------------------------"<<(i+1)<<"-------------------------------"<<std::endl;

		std::cout << "Code Pegs for Peg Row " << (i + 1) << " are :: "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfCodePegs()[0].getPegColor()]
			<< " , "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfCodePegs()[1].getPegColor()]
			<< " , "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfCodePegs()[2].getPegColor()]
			<< " , "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfCodePegs()[3].getPegColor()]<<std::endl;


		std::cout << "->Key Pegs for Peg Row " << (i + 1) << " are : "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[0].getPegColor()]
			<< " , "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[1].getPegColor()]
			<< " , "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[2].getPegColor()]
			<< " , "
			<< m_MapOfColors[programModelPtr->getProgramBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[3].getPegColor()]<<std::endl;
		if(m_programStoped)
			return true;
	}
	programControllerPtr->endProgram();
	return true;

}
/*
 * It Accepts an input for Peg Color and adds the Peg Data to the back-end Model.
 */
void ProgramScene::addPegData(int row, int pegNum, std::shared_ptr<ProgramController> programControllerPtr,
		std::shared_ptr<ProgramModel> programModelPtr) {

	if(m_programStoped)
		return;
	std::cout << "For PegRow " << (row + 1)
		<< " , Please enter CodePeg "<<(pegNum + 1)<<" :: ";
	std::string color;
	std::cin >> color;
	PegColor pegColor;
	if (getPegColor(color, pegColor) == true) {
		if(programControllerPtr->addCodePegs(row, Peg(pegColor, CODE), pegNum) )
		{
			m_programStoped = true;
		}
	}
	else if(color == "STOP")
	{
		programControllerPtr->stopProgram();
		m_programStoped = true;
	}
	else
	{
		std::cout << "Wrong Choice :: Do it again" << std::endl;
		this->addPegData(row, pegNum, programControllerPtr, programModelPtr);
	}
}

/*
 * It Accepts an input for Peg Color and adds the Peg Data to the back-end Model.
 */
void ProgramScene::addPegDataAuto(int row, int pegNum, std::shared_ptr<ProgramController> programControllerPtr,
		std::shared_ptr<ProgramModel> programModelPtr, std::string aColor) {

	if(m_programStoped)
		return;
	std::string color;
	char* colorInput[PNUM];
	PegColor pgColor[PNUM];
	PegColor pgColorInput[PNUM];
	char* strColor[PNUM+2] = { "RED", "YELLOW", "GREEN", "ORANGE", "VOILET", "BLUE" };
	pgColor[0] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[row][0];
	pgColor[1] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[row][1];
	pgColor[2] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[row][2];
	pgColor[3] = (PegColor) programModelPtr->getLinkedList()->data->guessed_code[row][3];
	pgColorInput[0] = (PegColor) programModelPtr->getLinkedList()->data->input_code[0];
	pgColorInput[1] = (PegColor) programModelPtr->getLinkedList()->data->input_code[1];
	pgColorInput[2] = (PegColor) programModelPtr->getLinkedList()->data->input_code[2];
	pgColorInput[3] = (PegColor) programModelPtr->getLinkedList()->data->input_code[3];
	color = strColor[(int)pgColor[pegNum]];
	colorInput[0] = strColor[(int)pgColorInput[0]];
	colorInput[1] = strColor[(int)pgColorInput[1]];
	colorInput[2] = strColor[(int)pgColorInput[2]];
	colorInput[3] = strColor[(int)pgColorInput[3]];
#if 0
	if (pegNum == 0) {
		std::cout<<"[ "<<color<<"";
	}
	else if (pegNum == 3) {
		std::cout<<" "<<color<<" ]\n";
	} else {
		std::cout<<" "<<color<<" ";
	}
#endif
	PegColor pegColor;
	if (getPegColor(color, pegColor) == true) {
		if(programControllerPtr->addCodePegs(row, Peg(pegColor, CODE), pegNum) )
		{
			m_programStoped = true;
		}
	}
	else if(color == "STOP")
	{
		programControllerPtr->stopProgram();
		m_programStoped = true;
	}
	else
	{
		std::cout << "Wrong Choice :: Do it again" << std::endl;
		this->addPegDataAuto(row, pegNum, programControllerPtr, programModelPtr, color);
	}
}

