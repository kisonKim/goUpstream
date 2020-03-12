//
//  main.cpp
//  12_BJ_2750_sorting
//
//  Created by kison kim on 2020/03/12.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <iostream>
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    int *data;
    cin >> N;
    data = new int[N];
    for(int i=0;i<N;i++)
    {
        cin >> data[i];
    }
    
    for(int i=0;i<N-1;i++){
        int min = 1001;
        int minidx = -1;
        for(int j=i;j<N;j++)
        {
            if(min>data[j]){
                min = data[j];
                minidx= j;
            }
        }
        swap(int, data[i],data[minidx]);
    }
    
    for(int i=0;i<N;i++)
    {
        printf("%d\n",data[i]);
    }
    return 0;
}
