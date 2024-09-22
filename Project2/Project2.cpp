//Name: Everett Otis
//Date September 6th 2024
//Description: intake a string and remove any html tags

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string text;

	cout << "Enter a string with html tags" << endl;
	getline(cin, text);

	cout << "Original: " << text << endl;

	for (int a = 0; a < text.length(); a++)
	{
		if (text[a] == '<')
		{
			for (int b = 0; b < text.length(); b++)
			{
				if (text[b] == '>')
				{
					text = text.erase(a, b - a+1);
					break;
				}
			}
		}
	}

	cout << "Updated Text: " << text << endl;
}
	

