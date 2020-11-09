#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

int inefficientMax(const vector<int>& A) {
	int N = A.size(); int ret = MIN;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += A[k];
			}
			ret = max(ret, sum);
		}
	}
	return ret;
}

int betterMaxSum(const vector<int>& A) {
	int N = A.size(); int ret = MIN;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}
//A[lo..hi]의 연속된 부분 구간의 최대 합을 구한다. 
int fastMaxSum(const vector<int>&A, int lo, int hi) {
	//기저 사례 : 구간의 길이가 1일 경우
	if (lo == hi) return A[lo];
	//배열을 A[lo..mid],A[mid..hi]의 두 조각으로 나눈다.
	int mid = (lo + hi) / 2;
	//두 부분에 모두 걸쳐 있는 최대 합을 구한다. 이 구간은
	//A[lo..mid]와 A[mid..hi]형태를 갖는 구간의 합으로 이루어진다.
	//A[i..mid]형태를 갖는 구간을 찾는다
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; i--) {
		sum += A[i];
		left = max(left, sum);
	}
	sum = 0;
	//A[mid..j]형태를 갖는 구간을 찾는다
	for (int j = mid + 1; j <= hi; j++) {
		sum += A[j];
		right = max(right, sum);
	}
	//최대 구간이 두 조각 중 하나에만 속해 있는 경우 답을 재귀 호출로 찾는다.
	int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));

	return max(left + right, single);
}

int fastestMaxSum(const vector<int> &A) {
	int N = A.size(), ret = MIN, psum = 0;
	for (int i = 0; i < N; i++) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
}

int main() {
	vector<int> A{ -7,4,-3,6,3,-8,3,4 };
	int ret = 0;
	ret = inefficientMax(A);
	cout << ret<<endl;
	ret = betterMaxSum(A);
	cout << ret << endl;
	ret = fastMaxSum(A, 0, A.size()-1);
	cout << ret << endl;
	ret = fastestMaxSum(A);
	cout << ret;
	return 0;
}