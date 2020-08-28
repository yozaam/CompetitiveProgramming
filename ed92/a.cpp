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
    ll tc;

    cin>>tc;
    while(tc--){

        int l , r ;

        cin>>l>>r;
        bool ok = 0;

        if(2*l <= r)ok = 1;
        r = 2*l;
        if(ok){
            cout<<l<<" "<<r;
        }else{
            cout<<"-1 -1";
        }
        cout<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

