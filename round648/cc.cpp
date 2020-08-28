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
#include <unordered_map>

typedef int ll;

using namespace std;

int main() {
    // your code goes here
//    ll tc,ans;
//    cin>>tc;
//    while(tc--){

        //for all test cases

        ll n,temp;

        cin>>n;

        vector<int> a, b;

    unordered_map<int ,int > bindex;

        ll i = n  ;
        sta =
        while(i--){
            cin>>temp;
            a.push_back(temp);
        }

        i = n;
        ll j = 0;
        while(i--){
            cin>>temp;
            b.push_back(temp);
            bindex[temp]=j;
            j++;
        }

        ll sta = 0,ans = 0;

        vector<bool> checked(n,0);
        unordered_set<int> tocheck()

        for( ; sta<n;sta++){
            if(checked[sta])continue;
            //where is sta in b
            ll stb = bindex[a[sta]];// index for b :)
            ll staa = sta;
            ll sans = 0;

//        cout<<"\nstb="<<stb;// no problem here big problem here.

            for(int i = 0 ; i< n ; i++){
                if( a[sta] == b[stb] ){
                    checked[sta] = 1;
                    sans++;
                }

//            cout<<a[sta]<<"->"<<b[stb]<<" \n";

                sta++; sta%=n;

                stb++; stb%=n; //goes through all elements ;D
            }

            sta = staa;
            if(sans>ans)ans = sans;
        }





        cout<<ans<<"\n";



//    }
    return 0;
}
//
// Created by yozaam on 07/06/20.
//

//
// Created by yozaam on 07/06/20.
//

