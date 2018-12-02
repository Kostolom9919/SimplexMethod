#pragma once
#include <iostream>
#include <string>

class drob {
private:
	int ch, zn;
public:
	drob(int a, int b) { ch = a; if (b != 0)zn = b; else zn = 1; }
	drob(int a) { ch = a; zn = 1; }
	drob() { ch = 0; zn = 1; }
	void Set(int a, int b) { ch = a; if (b != 0)zn = b; else zn = 1; }
	void Set(int a) { ch = a; zn = 1;}
	void Set() { ch = 0; zn = 1;}
	friend drob operator+ (drob, drob);
	friend drob operator+ (drob, int);
	friend drob operator+ (int, drob);

	friend drob operator- (drob, drob);
	friend drob operator- (drob, int);
	friend drob operator- (int, drob);

	friend drob operator* (drob, drob);
	friend drob operator* (drob, int);
	friend drob operator* (int, drob);

	friend drob operator/ (drob, drob);
	friend drob operator/ (drob, int);
	friend drob operator/ (int, drob);

	friend bool operator==(drob, drob);
	friend bool operator==(drob, int);
	friend bool operator==(int, drob);

	friend bool operator!=(drob, drob);
	friend bool operator!=(drob, int);
	friend bool operator!=(int, drob);

	friend bool operator< (drob, drob);
	friend bool operator< (drob, int);
	friend bool operator< (int, drob);

	friend bool operator> (drob, drob);
	friend bool operator> (drob, int);
	friend bool operator> (int, drob);

	friend bool operator>=(drob, drob);
	friend bool operator>=(drob, int);
	friend bool operator>=(int, drob);

	friend bool operator<=(drob, drob);
	friend bool operator<=(drob, int);
	friend bool operator<=(int, drob);
	friend std::ostream& operator<<(std::ostream &out, const drob &a);
	friend std::istream& operator>>(std::istream &in, drob &a);
};

int Nok(int, int);
int Nod(int, int);
void OutAnswer(drob**, std::string*, int, int);
bool CheckOne(drob**, int);
bool CheckTwo(drob**, int, int);
drob FunctionOne(drob**, int, int ,int& ,int&);
void NewTable(drob **, drob**, std::string*, std::string*, int, int, int, int);