// Name: Everett Otis
// Date: September 13th 2024
// Description: Bubble sort

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void readNamesFromFiles(const string& firstNameFile, const string& lastNameFile,
    string fName[], string lName[], int& counter) {
    ifstream fNameFileStream(firstNameFile);
    if (!fNameFileStream.is_open()) {
        cerr << "Error: Unable to open " << firstNameFile << endl;
        exit(1);
    }

    ifstream lNameFileStream(lastNameFile);
    if (!lNameFileStream.is_open()) {
        cerr << "Error: Unable to open " << lastNameFile << endl;
        exit(1);
    }

    counter = 0;
    while (fNameFileStream >> fName[counter] && lNameFileStream >> lName[counter]) {
        ++counter;
    }

    fNameFileStream.close();
    lNameFileStream.close();
}

void sortData(string primary[], string secondary[], int counter, bool sort) {
    string temp;
    for (int a = 0; a < counter - 1; ++a) {
        for (int b = 0; b < counter - a - 1; ++b) {
            bool swap = sort ? primary[b] > primary[b + 1] : secondary[b] > secondary[b + 1];
            if (swap)
            {
                temp = primary[b];
                primary[b] = primary[b + 1];
                primary[b + 1] = temp;

                temp = secondary[b];
                secondary[b] = secondary[b + 1];
                secondary[b + 1] = temp;
            }
        }
    }
}

void displayNames(const string fName[], const string lName[], int counter, bool sorted) {
    if (sorted) {
        cout << "List is sorted by first names:" << endl;
        for (int a = 0; a < counter; ++a) {
            cout << fName[a] << " " << lName[a] << endl;
        }
    }
    else {
        cout << "List is sorted by last names:" << endl;
        for (int a = 0; a < counter; ++a) {
            cout << lName[a] << " " << fName[a] << endl;
        }
    }
}

int main() {
    int choice;
    string fName[100], lName[100];
    int counter = 0;

    cout << "How would you like to sort the names?" << endl;
    cout << "Sort by first names: 1" << endl;
    cout << "Sort by last names: 2" << endl;
    cin >> choice;

    readNamesFromFiles("input.txt", "input2.txt", fName, lName, counter);

    cout << "List is unsorted:" << endl;
    displayNames(fName, lName, counter, true);

    bool sort = (choice == 1);
    sortData(fName, lName, counter, sort);

    displayNames(fName, lName, counter, sort);

    return 0;
}
