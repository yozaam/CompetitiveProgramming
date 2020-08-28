//
// Created by yozaam on 30/05/20.
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


using namespace std;

int main() {
    // your code goes here
    long long tc,n,ans;
    cin>>tc;
    while(tc--){

        cin>>n;

        long long a = 0 , b = 0, w = 0;

        vector<int> ali(n),bob(n);

        for(int i = 0 ; i<n;i++){
            cin>>ali[i];
        }

        for(int i = 0 ; i<n;i++){
            cin>>bob[i];
        }

        for(int i = 0 ; i<n;i++){
            if(a==b &&  ali[i] == bob[i]){
                a+=ali[i];
                b+=ali[i];
                w+=ali[i];
            }
            else{
                a+=ali[i],b+=bob[i];
            }
        }

        cout<<w<<"\n";



    }
    return 0;
}
//
// Created by yozaam on 30/05/20.
//

