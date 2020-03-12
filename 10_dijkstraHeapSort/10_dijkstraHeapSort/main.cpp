//
//  main.cpp
//  10_dijkstraHeapSort
//
//  Created by kison kim on 2020/03/05.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V,E;
int INF = 1000000000;

vector<pair<int,int>> *a;
int* d;

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    //가까운 순서대로 처리하므로 큐를 사용
    pq.push(make_pair(start,0));
    
    while(!pq.empty()){
        int current = pq.top().first;
        //짧은 것이 먼저 오도록 음수화 한다?
        int distance = -pq.top().second;
        pq.pop();
        //최단 거리가 아닌 경우 스킵한다.
        if(d[current]<distance) continue;
        for(int i=0;i<a[current].size();i++)
        {
            //선택된 노드의 인접 노드
            int next = a[current][i].first;
            //선택된 노드 거쳐서 인점 노드로 가는 비용
            int nextDistance = distance + a[current][i].second;
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }
                
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int start;
    cin >> V >> E;
    cin >>start;
    
    d = new int[V];
    
    a= new vector<pair<int,int>>[V+1];
    
    for(int i = 0;i<V+1;i++){
        d[i] = INF;
    }

    //vector 저장법
    for(int i=0;i<V+1;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
    }
    dijkstra(1);
    
    for(int i=1;i<V+1;i++)
    {
        if(d[i]==INF)
            printf("INF ");
        else
        printf("%d ",d[i]);
    }
    
    
//    for(int i=0;i<V+1;i++)
//    {
//        for(int j=0;j<a[i].size();j++)
//        {
//            printf("i = %d, j = %d, value= %d ",i,j,a[i].at(j).second);
//        }
//        printf("\n");
//    }
    return 0;
}

