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

        int n , m , r;

        cin>>n>>m>>r;

        int rr = r*2+1;

        int ans , a;



         ans = (n/rr) ;
        if(n%rr)ans++;

        a = (m/rr);
        if(m%rr)a++;

        ans = min(a,ans);
//
//        cout<<"\trows"<<ans;
//        ans = min(ans , (m/rr)?(m/rr):1);
//        cout<<"\tx col="<<ans;
        cout<<ans<<"\n";

    return 0;
}
//
// Created by yozaam on 13/06/20.
//

