#include "ManageSystem.h"
#include <iostream>
void addContact(string name, bool sex, short age, string telephone, Address_book* book)
{
	if (book->size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
		return;
	}
	Contact c = { name,sex,age,telephone };
	book->AddressArray[book->size] = c;
	book->size++;
	cout << "��ӳɹ���" << endl;
}