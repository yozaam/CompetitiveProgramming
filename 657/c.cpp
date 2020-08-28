//
// Created by yozaam on 23/06/20.
//

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


int cnt = 0;


inline void pre(string& a ,int p ){
    reverse(a.begin() , a.begin() + p);
    for(int i  = 0 ; i < p ; i++){
        if(a[i] == '0'){
            a[i] = '1';
        }else a[i] = '0';
    }

}


void setter(string& a , string& b , int n ,vector<int> & flips){
    

    // cout<<" a,b "<<a<<"\t"<<b;

    if(n ==0)return ;
    //flipp n bits!

    if(a[n-1] == b[n-1]){
        //no flip needed
        setter(a,b,n-1 , flips);
        // cout<<" skipper";
        // cout<<"\n";
        return ;
    }else if(a[0] != b[n-1]){
        // cout<<"\n";
        //call on whole array
        flips.push_back(n);
        pre(a, n);//nice
        setter(a,b,n-1,flips);
        return ;
    }else if(a[0] == b[n-1]){
        // cout<<"\n";
        flips.push_back(1); //reverse first guy!
        pre(a,n);
        flips.push_back(n);
        pre(a, n);//nice
        setter(a,b,n-1,flips);
        return ;
    }
    
}



int main() {
    // your code goes here
    
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);

ll tc,n;
    cin>>tc;
    vector<int> f;
    while(tc--) {



                cin >> n ;//>> k;
       
        // you set the last bit in every move!
        
        string a,b;

        cin>>a>>b;

        // for(int i = 0 ; i < n ; i++){

        //     //set last bit in each move!
        //     //then return;
            
        // }

        f.clear();

        setter(a,b,n,f);

        cout<<f.size()<<" ";
        for(int j : f){
            cout<<j<<" ";
        }
        cout<<"\n";





        
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

