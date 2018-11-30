#include "stdafx.h"

using namespace std;

int main() {
	int n, m, *Z, i, j, a;
	drob **Table, *Marks, Basis;
	//system("color F0");
	setlocale(LC_ALL, "Rus");
	cout << sizeof(drob);
	cout << "Кол-во X : ";
	cin >> m;
	cout << "Кол-во ограничений : ";
	cin >> n;
	Table = new drob*[n];
	Marks = new drob[n + m + 1];
	Z = new int[m];
	for (int i = 0; i < n; i++)
		Table[i] = new drob[n + m + 2];
	cout << "Коэффициенты X целевой функции" << endl;
	for (int i = 0; i < m; i++) {
		cout << "   X" << i+1 << ": ";
		cin >> Z[i];
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
		a = j;
		for (; j < n+a; j++) 
			if(i==j-a)
				Table[i][j].Set(1);
			else
				Table[i][j].Set();
	}
	cout << endl;
	system("cls"); 
	OutAnswer(Table, Marks, n, m);
	system("pause");
	for (i = 0; i < n; i++)
		delete[] Table[i];
	delete[] Table;
	delete Marks;
	return 0;
}
