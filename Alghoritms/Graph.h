#pragma once
#include <queue>
//template<class type>
class Graph {
private:
	int CountVertices;
	int*MatrixOFAdjacency;//n*n
	int*visited;
public:
	Graph() {
		CountVertices = 0;
		MatrixOFAdjacency = nullptr;
		visited = nullptr;
	}
	void Init(int CountVertices) {
		this->CountVertices = CountVertices;
		this->visited = new int[CountVertices];
		this->MatrixOFAdjacency = new int[CountVertices*CountVertices];
		Clear();
	}
	void Clear() {
		for (int i = 0; i < CountVertices; i++) {
			visited[i] = 0;
			for (int j = 0; j < CountVertices; j++) {
				MatrixOFAdjacency[i*CountVertices + j] = 0;
			}
		}
	}

	void SetEdge(int i, int j, int weight) {
		if (i <= 0 || j <= 0)
			return;
		MatrixOFAdjacency[(i - 1)*CountVertices + j - 1] = weight;
		MatrixOFAdjacency[(j - 1)*CountVertices + i - 1] = weight;
	}
	int GetEdge(int i, int j) {
		if (i <= 0 || j <= 0)
			return 0;
		return MatrixOFAdjacency[(i-1)*CountVertices +j-1];
	}
	void print() {
		std::cout << " ";
		for (int i = 0; i < CountVertices; i++) {
			std::cout <<" "<< i + 1;
		}std::cout << "\n";
	
		for (int i = 0; i < CountVertices; i++) {
			std::cout << i + 1 << " ";
			for (int j = 0; j < CountVertices; j++) {
				std::cout<<MatrixOFAdjacency[i*CountVertices + j]<<" ";
			}
			std::cout << "\n";
		}
	}

	void dfs(int v) {
		visited[v - 1] = 1;
		std::cout << "Vertex " << v << std::endl;
		for (int i = 0; i < CountVertices; i++) {
			if (MatrixOFAdjacency[(v - 1)*CountVertices + i] > 0 && visited[i] == 0) {
				dfs(i+1);
			}
		}

	}
	void bfs(int v) {
		int i;
		for (i = 0; i < CountVertices; i++) {
			visited[i] = 0;
		}
		std::queue<int> q;
		visited[v - 1] = 1;
		std::cout << "Vertex " << v <<std::endl;
		q.push(v - 1);
		while (q.size() > 0) {
			i = q.back();
			q.pop();
			for (int j = 0; j < CountVertices; j++) {
				if (MatrixOFAdjacency[i*CountVertices + j] > 0 && visited[j] == 0) {
					q.push(j);
					visited[j] = 1;
					std::cout << "Vertex " << j+1 << std::endl;
				}
			}
		}
	}
	~Graph() {
		delete[] MatrixOFAdjacency;
		delete[] visited;
	}
};