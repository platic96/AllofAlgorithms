#include "AllofHeader.h"

//그래프의 인접 리스트
vector<vector<int>> adj;
//각 지점을 방문했는지 여부를 나타낸다.
vector<bool> visited;
//깊이 우선 탐색을 구현

void dfs(int here) {
	cout << "DFS visits" << here << endl;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
	//더이상 방문할 정점이 없으니 재귀호출 종료하고 이전 정점으로
}


//모든 정점을 방문

void dfsAll() {
	//visited를 모두 valse로 초기화.
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < adj.size(); ++i)
		if (!visited[i])
			dfs(i);   
}