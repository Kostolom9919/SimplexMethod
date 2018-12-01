#include "stdafx.h"

using namespace std;

int main() {
	int n, m, *Z, i, j, a;
	drob **Table, *Marks, BasisNumber;
	string *Basis, *Not_Basis;
	system("color F0");
	setlocale(LC_ALL, "Rus");
	cout << "Кол-во X : ";
	cin >> m;
	cout << "Кол-во ограничений : ";
	cin >> n;
	Basis = new string[n];
	Not_Basis = new string[n];
	Table = new drob*[n];
	Marks = new drob[n + m + 1];
	Z = new int[m];
	for (i = 0; i < n; i++) {
		Table[i] = new drob[n + m + 2];
		Basis[i] = "S";
		Basis[i] += char(49 + i);
	}
	cout << "Коэффициенты X целевой функции" << endl;
	for (int i = 0; i < m; i++) {
		cout << "   X" << i+1 << ": ";
		cin >> Z[i];
		Not_Basis[i] = "X";
		Not_Basis[i] += char(49 + i);
	}
	cout << endl;
	Marks[0].Set();
	for (i = 1; i < m+1; i++)
		Marks[i].Set(-Z[i-1]);
	for ( ; i < n+m+1 ; i++)
		Marks[i].Set();
	for (i = 0; i < n; i++) {
		cout << "Ограничение №" << i+1 << endl;
		Table[i][0].Set();
		Table[i][1].Set();
		for (j = 2; j < m+2; j++) {
			cout << "   X" << j-1 << ": ";
			cin >> Table[i][j];
		}
		cout << "Решение : ";
		cin >> Table[i][j-m-1];
		a = j;
		for (; j < n+a; j++) 
			if(i==j-a)
				Table[i][j].Set(1);
			else
				Table[i][j].Set();
	}
	system("cls");
	while(CheckOne(Table, n)){

	}
	while (CheckTwo(Marks, n, m)) {

	}
	OutAnswer(Table, Marks, Basis, n, m);
	system("pause");
	for (i = 0; i < n; i++)
		delete[] Table[i];
	delete[] Table;
	delete Marks;
	return 0;
}
