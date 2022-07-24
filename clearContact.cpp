#include "ManageSystem.h"
void clearContact(Address_book* book)
{
	delete[] book->AddressArray;
	Contact* AddressArray = new Contact[MAX];
	book->AddressArray = AddressArray;
	book->size = 0;
}