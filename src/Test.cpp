/**
 * @file Test.cpp.
 * @description Kutuphanelerimiz Testlenmesi.
 * @course 1.C.
 * @assignment 1.Odev
 * @date Kodu 28/11/19
 * @author Omar Alkadri omar.alkadri@ogr.sakarya.edu.tr
 */
#include "sifreleme.hpp"
#include <string>
#include <fstream>
#include <sstream>

int main()
{

	circularlinked *a = new circularlinked;
	ifstream MyFile(".\\doc\\metin.txt");
	string line;
	stringstream ss;

	if (MyFile.is_open())
	{
		while (getline(MyFile, line))
		{
			stringstream ss(line);
			while (getline(ss, line, ' '))
			{
				if (line != "")
					a->AddNode(stoi(line));
				else
					cout << "satir Bos!!!\n";
			}
			cout << *a << endl;

			a->DeleteFirst();
		}
	}
	else
		cout << "Unable to open file!\n";

	delete a;

	return 0;
}