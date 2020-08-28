

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

       ll a, b , c ;

       cin>>a >> b >> c;

       ll one , two;

       one = a;

       two = b /c ;

       ll a1 , a2;

       ll ba = a*b; // cost of ten donuts in a

       if(c>a){
           a1 = 1; // one donut is cheaper at here
       }else {
           a1 = -1;
       }

       if(ba > c){
           a2 = b;
       }else{
           a2 = -1;
       }

       cout<<a1<<" "<<a2<<"\n";

    }
    return 0;
}
