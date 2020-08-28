//
// Created by yozaam on 03/06/20.
//


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

using namespace std;

int main() {
    // your code goes here
    long long t , shared = 0;
    cin>>t;
    for(int i  = 0  ; i< t ; i++) {

        //for t families
        long long slices, n, baby, inc, req;
        cin >> slices >> n >> baby >> inc;


        if(n == 1 ) req = baby;
        else {
            if (inc > 1)
             req = (baby * ((int)pow(inc, n)-1)) / ( inc-1);
            else
                req = n * baby;
         }
        long long extra = slices-req;

        shared = shared + extra;

        if(extra <0){
            cout<<"IMPOSSIBLE "<<(-1*extra)<<"\n";
        }else{
            cout<<"POSSIBLE "<<(extra)<<"\n";
        }

    }

    if(shared <0){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<"POSSIBLE\n";
    }

    return 0;
}
