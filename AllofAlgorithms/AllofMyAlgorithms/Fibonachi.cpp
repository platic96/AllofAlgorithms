#include <iostream>
#include <vector>

using namespace std;

int fibonachi[1000];

int fib(int n)
{
	fibonachi[0] = fibonachi[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibonachi[i] = fibonachi[n - 1] + fibonachi[n - 2];
	}
	return fibonachi[n];
}
