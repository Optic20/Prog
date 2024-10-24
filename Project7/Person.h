#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Person {
public:
	void setAge(int number)
	{
		age = number;
	}
	void setFirstName(string text)
	{
		fName = text;
	}
	void setLastName(string text)
	{
		lName = text;
	}

	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}
	int getAge()
	{
		return age;
	}

protected:
	string fName, lName;
	int age;
};

void fileCheck(ifstream& iFile)
{
	if (!iFile.is_open())
	{
		cout << "Input file not found" << endl;
		exit(1);
	}
}