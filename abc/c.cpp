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




#define fo(start,n) for(size_t i = start; i < n; ++i)


// unordered_map<int,int>mp;
// mp.reserve(1024);            //FAST UMAP
// mp.max_load_factor(0.25);
typedef long long ll;



using namespace std;



int main() {
    // your code goes here
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 1 , b =-1;

    long long sev = 7;

    long k ;cin>>k;
    if(k%2==0){cout<<b;return 0;}
    while(sev<ULONG_MAX){
        if(sev>=k && sev%k == 0){b = a;break;}
        else {
            sev = sev*10 +7 ;
             a++;
         }
         cout<<"sev"<<sev<<"\n";
    }

    cout<<b;
    
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

