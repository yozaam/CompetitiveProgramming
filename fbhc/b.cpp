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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc;
    ll i =1;
    cin>>tc;
    while(tc--){
        ll n;

        cin>>n;

        std::vector<bool> st(n,0), next;

        bool ok = 1;//if we break out then make it 0       
        
        char buf;

        int bc = 0;

        for(int i = 0 ; i< n ; i++){
            cin>>buf;
            if(buf == 'B'){
                st[i] =1;
                bc++;
            }
        }

        //let me imagine
        //when is answer no?
        //after one step a pir disapears
        //so make all pairs disappear
        //how many remaining?
        //invariant
        //there weill always be a way to destroy the a and b 
        int ac = n - bc;

        if(ac > bc){
            bc ^= ac;
            ac ^= bc;
            bc ^=ac;
        }

        //ac <= bc FOSHO now

        bc -= ac;
        // cout<<bc<<"\n";
        //these many bc left after joining :D
        //pairs have disappeared
        if(bc>1)ok =0;

        // while(ok){
        //     int t = 0 , f = 0; //true and false
        //     ok = 0;//noone merged in this round
        //     int end= 0 , start = 0;
        //     //sliding window

        //     for( ; end< st.size(); end++){
        //         if(st[end])t++;
        //         else f++;

        //         if(end>2){
        //             if(st[start++]) t--;
        //             else f--;
        //         }

        //         //here size is definitely 3. still let me check to avoid the case of first two elements
        //         if(t+f == 3 && t<3 && f<3){
        //             ok = 1;
        //             if(t == 1){
        //                 next.push_back(false);
        //             }else{
        //                 next.push_back(true);
        //             }
        //         }
        //     }

        //     if(ok)st= next;
        //     next.clear();

        // }
        
        
        cout<<"Case #"<<i++<<": ";
        
        
        if(ok)cout<<'Y';
        else cout<<'N';

        cout<<"\n";


    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

