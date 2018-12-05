//  Author:  Tammy O'Brien
//  Date:  December 03, 2018
//  Program:  5
//  Purpose:  Functions file for the superhero condo program


#include "prog5.h"

//  FUNCTION TO ENTER HEROES INTO STRUCTURES ARRAY
int enterHeroes(int maxHeroes, int & currentHeroes, Heroes* &heroList)
{
	int menuChoice = 0;
	
	if (currentHeroes == maxHeroes)
	{
		cout << endl << "Sorry!  Your complex can only hold " << maxHeroes << " heroes.\nYou cannot add more." << endl << endl;
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
				string heroFile, heroInfo;
				
				string heroName, heroDesc, rentAmt, damageAmt, nbrYears, isDangerous;
				
				cout << "\nWhat is the name of the file with your list of superheroes? (ex: filename.txt)\n";
				cout << "FILENAME:  ";
				cin >> heroFile;
				ifstream heroesFile;
				heroesFile.open(heroFile);
				
				if (!heroesFile)
				{
					cout << "There was an error with your heroes file.\n\n";
				}
				else
				{
					while(!getline(heroesFile, heroName, '#').eof())
					{
						heroList[currentHeroes].name = heroName;
						getline(heroesFile, heroDesc, '#');
						heroList[currentHeroes].description = heroDesc;
						getline(heroesFile, isDangerous, '#');
					//	heroList[currentHeroes].dangerous = isDangerous;
						getline(heroesFile, heroInfo, '#');
						cout << "Pre-Convert:  " << heroInfo << endl;
						heroList[currentHeroes].rentInfo.rent = convertToFloat(heroInfo);
						cout << "X Returned:  " << heroList[currentHeroes].rentInfo.rent << endl;
						getline(heroesFile, heroInfo, '#');
						heroList[currentHeroes].rentInfo.damage = convertToFloat(heroInfo);
						getline(heroesFile, heroInfo, '#');
						heroList[currentHeroes].rentInfo.years = convertToFloat(heroInfo);
						currentHeroes++;
					}
				}
				cout << endl << endl;
	
				break;
			}	
			case 2 :
			{
				bool addMore = true, isDangerous = true;
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
					cout << endl << "RENT PRICE:  $";
					cin.clear();
					cin.sync();
					cin >> rentAmt;
					cout << endl << endl << "What is the typical damage has each month?";
					cout << endl << "DAMAGE COST:  $";
					cin.clear();
					cin.sync();
					cin >> damageAmt;
					cout << endl << endl <<  "How many years has lived in your condo?";
					cout << endl << "YEARS:  ";
					cin.clear();
					cin.sync();
					cin >> nbrYears;
					
					if (isDangerous == 'y' || isDangerous == 'Y')
						isDangerous = true;
					else
						isDangerous = false;
					
					heroList[currentHeroes].name = name;
					heroList[currentHeroes].description = description;
					heroList[currentHeroes].dangerous = isDangerous;
					heroList[currentHeroes].rentInfo.rent = rentAmt;
					heroList[currentHeroes].rentInfo.damage = damageAmt;
					heroList[currentHeroes].rentInfo.years = nbrYears;
					
	 
					cout << endl << endl << "The " << name << " has been added.";
					currentHeroes++;
					
					cout << endl << endl << "Want to add more heroes?  (y or n)  ";
					cin >> addAnother;
					
					if (addAnother == 'n' || addAnother == 'N')
					{
						addMore = false;
					}
					else
					{
						if (currentHeroes == maxHeroes)
						{
							cout << endl << "Sorry!  Your complex can only hold " << maxHeroes << " heroes.\nYou cannot add more." << endl << endl;
							addMore = false;
							break;
						}
					}
					
				}while(addMore);
				
				return currentHeroes;
				
				break;
			}	
		}
	}
}


