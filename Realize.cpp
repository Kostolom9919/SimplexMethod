#include "stdafx.h"

drob operator+ (drob a, drob b) {
	drob s;
	s.zn = Nok(a.zn, b.zn);
	s.ch = a.ch*s.zn / a.zn + b.ch*s.zn / b.zn;
	s.ch /= Nod(s.zn, (int)(abs((int)s.ch)));
	s.zn /= Nod(s.zn, (int)(abs((int)s.ch)));
	return s;
}
drob operator+ (drob a, int b) {
	drob s;
	s.zn = a.zn;
	s.ch = a.ch + b * a.zn;
	s.ch /= Nod(s.zn, (int)(abs((int)s.ch)));
	s.zn /= Nod(s.zn, (int)(abs((int)s.ch)));
	return s;
}
drob operator+ (int a, drob b) {
	drob s;
	s.zn = b.zn;
	s.ch = b.ch + a * b.zn;
	s.ch /= Nod(s.zn, (int)(abs((int)s.ch)));
	s.zn /= Nod(s.zn, (int)(abs((int)s.ch)));
	return s;
}
drob operator- (drob a, drob b) {
	drob s;
	s.zn = Nok(a.zn, b.zn);
	s.ch = a.ch*s.zn / a.zn - b.ch*s.zn / b.zn;
	s.ch /= Nod(s.zn, (int)(abs((int)s.ch)));
	s.zn /= Nod(s.zn, (int)(abs((int)s.ch)));
	return s;
}
drob operator- (drob a, int b) {
	drob s;
	s.zn = a.zn;
	s.ch = a.ch - b * a.zn;
	s.ch /= Nod(s.zn, (int)(abs((int)s.ch)));
	s.zn /= Nod(s.zn, (int)(abs((int)s.ch)));
	return s;
}
drob operator- (int a, drob b) {
	drob s;
	s.zn = b.zn;
	s.ch = b.ch + a * b.zn;
	s.ch /= Nod(s.zn, (int)(abs((int)s.ch)));
	s.zn /= Nod(s.zn, (int)(abs((int)s.ch)));
	return s;
}
drob operator* (drob a, drob b) {
	a.ch *= b.ch;
	a.zn *= b.zn;
	a.ch /= Nod((int)(abs((int)a.ch)), a.zn);
	a.zn /= Nod((int)(abs((int)a.ch)), a.zn);
	return a;
}
drob operator* (drob a, int b) {
	a.ch *= b;
	a.ch /= Nod((int)(abs((int)a.ch)), a.zn);
	a.zn /= Nod((int)(abs((int)a.ch)), a.zn);
	return a;
}
drob operator* (int a, drob b) {
	b.ch *= a;
	b.ch /= Nod((int)(abs((int)b.ch)), b.zn);
	b.zn /= Nod((int)(abs((int)b.ch)), b.zn);
	return b;
}
drob operator/ (drob a, drob b) {
	a.ch *= b.zn;
	a.zn *= b.ch;
	a.ch /= Nod((int)(abs((int)a.ch)), a.zn);
	a.zn /= Nod((int)(abs((int)a.ch)), a.zn);
	return a;
}
drob operator/ (drob a, int b) {
	a.zn *= b;
	a.ch /= Nod((int)(abs((int)a.ch)), a.zn);
	a.zn /= Nod((int)(abs((int)a.ch)), a.zn);
	return a;
}
drob operator/ (int a, drob b) {
	b.ch *= a;
	b.ch /= Nod((int)(abs((int)b.ch)), b.zn);
	b.zn /= Nod((int)(abs((int)b.ch)), b.zn);
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
