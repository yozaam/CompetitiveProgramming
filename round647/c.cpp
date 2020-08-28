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
//
//int countBits(ll n)
//{
//    int count=0;
//    // While loop will run until we get n = 0
//    while(n)
//    {
//        count++;
//        // We are shifting n to right by 1
//        // place as explained above
//        n=n>>1;
//    }
//    return count;
//}


int main() {
    // your code goes here
    ll tc,n;
    cin>>tc;
    while(tc--){
        ll ans = 0;
        cin>>n;
//        int bits =countBits(n) ;
        //now i need the no of different bits hmmm maybe i do exor between two numbers and then count bits in that
        int x = 1;
        while(n>0){
            ans += n;
            n/=2;

        }
        cout<<ans<<"\n";

    }
    return 0;
}
