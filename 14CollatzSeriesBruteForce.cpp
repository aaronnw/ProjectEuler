#include <iostream>
#include <math.h>
#include <string>

using namespace std;

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
	long result = 0;
	long startVal = 2;
	long finalVal = 1000000;
	for (long i = startVal; i < finalVal; i++) {
		long result = calcSequenceLength(i);
		if (result > maxLength) {
			maxLength = result;
		}
	}
	cout << maxLength << endl;

	system("pause");
	return 0;
}