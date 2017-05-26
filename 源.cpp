#include <iostream>
#include <string>
#include "user.h"
#include "wegroups.h"
#include "weuser.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "groups.h"

using std::cout;
using  std::cin;

//文件的第一个数是当前用户数！

void QQ();//三个登陆
void wechat();
void WEIBO();
void JRQQ(int i);//登陆进入
void CGdatas(int);
void CGgroups(int);
void newgroups(int);
void addgroups(int i);
void entergroups(int i);
void CJgroups(int i, int k1);
void changegroupsname(int i, int k1);
void quitgroups(int i, int i1, int k1);
void quitgroups(int i, int k1);
void delgroups(int i, int k1);
void CGfriends(int);
void ZCQQ();
void DLQQ();
void addfriend(int );
void delfriend(int );
void fresh_user();
void fresh_groups();
void readgroups();
void readusers();
void readfriends();
void addgroupnums(int);
void changegroupsname(int i, int k1);

void readweusers();
void readwefriends();
void readwegroups();
void ZCwechat();
void DLwechat();
void JRwechat(int i);
void BANGDINGQQ(int i);
void CGwedatas(int i);
void CGwefriends(int i);
void CGwegroups(int i);
void addwefriend(int i);
void delwefriend(int i);
void newwegroups(int i);
void enterwegroups(int i);
void changewegroupsname(int i, int k1);
void quitwegroups(int i, int i1, int k1);
void quitwegroups(int i, int k1);
void delwegroups(int i, int k1);
void addwegroupnums(int j);

void WEIBO();
void JRWB(int i);//登陆进入
void CGWBdatas(int);
void CGWBfriends(int);
void ZCWB();
void DLWB();
void addWBfriend(int);
void delWBfriend(int);
void fresh_WBuser();
void readWBusers();
void readWBfriends();


//3个文件（暂时），1.user.txt 数量、储存账号7个内容  2.挨个 储存好友数量、好友信息（直接放是第几个就行了） 3.挨个储存 群组数量、群组信息
vector <user> v;
vector <groups> g;

vector <weuser> w;
vector <wegroups> wg;

int main() {
	
	/*
	群数
	（第一个群的）群账号；群名；有几个成员；挨个成员； 群主n；有几个管理；挨个管理的n；\n
	……
	*/
	readusers();
	readfriends();
	readgroups();
	readweusers();
	readwefriends();
	readWBusers();
	readWBfriends();	
	readwegroups();
	
	while (1)
	{
		system("cls");
		cout << "          欢迎使用          \n\n"
			"请选择您需要的服务：\n"
			"1.QQ\n"
			"2.微信\n"
			"3.微博\n" << endl;
		char p;
		cin >> p;
		switch (p)
		{
		case '1':
			QQ(); break;
		case '2':
			wechat(); break;
		case '3':
			WEIBO(); break;
		default:
			cout << "您的输入有误！" << endl;
		}
	}
}

void fresh_user()
{
	fstream suser("user.txt", ios::out);
	suser << (int)v.size() << endl;
	for (int i = 0; i <(int)v.size(); i++)
	{
		suser << v[i].id << " " << v[i].name << " " << v[i].PASSWORD << " " << v[i].birthday[0] << " " << v[i].birthday[1] << " " << v[i].birthday[2] << " " << v[i].location << endl;
	}
	suser.close();
}

void fresh_groups()
{
	fstream sgroups("groups.txt", ios::out);
	sgroups << (int)g.size() << endl;
	for (int i = 0; i <(int)g.size(); i++)
	{
		sgroups << g[i].id << " " << g[i].name << " " << (int)g[i].nums.size() << " ";
		for (int j = 0; j < (int)g[i].nums.size(); j++)
		{
			sgroups << g[i].nums[j] << " ";
		}
		sgroups << g[i].master << " " << (int)g[i].adm.size() << " ";
		for (int j = 0; j < (int)g[i].adm.size(); j++)
		{
			sgroups << g[i].adm[j] << " ";
		}
		sgroups << endl;
	}

	sgroups.close();
	/*v.~vector<user>();
	g.~vector<groups>();
	readusers();
	readfriends();
	readgroups();
*/
}

void fresh_friends()
{
	fstream sfriends("friends.txt", ios::out);
	for (int i = 0; i < (int)v.size(); i++)
	{
		sfriends << (int)v[i].friends.size() << " ";
		for (int j = 0; j < (int)v[i].friends.size(); j++)
		{
			sfriends << v[i].friends[j] << " ";
		}
		sfriends << endl;
	}
	sfriends.close();
}

void readusers()
{
	//***************
	int num = 0;//读取第一个数字，显示当前用户总数。
	string id; string name; string password; int y; int m; int d; string location;
	fstream vuser("user.txt");
	vuser >> num;
	for (int i = 0; i < num; i++)
	{
		vuser >> id >> name >> password >> y >> m >> d >> location;
		v.push_back(user(password, id, name, y, m, d, location));
	}
	vuser.close();
	for (int i = 0; i < (int)v.size(); i++)
	{
		v[i].n = i + 1;
	}
}

void readfriends()
{
	//********************
	fstream vfriends("friends.txt");
	//numf代表好友数
	int  numf = 0;
	int k = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		vfriends >> numf;
		for (int j = 0; j < numf; j++)
		{
			vfriends >> k;
			v[i].friends.push_back(k);
		}
	}
	vfriends.close();
}

void readgroups()
{
	//************************
	//读取groups文件
	int gnum = 0;//读取第一个数字，显示当前用户总数。
	string gid; string gname;  int pn;
	fstream vgroups("groups.txt");
	vgroups >> gnum;
	for (int i = 0; i < gnum; i++)
	{
		vgroups >> gid >> gname >> pn;//(成员个数)
		g.push_back(groups(gid, gname));
		int kkk;
		for (int j = 0; j < pn; j++)
		{
			vgroups >> kkk;
			g[i].nums.push_back(kkk);
			v[kkk - 1].groups.push_back(i + 1);
		}
		vgroups >> g[i].master;
		vgroups >> pn;//管理个数
		int admins;
		for (int j = 0; j < pn; j++)
		{
			vgroups >> admins;
			g[i].adm.push_back(admins);
		}
		g[i].ng = i + 1;
	}
	vgroups.close();
	//***********************
}

void QQ()
{
	char a2 = 'r';
	while(1)
	{
		system("cls");
		cout << "1.注册新用户\n"
			"2.登陆" << endl;
		char p='0';
		cin >> p;
		switch (p)
		{
		case '1':
			ZCQQ(); return;
		case '2':
			DLQQ(); return;
		default:
			cout << "您的输入有误！" << endl;
		}
	cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
	cin >> a2;
	if (a2 == 'r') { return; }
	}

}

