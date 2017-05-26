#include "groups.h"

groups::groups(int i)
{
	master = i + 1;
	string app;
	cout << "请输入您要创建群的账号：";
	cin >> app;
	id = app;
	cout << "请输入您要创建群的名称：";
	cin >> app;
	name = app;
}

groups::groups(int i, string aid,string aname)
{
	master = i + 1;
	name = aname;
	id = aid;
}

groups::groups(string aid, string aname)
{
	id = aid;
	name = aname;
	ng = 0; master = 1;
}

