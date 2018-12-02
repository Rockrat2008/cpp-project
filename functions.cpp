//  Author:  Tammy O'Brien
//  Date:  18 November 2018
//  Program:  5
//  Purpose:  Functions file for the superhero condo program


#include "prog5.h"

int enterHeroes(int maxHeroes, int & currentHeroes, Heroes* &heroList)
{
	int menuChoice = 0;
	
	if (currentHeroes == maxHeroes)
	{
		cout << "Sorry!  Your complex can only hold " << maxHeroes << " heroes.\nYou cannot add more.";
	}
	else
	{
		cout << "What do you want to do?\n";
		cout << "\t1.\tLoad the heroes from a file.\n";
		cout << "\t2.\tEnter a hero manually.\n";
		cout << "\tChooose 1 or 2.  ";
		cin >>  menuChoice;

		if(menuChoice < 1 || menuChoice > 2)  //  Loop to validate menu choice
		{
			cout << "\n \n That is not a valid option.  Please make a valid menu choice.  ";
			cin >> menuChoice;
		}

		switch(menuChoice)
		{
			case 1 :
			{
				string heroFile;
				
				cout << "\nWhat is the name of the file with your list of superheroes? (ex: filename.txt)\n";
				cout << "FILENAME:  ";
				cin >> heroFile;
				ifstream heroesFile;
				heroesFile.open(heroFile);
				
				if (!heroesFile)
				{
					cout << "There was an error with your heroes file.\n\n";
				}
/*				else
				{
					for (int i = 0; i < maxHeroes; i++)
					{
						heroesFile >> heroes[i].name >> heroes[i].description >> heroes[i].dangerous >> heroes[i].rentInfo.rent >> heroes[i].rentInfo.damage >> heroes[i].rentInfo.years;
					}
				}
*/				
				break;
			}	
			case 2 :
			{
				bool addMore = true, isDangerous;
				float rentAmt = 0, damageAmt = 0, nbrYears = 0;
				char addAnother;
				string name, description;
				do
				{
					cin.clear();
					cin.sync();
					cout << endl << endl << "SUPERHERO NAME:  ";
					getline(std::cin, name);
					cout << endl << endl <<  "DESCRIPTION:  ";
					cin.clear();
					cin.sync();
					getline(std::cin, description);
					cout << endl << endl << "IS IT A DANGEROUS HERO?  (y or n):  ";
					cin.clear();
					cin.sync();
					cin >> isDangerous;
					cout << endl << endl <<  "How much does pay for rent per month?";
					cout << endl << "RENT PRICE:  ";
					cin.clear();
					cin.sync();
					cin >> rentAmt;
					cout << endl << endl << "What is the typical damage has each month?";
					cout << endl << "DAMAGE COST:  ";
					cin.clear();
					cin.sync();
					cin >> damageAmt;
					cout << endl << endl <<  "How many years has lived in your condo?";
					cout << endl << "YEARS:  ";
					cin.clear();
					cin.sync();
					cin >> nbrYears;
					cout << "NAME:  " << name << endl;
					cout << "DESC:  " << description << endl;
					cout << "DANG:  " << isDangerous << endl;
					cout << "RENT:  " << rentAmt << endl;
					cout << "DAMG:  " << damageAmt << endl;
					cout << "YEAR:  " << nbrYears << endl;
					
					heroList[currentHeroes].name = name;
					heroList[currentHeroes].description = description;
					heroList[currentHeroes].dangerous = isDangerous;
					heroList[currentHeroes].rentInfo.rent = rentAmt;
					heroList[currentHeroes].rentInfo.damage = damageAmt;
					heroList[currentHeroes].rentInfo.years = nbrYears;
					
	 
					cout << endl << endl << "The " << name << " has been added.";
					currentHeroes++;
					cout << "Current heroes count " << currentHeroes;
					
					cout << endl << endl << "Want to add more heroes?  (y or n)  ";
					cin >> addAnother;
					
					if (addAnother == 'n' || addAnother == 'N')
					{
						addMore = false;
					}
					
				}while(addMore);
				
				return currentHeroes;
				
				break;
			}	
		}
	}
}

/*
void deleteHero(int & currentHeroes, string heroList[])
{
	cout << "The following is a list of all the heroes living in your condo complex:\n";
	
	cout << "Which hero are you kicking out of your complex?\n";
	cout << "SUPERHERO NAME:  ";
}


void saveToFile(int currentHeroes, string heroList[])
{
	
}
*/