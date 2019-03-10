#pragma once
#include <iostream>
#include <string>

class frac {
private:
	int ch, zn;
public:
	frac(int a, int b) : ch(a) { zn = (b != 0) ? b : 0; }
	frac(int a) : ch(a), zn(1) {}
	frac() { ch = 0; zn = 1; }
	void Set(int a, int b) { ch = a; zn = (b != 0) ? b : 0; }
	void Set(int a) { ch = a; zn = 1;}
	void Set() { ch = 0; zn = 1;}

	friend frac operator+ (frac, frac);
	friend frac operator- (frac, frac);
	friend frac operator* (frac, frac);
	friend frac operator/ (frac, frac);
	friend bool operator==(frac, frac);
	friend bool operator!=(frac, frac);
	friend bool operator< (frac, frac);
	friend bool operator> (frac, frac);
	friend bool operator>=(frac, frac);
	friend bool operator<=(frac, frac);
	friend std::ostream& operator<<(std::ostream &out, const frac &a);
	friend std::istream& operator>>(std::istream &in, frac &a);
};

int Nok(int, int);
int Nod(int, int);
void OutAnswer(frac**, std::string*, int, int);
bool CheckOne(frac**, int);
bool CheckTwo(frac**, int, int);
frac BasisOne(frac**, int, int ,int& ,int&);
frac** NewTable(frac**, std::string*, std::string*, int, int, int, int);