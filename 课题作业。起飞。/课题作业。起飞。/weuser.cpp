#include "weuser.h"
using namespace std;




weuser::weuser(string PAWO, string sid, string sname, int s1, int s2, int s3, string slocation)
{
	id = sid;
	PASSWORD = PAWO;
	name = sname;//初始化昵称
	birthday[0] = s1; birthday[1] = s2; birthday[2] = s3;//初始化生日
	location = slocation;//初始化所在地
	QQn = -1;
}

weuser::weuser(string PAWO, string sid, string sname, int s1, int s2, int s3, string slocation,int qqn)
{
	id = sid;
	PASSWORD = PAWO;
	name = sname;//初始化昵称
	birthday[0] = s1; birthday[1] = s2; birthday[2] = s3;//初始化生日
	location = slocation;//初始化所在地
	QQn = qqn;
}
