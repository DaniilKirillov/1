#include <iostream>
#include <string.h>
using namespace std;

bool TSC(string *s) {
	int c = 0;
	for (int i = 0; i < s->length; i++) {
		if (s[i] == "(") c++;
		else c--;
		if (c < 0) return false;
	}
	return c == 0;
}

int main() {
	string s;
}