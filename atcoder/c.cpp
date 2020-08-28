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

    cin>>n;
    int ans = n;

    vector<int>  nn ;
    int pre = -1;
    bool d = 0;
    while(n--){
        int x; cin>>x;
        if(pre != x) d = 1;
        nn.push_back(x);
        pre = x;
    }

    if(d)ans--;//there is a chance?

    unordered_set<int> ss(nn.begin(),nn.end());

    if(ss.size() == nn.size()) ans++;

    if(ss.size() == 1)ans  = 1 ;

    cout<<ans<<"\n";

    return 0;
}
//
// Created by yozaam on 13/06/20.
//

