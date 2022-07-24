#include "ManageSystem.h"
#include <fstream>
void saveBook(Address_book* book)
{
	ofstream out("config.ini");
	if (out.is_open())
	{
		for (int i = 0; i < book->size; i++)
		{
			out << book->AddressArray[i].name << endl;
			out << book->AddressArray[i].sex << endl;
			out << book->AddressArray[i].age << endl;
			out << book->AddressArray[i].telephone << endl;
		}
		out.close();
	}
}