#include "ManageSystem.h"
void findContact(Address_book* book, int returnArray[], string name, string telephone)
{
	if (name == "" && telephone == "") { return; }
	int j = 0;
	if (telephone == "")
	{
		for (int i = 0; i < book->size; i++)
		{
			if (book->AddressArray[i].name == name)
			{
				returnArray[j] = i;
				j++;
			}
		}
	}
	else if (name == "")
	{
		for (int i = 0; i < book->size; i++)
		{
			if (book->AddressArray[i].telephone == telephone)
			{
				returnArray[j] = i;
				j++;
			}
		}
	}
	else
	{
		int* tempArray = new int[MAX] {-1};
		int k = 0;
		for (int i = 0; i < book->size; i++)
		{
			if (book->AddressArray[i].name == name)
			{
				tempArray[j] = i;
				j++;
			}
		}
		if (tempArray[0] == -1)
		{
			delete[] tempArray;
			return;
		}
		for (int i = 0; i < j; i++)
		{
			if (book->AddressArray[tempArray[i]].telephone == telephone)
			{
				returnArray[k] = tempArray[i];
				k++;
			}
		}
		delete[] tempArray;
	}
}