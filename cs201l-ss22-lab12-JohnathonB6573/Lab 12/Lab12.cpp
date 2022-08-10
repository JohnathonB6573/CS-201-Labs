#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	
	int x, c[5];//initialization

	cout << "Please enter an integer\n";// initial prompt
	cin >> x;

	cout << endl << x << "! = " << factorial(x) << endl;//factorial

	cout << endl << "fibonacci(" << x << ") = " << fibonacci_r(x) << endl << endl;//fibonacci

	cout << "Enter a number to see if it is prime\n"; //prime number
	cin >> x;
	if (is_prime_r(x, 2) == true) {
		cout << x << " is a primme number" << endl;
	}
	else {
		cout << x << " is not a prime number" << endl;
	}

	cout << endl << "Next we will enter 5 values into an array" << endl;//array addition
	for (int i = 0; i < 5; i++) {
		cout << "Enter a value for index " << endl;
		cin >> c[i];
	}
	cout << "The sum of all the values is " << sum_r(c, 5) << endl;//array print reverse

	cout << "The list output in reverse is " << endl;
	output_reverse_list_r(c, 5);
}