// CPP code for printing shortest path between
// two vertices of undirected  unweighted graph
#include <iostream>
#include<vector>
#include<list>
#include <bits/stdc++.h>
using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p

bool BFS(vector<int> adj[], int src, int dest, int v,
		int pred[], int dist[])
{
	
	list<int> queue;

	// boolean array visited[] which stores the
	// information whether ith vertex is already visited or not
	bool visited[v];

	// initially all vertices are unvisited
	// so v[i] for all i is false
	
	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	// now source is first to be visited and
	// distance from source to itself should be 0
	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	// standard BFS algorithm
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				// We stop BFS when we find
				// destination.
				if (adj[u][i] == dest)
					return true;
			}
		}
	}

	return false; //if the queue is empty before reaching our destination , that means the source and the destination are connected
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestPath(vector<int> adj[], int s,int dest, int v)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s
	int pred[v], dist[v];

	if (BFS(adj, s, dest, v, pred, dist) == false) {
		cout << "Given source and destination"
			<< " are not connected";
		return;
	}

	// vector path stores the shortest path
	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	// distance from source is in distance array
	cout << "Shortest path length is : "
		<< dist[dest];

	// printing path from source to destination
	cout << "\nPath is::\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
}


int main()
{ 
  	int v, src, dest;
	cout<<"please give: number of vertices, the source and the destination \n";
	cin>>v>>src>>dest;
	vector<int> adj[v];
	int M[v][v];
	for(int i=0;i<v;i++)
	{
		for (int j=0;j<v;j++)
		{
			int a;
			cin>>a;
			M[i][j]=a;
		}
	}
	
	for(int i=0;i<v;i++)
	{
		for (int j=0;j<i;j++)
		{
			if(M[i][j] == 1)
				add_edge(adj, i, j);
		}
             printShortestPath(adj, src-1, dest-1, v);
	
	return 0;
	
}
}
