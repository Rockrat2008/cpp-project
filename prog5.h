//  Author:  Tammy O'Brien
//  Date:  December 03, 2018
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


//  DEFINE STRUCTURES
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

void deleteHero(int & currentHeroes, Heroes* &heroList);

void printHeroes(int currentHeroes, Heroes* &heroList);

void printRentDetails(int currentHeroes, Heroes* &heroList);

void saveToFile(int currentHeroes, Heroes* &heroList);

float convertToFloat(string s);

#endif