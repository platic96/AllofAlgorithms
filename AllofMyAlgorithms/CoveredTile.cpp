#include <iostream>
#include <vector>

using namespace std;

const int coverdType[4][3][2]=
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
//겹치거나 검은 칸을 덮을 때 False 를 반환한다.
bool set(vector<vector<int>>& board, int x, int y, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverdType[type][i][0];
		const int nx = x + coverdType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}
//board의 모든 빈칸을 덮을 수 있는 방법의 수를 반환한다.
//board[i][j] = 1 이미 덮인 칸 혹은 검ㄴ은 칸
//board[i][j] = 0 아직 덮이지 않은 칸
int cover(vector<vector<int>>& board) {
	//아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾음
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++ ) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
			if (y != -1)break;
		}
	}
	//기저사례 1 : 모든 칸을 채웠으면 1을 반환한다.
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, x, y, type, 1))
			ret += cover(board);
		set(board, x, y, type, -1);
	}
	return ret;
}