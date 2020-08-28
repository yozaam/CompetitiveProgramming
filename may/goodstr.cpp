//
// Created by yozaam on 31/05/20.
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

long long bd(string a, string b){
    long long cost;
    for(int i = 0 ; i < a.length() ; i++)
        if(a[i]!=b[i])
            cost++;
    return cost;
}


int main() {
    // your code goes here
    long long tc;
    cin>>tc;
    while(tc--){

        string s;

        cin>>s;

        long long zc=0,oc = 0,ans = 0;

        for(char c : s)
            (c=='1')?oc++:zc++;

       vector<string> ok(8);

       // zero then one
       for(int i  = 0 ; i<oc ; i++)
           ok[0]+='1';
       for(int i = 0 ; i < zc ;i++)
           ok[0]+='0';


       //one then zero
        for(int i  = 0 ; i<zc ; i++)
            ok[1]+='0';
        for(int i = 0 ; i < oc ;i++)
            ok[1]+='1';

        //only zeroes
        for( int i = 0 ; i < oc+zc ; i++)
            ok[2] +='0';

        //only ones
        for( int i = 0 ; i < oc+zc ; i++)
            ok[3] +='1';

        //start 0 then all 1 end 0 all one etc
        ok[5] = ok[4] = ok[3];
        ok[4][0] = '0';// start 0
        ok[5][ok[5].length()-1] = '0';

        //start 1 then all 0 end 1 all one etc
        ok[6] = ok[7] = ok[2];
        ok[6][0] = '1';// start 0
        ok[7][ok[5].length()-1] = '1';


        //now bitdifference with all 8 of them
         ans = INT_MAX;

        for(string x:ok)
            ans=min(ans, bd(x,s));

        cout<<ans<<"\n";

    }
    return 0;
}
