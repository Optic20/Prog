// Name: Everett Otis
// Date: October 14th, 2024
// Description: intro to OOP

#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

class pay {
public:
	void fileCheck(ifstream& iFile)
	{
		if (!iFile.is_open())
		{
			cout << "Input file not found" << endl;
			exit(1);
		}
	}

	void getData(vector<pay>& emp, ifstream& iFile)
	{
		pay temp;

		while (!iFile.eof())
		{
			iFile >> temp.fName;
			iFile >> temp.lName;
			iFile >> temp.jobTitle;
			iFile >> temp.empNum;
			iFile >> temp.hoursWorked;
			iFile >> temp.wage;
			iFile >> temp.ded;
			emp.push_back(temp);
		}
	}

	void calculate(vector<pay>& emp)
	{
		if (hoursWorked > 40)
		{
			oTWage = wage * 1.5;
			oTHours = hoursWorked - 40;
			oTPay = oTWage * oTHours;
			grossPay = 40 * wage + oTPay;
		}
		else
		{
			oTWage = 0;
			oTHours = 0;
			oTPay = 0;
			grossPay = hoursWorked * wage;
		}

		if (ded <= 0)
			tax = .35;
		else if (ded == 1)
			tax = .30;
		else if (ded == 2)
			tax = .25;
		else if (ded == 3)
			tax = .20;
		else
			tax = .15;

		tax = tax * grossPay;
		netPay = grossPay - tax;
	}

	void output(vector<pay>& emp)
	{
		for (int a = 0; a < emp.size(); a++)
		{
			cout << "Name: " << emp[a].lName << ", " << emp[a].fName << endl;
			cout << "Job Title: " << emp[a].jobTitle << endl;
			cout << "Employee Number: " << emp[a].empNum << endl;
			cout << "Deductions Claimed: " << emp[a].ded << endl;
			cout << "Hours Worked: " << emp[a].hoursWorked << endl;
			cout << "Hourly Wage: $" << emp[a].wage << endl;
			cout << "Gross Pay: $" << emp[a].grossPay << endl;
			cout << "Taxes Witheld: $" << emp[a].tax << endl;
			cout << "Net Pay: $" << emp[a].netPay << endl << endl;
		}
	}

private:
	string fName, lName, jobTitle, empNum;
	double hoursWorked, wage;
	int ded;
	double oTPay, oTWage, oTHours, grossPay, netPay, tax;
};

int main()
{
	vector<pay> emp;

	pay temp;

	ifstream iFile;
	iFile.open("input.txt");

	temp.fileCheck(iFile);

	temp.getData(emp, iFile);

	temp.calculate(emp);

	temp.output(emp);

	iFile.close();
	return 0;
}