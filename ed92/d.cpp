 
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
 
void pre(vector<bool>& a ,int p ){
    reverse(a.begin() , a.begin() + p);
    for(int i  = 0 ; i < p ; i++){
        a[i] = !a[i];
    }
 
}
 
 
void setter(vector<bool>& a , vector<bool>& b , int n ,vector<int>& flips){
    int j = n;
 
    // cout<<" a,b "<<a<<"\t"<<b;
 
    if(j ==0)return ;
    //flipp n bits!
 
    if(a[n-1] == b[n-1]){
        //no flip needed
        setter(a,b,n-1 , flips);
        // cout<<" skipper";
        // cout<<"\n";
    }else if(a[0] != b[n-1]){
        // cout<<"\n";
        //call on whole array
        flips.push_back(n);
        pre(a, j);//nice
        setter(a,b,n-1,flips);
    }else if(a[0] == b[n-1]){
        // cout<<"\n";
        flips.push_back(1); //reverse first guy!
        pre(a,1);
        flips.push_back(n);
        pre(a, j);//nice
        setter(a,b,n-1,flips);
    }
    
}
 
 
 
int main() {
    // your code goes here
  
  ios_base::sync_with_stdio(false);
        cin.tie(NULL);  ll tc,n;
    cin>>tc;
    while(tc--) {
 
        cin >> n ;//>> k;
       
        // you set the last bit in every move!
        int x;
        string a,b;
 
        cin>>a>>b;
        vector<bool > aa(n), bb(n);
        for(int i = 0 ; i < n ; i++){
 
            //set last bit in each move!
            //then return;
            aa[i] = a[i] == '1';
            bb[i] = b[i] =='1';
            
        }
 
        vector<int> f;
 
        setter(aa,bb,n,f);
 
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