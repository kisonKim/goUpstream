//
//  main.cpp
//  13_BJ_2751_Sorting2
//
//  Created by kison kim on 2020/03/12.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <iostream>
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)
using namespace std;
int N;
int *data;

void quickSort(int start,int end){
    int pivot = start;
    int i = start +1;
    int j = end;
    if(start>=end){
        return ;
    }
    while(i<=j){
        while(data[i]<=data[pivot] && i<=end){
            i++;
        }
        while(data[j]>=data[pivot] && j>start){
            j--;
        }
        if(i>=j)
        {
            swap(int, data[j],data[pivot]);
        }else{
            swap(int, data[j],data[i]);
        }
    }
    quickSort(start,j-1);
    quickSort(j+1,end);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    data = new int[N];
    
    for(int i=0;i<N;i++)
    {
        cin >> data[i];
    }
    
    quickSort(0,N-1);
    
    for(int i=0;i<N;i++)
    {
        printf("%d\n",data[i]);
    }
    return 0;
}
