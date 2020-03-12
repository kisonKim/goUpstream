
//void dijkstra(int start){
//    for(int i=0;i<MAX_VERTICES;i++)
//    {
//        distance[i] = weight[start][i];
//    }
//    visited[start] = 1;
//
//    for(int i=0;i<MAX_VERTICES-2;i++)
//    {
//        int current = choose();
//        visited[current] = 1;
//        for(int j=0;j<MAX_VERTICES;j++)
//            if(distance[j]>weight[current][j]+distance[current])
//                distance[j]=weight[current][j]+distance[current];
//    }
//}
//int main(void){
//    dijkstra(0);
//    for(int i=0;i<MAX_VERTICES;i++)
//    {
//        printf("%d",distance[i]);
//    }
//    return 0;
//}



#include <stdio.h>

#define MAX_VERTICES 6
#define INF 1000000000
int weight[MAX_VERTICES][MAX_VERTICES] = {
    {0,2,5,1,INF,INF},
    {2,0,3,2,INF,INF},
    {5,3,0,3,1,5},
    {1,2,3,0,1,INF},
    {INF,INF,1,1,0,2},
    {INF,INF,5,INF,2,0}
};
int distance[MAX_VERTICES] ={INF,};
int visited[MAX_VERTICES] ={0,};

int getMinIndex(){
    int min = INF;
    int minIdx=-1;
    for(int i=0;i<MAX_VERTICES;i++)
    {
        if(distance[i]<min && visited[i]!=1){
            min = distance[i];
            minIdx = i;
        }
    }
    return minIdx;
}
void dijkstra(int start){
    distance[start]=0;
    for(int i=0;i<MAX_VERTICES;i++)
    {
        distance[i] = weight[start][i];
    }
    for(int i=0;i<MAX_VERTICES-2;i++)
    {
        int minIdx = getMinIndex();
        visited[minIdx] = 1;
        
        for(int j=0;j<MAX_VERTICES;j++)
        {
            if(distance[j]>weight[minIdx][j]+distance[minIdx]){
                distance[j] = weight[minIdx][j]+distance[minIdx];
                
            }
        }
    }
}
int main(void){
    dijkstra(1);
    
    return 0;
}

























