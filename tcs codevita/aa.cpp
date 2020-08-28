//
// Created by yohaan vakil for codevita
//

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//All Required Header Files 
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

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626

typedef vector<bool>     vb;
typedef vector<vb>      vvb;

typedef vector<int>     vi;
typedef vector<vi>      vvi;


// void print(vvb& x){
//     fo(i,x.size()){
//         fo(j,x.size())cout<<(int)x[i][j]<<" ";
//         cout<<"\n";
//     }
// }

void melt(vb& x){
    int front = 0;
    int n = x.size();
    for(int k = 0 ;  k<n ; k++){
        if(x[k]){
            // cout<<k<<"\t";
            x[front++]=1;
        }
    }
    for(int k = front ; k<n ; k++){
        x[k] = 0;
    }
}

int dp(vvb& o){
    int i = 0 , j = 0 , ans = 0 , n = o.size();

    vvi count(n,vi(n,0));

    fo(i,n){
        count[i][0] = !o[i][0]; //1 square '0' size 1
        ans = max(ans,count[i][0]);
    }

    fo(i,n){
        count[0][i] = !o[0][i]; //1 square '0' size 1
        ans = max(ans,count[0][i]);
    }

    //now remaining cells!
    for(i  = 1 ; i < n ; i++){
        for(j = 1 ; j< n ; j++){
            if(!o[i][j]){
                //zero is here
                count[i][j] = 1+ 
                min(count[i][j-1],
                    min(count[i-1][j] , 
                        count[i-1][j-1]
                        ));
                //done?
                ans  = max(ans,count[i][j]);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, i , j;
    cin>>n;

    vvb top(n,vb(n,0)) , left(n,vb(n,0));


    int ans = 0 , ansleft = 0 ;

    fo(i,n){
        fo(j,n){
            char c ;
            cin>>c;
            if(c=='C')top[i][j] = left[j][i] = 1;
        }
    }

    fo(i,n)reverse(left[i].begin(),left[i].end());

    // cout<<"top\n";
    // print(top);

    // cout<<"left\n";
    // print(left);


    fo(i,n)
         melt(top[i]);
     
    
    fo(i,n)
        melt(left[i]);
    


    // cout<<"melt top\n";
    // print(top);

    // cout<<"melt left\n";
    // print(left);


    //now a dp method to return the largest square of zeroes ;D
    ans = dp(top);
    ansleft = dp(left);
    
    ans =  max(ans,ansleft);
    
    cout<<ans;

    return 0;
}