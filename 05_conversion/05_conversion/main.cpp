//
//  main.cpp
//  05_conversion
//
//  Created by kison kim on 2020/02/22.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <stdio.h>

int card_convr(unsigned x,int n, char d[]){
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    if(x == 0 )
        d[digits++] = dchar[0];
    else
        while(x){
            d[digits++] = dchar[x%n];
            x/=n;
        }
    return digits;
}
//진수 변환 알고리즘
int main(int argc, const char * argv[]) {
    int i;
    unsigned no;
    int cd;
    int dno;
    char cno[512];
    int retry;
    printf("10진수를 기수 변환 합니다.\n");
    do{
        printf("변환하는 음이 아닌 정수 : ");
        scanf("%u",&no);
        printf("어떤 진수로 변환할까요?(2-36) : ");
        scanf("%d",&cd);
        dno = card_convr(no,cd,cno);
        printf("%d진수로는 ",cd);
        for(i=dno-1;i>=0;i--){
            printf("%c",cno[i]);
        }
        printf("입니다.\n");
        printf("한 번 더 할까요?(1...예/0...아니요)");
        scanf("%d",&retry);
    }while(retry);
    
    return 0;
}
