// Name: Everett Otis
// Program Description: Vectors
// Date: Sept, 22, 2024

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void getData(ifstream &iFile, vector<string>& fName, vector<string>& lName, vector<string>& tNum, vector<string>& major,
	vector<string>& advisor, vector<double>& gpa, vector<double>& credits,  vector<double>& year, vector<string>& hard, vector<string>& easy)
{
	string tempF;
	string tempL;
	string tempT;
	string tempM;
	string tempA;
	double tempG;
	double tempC;
	double tempY;
	string tempH;
	string tempE;

	while (!iFile.eof())
	{
	getline(iFile, tempF);
	getline(iFile, tempL);
	getline(iFile, tempT);
	getline(iFile, tempM);
	getline(iFile, tempA);
	iFile >> tempG;
	iFile >> tempC;
	iFile >> tempY;
	iFile.ignore();
	getline(iFile, tempH);
	getline(iFile, tempE);


	fName.push_back(tempF);
	lName.push_back(tempL);
	tNum.push_back(tempT);
	major.push_back(tempM);
	advisor.push_back(tempA);
	gpa.push_back(tempG);
	credits.push_back(tempC);
	year.push_back(tempY);
	hard.push_back(tempH);
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

void output(vector<string> fName, vector<string> lName, vector<string> tNum, vector<string> major, vector<string> advisor, vector<double> gpa, 
	vector<double> credits, vector<double> year, vector<string> hard, vector<string> easy,ofstream& oFile)
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

	for (int a = 0; fName.size(); a++)
	{
		oFile << "First Name: " << fName[a] << endl;
		oFile << "Last Name: " << lName[a] << endl;
		oFile << "T-Number: " << tNum[a] << endl;
		oFile << "Major: " << major[a] << endl;
		oFile << "Advosor Name: " << advisor[a] << endl;
		oFile << "GPA: " << gpa[a] << endl;
		oFile << "Credit Hours: " << credits[a] << endl;
		oFile << "Year expected to graduate: " << year[a] << endl;
		oFile << "Hardest class taken so far: " << hard[a] << endl;
		oFile << "Easiest class taken so far: " << easy[a] << endl;
	}
}

int main()
{
	ifstream iFile;
	iFile.open("input.txt");
	ofstream oFile;
	oFile.open("output.txt");

	fileCheck(iFile);

	vector<string> fName;
	vector<string> lName;
	vector<string> tNum;
	vector<string> major;
	vector<string> advisor;
	vector<double> gpa;
	vector<double> credits;
	vector<double> year;
	vector<string> hard;
	vector<string> easy;


	getData(iFile, fName, lName, tNum, major, advisor, gpa, credits, year, hard, easy);

	output(fName, lName, tNum, major, advisor, gpa, credits, year, hard, easy, oFile);

	iFile.close();

}