//  Author:  Tammy O'Brien
//  Date:  December 03, 2018
//  Program:  5
//  Purpose:  Main program file for the superhero condo program


#include "prog5.h"

int main()
{
	//  VARIABLE DECLARATION
	bool exitMenu = false;
	char saveHero;
	int currentHeroes = 0, maxHeroes = 0;
	
	cout << endl << "How many superheoes can live in your condo complex?  ";
	cin >> maxHeroes;
	
	//  SETUP STRUCTURES ARRAY
	Heroes *heroList;
	heroList = new Heroes[maxHeroes];

	//  MAIN LOOP FOR SUPERHERO CONDO PROGRAM
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
				enterHeroes(maxHeroes, currentHeroes, heroList);
				break;
			case 2 :
				deleteHero(currentHeroes, heroList);
				break;
			case 3 :
				printHeroes(currentHeroes, heroList);
				break;
			case 4 :
				printRentDetails(currentHeroes, heroList);
				break;
			case 5 :
				exitMenu = true;
				break;
		}	
	}while(!exitMenu);
	
	//  CHECK IF USER WANTS TO SAVE SUPERHEROES TO FILE
	cout << "Would you like to save your superheoes list to a file?  (y or n)  ";
	cin >> saveHero;
	
	if(saveHero == 'y' || saveHero == 'Y')
	{
		saveToFile(currentHeroes, heroList);
	}
	cout << endl;
	cout << "GOODBYE!\n\n";
	
	return 0;
}