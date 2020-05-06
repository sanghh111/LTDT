#include <stdio.h>
#include <queue>
#include <conio.h>
#include <stack>
#include "graph.h"
using namespace std;


// Khởi tạo đồ thị
Graph::Graph(int size)
{
	int i, j;

	// xác định số đỉnh của đồ thị
	if (size < 2)
		n = 2;
	else 
		n = size;

	// Tạo mảng 2 chiều động n*n
	edge = new int*[n];
	for (i = 0; i < n; i++)
		edge[i] = new int[n];
	
	// Set mặc định không có các đỉnh đc nối với nhau (= 0)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			edge[i][j] = 0;
}

// Xóa đồ thị
Graph::~Graph()
{
	for (int i = 0; i < n; ++i)
		delete[] edge[i];	
	delete[] edge;
}

// kiểm tra giữa 2 đỉnh có kề nhau hay không
bool Graph::isConnected(int x, int y)
{
	if (edge[x - 1][y - 1] == 1)
		return true;

	return false;
}

// thêm cạnh nối đỉnh x và đỉnh y
void Graph::addEdge(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return;

	edge[x - 1][y - 1] = edge[y - 1][x - 1] = 1;
}

void Graph::DepthFirstSearch(int begin, int search)
{
	if (begin > n || begin < 0 || search > n || search < 0)
	{
		printf("Could not traverse this graph with your request\n");
		return;
	}

	stack <int> open;
	bool *close = new bool[n];
	int i;
	int p;

	// mặc định các đỉnh chưa được duyệt
	for (i = 0; i < n; i++)
		close[i] = false;

	// đưa đỉnh gốc begin vào stack chuẩn bị duyệt
	open.push(begin);
	
	printf("With Depth first Search , we have vertex(s):\n");

	while (!open.empty())
	{
		// lấy 1 đỉnh ra khỏi stack, thành đỉnh đang xét p.
		do
		{
			if (open.empty())
				return;

			p = open.top();
			open.pop();
		} while (close[p - 1] == true);

		// in ra đỉnh đang xét
		printf("%d ", p);

		// đỉnh search đã được duyệt qua
		close[p - 1] = true;

		// kết thúc tìm kiếm khi đã tìm ra kết quả		
		if (p == search)
			return;
		
		// khi chưa tìm dược, tìm đỉnh kề với đỉnh đang xét đưa nó vào stack.
		for (i = 1; i <= n; i++)
		{
			if (isConnected(p, i) && !close[i - 1])
			{
				open.push(i);
			}
		}
	}
	printf("\n");

	delete[] close;
}
void Graph::BreadthFirstSearch(int begin, int search)
{
	if (begin > n || begin < 0 || search > n || search < 0)
	{
		printf("Could not traverse this graph with your request\n");
		return;
	}
	queue <int> open;
	bool *close = new bool[n];
	int i;
	int p;
 
	//  mặc định các đỉnh chưa được duyệt
	for (i = 0; i < n; i++)
		close[i] = false;
 
	// đưa đỉnh gốc S vào queue chuẩn bị duyệt
	open.push(begin);
 
	printf("With Breadth first Search , we have vertex(s):\n");
 
	while (!open.empty())
	{
		// lấy 1 đỉnh ra khỏi queue, thành đỉnh đang xét p.
		do
		{
			if (open.empty())
				break;
 
			p = open.front();
			open.pop();
		} while (close[p - 1] == true);
 
		// in ra đỉnh đang xét
		printf("%d ", p);
 
		// đỉnh p đã được duyệt qua
		close[p - 1] = true;
 
		// kết thúc tìm kiếm khi đã tìm ra kết quả
		if (p == search)
			break;
		
		// khi chưa tìm dược, tìm đỉnh kề với đỉnh đang xét đưa nó vào stack.
		for (i = 1; i <= n; i++)
		{
			if (isConnected(p, i) && !close[i - 1])
			{
				open.push(i);
			}
		}
	}
	printf("\n");
 
	delete[] close;
}
