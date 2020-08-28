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
        int ok = 0;
        cin>>n;
        vector<bool> dubs(n);
        int o = 0 , d = 0;
        // unordered_set<int> ones;
        // unordered_set<int> twos;
        for(int i = 0 ; i < n ; i++){
            cin>>x;
            // cout<<x;

            if(x>1){
                dubs[i]  = 1;
                d++;
            }
            
        }
            // cout<<"\n";

        // ok = 0;

        // for(int i = 0 ; i < n ; i++){
        //     int rem  = n - i;  

        //     if(dubs[i]){
        //         //its a two you have a choice
        //         //take it or make it a one?
        //         //make it one is same as going
        //         //to next sqaure :O

        //         //o stores no of ones in future:O

        //         int no = rem - o;//these many non ones are left
        //         //dub is a reversal!
        //         //why would i want to reverse

        //         //bulldoze it!
        //         while(i<n-1 && dubs[i+1]){
        //             i++;
        //         }

        //         ok++;


        //     }else{
        //         // o--;

        //         //1s reduced
        //     }


        //     //if( i % 2 == 0) then maximise for first
            
            
            
        // }
        vector<bool> su;
        o = 0;
        for(int i = 0 ; i < n ; i++){
            // cout<<"\t"<<dubs[i];
            if(dubs[i] && (su.empty() || !su.back()) ){
                su.push_back(1);
            }else if(!dubs[i]){
                su.push_back(0);
                o++;
            }
        }
        // cout<<"\n";

        // int same = turn;

        // while(su.empty() == false && su.back()==0){
        //     su.pop_back();
        // }



        // for(int i = su.size() -1 ; i>=0 ; i--){

        // }
int i =  0 ;
        for(;i<su.size() ; i++){
        
            // cout<<"\t"<<su[i];
            //o stores 1
            //WHOEVER REACHES THE FIRST DUBS WINS!

            if(su[i]){
                i++;
                break;//first dubs reached byyy mr same
            }

            

        }

        if( i%2 ){
            cout<<"First\n";
        }else{
            cout<<"Second\n";
        }


      
        
       
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

