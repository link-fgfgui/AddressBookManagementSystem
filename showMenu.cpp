#include "ManageSystem.h"
#include <iostream>
string str = string(18, '*') + "\n" + string(5, '*') + " 1.添加 " + string(5, '*') + "\n" + string(5, '*') + " 2.显示 " + string(5, '*') + "\n" + string(5, '*') + " 3.删除 " + string(5, '*') + "\n" + string(5, '*') + " 4.查找 " + string(5, '*') + "\n" + string(5, '*') + " 5.修改 " + string(5, '*') + "\n" + string(5, '*') + " 6.清空 " + string(5, '*') + "\n" + string(5, '*') + " 0.退出 " + string(5, '*') + "\n" + string(18, '*') + "\n";
void showMenu()
{
	cout << str;
}