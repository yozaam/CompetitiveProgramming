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
    ll tc,n,x;

    cin>>tc;
    while(tc--){

        cin>>n;

        string s;

        cin>>s;

        ll oc = 0 , zc = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                zc++;
            }else{
                break;
            }
        }
        //  UNBELIEVABLE I THOUGHT OF THIS!
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '1'){
                oc++;
            }else{
                break;
            }
        }

        // now that many zeroes and one's for sure .

        // inbetween them.. what will come ?

        // if anything is between them it is like 1....0 it will become 0.
        //sure? no.

        //lets try :)

        if(zc+oc < n)zc++;

        while(zc--)cout<<"0";

        while(oc--)cout<<"1";

        cout<<"\n";


    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

