#include <iostream>
#include "functions.h"
#include <cmath>

using namespace std;

long factorial(long x) {
	if (x == 0) {
		return 1;
	}
	return x * factorial(x - 1);

}

int fibonacci_r(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

bool is_prime_r(int value, int n) {
	
	if (value <= 2)
		return (value == 2) ? true : false;
	if (value % n == 0)
		return false;
	if (n * n > value)
		return true;


	return is_prime_r(value, n + 1);
}

int sum_r(int list[], int list_size) {
	if (list_size <= 0) {
		return 0;
	}
	return sum_r(list, list_size - 1) + list[list_size - 1];
}	

void output_reverse_list_r(int list[], int list_size) {

	if (list_size > 0)
	{
		output_reverse_list_r(list + 1, list_size - 1);

		cout << list[0] << "   ";
	}
}