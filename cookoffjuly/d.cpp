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

typedef long long ll;

using namespace std;

int ch(string & s,int l , int r, char c){

    if((r-l ) == 1)return (c==s[l])?0:1;//base case
    
    
    int a= r-l;
    a/=2;
    int cost1 = 0,cost2=0 ;
    // map<char, int> fre;
    int left = 0,right= 0;
    for(int i = l ; i< l+a; i++){
        // fre[s[i]]++; //later i will collect max frequency :)
        if(s[i] == c)left++;
    }

    // fre.clear();
    for(int i = a+l ; i< r; i++){
        // fre[s[i]]++; //later i will collect max frequency :)
        // right  = max(right,fre[s[i]]);
        if(s[i] == c)right++;
    }

    
        cost1 += a-left;
        cost1 += ch(s, l+a, r, c+1); 
    
        cost2 += a - right;
        cost2 += ch(s, l , l+a , c+1);  //begin end format
    
    return min(cost1,cost2);

}

int main() {
    // your code goes here
    ll tc,n;

    cin>>tc;
    while(tc--) {

       

        cin>>n;
        string s;

        cin>>s;

        int cost = ch(s,0,n,'a');
        
        
        cout<<cost<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

