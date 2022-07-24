#pragma once
#include <string>
constexpr int MAX = 1000;
using namespace std;
struct Contact
{
	string name;
	bool sex = 0;
	short age = 0;
	string telephone;
};
struct Address_book
{
	Contact* AddressArray = new Contact[MAX];
	int size = 0;
};
void loadconfig(Address_book* book);
void showMenu();
void addContact(string name, bool sex, short age, string telephone, Address_book* book);
void showContact(Address_book* book);
void findContact(Address_book* book, int returnArray[], string name, string telephone);
void delContact(Address_book* book, int j);
void reviseContact(Address_book* book, int j, string name, bool sex, short age, string telephone);
void clearContact(Address_book* book);
void saveBook(Address_book* book);