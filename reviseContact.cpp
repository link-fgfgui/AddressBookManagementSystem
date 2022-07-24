#include "ManageSystem.h"
void reviseContact(Address_book* book, int j, string name, bool sex, short age, string telephone)
{
	Contact c = { name,sex,age,telephone };
	book->AddressArray[j] = c;
	return;
}