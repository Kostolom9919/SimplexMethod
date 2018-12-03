#include "stdafx.h"

using namespace std;

int main() {
	int n, m, *Z, x, y, l, i, j;
	drob **Table, **_Table, BasisNumber;
	string *Basis, *Not_Basis;
	system("color F0");
	setlocale(LC_ALL, "Rus");
	cout << "Кол-во X : ";
	cin >> m;
	cout << "Кол-во ограничений : ";
	cin >> n;
	Basis = new string[n];
	Not_Basis = new string[m];
	Table = new drob*[n+1];
	_Table = new drob*[n+1];
	Z = new int[m];
	for (i = 0; i < n + 1; i++) {
		Table[i] = new drob[n + m + 1];
		_Table[i] = new drob[n + m + 1];
	}
	for (i = 0; i < n; i++) {
		Basis[i] = "S";
		Basis[i] += char(49 + i);
	}
	cout << "Коэффициенты X целевой функции" << endl;
	for (i = 0; i < m; i++) {
		cout << "   X" << i+1 << ": ";
		cin >> Z[i];
		Not_Basis[i] = "X";
		Not_Basis[i] += char(49 + i);
	}
	cout << endl;
	Table[n][0].Set();
	for (j = 1; j < m + 1; j++)
		Table[n][j].Set(-Z[j - 1]);
	for (; j < n + m + 1; j++)
		Table[n - 1][j].Set();
	for (i = 0; i < n; i++) {
		cout << "Ограничение №" << i+1 << endl;
		
		for (j = 1; j < m+1; j++) {
			cout << "   X" << j << ": ";
			cin >> Table[i][j];
		}
		cout << "Решение : ";
		cin >> Table[i][0];
		l = j;
		for (; j < n+l; j++) 
			if(i==j-l)
				Table[i][j].Set(1);
			else
				Table[i][j].Set();
	}
	system("cls");
	OutAnswer(Table, Basis, n, m);
	if(CheckOne(Table, n)){
		BasisNumber = FunctionOne(Table, n, m, x, y);
		NewTable(Table, _Table, Basis, Not_Basis, n, m, x, y);
		Table = _Table;
		cout << endl;
		OutAnswer(Table, Basis, n, m);
		drob a1(0);
		drob a2(-2);
		drob a3(1);
		drob a4(-7);
		cout << ((a1*a2) - (a3*a4)) / a2;
		cout << endl;
		BasisNumber = FunctionOne(Table, n, m, x, y);
		NewTable(Table, _Table, Basis, Not_Basis, n, m, x, y);
		OutAnswer(Table, Basis, n, m);
		cout << endl;
	}
	while (CheckTwo(Table, n, m)) {
		cout << "Не оптимально 2" << endl;
		break;
	}
	
	system("pause");
	for (i = 0; i < n; i++)
		delete[] Table[i];
	delete[] Table;
	return 0;
}