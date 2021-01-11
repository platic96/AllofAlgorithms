#include "AllofHeader.h"

//그래프의 인접 행렬 표현 adj[i][j] = i와 j의 간선의 수
vector<vector<int>> adj;
//무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 꼐산한다.
//결과로 이어지는 circuit을 뒤집으면 오일러 서킷이 된다.

void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj[here].size(); there++) {
		while (adj[here][there] >0)
		{
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
		
	}
	circuit.push_back(here);
}