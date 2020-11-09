#include <iostream>
#include <vector>

int n;
bool areFriend[10][10];

int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;

	for (int PairWidth = firstFree + 1; PairWidth < n; PairWidth++) {
		if (!taken[PairWidth] && areFriend[firstFree][PairWidth])
		{
			taken[firstFree] = taken[PairWidth] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[PairWidth] = false;
		}
	}
	return ret;
}