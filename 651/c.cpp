//
// Created by yozaam on 23/06/20.
//

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
    ll tc,n,k;

    cin>>tc;
    while(tc--) {

        cin >> n >> k;

        int j;


        // first you will put all maximums!

        vector<int> v(n), w(k);


        for (int i = 0; i < n; i++) {
            cin >> j;
            v[i] = j;
        }

        ll zc = 0;

        for (int i = 0; i < k; i++) {
            cin >> j;
            //since biggest get packed first .
            if (j == 1)zc++;
            w[i] = j - 1;
        }

        ll ans = 0;

        sort(w.begin(), w.end(), greater<int>()); // put the biggest guys in the smallest holes
        sort(v.begin(), v.end()); // sort him

        //now take biggest guys and put them in smallest w?

        for (int i = 0; i < k; i++) {
            //biggest guys get counted for sure.
            ans += v.back();
            if (zc > 0)zc--, ans += v.back();
            v.pop_back(); // .. now the dillemma the smallest guys should get packed into a big w.

        }

        int mindex = 0; // he will get included no matter what!

        // now put one min guy?
        for (int i = 0; i < k; i++) {

            if (w[i] == 0)break;

            ans += v[mindex]; // include this guy

            // eg 2 and i have 1 1 2 so i want to

            mindex += w[i]; // next 2 guysget skipped :) mindex now at 2 .
            if (mindex >= v.size())break; // get out ur done.
        }

        cout<<ans<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

