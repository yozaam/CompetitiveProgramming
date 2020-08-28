

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
    ll tc,ans;
    cin>>tc;
    while(tc--){

        ll a, b ;

        cin>>a>>b;

        if(a>b){
            ll t = a ;
            a = b;
            b = t;
        }
        //now a is smaller element we want it to become bigger element

        //minimize them
//        ll c = __algo_gcd()
//        cout<<"\n a: "<<a<<" b: "<<b;

        ans = 0;
        while(a<b){

            a = a<<1;
            ans++;

        }

//        cout<<"\n shifts: "<<ans;

        if(a==b){
             // three shifts how many times then add one for next unless it was perfect three shifts
            if(ans%3)ans= ans/3+ 1;
            else ans = ans/3;
        }else{
            ans = -1;
        }


        cout<<ans<<"\n";
    }
    return 0;
}
