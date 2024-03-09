#include <stdio.h> #include <stdlib.h>

#define MAX_VERTICES 100


// Structure to represent a node in the adjacency list struct Node {
int vertex;
struct Node* next;
};


// Structure to represent the adjacency list struct Graph {
struct Node* adjList[MAX_VERTICES]; int visited[MAX_VERTICES];
};


// Function to create a new node struct Node* createNode(int v) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (newNode == NULL) {
printf("Memory allocation failed\n"); exit(1);
}
newNode->vertex = v; newNode->next = NULL; return newNode;
}


// Function to add an edge to the graph
 
void addEdge(struct Graph* graph, int src, int dest) { struct Node* newNode = createNode(dest); newNode->next = graph->adjList[src];
graph->adjList[src] = newNode;
}


// Function to initialize visited array
void initVisited(struct Graph* graph, int vertices) { for (int i = 0; i < vertices; ++i) {
graph->visited[i] = 0;
}
}


// Depth First Search traversal function void DFS(struct Graph* graph, int vertex) {
struct Node* adjNode = graph->adjList[vertex]; graph->visited[vertex] = 1;
printf("%d ", vertex);


while (adjNode != NULL) {
int connectedVertex = adjNode->vertex;
if (graph->visited[connectedVertex] == 0) { DFS(graph, connectedVertex);
}
adjNode = adjNode->next;
}
}


int main() {
int vertices, edges, src, dest;
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
if (graph == NULL) {
printf("Memory allocation failed\n"); exit(1);
}


printf("Enter the number of vertices and edges: "); scanf("%d %d", &vertices, &edges);

for (int i = 0; i < MAX_VERTICES; ++i) { graph->adjList[i] = NULL;
}


printf("Enter the edges (source destination):\n"); for (int i = 0; i < edges; ++i) {
scanf("%d %d", &src, &dest); addEdge(graph, src, dest);
}


initVisited(graph, vertices);


printf("DFS traversal starting from vertex 0: "); DFS(graph, 0); // Start DFS traversal from vertex 0

return 0;
}