void ZCQQ()
{
	system("cls");
	string PAWO; string sid; string sname; int s1, s2, s3; string slocation;
	cout << "注册QQ：\n";
	int i = 0; int j = 0;
	do {
		j = 0;
		cout << "请输入账号：";
		cin >> sid;
		for (; i <(int)v.size(); i++)
		{
			if (v[i].id == sid)
			{
				cout << "账号已被注册！请重新输入！";
				j = 1;
			}
			break;
		}
	}while(j);
	cout << "密码：";
		cin >> PAWO;
	cout << "昵称：";
		cin >> sname;
	cout << "出生日期： 年：";
		cin >> s1;
	cout << "月：";
		cin >> s2;
	cout << "日：";
		cin >> s3;
	cout << "所在地：";
		cin >> slocation;
		v.push_back( user(PAWO, sid, sname, s1, s2, s3, slocation));
	cout << "注册成功！\n";
	
	fresh_user();
	fresh_friends();

		cout <<
		"                      ********************************************             \n"
		"                      注册信息：                                               \n"
		"                      账号："; cout << v.back().id << "                            \n"
		"                      昵称："; cout << v.back().name << "                          \n"
		"                      密码："; cout << v.back().PASSWORD << "                          \n"
		"                      出生日期：" << v.back().birthday[0] << "年" << v.back().birthday[1] << "月" << v.back().birthday[2] << "日\n"
		"                      所在地：" << v.back().location << "                          \n"
		"                      *************按任意键进入QQ菜单*************             \n";
		system("pause");
		JRQQ((int)v.size() - 1);
}

