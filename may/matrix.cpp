//
// Created by Yohaan Vakil on 20/04/20.
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
    long long tc,n,a,p,s,d,ans,col;
    cin>>tc;
    while(tc--){

        cin>>n>>a;
        ans=0;//sum

        vector<vector<int> > m(n,vector<int>(n,a));


        for( int i = 0 ; i< n ; i++){
            //p is product
            p =1;
            //col n-i is removed upto
            col=n-i;
            if(col<n && col>=0){
                //upto i-2
                for(int k = 0 ; k < i-1 ; k++){
                    p*=m[k][col];
                    m[k][col]=1;
                }
            }

            //all element in row i
//            row = i;
            if(col<n){
                for(int k = 0 ; col+ k < n ; k++){
                    p*=m[i][col+k];
                    m[i][col+k]=1;
                }
            }


        }



        cout<<ans%(1e9+7)<<"\n";

        m.clear();
        m.shrink_to_fit();
    }
    return 0;
}
