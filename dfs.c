#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex
{
	char label;
	int val;
	bool visited;
};

//all declarations and initializations
int stack[MAX];
int top = -1;
int vertexCount = 0;
int adjMatrix[MAX][MAX];
struct Vertex* list[MAX];

//functions of stack

void push(int data)
{
	stack[++top] = data;
}

int pop()
{
	return stack[top--];
}

int peek()
{
	return stack[top];
}

bool isEmpty()
{
	return top == -1;
}

//functions for the graph

void addVertex(char label)
{
	struct Vertex* v = (struct Vertex *)malloc(sizeof(struct Vertex));
	printf("%c", v->label);
	v->label = label;
	v->visited = false;
	list[vertexCount++] = v;
}

void addEdge(int start, int end)
{
	adjMatrix[start][end] = 1;
	adjMatrix[end][start] = 1;
}

int getAdjVertex(int vindex)
{
	int i;
	for(i=0; i<vertexCount; i++){
		if(adjMatrix[vindex][i] == 1 && list[i]->visited == false){
			return i;
		}
	}
	return -1;
}

void display(int v)
{
	printf("%c ", list[v]->label);
}

void Dfs()
{
	int i;
	list[0]->visited = true;
	push(0);
	display(0);
	int unvisited_vertex = getAdjVertex(peek());
	printf("after peeking\n");
	while(!isEmpty())
	{
		if(unvisited_vertex == -1)
		{
			pop();
		}
		else
		{
			list[unvisited_vertex]->visited = true;
			display(unvisited_vertex);
			push(unvisited_vertex);
		}

	}

	for(i=0; i<vertexCount++; i++)
	{
		list[i]->visited = false;
	}
}

int main()
{
	int i, j;
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			adjMatrix[i][j] == 0;
		}
	}
	printf("starting to add vertices\n");
	addVertex('S');
	addVertex('A');
	addVertex('B');
	addVertex('C');
	addVertex('D');
	printf("end of adding vertices\n");
	printf("starting to add edges\n");	
	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(1,4);
	addEdge(2,4);
	addEdge(3,4);
	printf("end of adding edges\n");
		
	Dfs();
	return 0;
}





