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

	void setFirstName(string text)
	{
		fName = text;
	}
	void setLastName(string text)
	{
		lName = text;
	}
	void setJobTitle(string text)
	{
		jobTitle = text;
	}
	void setEmpNum(string text)
	{
		empNum = text;
	}
	void setHoursWorked(double number)
	{
		hoursWorked = number;
	}
	void setWage(double number)
	{
		wage = number;
	}
	void setDed(int number)
	{
		ded = number;
	}

	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}
	string getJobTitle()
	{
		return jobTitle;
	}
	string getEmpNum()
	{
		return empNum;
	}
	double getHoursWorked()
	{
		return hoursWorked;
	}
	double getWage()
	{
		return wage;
	}
	int getDed()
	{
		return ded;
	}

	void getData(vector<pay>& emp, ifstream& iFile)
	{
		pay temp;

		while (!iFile.eof())
		{
			string str;
			double dbl;
			int i;

			iFile >> str;
			temp.setFirstName(str);
			iFile >> str;
			temp.setLastName(str);
			iFile >> str;
			temp.setJobTitle(str);
			iFile >> str;
			temp.setEmpNum(str);
			iFile >> dbl;
			temp.setHoursWorked(dbl);
			iFile >> dbl;
			temp.setWage(dbl);
			iFile >> i;
			temp.setDed(i);
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