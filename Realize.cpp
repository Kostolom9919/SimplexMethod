#include "stdafx.h"

drob operator+ (drob a, drob b) {
	drob s;
	s.zn = Nok(a.zn, b.zn);
	s.ch = a.ch*s.zn / a.zn + b.ch*s.zn / b.zn;
	s.ch /= Nod(s.zn, abs(s.ch));
	s.zn /= Nod(s.zn, abs(s.ch));
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
drob operator* (drob a, drob b) {
	a.ch *= b.ch;
	a.zn *= b.zn;
	a.ch /= Nod((int)(abs((int)a.ch)), a.zn);
	a.zn /= Nod((int)(abs((int)a.ch)), a.zn);
	return a;
}
drob operator/ (drob a, drob b) {
	a.ch *= b.zn;
	a.zn *= b.ch;
	a.ch /= Nod((int)(abs((int)a.ch)), a.zn);
	a.zn /= Nod((int)(abs((int)a.ch)), a.zn);
	return a;
}
bool operator==(drob a, drob b) {
	if (a.ch == b.ch && a.zn == b.zn)return true;
	return false;
}
bool operator!=(drob a, drob b) {
	if (a.ch != b.ch && a.zn != b.zn)return true;
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
	if (a.zn != 1)
		out << a.ch << "/" << a.zn;
	else
		out << a.ch;
	return out;
}
std::istream& operator>>(std::istream &in, drob &a) {
	in >> a.ch;
	in >> a.zn;
	return in;
}

int Nok(int a, int b) {
	return a * b / Nod(a, b);
}
int Nod(int a, int b) {
	return b == 0 ? a : Nod(b, a % b);
}
void OutAnswer(drob **A, drob *B, int n, int m) {
	for (int i = 0; i < n; i++) {
		std::cout << "S" << i + 1 << " ";
		for (int j = 0; j < n + m + 2; j++) {
			std::cout.width(5);
			std::cout << A[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "Zi-Cj   ";
	for (int i = 0; i < n + m + 1; i++) {
		std::cout.width(5);
		std::cout << B[i];
	}
	std::cout << std::endl;
	return;
}