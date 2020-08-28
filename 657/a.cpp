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

        int n , m , x, ans = -1;
        bool ok = 0;
        cin>>n>>m;
        unordered_set<int> a;
        for(int i = 0 ; i < n ; i++){
            cin>>x;
            a.insert(x);
        }

        for(int i   = 0 ; i < m ; i++){
            cin>>x; 
            if(!ok && a.find(x)!=a.end()){
                ok = 1,ans = x;
            }
        }

        a.clear();
      
        
        if(ok){
            cout<<"YES\n1 "<<ans;
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

