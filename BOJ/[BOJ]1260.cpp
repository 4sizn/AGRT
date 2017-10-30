#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int N, M, V;
 
queue<int> q_data;
vector<int> bfs_arr;
vector<int> dfs_arr;
bool IsExistQueue(int index);
int flag[1001];
 
void BFS(int **MAP)
{
	q_data.push(V);
 
	while (q_data.size() > 0)
	{
		int new_vertex = q_data.front();
	
		q_data.pop();
 
		for (int i = 0; i <= N; i++)
		{
			if (MAP[new_vertex][i] == 1)
			{
				q_data.push(i);
				MAP[new_vertex][i] = MAP[i][new_vertex] = 0;
			}
		}
		
		if(!IsExistQueue(new_vertex))
		bfs_arr.push_back(new_vertex);
	}
}
 
bool IsExistQueue(int index)
{
	bool result = false;
	for (int i = 0; i < bfs_arr.size(); i++)
	{
		if (index == bfs_arr[i])
			result = true;
	}
	return result;
}
 
void DFS(int **MAP, int v)
{
	dfs_arr.push_back(v);
	flag[v] = 1;
 
	for (int i = 0; i <= N; i++)
	{
		if (MAP[v][i] == 1 && !flag[i])
		{
			MAP[v][i] = MAP[i][v] = 0;
			DFS(MAP, i);
		}
	}
}
 
int main()
{
	
	cin >> N >> M >> V;
	int **MAP = new int*[N + 1]();
	int **MAP1 = new int*[N + 1]();
 
	for (int i = 0; i <= N + 1; i++)
	{
		MAP[i] = new int[N + 1]();
		MAP1[i] = new int[N + 1]();
	}
 
	for (int i = 0; i < M; i++)
	{
		int temp1; int temp2;
		cin >> temp1 >> temp2;
		MAP[temp1][temp2] = MAP[temp2][temp1] = 1;
		MAP1[temp1][temp2] = MAP1[temp2][temp1] = 1;
	}
	DFS(MAP1, V);
	BFS(MAP);
 
	for (int i = 0; i < dfs_arr.size(); i++)
		cout << dfs_arr[i] << " ";
	cout << endl;
 
	for (int i = 0; i < bfs_arr.size(); i++)
		cout << bfs_arr[i] << " ";
	cout << endl;
	
	
	return 0;
}
