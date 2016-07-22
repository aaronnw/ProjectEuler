#include <iostream>
#include <math.h>

using namespace std;

//Returns the number of divisors for a given long
int getNumDivisors(long long x) {
	//Starts at 2 for the number itself and 1 
	int num = 2;
	//For each value up to the square root of the number
	//Increment the count of divisors twice for both the larger and smaller divisors
	for (long long i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) {
			num += 2;
		}
	}
	return num;
}

int main() {
	long i = 1;
	int target = 500;
	long increment = 1;
	//Guess for the number of primes to filter out to reach the target efficiently
	long maxPrime = 100000000;
	bool found = false;
	////////////////////////////////////////////////
	//Prime Sieve
	bool* primes = new bool[maxPrime];
	//Assume all numbers are prime
	for (long i = 2; i < maxPrime; i++) {
		primes[i] = true;
	}
	//Remove all multiples of numbers
	for (long j = 2; j < sqrt(maxPrime); j++) {
		if (primes[j]) {
			for (long k = j * 2; k< maxPrime; k += j) {
				primes[k] = false;
			}
		}
	}
	cout << "primes found " << endl;
	///////////////////////////////////////////////
	//Progress through each triangle number
	while (found == false) {
		if (!primes[i]) {
			if (getNumDivisors(i) > target) {
				cout << i << endl;
				found = true;
			}
		}
		increment++;
		i += increment;
	}
	system("pause");
	return 0;
}