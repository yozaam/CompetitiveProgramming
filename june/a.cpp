//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
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

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    int tc,ans;
    cin>>tc;

    while(tc--){

        ans = 0;

        int n , k, temp;

        cin>>n>>k;

        while(n--){
            cin>>temp;
            if(temp>k)ans+=temp-k;
        }

        cout<<ans<<"\n";

    }
    return 0;
}
