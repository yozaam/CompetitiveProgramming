
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


using namespace std;

int main() {
    // your code goes here
    int tc,a[5],p,ans;
    cin>>tc;
    while(tc--){

        for(int i = 0 ;  i < 5 ; i++){
            cin>>a[i];
        }

        cin>>p;

        int ans = 0;
        for(int ot:a){
            ans+=ot*p;
        }

         if(ans<=24*5)
             cout<<"No\n";
         else
             cout<<"Yes\n";

    }
    return 0;
}
//
// Created by yozaam on 30/05/20.
//

