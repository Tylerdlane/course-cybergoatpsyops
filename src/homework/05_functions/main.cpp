
#include <iostream>
#include <string>

#include "func.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int choice = 0;
	do
	{
		cout << "DNA Analysis Menu" << endl;
		cout << "1- Get GC Content" << endl;
		cout << "2- Get DNA Complement" << endl;
		cout << "3- Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			string dna;
			cout << "Enter DNA string: ";
			cin >> dna;
			double gc = get_gc_content(dna);
			cout << "GC Content: " << gc << endl;
		}
		else if (choice == 2)
		{
			string dna;
			cout << "Enter DNA string: ";
			cin >> dna;
			string complement = get_dna_complement(dna);
			cout << "DNA Complement: " << complement << endl;
		}
		else if (choice != 3)
		{
			cout << "Invalid option. Please try again." << endl;
		}

		cout << endl;
	} while (choice != 3);

	cout << "Program exited." << endl;
	return 0;
}
