#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int start, vector<vector<int>>& graph)
{
	vector<int> visited(graph.size() + 1, 0);
	stack<int> s;

	s.push(start);

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (visited[cur] == 0)
		{
			visited[cur] = 1;
			cout << cur << " ";
		}
		else
		{
			continue;
		}

		for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); it++)
		{
			int next = *it;
			if (visited[next] == 0)
			{
				s.push(next);
			}


		}


	}
	cout << "\n";
}

void DFS2(int now, vector<vector<int>>& graph,vector<int>& visited)
{
	if (visited[now] == 1)
	{
		return;
	}

	visited[now] = 1;
	cout << now << " ";

	for (auto next:graph[now])
	{
		if (visited[next] == 0)
		{
			DFS2(next, graph, visited);
		}
	}
}

void BFS(int start, vector<vector<int>>& graph)
{
	vector<int> visited(graph.size() + 1, 0);
	queue<int> q;

	q.push(start);
	visited[start] = 1;
	cout << start << " ";

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : graph[cur])
		{
			if (visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
				cout << next << " ";
			}


		}


	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V;

	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1, vector<int>());

	for (int a = 0; a < M; a++)
	{
		int to, from;
		cin >> to >> from;
		graph[to].push_back(from);
		graph[from].push_back(to);
	}
	for (auto& a : graph)
	{
		sort(a.begin(), a.end());
	}
	vector<int> visited(graph.size() + 1, 0);
	DFS2(V, graph, visited);
	//DFS(V, graph);
	cout << "\n";
	BFS(V, graph);
	return 0;
}
