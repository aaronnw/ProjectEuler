#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//Returns the length of the Collatz sequence starting at the given number
long long calcSequenceLength(long long x) {
	long count = 1;
	while (x != 1) {
		if ((x % 2) == 0) {
			x = x / 2;
		}
		else {
			x = (3 * x) + 1;
		}
		count++;
	}
	return count;
}

int main() {
	long maxLength = 0;
	long currentLength = 0;
	long startVal = 2;
	long finalVal = 1000000;
	long solution = 0;
	for (long i = startVal; i < finalVal; i++) {
		long currentLength = calcSequenceLength(i);
		//Stores the value of the number with the longest sequence
		if (currentLength > maxLength) {
			maxLength = currentLength;
			solution = i;
		}
	}
	cout << solution << endl;

	system("pause");
	return 0;
}