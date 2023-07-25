#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
int adj[MAX][MAX];
bool visited[MAX]; 

void bfs(int adj[MAX][MAX],int start,int v) {
    int queue[MAX];
    int front = 0, rear = 0;
    
    visited[start] = true;
    queue[rear++] = start;
    
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        for (int i = 0; i < v; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int v =7;
    int adj[MAX][MAX] = {
                        {0,1,1,0,0,0,0},
                        {1,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0},
                        {0,1,0,0,1,1,0},
                        {0,0,1,1,0,1,0},
                        {0,0,0,1,1,0,1},
                        {0,0,0,0,0,1,0}};
    bfs(adj,5,v);
    return 0;
}