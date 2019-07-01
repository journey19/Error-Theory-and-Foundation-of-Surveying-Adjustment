#include"��������.h"
void T1()
{
	matrix A;
	cout << "������A��������С����������" << endl;
	A.setmatrix();

	matrix W(A.m, 1);
	cout << "������W����" << endl;
	W.setmatrix();

	matrix Q;
	cout << "������Э�������Q��" << endl;
	Q.setp(A.n);

	double o2;
	matrix Naa, NaaS, V, K, QL,VPV;
	Naa = A * Q*TOM(A);
	NaaS = Naa ^ (-1);
	K = (-1)*NaaS*W;
	V = Q * TOM(A)*K;
	QL = Q - Q * TOM(A)*NaaS*A*Q;
	VPV=TOM(V)*(Q^(-1))*V;
	o2 = VPV.q[0][0] / A.m;

	cout << "*****��õĽ������Ϊ*****��" << endl;
	cout << "Naa=" << endl;
	Naa.showmatrix();
	cout << "NaaS=" << endl;
	NaaS.showmatrix();
	cout << "K=" << endl;
	K.showmatrix();
	cout << "V=" << endl;
	V.showmatrix();
	cout << "QL=" << endl;
	QL.showmatrix();
	cout << "o2=" << o2 << endl;;
}
void T2()
{
	matrix A;
	cout << "������A��������С����������" << endl;
	A.setmatrix();

	matrix B;
	cout << "������B����" << endl;
	B.setmatrix();

	matrix W(A.m, 1);
	cout << "������W����" << endl;
	W.setmatrix();

	matrix Q;
	cout << "������Э�������Q��" << endl;
	Q.setp(A.n);

	double o2;
	matrix Naa, NaaS, Nbb, NbbS, V, K, X,QL,VPV;
	Naa = A * Q*TOM(A);
	NaaS = Naa ^ (-1);
	Nbb = TOM(B)*NaaS*B;
	NbbS = Nbb ^ (-1);
	X = (-1)*NbbS*TOM(B)*NaaS*W;
	K = NaaS * B*NbbS*TOM(B)*NaaS*W - NaaS * W;
	V = Q * TOM(A)*K;
	QL = Q - Q * TOM(A)*(NaaS - NaaS * B*NbbS*TOM(B)*NaaS)*A*Q;
	VPV = TOM(V)*(Q ^ (-1))*V;
	o2 = VPV.q[0][0] / A.m;

	cout << "*****��õĽ������Ϊ*****��" << endl;
	cout << "Naa=" << endl;
	Naa.showmatrix();
	cout << "NaaS=" << endl;
	NaaS.showmatrix();
	cout << "Nbb=" << endl;
	Nbb.showmatrix();
	cout << "NbbS=" << endl;
	NbbS.showmatrix();
	cout << "X=" << endl;
	X.showmatrix();
	cout << "K=" << endl;
	K.showmatrix();
	cout << "V=" << endl;
	V.showmatrix();
	cout << "QL=" << endl;
	QL.showmatrix();
	cout << "o2=" <<o2<< endl;
}
void J1()
{
	matrix B;
	cout << "������B������������������" << endl;
	B.setmatrix();

	matrix L(B.m, 1);
	cout << "������L����" << endl;
	L.setmatrix();

	matrix P;
	cout << "������Ȩ����P��" << endl;
	P.setp(B.m);

	double o2;
	matrix W, NBB, NBBS, X, V,VPV;
	W = TOM(B)*P*L;
	NBB = TOM(B)*P*B;
	NBBS = NBB ^ (-1);
	X = NBBS * W;
	V = B * X - L;
	VPV=TOM(V)*P*V;
	o2 = VPV.q[0][0] / (B.m - B.n);

	cout << "*****��õĽ������Ϊ*****��" << endl;
	cout << "W=" << endl;
	W.showmatrix();
	cout << "NBB=" << endl;
	NBB.showmatrix();
	cout << "NBBS=" << endl;
	NBBS.showmatrix();
	cout << "X=" << endl;
	X.showmatrix();
	cout << "V=" << endl;
	V.showmatrix();
	cout << "QX=" << endl;
	NBBS.showmatrix();
	cout << "o2=" << o2<<endl;
}
void J2()
{
	matrix B;
	cout << "������B������������������" << endl;
	B.setmatrix();

	matrix L(B.m, 1);
	cout << "������L����" << endl;
	L.setmatrix();

	matrix C;
	cout << "������C����" << endl;
	C.setmatrix();

	matrix Wx(C.m, 1);
	cout << "������Wx����" << endl;
	Wx.setmatrix();

	matrix P;
	cout << "������Ȩ����P��" << endl;
	P.setp(B.m);

	double o2;
	matrix W, NBB, NBBS, NCC, NCCS, X, V,VPV,QX;
	W = TOM(B)*P*L;
	NBB = TOM(B)*P*B;
	NBBS = NBB ^ (-1);
	NCC = C * NBBS*TOM(C);
	NCCS = NCC ^ (-1);
	X = (NBBS - NBBS * TOM(C)*NCCS*C*NBBS)*W - NBBS * TOM(C)*NCCS*Wx;
	V = B * X - L;
	QX = NBBS - NBBS * TOM(C)*NCCS*C*NBBS;
	VPV = TOM(V)*P*V;
	o2 = VPV.q[0][0] / (B.m - B.n + C.m);

	cout << "*****��õĽ������Ϊ*****��" << endl;
	cout << "W=" << endl;
	W.showmatrix();
	cout << "NBB=" << endl;
	NBB.showmatrix();
	cout << "NBBS=" << endl;
	NBBS.showmatrix();
	cout << "NCC=" << endl;
	NCC.showmatrix();
	cout << "NCCS=" << endl;
	NCCS.showmatrix();
	cout << "X=" << endl;
	X.showmatrix();
	cout << "V=" << endl;
	V.showmatrix();
	cout << "QX=" << endl;
	QX.showmatrix();
	cout << "o2=" << o2 << endl;
}