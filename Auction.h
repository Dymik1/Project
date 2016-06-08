#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Person
{
	static vector <string> names;
	
	string _name;
	int _money;
	float _bravery;
	float _offence;
	
	static void init();
		
public:
	
	Person();
	
	string name() { return _name; }
	int money() {return _money;}
	float bravery() {return _bravery;}
	float offence() {return _offence;}
	void description();	
	
};