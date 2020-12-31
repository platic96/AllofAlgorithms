#include <iostream>
#include <vector>

using namespace std;

int n, board[100][100];

bool jump(int x, int y) {
	if (y >= n || x >= n) return false;
	if (y == n && x == n) return true;
	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int cache[1000][1000];

bool jump2(int x, int y) {
	if (y >= n || x >= n) return false;
	if (y == n && x == n) return true;
	int ret = cache[y][x];
	if (ret != -1)
		return ret;
	int jumpSize = board[y][x];
	return ret = jump2(y + jumpSize, x) || jump2(y, x + jumpSize);
}