//
// Created by yozaam on 23/06/20.
//

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

typedef int ll;



using namespace std;


int cnt = 0;

bool good(int& s){

    int d = floor(log10(n) + 1); //digits
    //if ten digits are there
    int p = pow(10,d-1);

    return ((s%p)*10 + s/p)  == ((s%10)*p + s/10);

}

int main() {
    // your code goes here
    
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--) {

        string s;
        cin>>s;
        
        if(good())
        // unordered_map<char,int> full,odd,even;
        
        // int f=0,o=0,e=0

        // for(char c : s)full[c]++, f=max(f,full[c]);
        
        // for(int i = 0 ; i < s.size() ; i+=2 )
        //     odd[s[i]]++, o=max(o,odd[s[i]]);

        // for(int i = 1 ; i < s.size() ; i+=2 )
        //     even[s[i]]++, e=max(e,even[s[i]]);

        // //o,e(min one * 2) or f is ans;
        // int a = 2*min(o,e);
        // int 


    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

