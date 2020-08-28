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

        cin>>n;

        vector<int> nums,idx(1,0),cp;
        cin>>x;
        n--;
        nums.push_back(x);
        cp.push_back(x);
        ll pre = x;

        cin>>x; n--;
        bool pos = (x>pre);
        pre = x;

        while(n--) {

            cin>> x ;

            if(pos){
                if( x<pre){
                    pos =0;
                    cp.push_back(pre);
                }
            }
            else if(!pos && x>pre){
                pos = 1 ;
                cp.push_back(pre);
            }

            pre = x;

        }

        cp.push_back(x);

        cout<<cp.size()<<"\n";
        for( auto j : cp){
            cout<<j<<" ";
        }

        cout<<"\n";

    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

