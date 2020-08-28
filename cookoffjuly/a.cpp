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

        string s;
        int n;
        cin>>n>>s;
        map<char,int> fre;
        for(char c:  s){
            fre[c]++;
        }
        bool ok = 1;
        for(auto a:fre){
            if(a.second%2){
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES";else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

