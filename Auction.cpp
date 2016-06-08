#include "Auction.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator> 
#include <sstream>
#include <time.h>

using namespace std;

template<typename T>
string to_string(const T& obj)
{
    stringstream ss;
    ss << obj;
    return ss.str();
}

vector <string> Person::names;

void Person::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

float randomValue()
{
	return rand() % 70 + 30;	
}

Person::Person()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_money = (rand() % 65 + 35)*10000;
	_bravery = randomValue()/100;
	_offence = randomValue()/100;
}

void Person::description()
{
	cout<<_name<<endl;
	cout<<"Pieniadze: "<<_money<<endl;
	cout<<"Ofensywnosc: "<<_offence<<endl;
	cout<<"Odwaga: "<<_bravery<<endl;
	cout<<endl;
	//return _name + "money: " + to_string(_money) + "\n\offence: " + 
	//to_string(_offence) + "\n\bravery: " + to_string(_bravery);
}