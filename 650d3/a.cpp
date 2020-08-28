

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
    ll tc;
    cin>>tc;
    while(tc--){

        //for all test cases

        string s , ans ;

        cin>>s;

        ans.push_back(s[0]);
        for(int i = 1 ; i< s.size(); i+=2){
            ans += s[i];
        }

        cout<<ans<<"\n";



    }
    return 0;
}
