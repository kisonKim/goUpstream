//
//  main.cpp
//  03_getMaxTall
//
//  Created by kison kim on 2020/02/18.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int maxof(const int a[], int arrSize){
    
    int max = a[0];
    for(int i = 1;i<arrSize;i++)
    {
        if(max<a[i])
            max = a[i];
    }
    return max;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int pNum = 0;
    int *tallArr;
    printf("사람 수 : ");
    scanf("%d",&pNum);
    tallArr = (int*)calloc(pNum, sizeof(int));
    
    for(int i=0;i<pNum;i++)
    {
        printf("height[%d] : ",i);
        scanf("%d",&tallArr[i]);
    }
    
    printf("최댓값은 %d 입니다.\n",maxof(tallArr,pNum));
    free(tallArr);
    return 0;
}
