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

        vector<int> a(n,0);

    unordered_map<int ,int > posa; // value of a to its position.

        ll i = n  ;
        int j = 0;
        while(i--){
            cin>>temp;
            a[j] = temp;
            posa[temp] = j++;
        }

        //now b is going to start coming! as soon as the first b comes i want to find his equivalent in a. and start scanning a?
        //second b not matching start finding his equivalent also.
        i = n ;
        j = 0;
        unordered_map<int,int>sta,ans;
        while(i--){
            cin>>temp;

            sta[j] = posa[temp]; // now this guy will start comparing with my friend at b.


            for(int jj = 0 ; jj<= j ; jj++){
                if(a[sta[jj]++] == temp){
                    ans[jj]++;
                }
                //track all trackers simulateously.
                sta[jj]%=n;
            }

            j++;
        }
        int sans = 0;
        for(auto a : ans){
            if(a.second > sans) sans = a.second;
        }

        cout<<sans<<"\n";


//    }
    return 0;
}
//
// Created by yozaam on 07/06/20.
//

//
// Created by yozaam on 07/06/20.
//

