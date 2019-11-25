// Напишите программу находящую первые n составных чисел. Программа должна работать не более чем за O(n* log log n) шагов.


#include <iostream>
#include <cmath>
using namespace std;

int composite(int n) {
	if (n < 0) return 0;
	else for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int number_comp = 0;
	int n;
	int num = 0;
	cin >> n;
	while (number_comp != n) {
		if (composite(num) == 0) {
			cout << num << " ";
			number_comp++;
		}
		num++;
	}
	return 0;
}