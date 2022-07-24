#include "ManageSystem.h"
#include <iostream>
Address_book book;
int main()
{
	loadconfig(&book);
	string s;
	int n;
	while (true)
	{
		showMenu();
		cin >> s;
		try {
			n = stoi(s);
		}
		catch (std::invalid_argument)
		{
			cout << "���������׼���֡�" << endl;
			system("pause");
			system("cls");
			continue;
		}
		catch (std::out_of_range)
		{
			cout << "����������󣬳����˳���Ľ��ܷ�Χ" << endl;
			system("pause");
			system("cls");
			continue;
		}
		string name;
		bool sex = 1;
		short age = 0;
		string telephone;
		switch (n)
		{
		case 1:
		{
			if (book.size == MAX)
			{
				cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
				break;
			}
			cout << "������" << endl;
			cin >> name;
			cout << "�Ա�" << endl
				<< "1----��" << endl
				<< "0----Ů" << endl;
		sexErrorFlag:
			cin >> s;
			if (s == "1") { sex = 1; }
			else if (s == "0") { sex = 0; }
			else
			{
				cout << "�������벻��ȷ�����������롣" << endl;
				goto sexErrorFlag;
			}
			cout << "���䣿" << endl;
		ageErrorFlag:
			cin >> s;
			try
			{
				age = (short)stoi(s);
			}
			catch (std::exception) {
				cout << "�쳣�����������롣" << endl;
				goto ageErrorFlag;
			}
			cout << "�绰��" << endl;
			cin >> telephone;
			addContact(name, sex, age, telephone, &book);
			break;
		}
		case 2:
			showContact(&book);
			break;
		case 3:
		{
			cout << "����������:(ȱʡ����0)" << endl;
			cin >> s;
			s == "0" ? name = "" : name = s;
			cout << "������绰:(ȱʡ����0)" << endl;
			cin >> s;
			s == "0" ? telephone = "" : telephone = s;
			int* resultArray = new int[MAX] {-1, -1};
			findContact(&book, resultArray, name, telephone);
			if (resultArray[0] == -1) { cout << "û���ҵ������ϵ��" << endl; }
			else if (resultArray[1] == -1)
			{
				delContact(&book, resultArray[0]);
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "�ҵ��˶����ϵ�ˣ���ѡ����Ҫɾ������ϵ�ˡ�(ȫɾ���� all )" << endl;
				for (int i = 0; i < book.size; i++)
				{
					if (resultArray[i] == 0 && i != 0) { break; }
					cout << i << "\t" << book.AddressArray[resultArray[i]].name << "\t"
						<< (book.AddressArray[resultArray[i]].sex ? "����" : "Ů��") << "\t"
						<< book.AddressArray[resultArray[i]].age << "��" << "\t�绰:"
						<< book.AddressArray[resultArray[i]].telephone << endl;
				}
			delErrorFlag:
				cin >> s;
				if (s == "all") {
					for (int i = book.size; i > 0; i--)
					{
						if (resultArray[i - 1] == 0 && (i - 1) != 0) { continue; }
						delContact(&book, resultArray[i - 1]);
					}cout << "ɾ���ɹ���" << endl;
				}
				else
				{
					try
					{
						int i = stoi(s);
						if (resultArray[i] == 0 && i != 0) { throw "�������볬����Χ�����������룡"; }
						delContact(&book, resultArray[i]);
						cout << "ɾ���ɹ���" << endl;
					}
					catch (const char* msg) {
						cout << msg << endl;
						goto delErrorFlag;
					}
					catch (exception) {
						cout << "�������������룡" << endl;
						goto delErrorFlag;
					}
				}
			}
			break;
		}
		case 4:
		{
			cout << "����������:(ȱʡ����0)" << endl;
			cin >> s;
			s == "0" ? name = "" : name = s;
			cout << "������绰:(ȱʡ����0)" << endl;
			cin >> s;
			s == "0" ? telephone = "" : telephone = s;
			int* resultArray = new int[MAX] {-1, -1};
			findContact(&book, resultArray, name, telephone);
			if (resultArray[0] == -1) { cout << "û���ҵ������ϵ��" << endl; }
			else if (resultArray[1] == -1)
			{
				cout << book.AddressArray[resultArray[0]].name << "\t"
					<< (book.AddressArray[resultArray[0]].sex ? "����" : "Ů��") << "\t"
					<< book.AddressArray[resultArray[0]].age << "��" << "\t�绰:"
					<< book.AddressArray[resultArray[0]].telephone << endl;
			}
			else
			{
				for (int i = 0; i < book.size; i++)
				{
					if (resultArray[i] == 0 && i != 0) { break; }
					cout << book.AddressArray[resultArray[i]].name << "\t"
						<< (book.AddressArray[resultArray[i]].sex ? "����" : "Ů��") << "\t"
						<< book.AddressArray[resultArray[i]].age << "��" << "\t�绰:"
						<< book.AddressArray[resultArray[i]].telephone << endl;
				}
			}
			delete[] resultArray;
			break;
		}
		case 5:
		{
			cout << "����������:(ȱʡ����0)" << endl;
			cin >> s;
			s == "0" ? name = "" : name = s;
			cout << "������绰:(ȱʡ����0)" << endl;
			cin >> s;
			s == "0" ? telephone = "" : telephone = s;
			int* resultArray = new int[MAX] {-1, -1};
			findContact(&book, resultArray, name, telephone);
			if (resultArray[0] == -1) { cout << "û���ҵ������ϵ��" << endl; }
			else if (resultArray[1] == -1)
			{
				cout << "�������޸ĺ��������ȱʡ���� OK ��" << endl;
				cin >> s;
				s == "OK" ? name = book.AddressArray[resultArray[0]].name : name = s;
				cout << "�������޸ĺ���Ա�ȱʡ���� OK ��" << endl;
			srf:
				cin >> s;
				if (!(s == "0" || s == "1")) { cout << "���벻��ȷ��" << endl; goto srf; }
				s == "OK" ? sex = book.AddressArray[resultArray[0]].sex : sex = (bool)stoi(s);
				cout << "�������޸ĺ�����䣨ȱʡ���� OK ��" << endl;
				cin >> s;
				s == "OK" ? age = book.AddressArray[resultArray[0]].age : age = stoi(s);
				cout << "�������޸ĺ�ĵ绰��ȱʡ���� OK ��" << endl;
				cin >> s;
				s == "OK" ? telephone = book.AddressArray[resultArray[0]].telephone : telephone = s;
				reviseContact(&book, resultArray[0], name, sex, age, telephone);
				cout << "�޸ĳɹ���" << endl;
			}
			else
			{
				cout << "�ҵ��˶����ϵ�ˣ���ѡ����Ҫ�޸ĵ���ϵ�ˡ�" << endl;
				for (int i = 0; i < book.size; i++)
				{
					if (resultArray[i] == 0 && i != 0) { break; }
					cout << i << "\t" << book.AddressArray[resultArray[i]].name << "\t"
						<< (book.AddressArray[resultArray[i]].sex ? "����" : "Ů��") << "\t"
						<< book.AddressArray[resultArray[i]].age << "��" << "\t�绰:"
						<< book.AddressArray[resultArray[i]].telephone << endl;
				}
			fof:
				cin >> s;
				try
				{
					int i = stoi(s);
					if (resultArray[i] == 0 && i != 0) { throw "�������볬����Χ�����������룡"; }
					cout << "�������޸ĺ��������ȱʡ���� OK ��" << endl;
					cin >> s;
					s == "OK" ? name = book.AddressArray[resultArray[i]].name : name = s;
					cout << "�������޸ĺ���Ա�ȱʡ���� OK ��" << endl;
				srf2:
					cin >> s;
					if (!(s == "0" || s == "1")) { cout << "���벻��ȷ��" << endl; goto srf2; }
					s == "OK" ? sex = book.AddressArray[resultArray[i]].sex : sex = (bool)stoi(s);
					cout << "�������޸ĺ�����䣨ȱʡ���� OK ��" << endl;
					cin >> s;
					s == "OK" ? age = book.AddressArray[resultArray[i]].age : age = stoi(s);
					cout << "�������޸ĺ�ĵ绰��ȱʡ���� OK ��" << endl;
					cin >> s;
					s == "OK" ? telephone = book.AddressArray[resultArray[i]].telephone : telephone = s;
					reviseContact(&book, resultArray[i], name, sex, age, telephone);
					cout << "�޸ĳɹ���" << endl;
				}
				catch (const char* msg) {
					cout << msg << endl;
					goto fof;
				}
				catch (exception) {
					cout << "�������������룡" << endl;
					goto fof;
				}
			}
			delete[] resultArray;
			break;
		}
		case 6:
			clearContact(&book);
			cout << "����ɹ���" << endl;
			break;
		case 0:
			cout << "��ӭ�´�ʹ��!" << endl;
			saveBook(&book);
			delete[] book.AddressArray;
			system("pause");
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}