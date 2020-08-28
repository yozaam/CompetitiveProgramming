
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

#define ll long long;

using namespace std;

int main() {
    // your code goes here
    long long tc,n,ans,q,floo,s,d;
    cin>>tc;
    while(tc--){

        floo = 0;
        ans = 0;
        cin>>n>>q;



        while(q--){
            cin>>s>>d;

                ans+= abs(s-floo);
                floo = s;

                ans+= abs(d-floo);
                floo =d;


        }

        cout<<ans<<"\n";

    }
    return 0;
}
