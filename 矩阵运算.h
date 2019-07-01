#include "������.h"
/*ת�þ�������:B=tom(A)*/
matrix const TOM(const matrix &a)
{
	matrix C(a.n, a.m);
	for (int i = 0; i < C.m; i++)
	{
		for (int j = 0; j < C.n; j++)
		{
			C.q[i][j] = a.q[j][i];
		}
	}
	return C;
}
/*����������㣺�ԡ�*���ŵ��ض���1*/
matrix const operator*(const matrix &a, const matrix &b)
{
	if (a.n != b.m)
	{
		cout << "�����������������Ͼ�����˵�ԭ������������" << endl;
		matrix C(0, 0);
		return C;
	}
	matrix C(a.m, b.n);
	for (int i = 0; i < C.m; i++)
	{
		for (int j = 0; j < C.n; j++)
		{
			for (int s = 0; s < a.n; s++)
			{
				C.q[i][j] += a.q[i][s] * b.q[s][j];
			}
		}
	}
	return C;
}
/*���������������㣺�ԡ�*���ŵ��ض���2*/
matrix const operator*(const double a, const matrix &b)
{
	matrix C(b.m, b.n);
	for (int i = 0; i < C.m; i++)
	{
		for (int j = 0; j < C.n; j++)
		{
			C.q[i][j] = a * b.q[i][j];
		}
	}
	return C;
}
/*������ӣ��ԡ�+���ŵ�����*/
matrix const operator + (const matrix &a, const matrix &b)
{
	if ((a.m != b.m) || (a.n != b.n))
	{
		cout << "�����������������Ͼ�����ӵ�ԭ������������" << endl;
		matrix C(0, 0);
		return C;
	}
	matrix C(a.m, a.n);
	for (int i = 0; i < a.m; i++)
	{
		for (int j = 0; j < a.n; j++)
		{
			C.q[i][j] = a.q[i][j] + b.q[i][j];
		}
	}
	return C;
}
/*�������:�ԡ�-���ŵ�����*/
matrix const operator - (const matrix &a, const matrix &b)
{
	if (a.m != b.m || a.n != b.n)
	{
		cout << "�����������������Ͼ��������ԭ������������" << endl;
		matrix C(0, 0);
		return C;
	}
	matrix C(a.m, a.n);
	for (int i = 0; i < a.m; i++)
	{
		for (int j = 0; j < a.n; j++)
		{
			C.q[i][j] = a.q[i][j] - b.q[i][j];
		}
	}
	return C;
}
/*��������:�ԡ�^���ŵ�����*/
matrix const operator^(const matrix &b, const int a)
{
	if (a != -1)
	{
		cout << "^�����ص��ô����븳�衰-1��Ϊ�����Ե������������" << endl;
		matrix C(0, 0);
		return C;
	}
	if (b.m != b.n)
	{
		cout << "�˾����Ƿ��󣬴˳����޷����棬�������" << endl;
		matrix C(0, 0);
		return C;
	}
	matrix L(b.m, b.n), U(b.m, b.n);
	//LU�ֽ⣺
	for (int i = 0; i < b.m; i++)
	{
		for (int j = 0; j < b.n; j++)
		{
			if (i == j)
				L.q[i][j] = 1;
			if (i < j)
				L.q[i][j] = 0;
			if (i > j)
				U.q[i][j] = 0;
		}
	}
	for (int i = 0; i < b.m; i++)
	{
		for (int j = 0; j < b.n; j++)
		{
			double k = 0;
			if (i <= j)
			{
				for (int s = 0; s < b.m; s++)
				{
					if (s == i)
						continue;
					k += (L.q[i][s] * U.q[s][j]);
				}
				U.q[i][j] = (b.q[i][j] - k) / L.q[i][i];
			}
			else
			{
				for (int s = 0; s < b.m; s++)
				{
					if (s == j)
						continue;
					k += (L.q[i][s] * U.q[s][j]);
				}
				L.q[i][j] = (b.q[i][j] - k) / U.q[j][j];
			}
		}
	}
	//L U�ֱ����棺
	matrix l(L.m, L.n), u(U.m, U.n);
	for (int i = 0; i < L.m; i++)
	{
		for (int j = 0; j < L.n; j++)
		{
			if (i < j)
				l.q[i][j] = 0;
			if (i > j)
				u.q[i][j] = 0;
		}
	}
	for (int i = 0; i < u.m; i++) /*�����U���� */
	{
		u.q[i][i] = 1.0 / U.q[i][i];//�Խ�Ԫ�ص�ֵ��ֱ��ȡ����
		for (int k = i - 1; k >= 0; k--)
		{
			double s = 0;
			for (int j = k + 1; j <= i; j++)
				s += U.q[k][j] * u.q[j][i];
			u.q[k][i] = -s / U.q[k][k];//�������㣬���е������εõ�ÿһ��ֵ��
		}
	}
	for (int i = 0; i < l.m; i++) //�����L���� 
	{
		l.q[i][i] = 1; //�Խ�Ԫ�ص�ֵ��ֱ��ȡ����������Ϊ1
		for (int k = i + 1; k < l.m; k++)
		{
			for (int j = i; j <= k - 1; j++)
				l.q[k][i] -= L.q[k][j] * l.q[j][i];   //�������㣬����˳�����εõ�ÿһ��ֵ
		}
	}
	matrix C(u.m, l.n);
	for (int i = 0; i < C.m; i++)
	{
		for (int j = 0; j < C.n; j++)
		{
			for (int s = 0; s < b.n; s++)
			{
				C.q[i][j] += u.q[i][s] * l.q[s][j];
			}
		}
	};
	return C;
}