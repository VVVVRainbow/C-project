#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;
using namespace std;

class groups
{
public:
	vector<int> nums;//一个组的成员的n的记录器
	int ng;//记录是第几个群
	int master;//群主
	vector<int> adm;
	string name;//群名
	string id;//群账号
	groups(int);
	groups(int i, string,string aname);
	groups(string,string);
};

/*
群数
（第一个群的）群账号；群名；有几个成员；挨个成员； 群主n；有几个管理；挨个管理的n；\n
……
*/