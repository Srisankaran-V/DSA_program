#include<stdio.h>
#include<stdlib.h>
int v,front=0, rear =0,n;
int Dvisited[20] = {0};

typedef struct edge{
    int u,v,w;
} edge;

void DisplayKruskal(int size);
void Display(int adj[][v]);
edge elist[20], span[20];

void sort(){
    edge temp;
    for(int i = 2; i < n; i++){
        for(int j = 1; j < n-1; j++){
            if(elist[j].w > elist[j+1].w){
                temp = elist[j];
                elist[j] = elist[j+1];
                elist[j+1] = temp;
            }
        }
    }
}

int find(int belongs[], int i){
    while(belongs[i]){
        i = belongs[i];
        return i;
    }
}

void Union(int belongs[], int i, int j){
    for(int k = 0; k <= v; k++){
        if(belongs[k] == j){
            belongs[k] = i;
        }
    }
}

void Kruskal(int adj[][v]){
    int belongs[20],sn = 1,cn1,cn2;
    n = 1;
    for(int i = 1; i <= v; i ++){
        for(int j = 1; j <= v; j++){
            if(adj[i][j] != 0){
                elist[n].u = i;
                elist[n].v = j;
                elist[n].w = adj[i][j];
                n++;
            }
        }
    }
    sort();

    for(int i = 1; i < n; i++){
        cn1 = find(belongs,elist[i].u);
        cn2 = find(belongs,elist[i].v);

        if(cn1!= cn2){
            span[sn] = elist[i];
            sn++;
            Union(belongs, cn1, cn2);
        }
    }
    DisplayKruskal(sn);
}

void init(int adj[][v]){
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            adj[i][j] = 0;
        }
    }
}
void DisplayKruskal(int size){
    int i, cost= 0;
    for(i = 1; i < size; i++){
        printf("\nedge(%d,%d) : %d", span[i].u, span[i].v, span[i].w);
        cost = cost + span[i].w;
    }
    printf("\nCost : %d", cost);

}
void AddEdges(int adj[][v]){
    int s,d,w;
    while(1){
        printf("\nEnter edge from node(1 to %d) to node(1 to %d): ",v,v);
        scanf("%d%d%d",&s,&d,&w);
        if(s == -1 && d == -1) break;
        adj[s][d] = w;
        adj[d][s] = w;
        //Display(adj);
    }
}
void DeleteEdge(int adj[][v]){
    int s,d;
    while(s != -1 && d != -1){
        printf("\nEnter edge from node(1to %d) to node(1 to %d): ",v,v);
        scanf("%d%d",&s,&d);
        adj[s][d] = 0;
        adj[d][s] = 0;
    }
}
void Display(int adj[][v]){
     for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            printf("%d  ", adj[i][j]);
        }
        printf("\n");
    }    
}
void enqueue(int queue[], int val){
    queue[rear] = val;
    rear++;
}

void dequeue(int queue[]){
    front++;
}

void Bfs(int adj[][v]){
    int start = 1;
    int queue[v];
    int visited[20] = {0};
    enqueue(queue,start);
    visited[start] = 1;
    while(front != rear){
        int current = queue[front];
        printf("%d ", current);
        dequeue(queue);
        for(int i = 1; i <= v; i++){
            if(adj[current][i] != 0 && visited[i] == 0 ){
                visited[i] = 1;
                enqueue(queue, i);
            } 
        }
    } 
}

void Dfs(int adj[][v], int current){
    Dvisited[current] = 1;
    printf("%d ",current);
    //printf("\n%d\n",Dvisited[current]);
    for(int i = 1; i <= v; i++){
         if(adj[current][i] != 0 && Dvisited[i] == 0 ){
            Dfs(adj,i);
         }
    }
}

void Djikstra(int adj[][v], int start){
    int cost[v][v],distance[v],prev[v],visited[v];
    int min, next, count;

    for(int i = 1; i <= v; i++){
        for(int j = 0; j <= v; j++){
        if (adj[i][j] == 0) cost[i][j] = 999;
        else cost[i][j] = adj[i][j];
        }
    }

    for(int i = 1; i <= v; i++){
        distance[i] = cost[start][i];
        prev[i] = start;
        visited[i] = 0;        
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < v - 1){
        min = 999;
        for(int i = 0; i <= v; i++){
            if(distance[i] < min && visited[i] == 0){
                min = distance[i];
                next = i;
            }
        }
        visited[next] = 1;
        for(int i = 1; i <= v; i++){
            if(visited[i]==0)
                if(min + cost[next][i] < distance[i]){
                    distance[i] = min + cost[next][i];
                    prev[next] = i;
                } 
        }
        count++;
    }
    for(int i = 1; i <= v; i++){
        if( i != start){
            printf("\n Distance from source  to %d : %d", i, distance[i]);
        }
    }
}

void Prims(int adj[][v]){
    int selected[20] = {0},ne = 0,x,y,min;
    x = y = 0;
    selected[1] = 1;
    while(ne < v-1){
        x = 0;
        y  = 0;
        min = 999;
        for(int i = 1; i <= v && selected[i] == 1 ; i++){
            for(int j = 1; j <= v; j++){
                if(selected[j] == 0 && adj[i][j] != 0){
                    if(min > adj[i][j]){
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("\n%d to %d : %d",x,y,adj[x][y]);
        selected[y] = 1;
        ne++;
    }    
}


void main(){
    int choice;
    printf("\nLet's create graph first\n");
    printf("\nNumber of vetices: ");
    scanf("%d",&v);
    int adj[v][v];
    init(adj);
    AddEdges(adj);
    while(1){
        printf("\n0.Exit\n1.Add Edges\n2.DeleteEdges\n03.Display\n4.Breadth-first traversal\n5.Depth-first Traversal\n6.Kruskal\n7.Djikstra\n8.Prims\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                AddEdges(adj);
                break;
            case 2:
                DeleteEdge(adj);
                break;
            case 3:
                Display(adj);
                break;
            case 4:
                Bfs(adj);
                break;
            case 5:
                Dfs(adj,1);
                break;
            case 6:
                Kruskal(adj);
                break;
            case 7: 
                Djikstra(adj,1);
                break;
            case 8:
                Prims(adj);
                break;
        }
    }

}
