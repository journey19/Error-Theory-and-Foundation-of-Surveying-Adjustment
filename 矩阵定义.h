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
	void setmatrix();/*��ͨ������*/
	void setp(int a);/*Ȩ����P�Ķ���*/
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
/*��ͨ������*/
inline void matrix::setmatrix()
{
	if (m == 0 && n == 0)
	{
		cout << "������þ�����������������:" << endl;
		cin >> m;
		cout << "������þ�����������������:" << endl;
		cin >> n;
		q = new double*[m];
		for (int i = 0; i < m; i++)
		{
			q[i] = new double[n];
		}
	}
	cout << "����������Ԫ�أ�" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "��" << i + 1 << "��:" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> q[i][j];
		}
	}
	cout << "������ľ���Ϊ:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << q[i][j] << ",     ";
		}
		cout << endl;
	}
}
/*Ȩ����P�Ķ���*/
inline void matrix::setp(int b)
{
	m = n = b;
	bool a;
	q = new double*[b];
	for (int i = 0; i < b; i++)
	{
		q[i] = new double[b];
	}
	cout << "�Ƿ�Ϊ��λ���� �ǣ�1������0����  ";
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
		cout << "������Խ���Ԫ�أ�" << endl;
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
