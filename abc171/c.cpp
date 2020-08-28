//
// Created by yozaam on 04/06/20.
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
#include <unordered_map>
#include <unordered_set>

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    ll tc,n,m;
    unordered_map<int , int  >  zhill , ohill; // each hill has a value
    //the corresponding hills should have the same values.
    cin>>tc;
    while(tc--){

        cin>>n>>m;

        ll ans = 0;

        zhill.clear();
        ohill.clear();

        for(int i = 0 ; i < n ; i++) {


            for (int j = 0; j < m; j++) {
                int temp;
                cin>>temp;
//                hills[i+j].insert(temp);
                if(temp == 0){
                    zhill[i+j]++;
                }else{
                    ohill[i+j]++;
                }
            }
        }


        // now corresponding hills ?
//        0 and n+m
//        1 and n+m -1 ;
//        2 and n+m -2 ;
        n--,m--;
        int  last = n+ m; int start = 0;

        int limit =  (last%2)?last/2+1:last/2;

        for(int i  = 0 ;  i < limit ; i++){

            int z = 0;
            int o = 0;

            if(zhill.count(i+start)){
                // theree are zero in that
                z+=zhill[i+start];
            }
            if(zhill.count(last - i)){
                // theree are zero in that
                z+=zhill[last - i];
            }
            if(ohill.count(i+start)){
                // theree are zero in that
                o+=ohill[i+start];
            }
            if(ohill.count(last- i)){
                // theree are zero in that
                o+=ohill[last-i];
            }
            //now count which is less and add that to ans.

            ans += min(o,z);

        }

        cout<<ans<<"\n";

    }
    return 0;
}
