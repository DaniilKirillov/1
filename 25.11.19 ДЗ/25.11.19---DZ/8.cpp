// Напишите функцию вычисляющую праймориал числа. Программа должна работать не более чем за O(n*log log n) шагов.

#include <iostream>
#include <cmath>
using namespace std;

int prime(int n) {
	if (n <= 0) return 0;
	else for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int n, primorial = 1;
	cin >> n;
	 for (int i = 0; i <= n; i++) {
		if (prime(i) == 1) {
			primorial = primorial * i;
		}
	}
	cout << primorial;
	return 0;
}