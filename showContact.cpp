#include "ManageSystem.h"
#include <iostream>
void showContact(Address_book* book)
{
	if (book->size == 0)
	{
		cout << "��ǰ����ϵ��" << endl;
		return;
	}
	string sex;
	for (int i = 0; i < book->size; i++)
	{
		sex = "��";
		book->AddressArray[i].sex ? sex = "��" + sex : sex = "Ů" + sex;
		cout << book->AddressArray[i].name << "\t" << sex << "\t"
			<< book->AddressArray[i].age << "��" << "\t�绰:"
			<< book->AddressArray[i].telephone << endl;
	}
}