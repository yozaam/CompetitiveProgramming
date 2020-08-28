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

        //first three semi primes
        int n;

        cin>>n;

        //sum of first three semi primes
        int three = 6 + 10 + 14;

        bool ok = n > three;

        if(ok){
            if(n-three == 6){
                cout<<"YES\n"<<"6 10 15 5";
            }else if(n-three == 14){
                cout<<"YES\n"<<"6 10 15 13";
            }else if(n-three == 10){
                cout<<"YES\n"<<"6 10 15 9";
            }else{
                cout<<"YES\n"<<"6 10 14 "<<n-three;
            }
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

