#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bruteForce(const vector<int>& h) {
	int ret = 0;
	int N = h.size();

	for (int i = 0; i < N; i++) {
		int minLeft = h[i];
		for (int j = i; j < N; j++) {
			minLeft = min(minLeft, h[j]);
			ret = max(ret, (i - j + 1)*minLeft);
		}
	}
}

vector<int> h;

int RefreshFence(int left,int right) {
	if (left == right) return h[left];

	int mid = (left + right) / 2;

	int ret = max(RefreshFence(left, mid), RefreshFence(mid, right);

	int lo = mid, hi = mid + 1;

	int height = min(h[lo], h[hi]);

	ret = max(ret, height);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			hi++;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(h[lo], height);
		}
		ret = max(ret, height *(hi - lo + 1));
	}
	return ret;
}