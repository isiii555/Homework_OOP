#include <iostream>
using namespace std;

// Task 1.

//class Fraction {
//private:
//	int numerator; // suret
//	int denominator; // mexrec
//public:
//	void InIt(int num,int den) {
//		numerator = num;
//		denominator = den > 0 ? den : 1;
//	}
//	Fraction Multiply(const Fraction& f2) {
//		Fraction f3;
//		numerator = numerator * f2.numerator;
//		denominator = denominator * f2.denominator;
//		f3.InIt(numerator, denominator);
//		return f3;
//	}
//	Fraction Add(const Fraction& f2) {
//		Fraction f3;
//		numerator = numerator * f2.denominator + f2.numerator * denominator;
//		denominator = denominator * f2.denominator;
//		f3.InIt(numerator, denominator);
//		return f3;
//	}
//	Fraction Minus(const Fraction& f2) {
//		Fraction f3;
//		numerator = numerator * f2.denominator - f2.numerator * denominator;
//		denominator = denominator * f2.denominator;
//		f3.InIt(numerator, denominator);
//		return f3;
//	}
//	Fraction Divide(const Fraction& f2) {
//		Fraction f3;
//		numerator = numerator * f2.denominator;
//		denominator = denominator * f2.denominator;
//		f3.InIt(numerator, denominator);
//		return f3;
//	}
//	void Simplify(Fraction& f2) {
//		int d;
//		int temp;
//		int a = f2.numerator;
//		int b = f2.denominator;
//		if (a > b)
//		{
//			temp = a;
//			a = b;
//			b = temp;
//		}
//		while ((d = a % b) != 0) {
//			a = b;
//			b = d;
//		}
//		f2.numerator /= b;
//		f2.denominator /= b;
//	}
//	void Print() {
//		cout << numerator << "/" << denominator << endl;
//	}
//};
//
//
//void main() {
//
//	Fraction f1;
//	f1.InIt(4, 7);
//	Fraction f2;
//	f2.InIt(5, 5);
//	Fraction result = f1.Multiply(f2);
//	result.Simplify(result);
//	result.Print();
//}

// Task 2.

//class Point {
//	int x;
//	int y;
//public:
//	Point() { x = 0; y = 0; }
//
//	Point(int argX, int argY) {
//		SetX(argX);
//		SetY(argY);
//	}
//
//	int GetX() { return x; }
//	int GetY() { return y; }
//
//	void SetX(int argX) { x = argX; }
//	void SetY(int argY) { y = argY; }
//
//
//
//	void Print() {
//		cout << "X: " << x << "\nY: " << y << endl;
//	}
//};