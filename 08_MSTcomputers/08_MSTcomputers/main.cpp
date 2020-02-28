#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int getParent(int parent[], int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = getParent(parent, parent[a]);
}

void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int find(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
    {
        return 1;
    }
    return 0;
}

bool sortByWeight(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
    return (get<2>(a) < get<2>(b));
}

int main(void) {
    int N;
    int M;
    vector<tuple<int, int, int>> weights;
    
    scanf("%d", &N);
    scanf("%d", &M);
    
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        weights.push_back(make_tuple(x, y, z));
    }
    
    int size = weights.size();
    
    int *parent = (int*)malloc(sizeof(int)*(N+1));
    //memset(parent, 0, sizeof(int) * size);
    
    //간선 비용 기준으로 오름차순 정렬
    sort(weights.begin(), weights.end(), sortByWeight);
    
    
    //연결되었는지 확인하는 배열
    for (int i = 0; i < N+1; i++)
        parent[i] = i;
    
    int sum = 0; //간선 가중치의 합을 0으로 초기화
    
    for (int i = 0; i < size; i++) {//모든 간선에 대해서 차례대로 수행
        //사이클이 발생하지 않는 경우 그래프에 포함
        if (!find(parent, get<0>(weights[i]), get<1>(weights[i]))) {//튜플 값 가져오는 방식 get<0>(weight[i]), get<1>(weight[i]), get<2>(weight[i])
            unionParent(parent, get<0>(weights[i]), get<1>(weights[i]));
            sum += get<2>(weights[i]);
        }
    }
    printf("%d", sum);
}
