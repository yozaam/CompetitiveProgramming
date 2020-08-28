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

        int n ,k,z,x;
        int ok = 0;
        cin>>n>>k>>z;
        vector<int> walk(n), lefty(n);
        

        for(int i = 0 ; i < n ; i++){
            cin>>walk[i];
            if(i>=1){
                lefty[i] = walk[i]+walk[i-1];
            }
        }

        int i = 0, sum = walk[0];

        //find the biggest lefty!
        //that we can add!
        //is it bigger than last two elements?
        //cool do it!
        //check while z-- :D
        vector<int> preleft(k+1);

        while(k--){

            sum+=walk[++i];

            preleft[i] = max(lefty[i],preleft[i-1]);    
            //this is the great one
        }

        //this is a plain doubler!
        while(z--){
            if(i>=3 && lefty[i] < preleft[i-2]){
                sum-=lefty[i];
                sum+=preleft[i-2];
                i-=2;
            }else{
                break;
            }
        }

        if(z>0){
            //check the last move!
            if(walk[i] < walk[i-2]){
                sum -= walk[i];
                sum += walk[i-2];
            }
        }

        // while(k--){
        //     //one move
        //     if(z==0){
        //         sum += walk[i+1];
        //         i++;
        //         cout<<" right ";
        //     }else{
        //         if(k==0){
        //             sum += max(walk[i-1],walk[i+1]);
        //             cout<<"last";
        //         }else{
        //             if(walk[i+1]+walk[i+2] >= lefty[i]){
        //                 sum+=walk[i+1];
        //                 sum+=walk[i+2];
        //                 i+=2;
        //                 cout<<" right right ";
        //             }else{
        //                 cout<<" left right ";
        //                 sum+=lefty[i];
                        
        //                 z--;
        //             }
        //             k--;
        //         }
        //     }
        // }

        cout<<sum<<"\n";
       
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

