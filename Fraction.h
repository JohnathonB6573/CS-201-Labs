#pragma once
// Johnathon Brumdield
// 07/14/22
// Lab 10

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int getGCD(int num1, int num2);
	int denominator;
	int numerator;

public:
	void reduce();
	friend ostream& operator<<(ostream& os, const Fraction& fract);
	friend istream& operator>>(istream& is, Fraction& fract);
	Fraction();
	void twof(Fraction &f2);
    const Fraction operator+(Fraction rhs);
	const Fraction operator-(Fraction rhs);
	const Fraction operator*(Fraction rhs);
	const Fraction operator/(Fraction rhs);
	bool operator==(Fraction rhs);
	void makepositive(Fraction &f2);
};

