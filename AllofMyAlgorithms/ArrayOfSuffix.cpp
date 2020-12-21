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
	for (int i = 0; <i< s.size(); ++i) perm.push_back(i);
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm;
}