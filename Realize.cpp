#include "stdafx.h"

drob operator+ (drob a, drob b) {
	int x;
	drob s;
	s.zn = Nok(a.zn, b.zn);
	s.ch = a.ch*s.zn / a.zn + b.ch*s.zn / b.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	s.ch /= x;
	s.zn /= x;
	return s;
}
drob operator+ (drob a, int b) {
	int x;
	drob s;
	s.zn = a.zn;
	s.ch = a.ch + b * a.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	s.ch /= x;
	s.zn /= x;
	return s;
}
drob operator+ (int a, drob b) {
	int x;
	drob s;
	s.zn = b.zn;
	s.ch = b.ch + a * b.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	s.ch /= x;
	s.zn /= x;
	return s;
}
drob operator- (drob a, drob b) {
	int x;
	drob s;
	s.zn = Nok(a.zn, b.zn);
	s.ch = a.ch*s.zn / a.zn - b.ch*s.zn / b.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	s.ch /= x;
	s.zn /= x;
	return s;
}
drob operator- (drob a, int b) {
	int x;
	drob s;
	s.zn = a.zn;
	s.ch = a.ch - b * a.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	s.ch /= x;
	s.zn /= x;
	return s;
}
drob operator- (int a, drob b) {
	int x;
	drob s;
	s.zn = b.zn;
	s.ch = b.ch + a * b.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	s.ch /= x;
	s.zn /= x;
	return s;
}
drob operator* (drob a, drob b) {
	int x;
	a.ch *= b.ch;
	a.zn *= b.zn;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	a.ch /= x;
	a.zn /= x;
	return a;
}
drob operator* (drob a, int b) {
	int x;
	a.ch *= b;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	a.ch /= x;
	a.zn /= x;
	return a;
}
drob operator* (int a, drob b) {
	int x;
	b.ch *= a;
	x = Nod((int)(abs((int)b.ch)), b.zn);
	b.ch /= x;
	b.zn /= x;
	return b;
}
drob operator/ (drob a, drob b) {
	int x;
	if (b < 0) {
		b.ch *= -1;
		b.zn *= -1;
	}
	a.ch *= b.zn;
	a.zn *= b.ch;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	a.ch /= x;
	a.zn /= x;
	return a;
}
drob operator/ (drob a, int b) {
	int x;
	a.zn *= b;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	a.ch /= x;
	a.zn /= x;
	return a;
}
drob operator/ (int a, drob b) {
	int x;
	b.ch *= a;
	x = Nod((int)(abs((int)b.ch)), b.zn);
	b.ch /= x;
	b.zn /= x;
	return b;
}
bool operator==(drob a, drob b) {
	if (a.ch*b.zn == b.ch*a.zn)return true;
	return false;
}
bool operator==(drob a, int b) {
	if (a.ch == b * a.zn)return true;
	return false;
}
bool operator==(int a, drob b) {
	if (a*b.zn == b.ch)return true;
	return false;
}
bool operator!=(drob a, drob b) {
	if (!(a.ch*b.zn == b.ch*a.zn))return true;
	return false;
}
bool operator!=(drob a, int b) {
	if (!(a.ch == b*a.zn))return true;
	return false;
}
bool operator!=(int a, drob b) {
	if (!(a*b.zn == b.ch))return true;
	return false;
}
bool operator< (drob a, drob b) {
	if (a.ch * b.zn < b.ch * a.zn)return true;
	return false;
}
bool operator< (drob a, int b) {
	if (a.ch < b * a.zn)
		return true;
	return false;
}
bool operator< (int a, drob b) {
	if (a * b.zn < b.ch)
		return true;
	return false;
}
bool operator> (drob a, drob b) {
	if (a.ch * b.zn > b.ch * a.zn)
		return true;
	return false;
}
bool operator> (drob a, int b) {
	if (a.ch > b * a.zn)
		return true;
	return false;
}
bool operator> (int a, drob b) {
	if (a * b.zn > b.ch)
		return true;
	return false;
}
bool operator>=(drob a, drob b) {
	if (a.ch * b.zn >= b.ch * a.zn)
		return true;
	return false;
}
bool operator>=(drob a, int b) {
	if (a.ch >= b * a.zn)
		return true;
	return false;
}
bool operator>=(int a, drob b) {
	if (a * b.zn >= b.ch)
		return true;
	return false;
}
bool operator<=(drob a, drob b) {
	if (a.ch * b.zn <= b.ch * a.zn)
		return true;
	return false;
}
bool operator<=(drob a, int b) {
	if (a.ch <= b * a.zn)
		return true;
	return false;
}
bool operator<=(int a, drob b) {
	if (a * b.zn <= b.ch)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream &out, const drob &a) {
	if (a.zn != 1) {
		std::cout.width(3);
		out << std::right << a.ch << "/";
		std::cout.width(3);
		out	<< std::left << a.zn;
	}
	else{
		std::cout.width(4);
		out << std::right << a.ch << "   ";
	}
	return out;
}
std::istream& operator>>(std::istream &in, drob &a) {
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
void OutAnswer(drob **A, drob *B, std::string* C, int n, int m) {
	using namespace std;
	for (int i = 0; i < n; i++) {
		cout << C[i] << " ";
		for (int j = 0; j < n + m + 2; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << "Zi-Cj     ";
	for (int i = 0; i < n + m + 1; i++) {
		cout << B[i];
	}
	cout << endl;
	return;
}
bool CheckOne(drob** A, int n) {
	for (int i = 0; i < n; i++)
		if (A[i][1] < 0) return true;
	return false;
}
bool CheckTwo(drob* B, int n, int m) {
	for (int i = 1; i < n + m + 1; i++)
		if (B[i] > 0) return true;
	return false;
}
drob FunctionOne(drob** A, drob* B, const int n, int m, int& base1, int& base2) {
	drob *a, answ;
	int *index, i = 0;
	index = new int[m];
	a = new drob[m];
	index[0] = i;
	for (int j = 2; j < m + 2; j++) {
		a[j - 2] = 1000;
		index[j - 2] = 0;
		for (i = 0; i < n; i++) 
			if ((A[i][1] * A[i][j] > 0) && (A[i][1] / A[i][j] < a[j - 2])) {
				a[j - 2] = A[i][1] / A[i][j];
				index[j - 2] = i;
			}
		if (a[j - 2] == 1000)
			a[j - 2] = -1000;
		if (a[j - 2] >= 0)
			a[j - 2] = a[j - 2] * B[j - 1];
	}
	i = 0;
	answ = -100;
	base1 = i;
	base2 = 2+i;
	for (; i < m; i++)
		if (a[i] > answ) {
			answ = a[i];
			base2 = i + 2;
			base1 = index[i];
		}
	answ = A[base1][base2];
	delete a;
	delete index;
	return answ;
}