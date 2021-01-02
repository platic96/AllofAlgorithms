// Algorithms.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
