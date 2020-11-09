#include <iostream>
#include <vector>

using namespace std;

vector<int> factor(int n) {
	if (n == 1) return vector<int>(1, 1);
	vector<int> ret;
	for (int i = 2; 1 < n; i++) {
		while (n%i == 0) {
			n /= i; 
			ret.push_back(i);
		}

	}
	return ret;
}

int main() {
	int n = 100;
	vector<int> result;
	result = factor(n);

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i)<<endl;
	return 0;
}