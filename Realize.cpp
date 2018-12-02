#include "stdafx.h"

drob operator+ (drob a, drob b) {
	int x;
	drob s;
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
drob operator+ (drob a, int b) {
	int x;
	drob s;
	s.zn = a.zn;
	s.ch = a.ch + b * a.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	if (x != 0) {
		s.ch /= x;
		s.zn /= x;
	}
	if (s.ch == 0)
		s.zn = 1;
	return s;
}
drob operator+ (int a, drob b) {
	int x;
	drob s;
	s.zn = b.zn;
	s.ch = b.ch + a * b.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	if (x != 0) {
		s.ch /= x;
		s.zn /= x;
	}
	if (s.ch == 0)
		s.zn = 1;
	return s;
}
drob operator- (drob a, drob b) {
	int x;
	drob s;
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
drob operator- (drob a, int b) {
	int x;
	drob s;
	s.zn = a.zn;
	s.ch = a.ch - b * a.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	if (x != 0) {
		s.ch /= x;
		s.zn /= x;
	}
	if (s.ch == 0)
		s.zn = 1;
	return s;
}
drob operator- (int a, drob b) {
	int x;
	drob s;
	s.zn = b.zn;
	s.ch = b.ch + a * b.zn;
	x = Nod(s.zn, (int)(abs((int)s.ch)));
	if (x != 0) {
		s.ch /= x;
		s.zn /= x;
	}
	if (s.ch == 0)
		s.zn = 1;
	return s;
}
drob operator* (drob a, drob b) {
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
drob operator* (drob a, int b) {
	int x;
	a.ch *= b;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	if (x != 0) {
		a.ch /= x;
		a.zn /= x;
	}
	if (a.ch == 0)
		a.zn = 1;
	return a;
}
drob operator* (int a, drob b) {
	int x;
	b.ch *= a;
	x = Nod((int)(abs((int)b.ch)), b.zn);
	if (x != 0) {
		b.ch /= x;
		b.zn /= x;
	}
	if (b.ch == 0)
		b.zn = 1;
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
	if (x != 0) {
		a.ch /= x;
		a.zn /= x;
	}	
	if (a.ch == 0)
		a.zn = 1;
	return a;
}
drob operator/ (drob a, int b) {
	int x;
	a.zn *= b;
	x = Nod((int)(abs((int)a.ch)), a.zn);
	if (x != 0) {
		a.ch /= x;
		a.zn /= x;
	}
	if (a.ch == 0)
		a.zn = 1;
	return a;
}
drob operator/ (int a, drob b) {
	int x;
	b.ch *= a;
	x = Nod((int)(abs((int)b.ch)), b.zn);
	if (x != 0) {
		b.ch /= x;
		b.zn /= x;
	}
	if (b.ch == 0)
		b.zn = 1;
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
void OutAnswer(drob **A, std::string* C, int n, int m) {
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
	cout << endl;
	return;
}
bool CheckOne(drob** A, int n) {
	for (int i = 0; i < n; i++)
		if (A[i][0] < 0) return true;
	return false;
}
bool CheckTwo(drob** A, int n, int m) {
	for (int i = 1; i < n + m + 1; i++)
		if (A[n][i] > 0) return true;
	return false;
}
drob FunctionOne(drob** A, const int n, int m, int& base1, int& base2) {
	drob *a, answ;
	int *index, i = 0;
	index = new int[m];
	a = new drob[m];	
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
			a[j - 1] = a[j - 1] * A[2][j];
		if (A[2][j] == 0) a[j - 1] = -1000;
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
	delete a;
	delete index;
	return answ;
}
void NewTable(drob ** A, drob** _A, std::string* C, std::string* _C, int n, int m, int x, int y) {
	std::string str;
	drob Base = A[x][y];
	str = C[x];
	C[x] = _C[y - 1];
	_C[y - 1] = str;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + m + 1; j++) {
			if (j != y && x != i) {
				drob a1 = A[i][j] * Base;
				drob a2 = A[i][y] * A[x][j];
				drob a3 = a1 - a2;
				_A[i][j] = a3 / Base;
			}
			else if (i == x && j != y) {
				_A[i][j] = A[i][j] / Base;
			} 
			else if (j == y){
				_A[i][j] = A[i][m + x + 1];
			} 
		}
	}
	return;
}