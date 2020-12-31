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
//��ġ�ų� ���� ĭ�� ���� �� False �� ��ȯ�Ѵ�.
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
//board�� ��� ��ĭ�� ���� �� �ִ� ����� ���� ��ȯ�Ѵ�.
//board[i][j] = 1 �̹� ���� ĭ Ȥ�� �ˤ��� ĭ
//board[i][j] = 0 ���� ������ ���� ĭ
int cover(vector<vector<int>>& board) {
	//���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã��
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
	//������� 1 : ��� ĭ�� ä������ 1�� ��ȯ�Ѵ�.
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, x, y, type, 1))
			ret += cover(board);
		set(board, x, y, type, -1);
	}
	return ret;
}