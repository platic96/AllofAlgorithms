#include "stdafx.h"


const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int poly(int n, int first) {
	if (n == first) return 1;

	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int secont = 1; secont <= n - first; ++secont) {
		int add = secont + first - 1;
		add *= poly(n - first, secont);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int T, N;

	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N;
		poly(N, 0);
	}
	return 0;
}