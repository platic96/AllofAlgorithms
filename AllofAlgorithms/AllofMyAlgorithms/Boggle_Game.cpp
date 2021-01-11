#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int dx[8] = { -1,-1,-1,1,1,1,0,0 };
int dy[8] = { -1,0,1,-1,0,1,-1,1 };

char board[5][5];

using namespace std;

bool hasWord(const string& word, int y, int x) {
	if (x<0 || y<0) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];

		if (hasWord(word.substr(1), nextY, nextX))
			return true;
	}
	return false;
}

int main() {
	int c = 0;
	int N = 0;

	bool isFound = false;
	char (*out)[10];
	cin >> c;
	while (c > 0)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++) {
				cin >> board[i][j];
			}
		}
		cin >> N;
		out = new char[N][10];
		for (size_t i = 0; i < N; i++)
		{
			cin >> out[i];
		}
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < 5; j++) {
				for (size_t k = 0; k < 5; k++)
				{
					if (hasWord(out[i], j, k))
					{
						isFound = true;
						break;
					}
					else {
						isFound = false;
					}
				}
				if (isFound) {
					string str = out[i];
					cout << str << "  YES" << endl;
					break;
				}
			}
			if (isFound) {
				continue;
			}
			string str = out[i];
			cout << str << "  NO" << endl;
		}
		c--;
	}
	return 0;
}