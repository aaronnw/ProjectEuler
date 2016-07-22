#include <iostream>
#include <math.h>

using namespace std;

//Finds the sum of all primes under a specified number n using a prime number sieve

int main(){
	long n = 2000000;
	long long sum = 0;
	bool* primes = new bool[n];
	//Assume all numbers are prime
	for (long i = 2; i < n; i ++) {
		primes[i] = true;
	}
	//Remove all multiples of numbers
	for (long j = 2; j < sqrt(n); j++) {
		if (primes[j]) {
			for (long k = j*2; k< n; k+=j) {
				primes[k] = false;
			}
		}
	}
	for (int x = 2; x < n; x++) {
		if (primes[x]) {
			sum += x;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}   