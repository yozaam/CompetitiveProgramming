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
typedef unsigned long long ui;

#define M 100000 
#define bits 64 
using namespace std; 
  
// Array to store bit-wise 
// prefix count 
int pre[bits][M]; 


void finder(ui arr[], ui n) 
{ 
    // ui n= arr.size();
    // cout<<sizeof pre;
    memset(&pre, 0, sizeof pre);
    for (int i = 0; i < bits; i++) { 

        pre[i][0] = ((arr[0] >> i) & 1); 
        for (int j = 1; j < n; j++) { 
            pre[i][j] = ((arr[j] >> i) & 1); 
            pre[i][j] += pre[i][j - 1]; 
        } 
    } 
} 

ui rr(ui l, ui r) 
{ 
  
    ui ans =0;
    for (ui i = 0; i < bits; i++) { 
        
        ui x; 
        if (l == 0) 
            x = pre[i][r]; 
        else
            x = pre[i][r] 
                - pre[i][l - 1]; 
  
        
        if (x != 0) 
            ans = (ans | (1 << i)); 
    } 
  
    return ans; 
} 


int main() {
    // your code goes here


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ui tc;

    cin>>tc;

    // unordered_set<int> s;



    while(tc--){
        
        ui n;cin>>n;

        if(n==2){


            ui x,y ;

            cin>>x>>y;

            set<ui> s;
            s.insert(x);
            s.insert(y);
            s.insert(x|y);

            if(s.size()==3) cout<<"YES\n"; 
            else cout<<"NO\n";

            continue;
        }

        ui v[n];
        unsigned int x = 0;
        while(x<n){
            
            cin>>v[x];

            x++;
        }

        finder(v,n);
        bool ok = 1;


        unordered_set<ui> vis;

        // cout<<sizeof(ui);

        for(ui l = 0; l<n ; l++){
            // cout<<"\n";
            for(ui r = l ; r< n ;r++){
                
              
                x  =rr(l,r);
                
                // cout<<" , "<<x;

                if(vis.count(x)){
                    ok = 0 ;
                    break;
                }
                else{
                    vis.insert(x);
                }
            }
            if(!ok)break;
        }

        // vector<unsigned int> pre(v.begin(),v.end()), post(v.begin(),v.end());



        // unordered_set<unsigned int> vis;


        // for(int i = 1 ; i< n ; i++){
        //     pre[i] |= pre[i-1];
        //     // cout<<
        // }

        // for(int i = n-2 ; i>=0 ; i--){
        //     post[i] |= post[i+1];
        // }

        // ui sum = pre[n-1];

        // cout<<"SIZE"<<sizeof(ui);
        // if (sum == pre[n-2] || sum==post[1])ok = 0;
        // for(int i = 1 ; i< n-2 ; i++){
        //     if(sum == (pre[i-0] | post[i+1])){
        //         ok = 0;
        //         break;
        //     }
        // }


        //now every range l,r is just 
        // for(int l = 0 ; l < n ; l++){
        //     // for(int r = l ; r < n ;r++){
        //     //     x = pre[r] ^ pre[l] | v[l];
        //         if(vis.count(pre[l])){
        //             ok = 0; 
        //             break;
        //         }
        //         vis.insert(x);
        //     // }
        // }

        if(ok) cout<<"YES\n"; else cout<<"NO\n";
       

    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

