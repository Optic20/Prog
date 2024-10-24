// Name: Everett Otis
// Date: Oct 23, 2024
// Description: Inheritence

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#include "Person.h"

using namespace std;



class Student : public Person {
public:

	void getData(vector<Student>& atu, ifstream& iFile)
	{
		while (!iFile.eof())
		{
			Student temp;
			iFile >> temp.fName;
			iFile >> temp.lName;
			iFile >> temp.age;
			iFile >> temp.gpa;
			iFile >> temp.yearGrad;
			atu.push_back(temp);
		}
	}

	void output(vector<Student>& atu)
	{
		for (int a = 0; a < atu.size(); a++)
		{
			cout << "Name: " << atu[a].fName << " " << atu[a].lName << endl;
			cout << "Age: " << atu[a].age << endl;
			cout << "GPA: " << atu[a].gpa << endl;
			cout << "Year Graduated: " << atu[a].yearGrad << endl << endl;
		}
	}

	void averageGPA(vector<Student>& atu)
	{
		double totalGPA = 0;
		int num=0;
		for (int a = 0; a < atu.size(); a++)
		{
			totalGPA += atu[a].gpa;
			num++;

		}
		totalGPA = totalGPA / num ;

		cout << "The average GPA is: " << totalGPA << endl << endl;
	}

	void highLowGPA(vector<Student>& atu)
	{
		double highestGPA = 0, lowestGPA = 4;
		for (int a = 0; a < atu.size(); a++) {
			
			
			if (atu[a].gpa > highestGPA)
			{
				highestGPA = atu[a].gpa;
			}
			else if (atu[a].gpa < lowestGPA)
			{
				lowestGPA = atu[a].gpa;
			}
		}
		cout << "Highest GPA: " << highestGPA << endl;
		cout << "Lowest GPA: " << lowestGPA << endl;
	}


private:
	double gpa;
	int yearGrad;
};


int main()
{
	ifstream iFile;
	iFile.open("input.txt");
	fileCheck(iFile);
	vector<Student> atu;
	Student temp;
	temp.getData(atu, iFile);
	temp.output(atu);
	temp.averageGPA(atu);
	temp.highLowGPA(atu);
	iFile.close();
}