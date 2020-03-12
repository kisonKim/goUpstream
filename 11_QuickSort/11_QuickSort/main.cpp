#include <stdio.h>
#define swap(type,x,y) do{type t = x;x=y;y=t;}while(0)

int number = 10;
int data[10] = {10,5,8,2,4,3,9,7,1,6};

void quickSort(int data[],int start,int end){
    if(start>=end){
        return;
    }
    int key = start;
    int i = start+1;
    int j = end;
    
    while(i<=j){
        while(data[key]>=data[i] && i<=end){
            i++;
        }
        while(data[key]<=data[j] && j>start){
            j--;
        }
        
        if(i>=j){
            swap(int,data[key],data[j]);
        }
        else{
            swap(int,data[j],data[i]);
        }
    }
    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    quickSort(data,0,number-1);
    for(int i=0;i<number;i++)
    {
        printf("%d ",data[i]);
    }

    return 0;
}
