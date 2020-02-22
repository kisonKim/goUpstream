//
//  main.cpp
//  04_reversePrintUsingSwap
//
//  Created by kison kim on 2020/02/18.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define SWAP(type,x,y) do{type t = x; x=y; y=t;}while(0)

int main(int argc, const char * argv[]) {
    int eNum = 0;
    int *numberArr;
    printf("요소 개수 : ");
    scanf("%d",&eNum);
    
    numberArr = (int*)calloc(eNum,sizeof(int));
    
    printf("%d개의 정수를 입력하세요.\n",eNum);
    for(int i=0;i<eNum;i++)
    {
        printf("x[%d] : ",i);
        scanf("%d",&numberArr[i]);
    }
    
    for(int i=0;i<eNum/2;i++)
    {
        SWAP(int, numberArr[i], numberArr[eNum-i-1] );
    }
    
    puts("배열의 요소를 역순으로 출력합니다.");
    for(int i=0;i<eNum;i++)
    {
        printf("x[%d] : %d\n",i,numberArr[i]);
    }
    
    return 0;
}
