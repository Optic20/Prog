// Name: Everett Otis
// Program Description: Vectors
// Date: Sept, 22, 2024

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void getData(ifstream &iFile, vector<string>& fName, vector<string>& lName, vector<double>& tNum, vector<string>& major, vector<string>& advisor, vector<double>& gpa, vector<double>& credits,  vector<double>& year, vector<string>& hard, vector<string>& easy)
{
string tempF;
string tempL;
string tempT;
string tempM;
string tempA;
string tempG;
string tempC;
string tempY;
string tempH;
string tempE;

while (!iFile.eof())
{
	getline(iFile, tempF);
	fName.push_back(tempF);

	getline(iFile, tempL);
	lName.push_back(tempL);

	iFile >> tempT;
	tNum.push_back(tempT);
	iFile.ignore();

	getline(iFile, tempM);
	major.push_back(tempM);

	getline(iFile, tempA);
	advisor.push_back(tempA)

	iFile >> tempG;
	gpa.push_back(tempG);
	iFile.ignore();

	iFile >> tempC;
	credits.push_back(tempC);
	iFile.ignore();

	iFile >> tempY;
	year.push_back(tempY);
	iFile.ignore();

	getline(iFile, tempH);
	hard.push_back(tempH);

	getline(iFile, tempE);
	easy.push_back(tempE);

}
}

void fileCheck(ifstream& iFile)
{
	if (!iFile.is_open())
	{
		cout << "Input file not found" << endl;
		exit(1);
	}
}

void output(vector<string> fName, vector<string> lName, vector<double> tNum, vector<string> major, vector<string> advisor, vector<double> gpa, vector<double> credits, vector<double> year, vector<string> hard, vector<string> easy)
{
	for (int a = 0; fName.size(); a++)
	{
		cout << "First Name: " << fName[a] << endl;
		cout << "Last Name: " << lName[a] << endl;
		cout << "T-Number: " << tNum[a] << endl;
		cout << "Major: " << major[a] << endl;
		cout << "Advosor Name: " << advisor[a] << endl;
		cout << "GPA: " << gpa[a] << endl;
		cout << "Credit Hours: " << credits[a] << endl;
		cout << "Year expected to graduate: " << year[a] << endl;
		cout << "Hardest class taken so far: " << hard[a] << endl;
		cout << "Easiest class taken so far: " << easy[a] << endl;
	}
}

int main()
{
	ifstream iFile;
	iFile.open("input.txt");

	fileCheck(iFile);

	vector<string> fName;
	vector<string> lName;
	vector<double> tNum;
	vector<string> major;
	vector<string> advisor;
	vector<double> gpa;
	vector<double> credits;
	vector<double> year;
	vector<string> hard;
	vector<string> easy;


	getData(iFile, fName, lName, tNum, major, advisor, gpa, credits, year, hard, easy);

	output(fName, lName, tNum, major, advisor, gpa, credits, year, hard, easy);

	iFile.close();

}