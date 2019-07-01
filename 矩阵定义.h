#include <iostream>                  
using namespace std;
class matrix
{
public:
	matrix(int, int);
	matrix()
	{
		m = n = 0;
	}
	//matrix(const matrix &);
	double **q = nullptr;
	int m;
	int n;
	void setmatrix();/*普通矩阵定义*/
	void setp(int a);/*权矩阵P的定义*/
	void showmatrix();
};
inline matrix::matrix(int a, int b)
{
	m = a, n = b;
	q = new double*[m];
	for (int i = 0; i < m; i++)
	{
		q[i] = new double[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			q[i][j] = 0.0;
		}
	}
}
/*普通矩阵定义*/
inline void matrix::setmatrix()
{
	if (m == 0 && n == 0)
	{
		cout << "请输入该矩阵行数（正整数）:" << endl;
		cin >> m;
		cout << "请输入该矩阵列数（正整数）:" << endl;
		cin >> n;
		q = new double*[m];
		for (int i = 0; i < m; i++)
		{
			q[i] = new double[n];
		}
	}
	cout << "请输入矩阵的元素：" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "第" << i + 1 << "行:" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> q[i][j];
		}
	}
	cout << "你输入的矩阵为:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << q[i][j] << ",     ";
		}
		cout << endl;
	}
}
/*权矩阵P的定义*/
inline void matrix::setp(int b)
{
	m = n = b;
	bool a;
	q = new double*[b];
	for (int i = 0; i < b; i++)
	{
		q[i] = new double[b];
	}
	cout << "是否为单位矩阵？ 是（1），否（0）：  ";
	cin >> a;
	if (a)
	{
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if (i == j)
				{
					q[i][j] = 1;
				}
				else
					q[i][j] = 0;
			}
		}
	}
	else
	{
		cout << "请输入对角线元素：" << endl;
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if (i == j)
				{
					cin >> q[i][j];
				}
				else
					q[i][j] = 0;
			}
		}
	}
}
double decline_accuracy(double t)
{
	t = int(t * 1000000);
	t = t / 1000000;
	return t;
}
inline void matrix::showmatrix()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

			cout << decline_accuracy(q[i][j]) << ",     ";
		}
		cout << endl << endl;
	}
}
