//  Author:  Tammy O'Brien
//  Date:  18 November 2018
//  Program:  5
//  Purpose:  Header file for the superhero condo program


#ifndef prog5_h
#define prog5_h


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;


struct Rent
{
	float rent;
	float damage;
	float years;
};

struct Heroes
{
	string name;
	string description;
	bool dangerous;
	Rent rentInfo;
};


int enterHeroes(int maxHeroes, int & currentHeroes, Heroes* &heroList);

// void deleteHero(int & currentHeroes, string heroList[]);

// void printHeroes();

// void printRentDetails();

// void saveToFile(int currentHeroes, string heroList[]);

#endif