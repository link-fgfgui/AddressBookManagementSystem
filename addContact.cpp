#include "ManageSystem.h"
#include <iostream>
void addContact(string name, bool sex, short age, string telephone, Address_book* book)
{
	if (book->size == MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
		return;
	}
	Contact c = { name,sex,age,telephone };
	book->AddressArray[book->size] = c;
	book->size++;
	cout << "添加成功！" << endl;
}