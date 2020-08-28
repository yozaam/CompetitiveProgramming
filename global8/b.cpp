

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

typedef int ll;

using namespace std;

int main() {
    // your code goes here
    int tc,ans;
    cin>>tc;
    while(tc--){

        ll n ,x,m;

        cin>>n>>x>>m;

//        vector<int> l(n+1) , r(n+1);

        ll l , r;

        ll i  = 1 ;

        ll bl = -1, br  = -1;

        ll t;

        bool xd = 0;

        while(i<=m){
            cin>>l;

            cin>>r;

            if(xd && l>=bl && l<=br ){
                bl = min(l,bl);
                br = max(r,br);
            }

            else if (xd && r>=bl && r<=br){
                bl = min(l,bl);
                br = max(r,br);
            }

            else if(x>=l && x<=r)
            {
                //now all are possible in next move!
                //lets do it
                bl = l;
                br = r;
                xd= 1;
                //next iteration if the x comes between br and bl then he is allowed?
                //increase boundary if he is so.
            }
            i++;
        }

        ans = br - bl + 1;

        cout<<ans<<"\n";
    }
    return 0;
}
