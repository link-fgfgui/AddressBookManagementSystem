#include "ManageSystem.h"
#include <iostream>
void showContact(Address_book* book)
{
	if (book->size == 0)
	{
		cout << "当前无联系人" << endl;
		return;
	}
	string sex;
	for (int i = 0; i < book->size; i++)
	{
		sex = "性";
		book->AddressArray[i].sex ? sex = "男" + sex : sex = "女" + sex;
		cout << book->AddressArray[i].name << "\t" << sex << "\t"
			<< book->AddressArray[i].age << "岁" << "\t电话:"
			<< book->AddressArray[i].telephone << endl;
	}
}