#include "ManageSystem.h"
#include <iostream>
string str = string(18, '*') + "\n" + string(5, '*') + " 1.��� " + string(5, '*') + "\n" + string(5, '*') + " 2.��ʾ " + string(5, '*') + "\n" + string(5, '*') + " 3.ɾ�� " + string(5, '*') + "\n" + string(5, '*') + " 4.���� " + string(5, '*') + "\n" + string(5, '*') + " 5.�޸� " + string(5, '*') + "\n" + string(5, '*') + " 6.��� " + string(5, '*') + "\n" + string(5, '*') + " 0.�˳� " + string(5, '*') + "\n" + string(18, '*') + "\n";
void showMenu()
{
	cout << str;
}