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
    string ans = "";
    cin>>n;
    string t ; //pre,c;
    cin>>t;
    int i = 0;
    ans += t[i];
    i++;
    while(i< n){
        if(t[i] != t[i-1]){
            ans+=t[i];
        }

        i++;
    }

    cout<<ans;
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