void DLQQ()
{
	char a1='r';
	while (1)
	{
		system("cls");
		cout << "欢迎使用          \n\n"
			"请输入用户名：" << endl;
		string p;
		cin >> p;
		cout << "请输入密码：" << endl;
		string q;
		cin >> q;
		int i = 0;
		for (; i < (int)v.size(); i++)
		{
			if (v[i].id == p&&v[i].PASSWORD == q)
			{
				JRQQ(i);
				return;
			}
		}
		i = 0;
		for (; i <= (int)w.size(); i++)
		{
			if (w[i].id == p&&w[i].PASSWORD == q)
			{
				char qqq;
				cout << "您尚未开通QQ服务，是否需要开通？输入1确认开通" << endl;
				cin >> qqq;
				if (qqq = '1')
				{
					v.push_back(user(w[i].PASSWORD, w[i].id, w[i].name, w[i].birthday[0], w[i].birthday[1], w[i].birthday[2], w[i].location));
					JRQQ((int)v.size() - 1);
					return;
				}
			}
		}


		cout << "您的输入有误！" << endl;
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		char a2;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

//i是可以等于0的那种

void JRQQ(int i)
{
		system("cls");
		cout <<
			"                      ********************************************             \n"
			"                      我的信息：                                               \n"
			"                      账号："; cout << v[i].id << "                            \n"
			"                      昵称："; cout << v[i].name << "                          \n"
			"                      出生日期：" << v[i].birthday[0] << "年" << v[i].birthday[1] << "月" << v[i].birthday[2] << "日\n"
			"                      所在地：" << v[i].location << "                          \n"
			"                      *************按任意键进入QQ菜单*************             \n";
		system("pause");
		
		while (1)
		{

			system("cls");
			cout <<
				"1.查看/更改 好友\n"
				"2.查看/更改 群组\n"
				"3.查看/更改 资料\n"
				"4.退出登录\n"
				"请选择功能：";
			char p;
			cin >> p;
			switch (p)
			{
			case '1':
				CGfriends(i); break;
			case '2':
				CGgroups(i); break;
			case '3':
				CGdatas(i); break;
			case '4':
				return;
			default:
				char a2;
				cout << "您的输入有误！输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
				cin >> a2;
				if (a2 == 'r') { return; }
			}
		}
}

void CGfriends(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"好友列表：\n" << endl;
		for (int j = 0; j < (int)v[i].friends.size(); j++)
		{
			cout <<
				"*******************好友" << j + 1 << ":*******************\n"
				"账号:" << v[v[i].friends[j] - 1].id << "\n"
				"昵称:" << v[v[i].friends[j] - 1].name << "\n"
				"出生日期：" << v[v[i].friends[j] - 1].birthday[0] << "年" << v[v[i].friends[j] - 1].birthday[1] << "月" << v[v[i].friends[j] - 1].birthday[2] << "日\n"
				"所在地：" << v[v[i].friends[j] - 1].location << "\n"
				"********************************************\n";
		}
		cout <<
			"1.添加好友\n"
			"2.删除好友\n"
			"3.返回上级菜单" << endl;
		char a3; cin >> a3;
		switch (a3)
		{
		case '1':
			addfriend(i); break;
		case '2':
			delfriend(i); break;
		case '3':
			return;
		}
	}
}

void addfriend(int i)
{
	while (1)
	{
		cout << "请输入您想添加的好友账号：";
		string a4;
		cin >> a4;
		int y = 0;
		for (; y < (int)v.size(); y++)
		{
			if (v[y].id == a4)
			{
				v[i].friends.push_back(v[y].n);
				cout << "添加成功！" << endl;
				fresh_friends();
				return;
			}
		}
			cout << "您的输入有误！" << endl;
		char a2;
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void delfriend(int i)
{
	char a6='r';
	while(1)
	{
		cout << "请输入您想删除的好友标号（好友列表中显示）：";
		int a6;
		cin >> a6;
		if (a6 <= (int)v[i].friends.size())
		{
			v[i].friends.erase(v[i].friends.begin() + a6 - 1);
			cout << "删除成功！" << endl;
			fresh_friends();
			return;
		}
		else
		{
			cout << "您的输入有误！";
		}
		
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a6;
		if (a6 == 'r') { return; }
	} 
}

void CGgroups(int i)
{
	system("cls");
	cout <<
		"群列表：\n" << endl;
	for (int j = 0; j < (int)v[i].groups.size(); j++)
	{
		cout <<
			"*******************群" << j + 1 << ":*******************\n"
			"账号:" << g[v[i].groups[j] - 1].id << "\n"
			"名称:" << g[v[i].groups[j] - 1].name << "\n"
			"********************************************\n";
	}
	while (1)
	{
		char a6;
		cout << "1.申请群\n"
			"2.加入群\n"
			"3.对已有群操作\n";
		cin >> a6;
		switch (a6)
		{
		case '1':
			newgroups(i); return;
		case '2':
			addgroups(i); return;
		case '3':
			entergroups(i); return;
		default:
			char a2;
			cout << "您的输入有误！输入r返回上一级菜单，输入其他字符重新输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void newgroups(int i)
{
	g.push_back(groups(i));
	g[(int)g.size() - 1].ng = (int)g.size();
	g[(int)g.size() - 1].nums.push_back(i + 1);
	v[i].groups.push_back((int)g.size());
	cout << "创建成功！" << endl;
	fresh_groups();
}

void addgroups(int i)
{
	string a4;
	cout << "请输入您要添加的群账号：";
	cin >> a4;
	for (int a = 0; a < (int)g.size(); a++)
	{
		if (a4 == g[a].id)
		{
			g[a].nums.push_back(i + 1);
			v[i].groups.push_back(g[a].ng);
			cout << "添加成功！" << endl;
			fresh_groups();
			return;
		}
	}
}

void entergroups(int i)
{
	cout << "请选择要操作的群标号（群列表中显示）：\n";
	int k1;
	cin >> k1;
	system("cls");
	cout <<
		"群成员列表：\n" << endl;
	for (int j = 0; j < (int)g[v[i].groups[k1 - 1] - 1].nums.size(); j++)
	{
		bool k8 = 0;
		//***
		for (int k2 = 0; k2 < (int)g[v[i].groups[k1 - 1] - 1].adm.size(); k2++)
		{
			if (v[g[v[i].groups[k1 - 1] - 1].nums[j] - 1].n == g[v[i].groups[k1 - 1] - 1].adm[k2])
				k8 = 1;
		}
		//***
		if (k8)
			cout << "****************群成员" << j + 1 << "(管理):****************\n";
		else
			cout << "*******************群成员" << j + 1 << ":*******************\n";

		cout << "账号:" << v[g[v[i].groups[k1 - 1] - 1].nums[j] - 1].id << "\n"
			"昵称:" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].name << "\n"
			"出生日期：" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].birthday[0] << "年" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].birthday[1] << "月" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].birthday[2] << "日\n"
			"所在地：" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].location << "\n"
			"********************************************\n";
	}
	//检查本人是不是管理
	bool k3 = 0;
	for (int k2 = 0; k2 < (int)g[v[i].groups[k1 - 1]-1].adm.size(); k2++)
	{
		if (g[v[i].groups[k1 - 1]-1].adm[k2] == v[i].n)
			k3 = 1;
	}
	
	char k4;
	if (g[v[i].groups[k1 - 1]-1].master == v[i].n)//群主 菜单： 添加 踢人 提升为管理 解散 修改群昵称
	{
		cout <<
			"1.解散该群\n"
			"2.添加群成员\n"
			"3.踢出群成员\n"
			"4.修改群名称\n"
			"5.任命管理\n"
			"6.创建讨论组\n"
			"7.返回上级菜单\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			delgroups(i, k1 - 1); break;
		case '2':
			addgroupnums(v[i].groups[k1 - 1]-1); break;
		case '3':
			int a5;
			cout << "输入您要踢出的成员序号（群成员列表中有）：";
			cin >> a5;
			quitgroups(i, g[v[i].groups[k1 - 1] - 1].nums[a5 - 1] - 1, k1 - 1);
			cout << "删除成功！" << endl;
			fresh_groups();
			break;
		case '4':
			changegroupsname(i, k1); break;
		case '5':
			int a8;
			cout << "输入您要任命管理的成员序号（群成员列表中有）：";
			cin >> a8;
			g[v[i].groups[k1 - 1] - 1].adm.push_back(v[g[v[i].groups[k1 - 1] - 1].nums[a8 - 1] - 1].n);
			fresh_groups(); 
			break;
		case '6':
			CJgroups(i,k1-1);
		case '7':
			return;
		default:
			char a2;
			cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
	else if (k3)//群管理的菜单   //添加 踢人 退出 修改群昵称
	{
		cout <<
			"1.退出群\n"
			"2.添加群成员\n"
			"3.踢出群成员\n"
			"4.修改群名称\n"
			"5.创建讨论组\n"
			"6.返回上级菜单\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			quitgroups(i, k1 - 1); break;
		case '2':
			addgroupnums(v[i].groups[k1 - 1]-1); break;//群下标
		case '3':
			int a5;
			cout << "输入您要踢出的成员序号（群成员列表中有）：";
			cin >> a5;
			quitgroups(i,g[v[i].groups[k1 - 1] - 1].nums[a5 - 1] - 1, k1 - 1);
			cout << "删除成功！" << endl;
		case '4':
			changegroupsname(i, k1);
		case '5':
			CJgroups(i, k1 - 1);
		case '6':
			return;
		default:
			char a2;
			cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}

	}
	else//普通成员菜单：  退出  
	{
		cout <<
			"1.退出群\n"
			"2.创建讨论组\n"
			"3.返回上级菜单\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			quitgroups(i, k1 - 1);
		case '2':
			CJgroups(i, k1 - 1);
		case '3':
			return;
		default:
			char a2;
			cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void CJgroups(int i, int k1)
{
	string pad;
	int k = v[i].groups[k1] - 1;//k 是群的下标
	cout << "请输入子群id：";
	cin >> pad;
	int iddd;
	g.push_back(groups(i,pad,g[k].name+"的子群"));
	v[i].groups.push_back((int)g.size() - 1);
	while (1)
	{
		cout << "请选择要加入的原群成员编号：";
		cin >> iddd;
		if (iddd >= 1 && iddd <= (int)g[k].nums.size())
		{
			g[(int)g.size() - 1].nums.push_back(g[k].nums[iddd - 1]);
			v[g[k].nums[iddd - 1] - 1].groups.push_back((int)g.size() - 1);
		}
		else
		{
			cout << "输入有误！输入r停止添加，输入其他字符继续添加！" << endl;
			char c2;
			cin >> c2;
			if (c2 == 'r')
				return;
		}
	}
	fresh_groups();
}

void changegroupsname(int i, int k1)
{
	string a4;
	cout << "请输入群新名称：";
	cin >> a4;
	g[v[i].groups[k1 - 1] - 1].name = a4;
	fresh_groups();
}

void quitgroups(int i, int i1,int k1)
{
	int k = v[i].groups[k1] - 1;//k 是群的下标
	int k2 = 0;
	for (; k2 < (int)v[i1].groups.size(); k2++)
	{
		if (v[i1].groups[k2] == k + 1)
			break;
	}
	v[i1].groups.erase(v[i1].groups.begin() + k2);				//用户列表里清除群
	int a7;
	for (a7 = 0; a7 < (int)g[k].nums.size(); a7++)
	{
		if (g[k].nums[a7] == v[i1].n)
			break;
	}
	g[k].nums.erase(g[k].nums.begin() + a7);//群列表里清除用户
	fresh_groups();//更新文件
}

void quitgroups(int i, int k1)//n=i的user 离开 该用户列表groups[k1]    g[v[i].groups[k1]].ng 是自己的标号   
{
	int k = v[i].groups[k1] - 1;//k 是群的下标
	v[i].groups.erase(v[i].groups.begin() + k1);//用户列表里清除群
	int a7;
	for (a7 = 0; a7 < (int)g[k].nums.size(); a7++)
	{
		if (g[k].nums[a7] == v[i].n)
			break;
	}
	g[k].nums.erase(g[k].nums.begin()+ a7);//群列表里清除用户
	fresh_groups();//更新文件
}

void delgroups(int i,int k1)//删除群
{
	int k = v[i].groups[k1] - 1;//k是下标
	for (int k3 = 0; k3 < (int)g[k].nums.size(); k3++)//通过群寻找用户  在用户里删除群
	{
		int k4;
		for (k4 = 0; k4 < (int)v[g[k].nums[k3] - 1].groups.size(); k4++)
		{
			if (v[g[k].nums[k3] - 1].groups[k4] == g[k].ng)
				break;
		}
		v[g[k].nums[k3] - 1].groups.erase(v[g[k].nums[k3] - 1].groups.begin() + k4);
	}
	g.erase(g.begin() + g[k].ng - 1);
	/*for (int ax = k; ax < (int)g.size(); ax++)//为每一个 删除的群的 后面的每个群
	{
		g[ax].ng--;   //标号减一
		for (int cx = 0; cx < (int)g[k].nums.size(); cx++)//为这个群的每一个成员
		{
			for (int zx = 0; zx < (int)v[g[k].nums[cx] - 1].groups.size(); zx++)//找到这个成员的这个群 标号减一
			{
				if (v[g[k].nums[cx] - 1].groups[zx] == g[ax].ng + 1)
					v[g[k].nums[cx] - 1].groups[zx]--;
				break;
			}
		}
	}*/
	fresh_groups();
	v.~vector<user>();
	g.~vector<groups>();
	readusers();
	readfriends();
	readgroups();
}

void addgroupnums(int j)
{
	string c9;
	char a2;
	while (1)
	{
		cout << "请输入您要添加的用户账号：\n";
		cin >> c9;
		for (int x = 0; x < (int)v.size(); x++)
		{
			if (v[x].id == c9)
			{
				v[x].groups.push_back(g[j].ng);
				g[j].nums.push_back(v[x].n);
				fresh_groups();
				cout << "添加成功！" << endl;
				system("pause");
				return;
			}
		}
			{
				cout << "输入有误，输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
				cin >> a2;
				if (a2 == 'r') { return; }
			}
	}
}

void CGdatas(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"1.修改密码\n"
			"2.修改昵称\n"
			"3.修改出生日期\n"
			"4.修改所在地\n";
		char a;
		cin >> a;
		string newx;
		switch (a)
		{
		case '1':
			cout << "请输入新密码：";
			cin >> newx;
			v[i].PASSWORD = newx;
			cout << "修改成功！";
			fresh_user();
			return;
		case '2':
			cout << "请输入新昵称：";
			cin >> newx;
			v[i].name = newx;
			cout << "修改成功！";
			fresh_user();
			return;
		case '3':
			cout << "请输入新出生日期：\n";
			int q[3];
			cout << "请输入年：";
			cin >> q[0];
			cout << "请输入月：";
			cin >> q[1];
			cout << "请输入日：";
			cin >> q[2];
			v[i].birthday[0] = q[0];
			v[i].birthday[1] = q[1];
			v[i].birthday[2] = q[2];
			cout << "修改成功！";
			fresh_user();
			return;
		case '4':
			cout << "请输入所在地：";
			cin >> newx;
			v[i].location = newx;
			cout << "修改成功！";
			fresh_user();
			return;
		default:
			cout << "您的输入有误！输入r返回上一级，输入其他字符重新选择！" << endl;
			char c;
			cin >> c;
			if (c == 'r') { return; }
		}
	}
}

//*******************************

void fresh_weuser()
{
	fstream sweuser("weuser.txt", ios::out);
	sweuser << (int)w.size() << endl;
	for (int i = 0; i <(int)w.size(); i++)
	{
		sweuser << w[i].id << " " << w[i].name << " " << w[i].PASSWORD << " " << w[i].birthday[0] << " " << w[i].birthday[1] << " " << w[i].birthday[2] << " " << w[i].location<<" "<< w[i].QQn << endl;
	}
	sweuser.close();
}

void fresh_wegroups()
{
	fstream swegroups("wegroups.txt", ios::out);
	swegroups << (int)wg.size() << endl;
	for (int i = 0; i <(int)wg.size(); i++)
	{
		swegroups << wg[i].id << " " << wg[i].name << " " << (int)wg[i].nums.size() << " ";
		for (int j = 0; j < (int)wg[i].nums.size(); j++)
		{
			swegroups << wg[i].nums[j] << " ";
		}
		swegroups << endl;
	}

	swegroups.close();
	/*w.~vector<weuser>();
	g.~vector<wegroups>();
	readweusers();
	readfriends();
	readwegroups();
	*/
}

void fresh_wefriends()
{
	fstream sfriends("friends.txt", ios::out);
	for (int i = 0; i < (int)w.size(); i++)
	{
		sfriends << (int)w[i].friends.size() << " ";
		for (int j = 0; j < (int)w[i].friends.size(); j++)
		{
			sfriends << w[i].friends[j] << " ";
		}
		sfriends << endl;
	}
	sfriends.close();
}

void readweusers()//QQid的更新
{
	//***************
	int num = 0;//读取第一个数字，显示当前用户总数。
	string id; string name; string password; int y; int m; int d; string location; int QQn;
	fstream vweuser("weuser.txt");
	vweuser >> num;
	for (int i = 0; i < num; i++)
	{
		vweuser >> id >> name >> password >> y >> m >> d >> location>>QQn;
		w.push_back(weuser(password, id, name, y, m, d, location, QQn));
	}
	vweuser.close();
	for (int i = 0; i < (int)w.size(); i++)
	{
		w[i].n = i + 1;
	}
}

void readwefriends()
{
	//********************
	fstream wfriends("wefriends.txt");
	//numf代表好友数
	int  numf = 0;
	int k = 0;
	for (int i = 0; i < (int)w.size(); i++)
	{
		wfriends >> numf;
		for (int j = 0; j < numf; j++)
		{
			wfriends >> k;
			w[i].friends.push_back(k);
		}
	}
	wfriends.close();
}

void readwegroups()
{
	//************************
	//读取wegroups文件
	int gnum = 0;//读取第一个数字，显示当前用户总数。
	string gid; string gname;  int pn;
	fstream vwegroups("wegroups.txt");
	vwegroups >> gnum;
	for (int i = 0; i < gnum; i++)
	{
		vwegroups >> gid >> gname >> pn;//(成员个数)
		wg.push_back(wegroups(gid, gname));
		int kkk;
		for (int j = 0; j < pn; j++)
		{
			vwegroups >> kkk;
			wg[i].nums.push_back(kkk);
			w[kkk - 1].groups.push_back(i + 1);
		}
		vwegroups >> wg[i].master;
		wg[i].ng = i + 1;
	}
	vwegroups.close();
	//***********************
}

void wechat()
{
	char a2 = 'r';
	while (1)
	{
		system("cls");
		cout << "1.注册新用户\n"
			"2.登陆" << endl;
		char p = '0';
		cin >> p;
		switch (p)
		{
		case '1':
			ZCwechat(); return;
		case '2':
			DLwechat(); return;
		default:
			cout << "您的输入有误！" << endl;
		}
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void ZCwechat()
{
	system("cls");
	string PAWO; string sid; string sname; int s1, s2, s3; string slocation;
	cout << "注册wechat：\n";
	int i = 0; int j = 0;
	do {
		j = 0;
		cout << "请输入账号：";
		cin >> sid;
		for (; i <(int)w.size(); i++)
		{
			if (w[i].id == sid)
			{
				cout << "账号已被注册！请重新输入！";
				j = 1;
			}
			break;
		}
	} while (j);
	cout << "密码：";
	cin >> PAWO;
	cout << "昵称：";
	cin >> sname;
	cout << "出生日期： 年：";
	cin >> s1;
	cout << "月：";
	cin >> s2;
	cout << "日：";
	cin >> s3;
	cout << "所在地：";
	cin >> slocation;
	w.push_back(weuser(PAWO, sid, sname, s1, s2, s3, slocation));
	cout << "注册成功！\n";

	fresh_weuser();
	fresh_wefriends();

	cout <<
		"                      ********************************************             \n"
		"                      注册信息：                                               \n"
		"                      账号："; cout << w.back().id << "                            \n"
		"                      昵称："; cout << w.back().name << "                          \n"
		"                      密码："; cout << w.back().PASSWORD << "                          \n"
		"                      出生日期：" << w.back().birthday[0] << "年" << w.back().birthday[1] << "月" << w.back().birthday[2] << "日\n"
		"                      所在地：" << w.back().location << "                          \n"
		"                      *************按任意键进入wechat菜单*************             \n";
	system("pause");
	JRwechat((int)w.size() - 1);
}

void DLwechat()
{
	char a1 = 'r';
	while (1)
	{
		system("cls");
		cout << "欢迎使用          \n\n"
			"请输入用户名：" << endl;
		string p;
		cin >> p;
		cout << "请输入密码：" << endl;
		string q;
		cin >> q;
		int i = 0;
		for (; i < (int)w.size(); i++)
		{
			if (w[i].id == p&&w[i].PASSWORD == q)
			{
				JRwechat(i);
				return;
			}
		}
		i = 0;
		for (; i < (int)v.size(); i++)
		{
			if (v[i].id == p&&v[i].PASSWORD == q)
			{
				char qqq;
				cout << "您尚未开通wechat服务，是否需要开通？输入1确认开通" << endl;
				cin >> qqq;
				if (qqq = '1')
				{
					string wechatid;
					cout << "请输入您的微信号：" << endl;
					cin >> wechatid;
					w.push_back(weuser(v[i].PASSWORD, wechatid, v[i].name, v[i].birthday[0], v[i].birthday[1], v[i].birthday[2], v[i].location, i + 1));
					fresh_weuser();
					JRwechat((int)w.size() - 1);
					return;
				}
			}
		}
		if (i = (int)w.size())
			cout << "您的输入有误！" << endl;
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		char a2;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

//i是可以等于0的那种

void JRwechat(int i)
{
	system("cls");
	cout <<
		"                      ********************************************             \n"
		"                      我的信息：                                               \n"
		"                      账号："; cout << w[i].id << "                            \n"
		"                      昵称："; cout << w[i].name << "                          \n"
		"                      出生日期：" << w[i].birthday[0] << "年" << w[i].birthday[1] << "月" << w[i].birthday[2] << "日\n"
		"                      所在地：" << w[i].location << "                          \n"
		"                      *************按任意键进入wechat菜单*************             \n";
	system("pause");

	while (1)
	{

		system("cls");
		cout <<
			"1.查看/更改 好友\n"
			"2.查看/更改 群组\n"
			"3.查看/更改 资料\n"
			"4.绑定QQ\n"
			"5.退出登录\n"
			"请选择功能：";
		char p;
		cin >> p;
		switch (p)
		{
		case '1':
			CGwefriends(i); break;
		case '2':
			CGwegroups(i); break;
		case '3':
			CGwedatas(i); break;
		case '4':
			BANGDINGQQ(i); break;
				break;
		case '5':
			return;
		default:
			char a2;
			cout << "您的输入有误！输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void BANGDINGQQ(int i)
{

	if (w[i].QQn == -1) 
	{
		string QQQQ; string QQQQpass;
		cout << "请输入您想绑定的QQ号：";
		cin >> QQQQ;
		cout << "请输入密码：";
		cin >> QQQQpass;
		for (int cad = 0; cad < (int)v.size(); cad++)
		{
			if (v[cad].id == QQQQ&&v[cad].PASSWORD == QQQQpass)
			{
				w[i].QQn = cad + 1;
				cout << "绑定成功！";
				fresh_weuser();
				system("pause");
				return;
			}
		}
		cout << "您的输入有误！" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "操作失败！您已绑定了" << v[w[i].QQn - 1].id << "！" << endl;
		system("pause");
	}

}

void CGwefriends(int i)
{
	system("cls");
	cout <<
		"好友列表：\n" << endl;
	for (int j = 0; j <(int)w[i].friends.size(); j++)
	{
		cout <<
			"*******************好友" << j + 1 << ":*******************\n"
			"账号:" << w[w[i].friends[j] - 1].id << "\n"
			"昵称:" << w[w[i].friends[j] - 1].name << "\n"
			"出生日期：" << w[w[i].friends[j] - 1].birthday[0] << "年" << w[w[i].friends[j] - 1].birthday[1] << "月" << w[w[i].friends[j] - 1].birthday[2] << "日\n"
			"所在地：" << w[w[i].friends[j] - 1].location << "\n"
			"********************************************\n";
	}
	cout <<
		"1.添加好友\n"
		"2.删除好友\n"
		"3.返回上级菜单" << endl;
	char a3; cin >> a3;
	switch (a3)
	{
	case '1':
		addwefriend(i);
	case '2':
		delwefriend(i);
	case '3':
		return;
	}
}

void addwefriend(int i)
{
	while (1)
	{
		bool q=0;
		int t = 0;
		vector<int> tt;
		cout << "推荐好友：\n";//他的qq好友中 注册了微信并没有成为他好友的
		for (int kkkk = 0; kkkk < (int)v[w[i].QQn - 1].friends.size(); kkkk++)//对每一个他的qq好友
		{
			for (int ffff = 0; ffff < (int)w[i].friends.size(); ffff++)	//首先不是他的微信好友
			{
				if (w[w[i].friends[ffff] - 1].QQn != v[w[i].QQn - 1].friends[kkkk])
					q = 1;
			}
			if (q)
			{
				for (int wwww = 0; wwww < (int)w.size(); wwww++)//对每一个微信用户
					if (w[wwww].QQn == v[w[i].QQn - 1].friends[kkkk])
					{
						t++;
						tt.push_back(wwww);//wwww是微信【】下角标
					}
				cout << t << ":" << "您的QQ好友：" << v[v[w[i].QQn - 1].friends[kkkk] - 1].name << endl;
			
			}
		}




		cout << "输入对应标号添加好友，输入其他数字手动输入好友账号\n";
		int o;
		cin >> o;
		if (1 <= o&&o <= t)
		{
			w[i].friends.push_back(w[tt[o - 1]].n);
			cout << "添加成功！" << endl;
			fresh_wefriends();
		}

		cout << "请输入您想添加的好友账号：";
		string a4;
		cin >> a4;
		int y = 0;
		for (; y < (int)w.size(); y++)
		{
			if (w[y].id == a4)
			{
				w[i].friends.push_back(w[y].n);
				cout << "添加成功！" << endl;
				fresh_wefriends();
				return;
			}
		}
		cout << "您的输入有误！" << endl;
		char a2;
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void delwefriend(int i)
{
	char a6 = 'r';
	while (1)
	{
		cout << "请输入您想删除的好友标号（好友列表中显示）：";
		int a6;
		cin >> a6;
		if (a6 <= (int)w[i].friends.size())
		{
			w[i].friends.erase(w[i].friends.begin() + a6 - 1);
			cout << "删除成功！" << endl;
			fresh_wefriends();
			return;
		}
		else
		{
			cout << "您的输入有误！";
		}

		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a6;
		if (a6 == 'r') { return; }
	}
}

void CGwegroups(int i)
{
	system("cls");
	cout <<
		"群列表：\n" << endl;
	for (int j = 0; j < (int)w[i].groups.size(); j++)
	{
		cout <<
			"*******************群" << j + 1 << ":*******************\n"
			"账号:" << wg[w[i].groups[j] - 1].id << "\n"
			"名称:" << wg[w[i].groups[j] - 1].name << "\n"
			"********************************************\n";
	}
	while (1)
	{
		char a6;
		cout << "1.申请群\n"
			"2.对已有群操作\n";
		cin >> a6;
		switch (a6)
		{
		case '1':
			newwegroups(i); return;
		case '2':
			enterwegroups(i); return;
		default:
			char a2;
			cout << "您的输入有误！输入r返回上一级菜单，输入其他字符重新输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void newwegroups(int i)
{
	wg.push_back(wegroups(i));
	wg[(int)wg.size() - 1].ng = (int)wg.size();
	wg[(int)wg.size() - 1].nums.push_back(i + 1);
	w[i].groups.push_back((int)wg.size());
	cout << "创建成功！" << endl;
	fresh_wegroups();
}

void enterwegroups(int i)
{
	cout << "请选择要操作的群标号（群列表中显示）：\n";
	int k1;
	cin >> k1;
	system("cls");
	cout <<
		"群成员列表：\n" << endl;
	for (int j = 0; j < (int)wg[w[i].groups[k1 - 1] - 1].nums.size(); j++)
	{

	
			cout << "*******************群成员" << j + 1 << ":*******************\n";

		cout << "账号:" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].id << "\n"
			"昵称:" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].name << "\n"
			"出生日期：" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].birthday[0] << "年" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].birthday[1] << "月" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].birthday[2] << "日\n"
			"所在地：" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].location << "\n"
			"********************************************\n";
	}
	//检查本人是不是管理
	char k4;
	if (wg[w[i].groups[k1 - 1] - 1].master == w[i].n)//群主 菜单： 添加 踢人 提升为管理 解散 修改群昵称
	{
		cout <<
			"1.解散该群\n"
			"2.添加群成员\n"
			"3.踢出群成员\n"
			"4.修改群名称\n"
			"5.返回上级菜单\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			delwegroups(i, k1 - 1); break;
		case '2':
			addwegroupnums(w[i].groups[k1 - 1] - 1); break;
		case '3':
			int a5;
			cout << "输入您要踢出的成员序号（群成员列表中有）：";
			cin >> a5;
			quitwegroups(i, wg[w[i].groups[k1 - 1] - 1].nums[a5 - 1] - 1, k1 - 1);
			cout << "删除成功！" << endl;
			fresh_wegroups();
			break;
		case '4':
			changewegroupsname(i, k1); break;
		case '5':
			return;
		default:
			char a2;
			cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
	
	else//普通成员菜单：  退出  
	{
		cout <<
			"1.退出群\n"
			"2.返回上级菜单\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			quitwegroups(i, k1 - 1);
		case '2':
			return;
		default:
			char a2;
			cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void changewegroupsname(int i, int k1)
{
	string a4;
	cout << "请输入群新名称：";
	cin >> a4;
	wg[w[i].groups[k1 - 1] - 1].name = a4;
	fresh_wegroups();
}

void quitwegroups(int i, int i1, int k1)
{
	int k = w[i].groups[k1] - 1;//k 是群的下标
	int k2 = 0;
	for (; k2 < (int)w[i1].groups.size(); k2++)
	{
		if (w[i1].groups[k2] == k + 1)
			break;
	}
	w[i1].groups.erase(w[i1].groups.begin() + k2);				//用户列表里清除群
	int a7;
	for (a7 = 0; a7 < (int)wg[k].nums.size(); a7++)
	{
		if (wg[k].nums[a7] == w[i1].n)
			break;
	}
	wg[k].nums.erase(wg[k].nums.begin() + a7);//群列表里清除用户
	fresh_wegroups();//更新文件
}

void quitwegroups(int i, int k1)//n=i的weuser 离开 该用户列表wegroups[k1]    wg[w[i].groups[k1]].nwg 是自己的标号   
{
	int k = w[i].groups[k1] - 1;//k 是群的下标
	w[i].groups.erase(w[i].groups.begin() + k1);//用户列表里清除群
	int a7;
	for (a7 = 0; a7 < (int)wg[k].nums.size(); a7++)
	{
		if (wg[k].nums[a7] == w[i].n)
			break;
	}
	wg[k].nums.erase(wg[k].nums.begin() + a7);//群列表里清除用户
	fresh_wegroups();//更新文件
}

void delwegroups(int i, int k1)//删除群
{
	int k = w[i].groups[k1] - 1;//k是下标
	for (int k3 = 0; k3 < (int)wg[k].nums.size(); k3++)//通过群寻找用户  在用户里删除群
	{
		int k4;
		for (k4 = 0; k4 < (int)w[wg[k].nums[k3] - 1].groups.size(); k4++)
		{
			if (w[wg[k].nums[k3] - 1].groups[k4] == wg[k].ng)
				break;
		}
		w[wg[k].nums[k3] - 1].groups.erase(w[wg[k].nums[k3] - 1].groups.begin() + k4);
	}
	wg.erase(wg.begin() + wg[k].ng - 1);
	/*for (int ax = k; ax < (int)wg.size(); ax++)//为每一个 删除的群的 后面的每个群
	{
	wg[ax].nwg--;   //标号减一
	for (int cx = 0; cx < (int)wg[k].nums.size(); cx++)//为这个群的每一个成员
	{
	for (int zx = 0; zx < (int)w[wg[k].nums[cx] - 1].groups.size(); zx++)//找到这个成员的这个群 标号减一
	{
	if (w[wg[k].nums[cx] - 1].groups[zx] == wg[ax].nwg + 1)
	w[wg[k].nums[cx] - 1].groups[zx]--;
	break;
	}
	}
	}*/
	fresh_wegroups();
	w.~vector<weuser>();
	wg.~vector<wegroups>();
	readweusers();
	readwefriends();
	readwegroups();
}

void addwegroupnums(int j)
{
	string c9;
	char a2;
	while (1)
	{
		cout << "请输入您要添加的用户账号：\n";
		cin >> c9;
		for (int x = 0; x < (int)w.size(); x++)
		{
			if (w[x].id == c9)
			{
				w[x].groups.push_back(wg[j].ng);
				wg[j].nums.push_back(w[x].n);
				fresh_wegroups();
				cout << "添加成功！" << endl;
				system("pause");
				return;
			}
		}
		{
			cout << "输入有误，输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void CGwedatas(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"1.修改密码\n"
			"2.修改昵称\n"
			"3.修改出生日期\n"
			"4.修改所在地\n";
		char a;
		cin >> a;
		string newx;
		switch (a)
		{
		case '1':
			cout << "请输入新密码：";
			cin >> newx;
			w[i].PASSWORD = newx;
			cout << "修改成功！";
			fresh_weuser();
			return;
		case '2':
			cout << "请输入新昵称：";
			cin >> newx;
			w[i].name = newx;
			cout << "修改成功！";
			fresh_weuser();
			return;
		case '3':
			cout << "请输入新出生日期：\n";
			int q[3];
			cout << "请输入年：";
			cin >> q[0];
			cout << "请输入月：";
			cin >> q[1];
			cout << "请输入日：";
			cin >> q[2];
			w[i].birthday[0] = q[0];
			w[i].birthday[1] = q[1];
			w[i].birthday[2] = q[2];
			cout << "修改成功！";
			fresh_weuser();
			return;
		case '4':
			cout << "请输入所在地：";
			cin >> newx;
			w[i].location = newx;
			cout << "修改成功！";
			fresh_weuser();
			return;
		default:
			cout << "您的输入有误！输入r返回上一级，输入其他字符重新选择！" << endl;
			char c;
			cin >> c;
			if (c == 'r') { return; }
		}
	}
}




vector <user> wb;

void fresh_WBuser()
{
	fstream swbuser("wbuser.txt", ios::out);
	swbuser << (int)wb.size() << endl;
	for (int i = 0; i <(int)wb.size(); i++)
	{
		swbuser << wb[i].id << " " << wb[i].name << " " << wb[i].PASSWORD << " " << wb[i].birthday[0] << " " << wb[i].birthday[1] << " " << wb[i].birthday[2] << " " << wb[i].location << endl;
	}
	swbuser.close();
}

void fresh_WBfriends()
{
	fstream swbfriends("friends.txt", ios::out);
	for (int i = 0; i < (int)wb.size(); i++)
	{
		swbfriends << (int)wb[i].friends.size() << " ";
		for (int j = 0; j < (int)wb[i].friends.size(); j++)
		{
			swbfriends << wb[i].friends[j] << " ";
		}
		swbfriends << endl;
	}
	swbfriends.close();
}

void readWBusers()
{
	//***************
	int num = 0;//读取第一个数字，显示当前用户总数。
	string id; string name; string password; int y; int m; int d; string location;
	fstream vwbuser("wbuser.txt");
	vwbuser >> num;
	for (int i = 0; i < num; i++)
	{
		vwbuser >> id >> name >> password >> y >> m >> d >> location;
		wb.push_back(user(password, id, name, y, m, d, location));
	}
	vwbuser.close();
	for (int i = 0; i < (int)wb.size(); i++)
	{
		wb[i].n = i + 1;
	}
}

void readWBfriends()
{
	//********************
	fstream vwbfriends("friends.txt");
	//numf代表好友数
	int  numf = 0;
	int k = 0;
	for (int i = 0; i < (int)wb.size(); i++)
	{
		vwbfriends >> numf;
		for (int j = 0; j < numf; j++)
		{
			vwbfriends >> k;
			wb[i].friends.push_back(k);
		}
	}
	vwbfriends.close();
}

void WEIBO()
{
	char a2 = 'r';
	while (1)
	{
		system("cls");
		cout << "1.注册新用户\n"
			"2.登陆" << endl;
		char p = '0';
		cin >> p;
		switch (p)
		{
		case '1':
			ZCWB(); return;
		case '2':
			DLWB(); return;
		default:
			cout << "您的输入有误！" << endl;
		}
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}

}

void ZCWB()
{
	system("cls");
	string PAWO; string sid; string sname; int s1, s2, s3; string slocation;
	cout << "注册QQ：\n";
	int i = 0; int j = 0;
	do {
		j = 0;
		cout << "请输入账号：";
		cin >> sid;
		for (; i <(int)wb.size(); i++)
		{
			if (wb[i].id == sid)
			{
				cout << "账号已被注册！请重新输入！";
				j = 1;
			}
			break;
		}
	} while (j);
	cout << "密码：";
	cin >> PAWO;
	cout << "昵称：";
	cin >> sname;
	cout << "出生日期： 年：";
	cin >> s1;
	cout << "月：";
	cin >> s2;
	cout << "日：";
	cin >> s3;
	cout << "所在地：";
	cin >> slocation;
	wb.push_back(user(PAWO, sid, sname, s1, s2, s3, slocation));
	cout << "注册成功！\n";

	fresh_WBuser();
	fresh_WBfriends();

	cout <<
		"                      ********************************************             \n"
		"                      注册信息：                                               \n"
		"                      账号："; cout << wb.back().id << "                            \n"
		"                      昵称："; cout << wb.back().name << "                          \n"
		"                      密码："; cout << wb.back().PASSWORD << "                          \n"
		"                      出生日期：" << wb.back().birthday[0] << "年" << wb.back().birthday[1] << "月" << wb.back().birthday[2] << "日\n"
		"                      所在地：" << wb.back().location << "                          \n"
		"                      *************按任意键进入QQ菜单*************             \n";
	system("pause");
	JRWB((int)wb.size() - 1);
}

void DLWB()
{
	char a1 = 'r';
	while (1)
	{
		system("cls");
		cout << "欢迎使用          \n\n"
			"请输入用户名：" << endl;
		string p;
		cin >> p;
		cout << "请输入密码：" << endl;
		string q;
		cin >> q;
		int i = 0;
		for (; i < (int)wb.size(); i++)
		{
			if (wb[i].id == p&&wb[i].PASSWORD == q)
			{
				JRWB(i);
				return;
			}
		}
		i = 0;
		for (; i < (int)v.size(); i++)
		{
			if (v[i].id == p&&v[i].PASSWORD == q)
			{
				char qqq;
				cout << "您尚未开通微博服务，是否需要开通？输入1确认开通" << endl;
				cin >> qqq;
				if (qqq = '1')
				{
					wb.push_back(user(v[i].PASSWORD, v[i].id, v[i].name, v[i].birthday[0], v[i].birthday[1], v[i].birthday[2], v[i].location));
					JRWB((int)wb.size() - 1);
					return;
				}
			}
		}
		cout << "您的输入有误！" << endl;
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		char a2;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

//i是可以等于0的那种

void JRWB(int i)
{
	system("cls");
	cout <<
		"                      ********************************************             \n"
		"                      我的信息：                                               \n"
		"                      账号："; cout << wb[i].id << "                            \n"
		"                      昵称："; cout << wb[i].name << "                          \n"
		"                      出生日期：" << wb[i].birthday[0] << "年" << wb[i].birthday[1] << "月" << wb[i].birthday[2] << "日\n"
		"                      所在地：" << wb[i].location << "                          \n"
		"                      *************按任意键进入QQ菜单*************             \n";
	system("pause");

	while (1)
	{

		system("cls");
		cout <<
			"1.查看/更改 好友\n"
			"2.查看/更改 群组\n"
			"3.查看/更改 资料\n"
			"4.退出登录\n"
			"请选择功能：";
		char p;
		cin >> p;
		switch (p)
		{
		case '1':
			CGWBfriends(i); break;
		case '2':
			CGgroups(i); break;
		case '3':
			CGWBdatas(i); break;
		case '4':
			return;
		default:
			char a2;
			cout << "您的输入有误！输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void CGWBfriends(int i)
{
	system("cls");
	cout <<
		"好友列表：\n" << endl;
	for (int j = 0; j <(int)wb[i].friends.size(); j++)
	{
		cout <<
			"*******************好友" << j + 1 << ":*******************\n"
			"账号:" << wb[wb[i].friends[j] - 1].id << "\n"
			"昵称:" << wb[wb[i].friends[j] - 1].name << "\n"
			"出生日期：" << wb[wb[i].friends[j] - 1].birthday[0] << "年" << wb[wb[i].friends[j] - 1].birthday[1] << "月" << wb[wb[i].friends[j] - 1].birthday[2] << "日\n"
			"所在地：" << wb[wb[i].friends[j] - 1].location << "\n"
			"********************************************\n";
	}
	cout <<
		"1.添加好友\n"
		"2.删除好友\n"
		"3.返回上级菜单" << endl;
	char a3; cin >> a3;
	switch (a3)
	{
	case '1':
		addWBfriend(i);
	case '2':
		delWBfriend(i);
	case '3':
		return;
	}
}

void addWBfriend(int i)
{
	while (1)
	{
		cout << "请输入您想添加的好友账号：";
		string a4;
		cin >> a4;
		int y = 0;
		for (; y < (int)wb.size(); y++)
		{
			if (wb[y].id == a4)
			{
				wb[i].friends.push_back(wb[y].n);
				cout << "添加成功！" << endl;
				fresh_WBfriends();
				return;
			}
		}
		cout << "您的输入有误！" << endl;
		char a2;
		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void delWBfriend(int i)
{
	char a6 = 'r';
	while (1)
	{
		cout << "请输入您想删除的好友标号（好友列表中显示）：";
		int a6;
		cin >> a6;
		if (a6 <= (int)wb[i].friends.size())
		{
			wb[i].friends.erase(wb[i].friends.begin() + a6 - 1);
			cout << "删除成功！" << endl;
			fresh_WBfriends();
			return;
		}
		else
		{
			cout << "您的输入有误！";
		}

		cout << "输入r返回上一级菜单，输入其他字符继续输入\n" << endl;
		cin >> a6;
		if (a6 == 'r') { return; }
	}
}

void CGWBdatas(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"1.修改密码\n"
			"2.修改昵称\n"
			"3.修改出生日期\n"
			"4.修改所在地\n";
		char a;
		cin >> a;
		string newx;
		switch (a)
		{
		case '1':
			cout << "请输入新密码：";
			cin >> newx;
			wb[i].PASSWORD = newx;
			cout << "修改成功！";
			fresh_WBuser();
			return;
		case '2':
			cout << "请输入新昵称：";
			cin >> newx;
			wb[i].name = newx;
			cout << "修改成功！";
			fresh_WBuser();
			return;
		case '3':
			cout << "请输入新出生日期：\n";
			int q[3];
			cout << "请输入年：";
			cin >> q[0];
			cout << "请输入月：";
			cin >> q[1];
			cout << "请输入日：";
			cin >> q[2];
			wb[i].birthday[0] = q[0];
			wb[i].birthday[1] = q[1];
			wb[i].birthday[2] = q[2];
			cout << "修改成功！";
			fresh_WBuser();
			return;
		case '4':
			cout << "请输入所在地：";
			cin >> newx;
			wb[i].location = newx;
			cout << "修改成功！";
			fresh_WBuser();
			return;
		default:
			cout << "您的输入有误！输入r返回上一级，输入其他字符重新选择！" << endl;
			char c;
			cin >> c;
			if (c == 'r') { return; }
		}
	}
}
