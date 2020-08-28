//
// Created by yozaam on 12/06/20.
//

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
    ll tc,n,x;

    cin>>tc;
    while(tc--){

        cin>>n>>x;
        ll temp;
        ll ans = n;
        vector<ll > mods ;

        vector<ll > nums;

//        unordered_set<int , int > modcounts;

        ll sum  = 0 ,zc=0 , dc = 0;
        while(n--){
            cin>>temp;
            sum+=temp;
//            if(temp==0)zc++;

            if(temp%x )dc+= 1;
            else zc++;
        }

        ll mod = sum%x;

        if(mod==0)

        {
            if(dc) ans--;
//            else if(zc)ans = zc;
                else ans = -1;// pop this back element and create our answer :)
        }

        cout<<ans<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

