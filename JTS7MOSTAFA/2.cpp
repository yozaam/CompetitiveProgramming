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


    string sl;
    cin>>sl;

    transform(sl.begin(), sl.end(), sl.begin(), ::tolower);

    string ans ;
    ans = "";
    set<char> vow;

    for(char c : "aeiouy"){vow.insert(c);}

    for(char c : sl){
        if(!vow.count(c)){
            ans += ".";
            ans+=c;
        }
    }

    cout<<ans;
    return 0;

}