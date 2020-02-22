//
//  main.cpp
//  01_DoWhileSum1to10
//
//  Created by kison kim on 2020/02/17.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int sum = 0;
    int lastNum = 0;
    
    //do while 문을 이용해서 입력을 받음
    do{
        cout << "1부터 10사이의 값을 입력하세요." << endl;
        cin >> lastNum;
    }while(lastNum<=0 || lastNum>10);
    
    for(int i=1;i<=lastNum;i++)
    {
        sum+=i;
    }
    
    cout << "1부터 " << lastNum << "까지의 합은 " << sum << "입니다." << endl;
    return 0;
}
