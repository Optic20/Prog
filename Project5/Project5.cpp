//Name: Everett Otis
//Date: September 30th, 2024
//Description: Structs

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

struct pay {
	string fName, lName, jobTitle, empNum;
	double hoursWorked, wage;
	int ded;
	double oTPay, oTWage, oTHours, grossPay, netPay, tax;
};

void input(pay& employee)
{
	for (int a = 0; a < 3; a++)
	{
		cout << "Enter your First Name: ";
		cin >> employee.fName;

		cout << "Enter Last Name: ";
		cin >> employee.lName;

		cin.ignore();

		cout << "Enter Job Tiltle: ";
		getline(cin, employee.jobTitle);

		cout << "Enter Employee Number: ";
		getline(cin, employee.empNum);

		cout << "Enter Hours Worked: ";
		cin >> employee.hoursWorked;

		cout << "Enter Hourly Wage: $";
		cin >> employee.wage;

		cout << "Enter Deductions Claimed: ";
		cin >> employee.ded;
		cout << endl;
	}
}

void calculate(pay& employee) 
{
	if (employee.hoursWorked > 40)
	{
		employee.oTWage = employee.wage * 1.5;
		employee.oTHours = employee.hoursWorked - 40;
		employee.oTPay = employee.oTWage * employee.oTHours;
		employee.grossPay = 40 * employee.wage + employee.oTPay;
	}
	else
	{
		employee.oTWage = 0;
		employee.oTHours = 0;
		employee.oTPay = 0;
		employee.grossPay = employee.hoursWorked * employee.wage;
	}

	if (employee.ded <= 0)
		employee.tax = .35;
	else if (employee.ded == 1)
		employee.tax = .30;
	else if (employee.ded == 2)
		employee.tax = .25;
	else if (employee.ded == 3)
		employee.tax = .20;
	else
		employee.tax = .15;

	employee.tax = employee.tax * employee.grossPay;
	employee.netPay = employee.grossPay - employee.tax;
}

void output(pay& employee)
{
	for (int a = 0; a < 3; a++)
	{
		cout << "Name: " << employee.lName << ", " << employee.fName << endl;
		cout << "Job Title: " << employee.jobTitle << endl;
		cout << "Employee Number: " << employee.empNum << endl;
		cout << "Deductions Claimed: " << employee.ded << endl;
		cout << "Hours Worked: " << employee.hoursWorked << endl;
		cout << "Hourly Wage: $" << employee.wage << endl;
		cout << "Gross Pay: $" << employee.grossPay << endl;
		cout << "Taxes Witheld: $" << employee.tax << endl;
		cout << "Net Pay: $" << employee.netPay << endl;
		cout << endl;
	}
}

int main()
{
	vector<pay> emp;
	pay employee;

	cout << fixed << showpoint << setprecision(2);

	input(employee);

	calculate(employee);

	output(employee);
}