//
// Created by yozaam on 05/06/20.
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

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    ll tc;
    cin>>tc;
    while(tc--){
        //for all test cases

        int n;
        cin>>n;

        vector< vector<int> > m(n,vector<int>(n));

        int k = 1;

        bool ascend = 1;

        for(int i = 0 ; i< n ; i++){

            if(ascend){
                for(int j = 0 ; j< n ; j++)
                    cout<<k++<<" ";
            }else{
                for(int j = 0 ; j< n ; j++)
                    cout<<--k<<" ";
            }

            cout<<"\n";
            ascend = !ascend;
            k+=n;

        }
    // end of test case :);
    }
    return 0;
}
