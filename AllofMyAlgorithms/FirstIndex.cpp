#include <iostream>
#include <vector>

using namespace std;

int fistIndex(const vector<int>& array, int element) {
	for (int i = 0; i < array.size(); i++) {
		if (array[i] == element)
			return i;
	}
	return -1;
}
