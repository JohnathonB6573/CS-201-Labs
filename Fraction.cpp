// Johnathon Brumdield
// 07/14/22
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

}

ostream& operator<<(ostream& os, const Fraction& fract)//ostream function
{
	os << fract.numerator << '/' << fract.denominator;
	return os;
}

istream& operator>>(istream& is, Fraction& fract) {//istream function
	char a;
	is >> fract.numerator >> a >> fract.denominator;
	return is;
}

Fraction::Fraction() {//default constructor
	numerator = 0;
	denominator = 0;
}

void Fraction :: twof(Fraction& f2) {
	int d1 = denominator, d2 = f2.denominator, d3 = denominator * f2.denominator;//function for adjusting the fractions before they do the operation
	denominator = d3;
	f2.denominator = d3;
	numerator *= d2;
	f2.numerator *= d1;
}

 const Fraction Fraction :: operator+(Fraction rhs) {//add operator
	Fraction temp;
	twof(rhs);
	temp.numerator = numerator + rhs.numerator;
	temp.denominator = denominator;
	temp.reduce();
	return temp;
}

 const Fraction Fraction :: operator-(Fraction rhs) {//subtraction operator
	 Fraction temp;
	 twof(rhs);
	 temp.numerator = numerator - rhs.numerator;
	 temp.denominator = denominator;
	 temp.reduce();
	 return temp;
 }

 const Fraction Fraction :: operator*(Fraction rhs) {//multiplication operator
	 Fraction temp;
	 twof(rhs);
	 temp.numerator = numerator * rhs.numerator;
	 temp.denominator = denominator;
	 temp.reduce();
	 return temp;
 }

 const Fraction Fraction :: operator/(Fraction rhs) {//division operator
	 Fraction temp;
	 twof(rhs);
	 temp.numerator = (numerator / rhs.numerator) + (numerator % rhs.numerator);
	 temp.denominator = denominator;
	 temp.reduce();
	 return temp;
 }

 void Fraction :: makepositive(Fraction &f2) {//makes the fractions positive
	 if (numerator < 0 && f2.denominator < 0) {
		 numerator *= -1;
		 f2.denominator *= -1;
	 }
	 if (f2.numerator < 0 && denominator < 0) {
		 f2.numerator *= -1;
		 denominator *= -1;
	 }
	 if (numerator < 0 && denominator < 0) {
			 numerator *= -1;
			 denominator *= -1;
	 }
	 if (f2.numerator < 0 && f2.denominator < 0) {
		 f2.numerator *= (- 1);
		 f2.denominator *= (-1);
	 }
 }

 bool Fraction :: operator==(Fraction rhs) {//equality operator
	 makepositive(rhs);
	 twof(rhs);
	 if (numerator == rhs.numerator && denominator == rhs.denominator) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }

