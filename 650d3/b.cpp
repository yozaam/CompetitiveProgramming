

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

typedef int ll;

using namespace std;

int main() {
    // your code goes here
    int tc,ans;
    cin>>tc;
    while(tc--){

        int n ;

        cin>>n ;

        vector<int> arr;

        int oc = 0 ;
        int ec = 0;

        int nn = n;
        while(n--){

            cin>>ans;
            if(ans%2)oc++ ; else ec++;
            arr.push_back(ans);
        }


        if(oc != nn/2){
            ans = -1;
        }else{
            ans = 0;
            int poc = 0 , pec = 0;
            for(int i = 0 ; i < arr.size() ; i++){
                if(i%2 != arr[i]%2){
                    if(i%2)poc++;
                    else pec++;
                }
            }


            if(poc == pec){
                ans = pec;
            }else{
                ans = -1;
            }
        }




        cout<<ans<<"\n";
    }
    return 0;
}
