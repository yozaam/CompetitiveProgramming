

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
    ll tc,ans;
    cin>>tc;
    while(tc--){

        //for all test cases

        int ans = 0;

        int a , b ;

        cin>>a>>b;

        if(a>b){
            a ^=b ; b ^=a ; a^=b;
        }
        // a is always the smaller one.
//        cout<<"\na "<<a<<" b "<<b;


        //now the difference!

        int dif = b -a;

        if(dif>= a){
           ans = a;
        }

        else if(dif < a) {
            b -= 2 * dif;
            a -= dif;

            ans += dif;

            //if (b < 0) // assuming its not possible..
            if( b == a){
                ans += (b+a)/3;
            }
        }


        cout<<ans<<"\n";



    }
    return 0;
}
