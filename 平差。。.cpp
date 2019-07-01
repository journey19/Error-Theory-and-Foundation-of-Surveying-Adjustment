#include "pch.h"
#include "平差方式.h"
int main()
{
	cout << "----------------------" << endl << "      平差计算       |" << endl << "   create by:郑亚林  |" << endl << "----------------------" << endl;
	for (bool o=1; o;)
	{
		cout << "请选择平差方式:  ①：条件平差。 ②：含有参数的条件平差。  ③：间接平差。  ④：附有限制条件的间接平差。" << endl;
		int z;
		cin >> z;
		switch (z)
		{
		case 1: T1(); break;
		case 2: T2(); break;
		case 3: J1(); break;
		case 4: J2(); break;
		default:cout << "非法输入！" << endl;
		}
		cout << "是否进行下一次平差？：是（1）  否（0）" << endl;
		cin >> o;
		cout << endl;
	}
	return 0;
}