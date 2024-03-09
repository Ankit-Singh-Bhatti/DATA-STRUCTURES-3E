#include <stdio.h> #include <stdlib.h>
#define MAX_VERTICES 100


// Structure to represent a queue for BFS traversal struct Queue {
int items[MAX_VERTICES]; int front;
int rear;
};


// Function to create a new queue struct Queue* createQueue() {
struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); q->front = -1;
q->rear = -1; return q;
}


// Function to check if the queue is empty int isEmpty(struct Queue* q) {
return q->rear == -1;
}


// Function to add an item to the queue
 
void enqueue(struct Queue* q, int value) { if (q->rear == MAX_VERTICES - 1) {
printf("Queue Overflow\n"); return;
}
if (q->front == -1) { q->front = 0;
}
q->rear++;
q->items[q->rear] = value;
}


// Function to remove an item from the queue int dequeue(struct Queue* q) {
if (isEmpty(q)) {
printf("Queue Underflow\n"); exit(1);
}
int item = q->items[q->front]; q->front++;
if (q->front > q->rear) {
q->front = q->rear = -1;
}
return item;
}


// Function to create a graph and add an edge between two vertices
void addEdge(int adjacencyMatrix[][MAX_VERTICES], int src, int dest) { adjacencyMatrix[src][dest] = 1;
adjacencyMatrix[dest][src] = 1; // For undirected graph
}
 
// Function to perform BFS traversal of the graph
void BFS(int adjacencyMatrix[][MAX_VERTICES], int vertices, int startVertex) { int visited[MAX_VERTICES] = {0};
struct Queue* q = createQueue(); visited[startVertex] = 1; enqueue(q, startVertex);
printf("BFS Traversal starting from vertex %d: ", startVertex); while (!isEmpty(q)) {
int currentVertex = dequeue(q); printf("%d ", currentVertex); for (int i = 0; i < vertices; i++) {
if (adjacencyMatrix[currentVertex][i] && !visited[i]) { visited[i] = 1;
enqueue(q, i);
}
}
}
printf("\n");
}


int main() {
int vertices, edges;
printf("Enter the number of vertices and edges: "); scanf("%d %d", &vertices, &edges);

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};


printf("Enter the edges (src dest):\n"); for (int i = 0; i < edges; i++) {
int src, dest;
 
scanf("%d %d", &src, &dest); addEdge(adjacencyMatrix, src, dest);
}


int startVertex;
printf("Enter the starting vertex for BFS traversal: "); scanf("%d", &startVertex);

BFS(adjacencyMatrix, vertices, startVertex);


return 0;
}
