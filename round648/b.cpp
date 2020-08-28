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
#include <unordered_set>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    ll tc,ans;
    cin>>tc;
    while(tc--){

        //for all test cases


        ll m,n,temp;

        cin>>n;

        vector<int> val;
        vector<int> type;

        for(int i = 0 ; i< n ; i++)
        {
            cin>>temp;
            val.push_back(temp);
        }

        int zz = 0;

        for(int i = 0 ; i< n ; i++){

            cin>>temp;
            if(temp==0)zz++;
            type.push_back(temp);
        }

        if(is_sorted(val.begin(),val.end())){
            cout<<"Yes\n";
            continue;
        }




        if(zz == 0 ||zz == n ){
            cout<<"No\n";
            continue;
        }

        else{
            cout<<"Yes\n";
        }

    }
    return 0;
}
//
// Created by yozaam on 07/06/20.
//

//
// Created by yozaam on 07/06/20.
//

