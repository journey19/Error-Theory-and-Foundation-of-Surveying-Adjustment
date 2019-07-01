#include "矩阵定义.h"
/*转置矩阵运算:B=tom(A)*/
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
/*矩阵相乘运算：对“*”号的重定义1*/
matrix const operator*(const matrix &a, const matrix &b)
{
	if (a.n != b.m)
	{
		cout << "两矩阵行列数不符合矩阵相乘的原则，请检查两矩阵" << endl;
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
/*常数与矩阵相乘运算：对“*”号的重定义2*/
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
/*矩阵相加：对“+”号的重载*/
matrix const operator + (const matrix &a, const matrix &b)
{
	if ((a.m != b.m) || (a.n != b.n))
	{
		cout << "两矩阵行列数不符合矩阵相加的原则，请检查两矩阵" << endl;
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
/*矩阵相减:对“-”号的重载*/
matrix const operator - (const matrix &a, const matrix &b)
{
	if (a.m != b.m || a.n != b.n)
	{
		cout << "两矩阵行列数不符合矩阵相减的原则，请检查两矩阵" << endl;
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
/*矩阵求逆:对“^”号的重载*/
matrix const operator^(const matrix &b, const int a)
{
	if (a != -1)
	{
		cout << "^号重载调用错误，请赋予“-1”为参数以调用求逆矩阵功能" << endl;
		matrix C(0, 0);
		return C;
	}
	if (b.m != b.n)
	{
		cout << "此矩阵不是方阵，此程序无法求逆，请检查矩阵" << endl;
		matrix C(0, 0);
		return C;
	}
	matrix L(b.m, b.n), U(b.m, b.n);
	//LU分解：
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
	//L U分别求逆：
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
	for (int i = 0; i < u.m; i++) /*求矩阵U的逆 */
	{
		u.q[i][i] = 1.0 / U.q[i][i];//对角元素的值，直接取倒数
		for (int k = i - 1; k >= 0; k--)
		{
			double s = 0;
			for (int j = k + 1; j <= i; j++)
				s += U.q[k][j] * u.q[j][i];
			u.q[k][i] = -s / U.q[k][k];//迭代计算，按列倒序依次得到每一个值，
		}
	}
	for (int i = 0; i < l.m; i++) //求矩阵L的逆 
	{
		l.q[i][i] = 1; //对角元素的值，直接取倒数，这里为1
		for (int k = i + 1; k < l.m; k++)
		{
			for (int j = i; j <= k - 1; j++)
				l.q[k][i] -= L.q[k][j] * l.q[j][i];   //迭代计算，按列顺序依次得到每一个值
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