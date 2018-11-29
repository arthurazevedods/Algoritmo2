#include <stdio.h>
#include <stdlib.h>
#define SIZE 10001

struct queue {
    int items[SIZE];
    int front;
    int back;
};

struct queue* createQueue();
void enqueue(struct queue* q, int value);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
int busca(struct Graph* graph, int st);

int main(){
    int T,n,m,l;
    int inicio,dest,peteleco,count;
    scanf("%d",&T);

    while(T){
        count = 0;
        struct Graph* graph;
        scanf("%d %d %d",&n,&m,&l);
        graph=createGraph(n+1);
        for(int i = 0;i < m;i++){
            scanf("%d %d",&inicio,&dest);
            addEdge(graph,inicio,dest); 
        }

        for (int i = 0;i<l;i++){
            scanf("%d",&peteleco);
            count += busca(graph,peteleco);
            //printf("peteleco:%d\n",peteleco );
        }

        printf("%d\n",count );
        T--;
    }
 
    return 0;
}

int busca(struct Graph* graph, int st) {
    int count = 0;
    struct queue* q = createQueue();
    if(graph->visited[st] == 0){
        graph->visited[st] = 1;
        count++;
        enqueue(q, st);
    }
    
    
    
    while(!isEmpty(q)){
        int currentVertex = dequeue(q);
        //printf("Visited %d\n", currentVertex);    
        struct node* temp = graph->adjLists[currentVertex];
        while(temp) {
            int adjVertex = temp->vertex;
        
            if(graph->visited[adjVertex] == 0){
                count++;
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    return count;
}

 
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // Add edge from dest to src
    //newNode = createNode(src);
    //newNode->next = graph->adjLists[dest];
    //graph->adjLists[dest] = newNode;
}

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->back = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->back == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->back == SIZE-1)
        return NULL;
    else {
        if(q->front == -1)
            q->front = 0;
        q->back++;
        q->items[q->back] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){  
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->back){
            q->front = q->back = -1;
        }
    }
    return item;
}




