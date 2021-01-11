#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool solve(string st) {
	stack<char> a;
	a.push(st[0]);
	int i = 1;
	while (true)
	{
		if (i == st.size())
			return a.empty();
		switch (st[i])
		{
		case '(':
		case '[':
		case '{': a.push(st[i]); break;
		case ')': if (a.top() == '(') {a.pop();}
				  else return false; break;
		case ']': if (a.top() == '[') { a.pop();}
				  else return false; break;
		case '}': if (a.top() == '{') { a.pop();}
				  else return false; break;
		}
		i++;
	}
	return true;
}

void main() {
	string tmp;
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> tmp;
		if (solve(tmp))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}