#include <iostream>
#include <string>
#include <vector>
#define SWAP(type,x,y)do{type t=x;x=y;y=t;}while(0)
using namespace std;

int solution(vector<int> budgets, int M) {
    unsigned long size = budgets.size();
    int mid=0;
    int prevMid = 0;
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
            if (budgets[i] > budgets[j])
            {
                SWAP(int, budgets[i], budgets[j]);
            }
    
    int min = budgets[0];
    int max = budgets[size - 1];
    int sum = 0;
    
    for(int i=0;i<size;i++)
        sum+=budgets[i];
    
    if (sum<M)
        return budgets[budgets.size() - 1];
    
    
    
    while (1) {
        sum = 0;
        mid = (max+min) / 2;
        
        if(mid == prevMid){
            break;
        }
        
        for (int i = 0; i < size; i++) // SUM, 상한 값은 mid값으로 대체
            if (budgets[i] > mid) {
                sum += mid;
            }
            else {
                sum += budgets[i];
            }
        
        if (sum > M)
            max = mid;
        else
            min = mid;
        
        prevMid = mid;
    }
    
    return mid;
}
int main(int args, char** argc) {
    vector<int> budgets;
    budgets.push_back(120);
    budgets.push_back(110);
    budgets.push_back(140);
    budgets.push_back(150);
    
    printf("%d",solution(budgets, 485));
}
