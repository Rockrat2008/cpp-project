//  Author:  Tammy O'Brien
//  Date:  18 November 2018
//  Program:  5
//  Purpose:  Main program file for the superhero condo program


#include "prog5.h"

int main()
{
	bool exitMenu = false;
	char saveHero, saveFile;
	int currentHeroes = 0, maxHeroes = 0;
	
	cout << "How many superheoes can live in your condo complex?  ";
	cin >> maxHeroes;
	
	Heroes *heroList;
	heroList = new Heroes[maxHeroes];
//	Heroes heroList[maxHeroes];
	do
	{
		int menuChoice = 0;
		
		//  MAIN MENU
		cout << "What would you like to do?\n";
		cout << "\t 1. \t Enter some superheroes \n";
		cout << "\t 2. \t Delete a superhero \n";
		cout << "\t 3. \t Print all superheroes \n";
		cout << "\t 4. \t Print rent details \n";
		cout << "\t 5. \t End program \n";
		cout << "\t Enter 1, 2, 3, 4, or 5.\n";
		cout << "CHOICE:  ";
		cin >> menuChoice;
		
		if(menuChoice < 1 || menuChoice > 5)  //  Loop to validate menu choice
		{
			cout << "\n \n That is not a valid option.  Please make a valid menu choice.  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)  //  Switch / Case loop to call function based on user menu choice
		{
			case 1 :
				enterHeroes(currentHeroes, maxHeroes, heroList);
				break;
			case 2 :
				cout << "Call deleteHero(currentHeroes, heroList);\n";
				break;
			case 3 :
				cout << "Call printHeroes();\n";
				break;
			case 4 :
				cout << "Call printRentDetails();\n";
				break;
			case 5 :
				exitMenu = true;
				break;
		}	
	}while(!exitMenu);
	
	cout << "Would you like to save your superheoes list to a file?  (y or n)  ";
	cin >> saveHero;
	
	if(saveHero == 'y' || saveHero == 'Y')
	{
		cout << "What is the name of the file you want to save your creatures to?\n";
		cout << "FILENAME:  ";
		cin >> saveFile;
		cout << "\n";
		cout << "Call saveToFile(currentHeroes, heroList):\n\n";
	}
	
	cout << "GOODBYE!\n\n";
	
	return 0;
}