//  FUNCTION TO DELETE A HERO FROM THE ARRAY
void deleteHero(int & currentHeroes, Heroes* &heroList)
{
	string heroToKick;
	int notFound = 0, kickCounter = 0;
	
	cout << endl << "The following is a list of all the heroes living in your condo complex:\n";
	
	for(int i = 0; i < currentHeroes; i++)
	{
		cout << heroList[i].name << endl;
	}
	
	cout << endl << "Which hero are you kicking out of your complex?\n";
	cout << "SUPERHERO NAME:  ";
	cin.clear();
	cin.sync();
	getline(cin, heroToKick);
	
	for (int i = 0; i < currentHeroes; i++)
	{
		if (heroToKick == heroList[i].name)
		{
			kickCounter++;
			for(int b = kickCounter; b < currentHeroes; b++)
			{
				heroList[b-1].name = heroList[b].name;
				heroList[b-1].description = heroList[b].description;
				heroList[b-1].dangerous = heroList[b].dangerous;
				heroList[b-1].rentInfo.rent = heroList[b].rentInfo.rent;
				heroList[b-1].rentInfo.damage = heroList[b].rentInfo.damage;
				heroList[b-1].rentInfo.years = heroList[b].rentInfo.years;
			}
			cout << endl << "You have removed " << heroToKick << endl << endl;
			currentHeroes--;
		}	
		else
		{
			notFound++;
		}
	}
	if (notFound == currentHeroes)
		cout << "Sorry, a hero by the name " << heroToKick << " could not be found." << endl << endl;
}



//  FUNTION TO DISPLAY HEROES TO SCREEN
void printHeroes(int currentHeroes, Heroes* &heroList)
{
	int heroNbr = 1;
	
	for(int i = 0; i < currentHeroes; i++)
	{
		//cout << setfill('-') << setw(80);
		cout << endl;
		cout << setfill(' ') << setw(60) << std::right << "SUPERHERO  " << heroNbr << endl;
		cout << setw(25) << std::left << "NAME" << setw(16) << std::left << heroList[i].name << endl;
		cout << setw(25) << std::left << "DESCRIPTON" << setw(16) << std::left << heroList[i].description << endl;
		cout << boolalpha << setw(25) << std::left << "DANGEROUS" << setw(16) << std::left << heroList[i].dangerous << endl;
		cout << setw(25) << std::left << "RENT PRICE" << std::right << "$" << setw(1) << std::left << heroList[i].rentInfo.rent << endl;
		cout << setw(25) << std::left << "DAMAGE COST" << std::right << "$" << setw(1) << std::left << heroList[i].rentInfo.damage << endl;
		cout << setw(25) << std::left << "YEARS" << setw(16) << std::left << heroList[i].rentInfo.years << endl << endl;
		heroNbr++;
	}
}


//  FUNCTION TO PRINT HERO RENT DETAILS TO SCREEN
void printRentDetails(int currentHeroes, Heroes* &heroList)
{
	float rentTotal = 0, damageTotal = 0;
	
	cout << "PRINT DETAILS OF EACH HERO:" << endl << endl;
	cout << setw(20) << std::left << "SUPERHERO" << setw(16) << std::right << "MONTHLY RENT" << setw(20) << std::right << "DAMAGE COST" << endl;
	
	for(int i = 0; i < currentHeroes; i++)
	{
		rentTotal = rentTotal + heroList[i].rentInfo.rent;
		damageTotal = damageTotal + heroList[i].rentInfo.damage;
		
		cout << setw(20) << std::left << heroList[i].name << "$" << setw(15) << std::right << heroList[i].rentInfo.rent << setw(9) << "$" << setw(11) << std::right << heroList[i].rentInfo.damage << endl;
	}
	
//	cout << setfill('-') << setw(80);
	cout << endl;
	cout << setfill(' ') << setw(20) << std:: left << "TOTALS:" << "$" << setw(15) << std::right << rentTotal << setw(9) << "$" << setw(11) << std::right << damageTotal << endl << endl;
}


//  FUNCTION TO SAVE THE USERS HEROES TO A FILE OF THEIR CHOICE
void saveToFile(int currentHeroes, Heroes* &heroList)
{
	string saveFile;
	
	cout << "What is the name of the file you want to save your creatures to?\n";
	cout << "FILENAME:  ";
	cin >> saveFile;
	cout << "\n";
	
	ofstream saveHeroes(saveFile);
	for(int i =0; i < currentHeroes; i++)
	{
		saveHeroes << heroList[i].name << "#";
		saveHeroes << heroList[i].description << "#";
		saveHeroes << heroList[i].dangerous << "#";
		saveHeroes << heroList[i].rentInfo.rent << "#";
		saveHeroes << heroList[i].rentInfo.damage << "#";
		saveHeroes << heroList[i].rentInfo.years << "#";
	}
	saveHeroes.close();
	
	cout << endl << endl << "Your superheroes were successfully saved to the " << saveFile << " file." << endl << endl;
}


float convertToFloat(string heroInfo)
{
	istringstream i(heroInfo);
	float x;
	if(!(i >> x))
		x = 0;
	return x;
}