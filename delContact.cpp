#include "ManageSystem.h"
void delContact(Address_book* book, int j)
{
	if ((j + 1) == book->size)
	{
		Contact c = { "",0,0,"" };
		book->AddressArray[j] = c;
		book->size--;
		return;
	}
	for (int i = j; i < book->size; i++)
	{
		book->AddressArray[i] = book->AddressArray[i + 1];
	}
	book->size--;
	return;
}