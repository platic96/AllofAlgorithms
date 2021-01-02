#include "stdafx.h"

struct SuffixComparator
{
	const string& s;
	SuffixComparator(const string& s) : s(s){}
	bool operator () (int i, int j) {
		return strcmp(s.c_str() + i, s.c_str() + j);
	}
};

vector<int> getSuffixaraayNaive(const string& s) {
	vector<int> perm;
	for (int i = 0; i < s.size(); ++i) perm.push_back(i);
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm;
}

// �� ���̻���� ù t���ڸ� �������� �� �׷� ��ȣ�� �־��� ��
// �־��� �� ���̻縦 ù 2*t���ڸ� �������� ���Ѵ�.
//group[]�� ���̰� 0�� ���̻絵 �����Ѵ�.

struct Comparator
{
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t)
	{
		t = _t;
	}
	bool operator ()(int a, int b) {
		if (group[a] != group[b]) return group[a] < group[b];

		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray(const string& s){
	int n = s.size();

	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i) group[i] = s[i];
	group[n] = -1;

	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		perm[i] = i;
	}
	while (t<n)
	{
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);

		t *= 2;
		if (t >= n)break;

		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; ++i) {
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
			{
				newGroup[perm[i]] = newGroup[perm[i - 1]];
			}
		}
		group = newGroup;
	}
	return perm;
}