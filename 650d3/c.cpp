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
    while(tc--){

        cin>>n>>k;

        ll ans = 0;

        ll tc = 0;

        ll oc = 0; ll pc = 0;

        ll zc = 0;

string bb;
        cin>>bb;

        for(int i = 0 ; i< n ; i++)
        {
            char buf = bb[i];


            if(buf == '1'){
                oc++;
                if(zc <= 2*k){
                    zc = 0;
                }else{
                    zc-=k;// left side
                    //now how many pairs of 10000ktimes
                    ans += zc/(k+1);// ok
                    zc = 0;
                }
            }else{
                if(oc==0){
                    pc++;
                }
                else zc++;
            }
        }

        // at the end how many zc?

        if(zc>k){
            ans += zc/(k+1);
        }

        if(pc>k && oc>0){
            ans += pc/(k+1);
        }else if(pc>=k && oc==0){
            pc-=1; ans++; // put one one in start then do whatever u want
            ans += pc/(k+1);
        }
        // if there were no 1s at all the pc is big and zc is zero



        cout<<ans<<"\n";

    }
    return 0;
}
