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

    unordered_set<int> s;

    while(tc--){
        int n;
        cin>>n;
        n*=2;

        int x;
        int i =0 ;  
        vector<int> ans;
        while(i<n){
            cin>>x;
            if(s.count(x)){
                ans.push_back(x);
                s.erase(x);
            }else{
                s.insert(x);
            }
            i++;
        }
       
        for(int f:ans)cout<<f<<" ";
        
        cout<<"\n";


    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

