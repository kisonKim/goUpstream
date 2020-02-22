//
//  main.cpp
//  02_multi9x9Table
//
//  Created by kison kim on 2020/02/18.
//  Copyright © 2020 kison kim. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "\t\t\t----곱셈표---"<<endl;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout << setw(3) << j*i << " " ;
        }
        cout << endl;
    }
    return 0;
}
