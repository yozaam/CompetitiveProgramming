//
// Created by yozaam on 28/05/20.
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
    long long tc,h,c,t,ans;
    cin>>tc;
    while(tc--){

        cin>>h>>c>>t;

        ans = 1;

        if(h==t){
            cout<<ans<<"\n";
            continue;
        }
        if(h+t == 2*t){
            ans = 2;
            cout<<ans<<"\n";
            continue;
        }

        int denom = 2;

        //get temp
        double cur = (double)h+(double)c;
        cur/=2.0;// this is avg temp
        double mid = cur;
//        cout<<mid<<endl;
        double prevdiff = h*h + 10000 ;

        cur += h*1.0/denom++;
        ans+=2;

        while(abs(cur - t) <prevdiff ){
            //going closer

            if(cur-t == 0 ) { ans++;  break;}

            prevdiff = abs(cur-t);

            cur  = mid;
            cur += h*1.0/denom++;


            ans+=2;
        }

        cout<<ans<<"\n";

    }
    return 0;
}
