#include <iostream>
#include <vector>
#include <algorithm>

int dx[8] = { -1,-1,-1,1,1,1,0,0 };
int dy[8] = { -1,0,1,-1,0,1,-1,-1 };

using namespace std;

bool hasWord(const string& word, int y, int x) {
	if (x<0 || y<0) return false;
	if (borard[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];

		if (hasWord(word.substr(1), nextY, nextX))
			return true;
	}
	return false;
}