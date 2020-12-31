#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct RNG
{
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};



unsigned makeSignal() {
	static unsigned seed = 1983;
	unsigned ret = seed;
	seed = ((seed * 214013u) + 2531011u);
	return ret % 10000 + 1;
}

//오프라인 알고리즘
int optimized(const vector<int>& signal, int k) {
	int ret = 0, tail = 0, rangeSum = signal[0];

	for (int head = 0; head < signal.size(); ++head) {
		while (rangeSum<k && tail+1 <signal.size())
		{
			rangeSum += signal[++tail];
		}
		if (rangeSum == k) ret++;
		rangeSum -= signal[head];
	}
	return ret;
}

void print_value(stack<int>& st) {
	int d;
	while (!st.empty())
	{
		d = st.top();
		st.pop();
		cout << d << "	";
	}
	cout << endl;
}
//온라인 알고리즘

int countRange(int k, int n) {
	queue<int> range;
	stack<int> st;
	bool flag;
	long long seed;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; ++i) {
		seed = makeSignal();
		int newSignal = seed;//rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
			
		}
		if (rangeSum == k) { ret++;}
	}
	return ret;
}

int main() {
	int C;
	int k,n;
	int ret;
	cin >> C;

	while (C--)
	{
		cin >> k >> n;
		ret  = countRange(k, n);
		cout << ret << endl;
	}
	return 0;
}