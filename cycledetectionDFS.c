#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Adjacency list representation of the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* graph[MAX_NODES]; // Array of linked lists

// Function to add an edge to the graph
void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph[src];
    graph[src] = newNode;
}

// Recursive function to perform DFS and detect cycles
bool isCyclicUtil(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    Node* curr = graph[v];
    while (curr != NULL) {
        int neighbor = curr->data;

        // If the neighbor is not visited, recursively call the function on it
        if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack))
            return true;

        // If the neighbor is visited and present in the recursion stack, a cycle is detected
        else if (recStack[neighbor])
            return true;

        curr = curr->next;
    }

    recStack[v] = false; // Remove the vertex from the recursion stack
    return false;
}

// Function to detect cycles in the graph using DFS
bool isCyclic(int numNodes) {
    bool visited[MAX_NODES] = { false };
    bool recStack[MAX_NODES] = { false };

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack))
                return true;
        }
    }

    return false;
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    for (int i = 0; i < numNodes; i++) {
        graph[i] = NULL; // Initialize the adjacency list
    }

    printf("Enter the edges (source -> destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    if (isCyclic(numNodes))
        printf("Graph contains a cycle.\n");
    else
        printf("Graph does not contain a cycle.\n");

    return 0;
}
