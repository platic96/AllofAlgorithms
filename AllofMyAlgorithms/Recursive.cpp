#include <iostream>
#include <vector>

using namespace std;

int sum(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret += i;
	}
	return ret;
}

int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n-1);
}

void printPicked(vector<int>& picked) {
	for (auto i : picked.begin) {
		cout << i << endl;
	}
}

//중첩 반복문 대체하기
//n : 전체 원소의 수
//picked : 지금까지 고른 원소들의 번호
//toPick: 더 고를 원소의 수
//일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
void pick(int n, vector<int>& picked, int toPick) {
	//기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if (toPick == 0) { printPicked(picked); return; }
	//고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

