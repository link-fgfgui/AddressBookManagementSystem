#include "ManageSystem.h"
#include <fstream>
#include <sys/stat.h>
void loadconfig(Address_book* book)
{
	struct stat* bufP = new struct stat;
	if (!stat("config.ini", bufP))
	{
		string* strArray = new string[4 * MAX];
		ifstream fin("config.ini");
		string s;
		int i = 0;
		while (getline(fin, s))
		{
			strArray[i] = s;
			i++;
		}
		int len = 4 * MAX;
		for (int j = 0; j < len; j += 4)
		{
			if (strArray[j] == "") { break; }
			book->AddressArray[j / 4].name = strArray[j];
			book->AddressArray[j / 4].age = stoi(strArray[j + 2]);
			book->AddressArray[j / 4].sex = (bool)stoi(strArray[j + 1]);
			book->AddressArray[j / 4].telephone = strArray[j + 3];
			book->size++;

		};
		delete[] strArray;
	};
	delete bufP;
}