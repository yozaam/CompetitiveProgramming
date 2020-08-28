

/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll;

using namespace std;

int main() {
    // your code goes here

    ll n ;

    cin>>n ;

//    n  = 4 ;

    vector< vector<int> > v(25 , vector<int>(25));

    // start filling a sqaure

    ll rows = ceil(sqrt(n));

//    if(n%rows)
//        rows++;

    ll k = n + 4*rows;
    if(n%rows)
        k--;
    cout<<k<<"\n";

    ll lastcol = rows+1;

    for(int i = 1 ; i <= rows ; i++){
        cout<<0<<" "<<i<<"\n";
        v[0][i] = 1;
    }
    bool done = 0;

    ll lastrow = rows+1;

    for(int i = 1 ; i <= rows ; i++){




        for(int col = 0 ; col<=lastcol ; col++){

            cout<<i<<" "<<col<<"\n";
            v[i][col] = 1;
            if( (col > 0 && col<=rows) )n--;

            if(n == 0){
                done = 1;
                if(col!=rows)
                    lastcol = rows; // now this row is filled only till rows
                lastrow = col; // below this only till here
                n--;
//                do{
//                    col++;
//                    cout<<i<<" "<<col<<"\n";
////                    v[i][col] = 1;
//                }
//                while(col<rows);
//                break;
            }
        }


    }

    for(int i = 1 ; i <= lastrow; i++){
        v[rows+1][i] = 1;
        cout<<rows+1<<" "<<i<<"\n";
    }

//
//    for(auto a : v){
//
//        for(int x:a){
//            cout<<x<<"\t";
//        }
//
//        cout<<"\n";
//    }

    return 0;
}
