
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


using namespace std;

int main() {
    // your code goes here
    long long tc,q,floo,s,d,left,right,pre;
    int n = 1;
    vector<long long> x;
    cin>>tc;
    while(tc--){

        int maxi = 1;
        cin>>n;
        int mini = n;

        x.resize(0);

        while(n--){
            cin>>s;
            x.push_back(s);
        }

//        for(int i:x)cout<<i;
//        cout<<"\n";
        int n = 1;
        //now i have the elements, I will create a sliding window
        //at any moment if the element cannot be in window, we will not include it
        //brute force is better
        right =1;pre = x[0];
        while(right<x.size()){
            if(abs(x[right-1]-x[right])<3){
               n++;
                maxi = max(maxi,n);
//                mini = min(mini,n);
            }else{
                maxi = max(maxi,n);
                mini = min(mini,n);
                n=1;
            }
//            if(mini = INT_MAX)
            right++;
        }
        
        cout<<mini<<" "<<maxi<<"\n";

    }
    return 0;
}
