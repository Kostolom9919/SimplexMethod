#include "stdafx.h"

frac operator+ (frac a, frac b) {
	int x;
	frac s;
	s.zn = a.zn * b.zn;
	s.ch = a.ch * b.zn + b.ch * a.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	if (x != 0) {
		s.ch /= x;
		s.zn /= x;
	}
	if (s.ch == 0)
		s.zn = 1;
	return s;
}
frac operator- (frac a, frac b) {
	int x;
	frac s;
	s.zn = a.zn * b.zn;
	s.ch = a.ch * b.zn - b.ch * a.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	if (x != 0) {
		s.ch /= x;
		s.zn /= x;
	}
	if (s.ch == 0)
		s.zn = 1;
	return s;
}
frac operator* (frac a, frac b) {
	int x;
	a.ch *= b.ch;
	a.zn *= b.zn;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	if (x != 0) {
		a.ch /= x;
		a.zn /= x;
	}
	if (a.ch == 0)
		a.zn = 1;
	return a;
}
frac operator/ (frac a, frac b) {
	int x;
	if (b < 0) {
		b.ch *= -1;
		b.zn *= -1;
	}
	a.ch *= b.zn;
	a.zn *= b.ch;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	if (x != 0) {
		a.ch /= x;
		a.zn /= x;
	}	
	if (a.ch == 0)
		a.zn = 1;
	return a;
}
bool operator==(frac a, frac b) {
	if (a.ch*b.zn == b.ch*a.zn)return true;
	return false;
}
bool operator!=(frac a, frac b) {
	if (!(a.ch*b.zn == b.ch*a.zn))return true;
	return false;
}
bool operator< (frac a, frac b) {
	if (a.ch * b.zn < b.ch * a.zn)return true;
	return false;
}
bool operator> (frac a, frac b) {
	if (a.ch * b.zn > b.ch * a.zn)
		return true;
	return false;
}
bool operator>=(frac a, frac b) {
	if (a.ch * b.zn >= b.ch * a.zn)
		return true;
	return false;
}
bool operator<=(frac a, frac b) {
	if (a.ch * b.zn <= b.ch * a.zn)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream &out, const frac &a) {
	if (a.zn != 1) {
		std::cout.width(4);
		out << std::right << a.ch << "/";
		std::cout.width(2);
		out	<< std::left << a.zn;
	}
	else{
		std::cout.width(5);
		out << std::right << a.ch << "  ";
	}
	return out;
}
std::istream& operator>>(std::istream &in, frac &a) {
	in >> a.ch;
	if (getchar() == '/')
		in >> a.zn;
	else
		a.zn = 1;
	return in;
}

int Nok(int a, int b) {
	return a * b / Nod(a, b);
}
int Nod(int a, int b) {
	return b == 0 ? a : Nod(b, a % b);
}
void OutAnswer(frac **A, std::string* C, int n, int m) {
	using namespace std;
	for (int i = 0; i < n + 1 ; i++) {
		if (i == n ) 
			cout << "Zi-Cj  ";
		else
			cout << C[i] << "     ";
		for (int j = 0; j < n + m + 1; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}
	if (CheckOne(A, n)) cout << "�� ��⨬��쭮 1" << endl;
	else if (CheckTwo(A, n, m)) cout << "�� ��⨬��쭮 2" << endl;
	cout << endl;
	return;
}
bool CheckOne(frac** A, int n) {
	for (int i = 0; i < n; i++)
		if (A[i][0] < 0) return true;
	return false;
}
bool CheckTwo(frac** A, int n, int m) {
	for (int i = 1; i < n + m + 1; i++)
		if (A[n][i] > 0) return true;
	return false;
}
frac BasisOne(frac** A, int n, int m, int& base1, int& base2) {
	frac *a, answ;
	int *index, i = 0;
	index = new int[m];
	a = new frac[m];	
	for (int j = 1; j < m + 1; j++) {
		a[j - 1] = 1000;
		index[j - 1] = 1;
		for (i = 0; i < n; i++) 
			if ((A[i][0] * A[i][j] > 0) && (A[i][0] / A[i][j] < a[j - 1])) {
				a[j - 1] = A[i][0] / A[i][j];
				index[j - 1] = i;
			}
		if (a[j - 1] == 1000)
			a[j - 1] = -1000;
		else
			a[j - 1] = a[j - 1] * A[n][j];
		if (A[n][j] == 0) a[j - 1] = -1000;
	}
	answ = -100;
	for (i = 0; i < m; i++) {
		if (a[i] > answ) {
			answ = a[i];
			base2 = i + 1;
			base1 = index[i];
		}
	}
	answ = A[base1][base2];
	delete[] a;
	delete[] index;
	return answ;
}
frac BasisTwo() {
	return frac(1,1);
}
frac** NewTable(frac** A, std::string* C, std::string* _C, int n, int m, int x, int y) {
	frac** _A = new frac*[n + 1];
	for (int i = 0; i < n + 1; i++)
		_A[i] = new frac[n + m + 1];
	frac Base = A[x][y];
	std::swap(C[x], _C[y - 1]);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + m + 1; j++) {
			if (j != y && x != i) {
				_A[i][j] = ((A[i][j] * Base) - (A[i][y] * A[x][j])) / Base;
			}else
			if (i == x && j != y) {
				_A[i][j] = A[i][j] / Base;
			}else
			if (j == y && x == i){
				_A[i][j] = 1;
			}else
			if (j == y && x != i)
				_A[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	return _A;
}