#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;
using namespace std;

class wegroups
{
public:
	vector<int> nums;//一个组的成员的n的记录器
	int ng;//记录是第几个群
	int master;//群主
	string name;//群名
	string id;//群账号
	wegroups(int);
	wegroups(string, string);
};
