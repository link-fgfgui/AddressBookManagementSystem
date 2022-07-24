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
			cout << "请您输入标准数字。" << endl;
			system("pause");
			system("cls");
			continue;
		}
		catch (std::out_of_range)
		{
			cout << "您的输入过大，超出了程序的接受范围" << endl;
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
				cout << "通讯录已满，添加失败！" << endl;
				break;
			}
			cout << "姓名？" << endl;
			cin >> name;
			cout << "性别？" << endl
				<< "1----男" << endl
				<< "0----女" << endl;
		sexErrorFlag:
			cin >> s;
			if (s == "1") { sex = 1; }
			else if (s == "0") { sex = 0; }
			else
			{
				cout << "您的输入不正确，请重新输入。" << endl;
				goto sexErrorFlag;
			}
			cout << "年龄？" << endl;
		ageErrorFlag:
			cin >> s;
			try
			{
				age = (short)stoi(s);
			}
			catch (std::exception) {
				cout << "异常！请重新输入。" << endl;
				goto ageErrorFlag;
			}
			cout << "电话？" << endl;
			cin >> telephone;
			addContact(name, sex, age, telephone, &book);
			break;
		}
		case 2:
			showContact(&book);
			break;
		case 3:
		{
			cout << "请输入姓名:(缺省输入0)" << endl;
			cin >> s;
			s == "0" ? name = "" : name = s;
			cout << "请输入电话:(缺省输入0)" << endl;
			cin >> s;
			s == "0" ? telephone = "" : telephone = s;
			int* resultArray = new int[MAX] {-1, -1};
			findContact(&book, resultArray, name, telephone);
			if (resultArray[0] == -1) { cout << "没有找到相关联系人" << endl; }
			else if (resultArray[1] == -1)
			{
				delContact(&book, resultArray[0]);
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "找到了多个联系人，请选择您要删除的联系人。(全删请输 all )" << endl;
				for (int i = 0; i < book.size; i++)
				{
					if (resultArray[i] == 0 && i != 0) { break; }
					cout << i << "\t" << book.AddressArray[resultArray[i]].name << "\t"
						<< (book.AddressArray[resultArray[i]].sex ? "男性" : "女性") << "\t"
						<< book.AddressArray[resultArray[i]].age << "岁" << "\t电话:"
						<< book.AddressArray[resultArray[i]].telephone << endl;
				}
			delErrorFlag:
				cin >> s;
				if (s == "all") {
					for (int i = book.size; i > 0; i--)
					{
						if (resultArray[i - 1] == 0 && (i - 1) != 0) { continue; }
						delContact(&book, resultArray[i - 1]);
					}cout << "删除成功！" << endl;
				}
				else
				{
					try
					{
						int i = stoi(s);
						if (resultArray[i] == 0 && i != 0) { throw "您的输入超出范围！请重新输入！"; }
						delContact(&book, resultArray[i]);
						cout << "删除成功！" << endl;
					}
					catch (const char* msg) {
						cout << msg << endl;
						goto delErrorFlag;
					}
					catch (exception) {
						cout << "出错！请重新输入！" << endl;
						goto delErrorFlag;
					}
				}
			}
			break;
		}
		case 4:
		{
			cout << "请输入姓名:(缺省输入0)" << endl;
			cin >> s;
			s == "0" ? name = "" : name = s;
			cout << "请输入电话:(缺省输入0)" << endl;
			cin >> s;
			s == "0" ? telephone = "" : telephone = s;
			int* resultArray = new int[MAX] {-1, -1};
			findContact(&book, resultArray, name, telephone);
			if (resultArray[0] == -1) { cout << "没有找到相关联系人" << endl; }
			else if (resultArray[1] == -1)
			{
				cout << book.AddressArray[resultArray[0]].name << "\t"
					<< (book.AddressArray[resultArray[0]].sex ? "男性" : "女性") << "\t"
					<< book.AddressArray[resultArray[0]].age << "岁" << "\t电话:"
					<< book.AddressArray[resultArray[0]].telephone << endl;
			}
			else
			{
				for (int i = 0; i < book.size; i++)
				{
					if (resultArray[i] == 0 && i != 0) { break; }
					cout << book.AddressArray[resultArray[i]].name << "\t"
						<< (book.AddressArray[resultArray[i]].sex ? "男性" : "女性") << "\t"
						<< book.AddressArray[resultArray[i]].age << "岁" << "\t电话:"
						<< book.AddressArray[resultArray[i]].telephone << endl;
				}
			}
			delete[] resultArray;
			break;
		}
		case 5:
		{
			cout << "请输入姓名:(缺省输入0)" << endl;
			cin >> s;
			s == "0" ? name = "" : name = s;
			cout << "请输入电话:(缺省输入0)" << endl;
			cin >> s;
			s == "0" ? telephone = "" : telephone = s;
			int* resultArray = new int[MAX] {-1, -1};
			findContact(&book, resultArray, name, telephone);
			if (resultArray[0] == -1) { cout << "没有找到相关联系人" << endl; }
			else if (resultArray[1] == -1)
			{
				cout << "请输入修改后的姓名（缺省输入 OK ）" << endl;
				cin >> s;
				s == "OK" ? name = book.AddressArray[resultArray[0]].name : name = s;
				cout << "请输入修改后的性别（缺省输入 OK ）" << endl;
			srf:
				cin >> s;
				if (!(s == "0" || s == "1")) { cout << "输入不正确！" << endl; goto srf; }
				s == "OK" ? sex = book.AddressArray[resultArray[0]].sex : sex = (bool)stoi(s);
				cout << "请输入修改后的年龄（缺省输入 OK ）" << endl;
				cin >> s;
				s == "OK" ? age = book.AddressArray[resultArray[0]].age : age = stoi(s);
				cout << "请输入修改后的电话（缺省输入 OK ）" << endl;
				cin >> s;
				s == "OK" ? telephone = book.AddressArray[resultArray[0]].telephone : telephone = s;
				reviseContact(&book, resultArray[0], name, sex, age, telephone);
				cout << "修改成功！" << endl;
			}
			else
			{
				cout << "找到了多个联系人，请选择您要修改的联系人。" << endl;
				for (int i = 0; i < book.size; i++)
				{
					if (resultArray[i] == 0 && i != 0) { break; }
					cout << i << "\t" << book.AddressArray[resultArray[i]].name << "\t"
						<< (book.AddressArray[resultArray[i]].sex ? "男性" : "女性") << "\t"
						<< book.AddressArray[resultArray[i]].age << "岁" << "\t电话:"
						<< book.AddressArray[resultArray[i]].telephone << endl;
				}
			fof:
				cin >> s;
				try
				{
					int i = stoi(s);
					if (resultArray[i] == 0 && i != 0) { throw "您的输入超出范围！请重新输入！"; }
					cout << "请输入修改后的姓名（缺省输入 OK ）" << endl;
					cin >> s;
					s == "OK" ? name = book.AddressArray[resultArray[i]].name : name = s;
					cout << "请输入修改后的性别（缺省输入 OK ）" << endl;
				srf2:
					cin >> s;
					if (!(s == "0" || s == "1")) { cout << "输入不正确！" << endl; goto srf2; }
					s == "OK" ? sex = book.AddressArray[resultArray[i]].sex : sex = (bool)stoi(s);
					cout << "请输入修改后的年龄（缺省输入 OK ）" << endl;
					cin >> s;
					s == "OK" ? age = book.AddressArray[resultArray[i]].age : age = stoi(s);
					cout << "请输入修改后的电话（缺省输入 OK ）" << endl;
					cin >> s;
					s == "OK" ? telephone = book.AddressArray[resultArray[i]].telephone : telephone = s;
					reviseContact(&book, resultArray[i], name, sex, age, telephone);
					cout << "修改成功！" << endl;
				}
				catch (const char* msg) {
					cout << msg << endl;
					goto fof;
				}
				catch (exception) {
					cout << "出错！请重新输入！" << endl;
					goto fof;
				}
			}
			delete[] resultArray;
			break;
		}
		case 6:
			clearContact(&book);
			cout << "清除成功！" << endl;
			break;
		case 0:
			cout << "欢迎下次使用!" << endl;
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