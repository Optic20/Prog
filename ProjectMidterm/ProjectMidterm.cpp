// Name: Everett Otis
// Date: October 7th, 2024
// Description Midterm

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

struct emp {
	string fName, lName, jobTitle;
	double grossPay, timeOnJob;
};

void checkFile(ifstream& iFile)
{
	if (!iFile.is_open())
	{
		cout << "Input file not found" << endl;
		exit(1);
	}
}

void swapData(vector<emp>& atu, int b)
{
	emp temp;
	temp = atu[b];
	atu[b] = atu[b + 1];
	atu[b + 1] = temp;
}

void sortData(vector<emp>& atu, int choice)
{
	emp temp;
	for (int a = 0; a < atu.size(); a++)
	{
		for (int b = 0; b < atu.size() - 1; b++)
		{
			if (choice == 1)
			{
				if (atu[b].lName > atu[b + 1].lName)
				{
					swapData(atu, b);
				}
			}
			else if (choice == 2)
			{
				if (atu[b].jobTitle > atu[b + 1].jobTitle)
				{
					swapData(atu, b);
				}
			}
			else if (choice == 3)
			{
				if (atu[b].timeOnJob > atu[b + 1].timeOnJob)
				{
					swapData(atu, b);
				}
			}
			else if (choice == 4)
			{
				if (atu[b].grossPay > atu[b + 1].grossPay)
				{
					swapData(atu, b);
				}
			}

		}
	}
}

void output(vector<emp>& atu, int choice, ofstream& oFile)
{
	if (choice == 5)
	{
		int max = 0;
		for (int a = 0; a < atu.size(); a++)
		{
			if (atu[a].grossPay > atu[max].grossPay)
			{
				max = a;
			}
		}

		cout << "Highest Paid Employee: " << atu[max].fName << " " << atu[max].lName
			<< ", Title: " << atu[max].jobTitle
			<< ", Gross Pay: $" << atu[max].grossPay
			<< ", Time on Job: " << atu[max].timeOnJob << " years" << endl;

		oFile << "Highest Paid Employee: " << atu[max].fName << " " << atu[max].lName
			<< ", Title: " << atu[max].jobTitle
			<< ", Gross Pay: $" << atu[max].grossPay
			<< ", Time on Job: " << atu[max].timeOnJob << " years" << endl;
	}
	else if (choice == 6)
	{
		int max = 0;
		for (int a = 0; a < atu.size(); a++)
		{
			if (atu[a].timeOnJob > atu[max].timeOnJob)
			{
				max = a;
			}
		}

		cout << "Longest Employed Employee: " << atu[max].fName << " " << atu[max].lName
			<< ", Title: " << atu[max].jobTitle
			<< ", Gross Pay: $" << atu[max].grossPay
			<< ", Time on Job: " << atu[max].timeOnJob << " years" << endl;

		oFile << "Longest Employed Employee: " << atu[max].fName << " " << atu[max].lName
			<< ", Title: " << atu[max].jobTitle
			<< ", Gross Pay: $" << atu[max].grossPay
			<< ", Time on Job: " << atu[max].timeOnJob << " years" << endl;
	}
	else
	{
		for (int a = 0; a < atu.size(); a++)
		{
			cout << "Name: " << atu[a].lName << ", " << atu[a].fName
				<< ", Title: " << atu[a].jobTitle
				<< ", Gross pay: $" << atu[a].grossPay
				<< ", Time on Job: " << atu[a].timeOnJob << " years" << endl;

			oFile << "Name: " << atu[a].lName << ", " << atu[a].fName
				<< ", Title: " << atu[a].jobTitle
				<< ", Gross pay: $" << atu[a].grossPay
				<< ", Time on Job: " << atu[a].timeOnJob << " years" << endl;
		}
	}
}

void menu(vector<emp>& atu, ofstream& oFile)
{
	int choice = 0;
	while (choice != 99)
	{
		cout << "Please select an option from below: " << endl;
		cout << "1. Sort on Name(Last, First): " << endl;
		cout << "2. Sort on Job Title: " << endl;
		cout << "3. Sort on Time Employed(highest to lowest): " << endl;
		cout << "4. Sort on Gross Pay(highest to lowest): " << endl;
		cout << "5. Display info for the highest paid employee" << endl;
		cout << "6. Display info for the longest employed employee" << endl;
		cout << "Enter Selection (99 to exit): ";
		cin >> choice;

		if (choice == 1)
		{
			sortData(atu, choice);
			output(atu, choice, oFile);
		}
		else if (choice == 2)
		{
			sortData(atu, choice);
			output(atu, choice, oFile);
		}
		else if (choice == 3)
		{
			sortData(atu, choice);
			output(atu, choice, oFile);
		}
		else if (choice == 4)
		{
			sortData(atu, choice);
			output(atu, choice, oFile);
		}
		else if (choice == 5)
		{
			output(atu, choice, oFile);
		}
		else if (choice == 6)
		{
			output(atu, choice, oFile);
		}
		else if (choice != 99)
		{
			cout << "Invalid selection" << endl;
		}
	}
}


int main()
{
	cout << fixed << showpoint << setprecision(2);
	vector<emp> atu;
	ifstream iFile;
	iFile.open("input.txt");
	ofstream oFile;
	oFile.open("output.txt");

	checkFile(iFile);

	emp temp;

	while (!iFile.eof())
	{
		getline(iFile, temp.fName);
		getline(iFile, temp.lName);
		getline(iFile, temp.jobTitle);
		iFile >> temp.grossPay;
		iFile >> temp.timeOnJob;
		iFile.ignore();
		atu.push_back(temp);
	}

	menu(atu, oFile);
	iFile.close();
	oFile.close();
	return 0;
}