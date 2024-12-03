// Name: Everett Otis
// Date: December 2nd, 2024
// Description: Final

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int num()
{
	int movieNum;
	do {
		cout << "How many movies (3 or more)";
		cin >> movieNum;

		if (movieNum < 3) {
			cout << "Please enter at least 3 movies!";
		}
	} while (movieNum < 3);
	return movieNum;
}

class Movie {
public:
	void getMovieData()
	{
		cout << "Enter the movie name: ";
		cin.ignore();
		getline(cin, name);
		cout << "What is the rating (G, PG, PG-13, R): ";
		cin >> rating;

	}

protected:
	string name, rating;
};

class Genre : virtual public Movie {
public:
	void getGenreData() {
		cout << "Enter the genre: ";
		cin.ignore();
		getline(cin, genre);
	}

protected:
	string genre;
};

class Actor : virtual public Movie {
public:
	void getActorData() {
		cout << "Enter the actor's first name: ";
		cin >> fName;
		cout << "Enter the actor's last name: ";
		cin >> lName;
	}

protected:
	string fName, lName;
};

class Financial : public Genre, public Actor {
public:
	int movieNum;

	void getData(vector<Financial>& atu)
	{
		movieNum = num();

		for (int a = 0; a < movieNum; a++)
		{
			Financial temp;

			temp.getMovieData();
			temp.getGenreData();
			temp.getActorData();
			cout << "Enter the gross: ";
			cin >> temp.gross;
			atu.push_back(temp);
		}
	}

	void hGross(vector<Financial>& atu, int movieNum) {
		int temph = 0, tempa = 0;
		for (int a = 1; a < movieNum; a++)
		{
			if (atu[a].gross > atu[tempa].gross)
			{
				temph = a;

			}
			tempa++;
		}

		cout << "The highest grossing film:" << endl;
		cout << "Movie: " << atu[temph].name << endl;
		cout << "Rating: " << atu[temph].rating << endl;
		cout << "Genre: " << atu[temph].genre << endl;
		cout << "Actor's first name: " << atu[temph].fName << endl;
		cout << "Actor's last name: " << atu[temph].lName << endl;
		cout << "Box office gross: $" << atu[temph].gross << " million" << endl;

	}

	void averagegross(vector<Financial>& atu)
	{
		int totalGross = 0;
		for (int a = 0; a < movieNum; a++)
		{
			totalGross += atu[a].gross;
		}
		double average = totalGross / movieNum;
		cout << "The Average Gross is: " << average << " million" << endl;
	}

	void ratings(vector<Financial>& atu, int movieNum)
	{
		int G = 0, P = 0, PG = 0, R = 0;
		for (int a = 0; a < movieNum; a++)
		{
			if (atu[a].rating == "G") {
				G++;
			}
			else if (atu[a].rating == "PG") {
				P++;
			}
			else if (atu[a].rating == "PG-13") {
				PG++;
			}
			else if (atu[a].rating == "R") {
				R++;
			}
			else {
				cout << "Invalid input";
			}
		}
		cout << "Rating   Count" << endl;
		cout << "G    " << G << endl;
		cout << "PG    " << P << endl;
		cout << "PG-13    " << PG << endl;
		cout << "R    " << R << endl;
	}

	void h100(vector<Financial>& atu, int MovieNum) {
		int over = 0;
		for (int a = 0; a < movieNum; a++) {
			if (atu[a].gross > 100) {
				over++;
			}
		}
		cout << "The number of movies that made over $100 million at the box office was " << over << endl;
	}

	void menu(vector<Financial>& atu) {
		int choice = 0;
		Financial temp;

		while (true) {
			cout << "Choice 1: Output the highest gross" << endl;
			cout << "Choice 2: Output the average box office gross" << endl;
			cout << "Choice 3: Output a count of movie ratings" << endl;
			cout << "Choice 4: Output a count of movies that made over $100 million" << endl;
			cout << "Choice 5: Return to menu" << endl;
			cout << "Choice 6: Exit" << endl;
			cin >> choice;

			if (choice == 1) {
				temp.hGross(atu, movieNum);
			}
			else if (choice == 2) {
				temp.averagegross(atu);
			}
			else if (choice == 3) {
				temp.ratings(atu, movieNum);
			}
			else if (choice == 4) {
				temp.h100(atu, movieNum);
			}
			else if (choice == 5) {
				break;
			}
			else if (choice == 6) {
				exit(0);
			}
			else {
				cout << "Invalid input!";
			}

		}

	}

	void output(vector<Financial>& atu)
	{
		for (int a = 0; a < movieNum; a++)
		{
			cout << "Movie: " << atu[a].name << endl;
			cout << "Rating: " << atu[a].rating << endl;
			cout << "Genre: " << atu[a].genre << endl;
			cout << "Actor's first name: " << atu[a].fName << endl;
			cout << "Actor's last name: " << atu[a].lName << endl;
			cout << "Box office gross: $" << atu[a].gross << " million" << endl;
			cout << movieNum << endl;
		}

		menu(atu);

	}
protected:
	double gross;
};

int main()
{
	vector<Financial> atu;
	Financial temp;

	temp.getData(atu);
	temp.output(atu);
};