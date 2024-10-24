#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std; 

void menu() {

	//Menu
	cout << endl;
	cout << "Welcome to Menu" << endl; 
	
	cout << "1: Search. " << endl; 
	cout << "2: Print Entire List. " << endl;
	cout << "3: Print Histogram. " << endl;
	cout << "4: Exit Program. " << endl;

}


int GroceryFile(int MenuInput, string Search) {

	//Opens File
	ifstream Grocer("CS210_Project_Three_Input_File.txt");

	//Gives error if file isn't found
	if (!Grocer) {
		cerr << "File not Found!" << endl;
		return 1;
	}

	//Creates Backup file
	ofstream Backup("frequency.dat.txt");

	//Gives error if the file isn't created/found
	if (!Backup) {
		cerr << "Backup file not Found!" << endl;
		return 1;
	}

	//Map function allows me to store the frequency of the words 
	map <string, int> WordCount;
	string word;

	

	while (Grocer >> word) {
		WordCount[word]++;
	}

	//Backup File 
	for (const auto& entry : WordCount) {
		Backup << entry.first << " " << entry.second << endl;
	}
	
	//Use MenuInput to determine which case to go to then preforms different task
	switch (MenuInput) {
		case 1:
			if (WordCount.find(Search) != WordCount.end()) {
				cout << Search << " Were Searched for " << WordCount[Search] << " times." << endl;
			}
			else {
				cout << "Sorry! We don't sell " << Search << "!" << endl;
			}
			break;
		case 2: 
			for (const auto& entry : WordCount) {
				cout << entry.first << " " << entry.second << endl;
			}
			break;
		case 3:
			for (const auto& entry : WordCount) {
				cout << entry.first << ": ";
				for (int i = 0; i < entry.second; ++i) {
					cout << "*";
				}
				cout << endl;
			}
			break;
		default: 
			cout << "error!" << endl;
	}
}


int main() {

	//Menu Navigation Variable
	int MenuInput = 0;
	string Search , line; 

	//While Menu Loop. 
	while (MenuInput != 4) {
		try {
			menu();
			cin >> MenuInput;
			if (MenuInput == 1) {
				cout << "Please enter a food you would like to see!" << endl; 
				cin >> Search;
				GroceryFile(MenuInput, Search);
			}
			else if (MenuInput == 2) {
				GroceryFile(MenuInput, Search);
			}
			else if (MenuInput == 3) {
				GroceryFile(MenuInput, Search);
			}
			else if (MenuInput == 4) {
				//Leaves loop and closes program
				cout << "Goodbye!";
			}
			else {
				throw (MenuInput);
			}
		}
		catch (int error) {
			cout << "Please Enter a number 1 - 4." << endl;

		}
		

	}




	return 0;
}