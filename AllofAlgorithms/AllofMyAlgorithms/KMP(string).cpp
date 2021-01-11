#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched];
				matched = pi[matched - 1];
			}
		}
	}	
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	int begin = 0, matched = 0;
	while (begin <= n-m)
	{
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

// KMP 전통적인 알고리즘 구현

vector<int> kmpSerch2(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	int matched = 0;
	for (int i = 0; i < n; ++i) {
		while (matched > 0 && H[i] != N[matched])
		{
			matched = pi[matched - 1];
			if (H[i] == N[matched]) {
				matched++;
				if (matched == n) {
					ret.push_back(i - m + 1);
					matched = pi[matched - 1];
				}
			}

		}
	}
	return ret;
}

//s의 접두사도 되고 접미사도 되는 모든 문자열의 길이를 반환

vector<int> getPreifxSuffix(const string& s) {
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k>0)
	{
		ret.push_back(k);
		k = pi[k - 1];
	}
	return ret;
}

// 팰린드롬 만들기

int maxOverlap(const string& a, const string& b) {
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);

	int begin = 0, matched = 0;
	while (begin < n) {
		if (matched < m && a[begin + matched] == b[matched])
		{
			++matched;
			if (begin + matched == n)
				return matched;
		}
		else
		{
			if (matched == 0) {
				++begin;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}
