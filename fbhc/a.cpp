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

int main() {
    // your code goes here
    ll tc;
    ll i =1;
    cin>>tc;
    while(tc--){
        ll n;

        cin>>n;

        std::vector<bool> in(n,0), out(n,0);

        std::vector< vector<bool> > p(n,std::vector<bool>(n,0));        
        
        char buf;

        for(int i = 0 ; i< n ; i++){
            cin>>buf;
            if(buf == 'Y'){
                in[i] =1;
            }
        }

        
        for(int i = 0 ; i< n ; i++){
            cin>>buf;
            if(buf == 'Y'){
                out[i] =1;
            }
        }

        for(int i = 0 ; i< n ; i++){
            p[i][i] = 1;
        }
        //first flight i to j

        for(int i = 0 ; i< n ; i++){

            //go right and then go left
            for(int j = i+1 ; j<n ; j++ ){

                if(p[i][j-1]){
                    //previous was a safe one
                    //now check if in out is allowed here!
                    if(in[j] && out[j-1]){
                        p[i][j] = 1;
                    }
                }

            }

            for(int j = i-1 ; j >=0 ;j--){

                if(p[i][j+1]){
                    if(in[j] && out[j+1]){
                        p[i][j] = 1;
                    }
                }

            }
        }


        cout<<"Case #"<<i++<<":\n";
        
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(p[i][j])cout<<'Y';
                else cout<<'N';
            }
            cout<<"\n";
        }

        


    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

