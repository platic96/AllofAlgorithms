// Algorithms.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void Partition(vector<int>& arr, int start, int end) {
	int mid;
	if (left < right) {
		mid = (start + end) / 2;
		Partition(arr, start, mid);
		Partition(arr, mid, end);
	}
}

int main()
{
    return 0;
}
