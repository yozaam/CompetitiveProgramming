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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n ,i , j, rowmax=0, colmax=0 ,ans = 0;
    cin>>n;

    vvb original(n,vb(n,0)),left(n,vb(n,0));//1 for c!
    //how many succesive rows had a single C?
    fo(i,n){
        
        fo(j,n){
            //this is first row!
            char buffer;
            cin>>buffer;
            if(buffer == 'C'){
                original[i][j] = 1;
                left[i][j] = 1;
            }
        }
        
    }


    // cout<<"original!!\n"
    // fo(i,n){
    //     fo(j,n)
    //     {   
    //         if(original[i][j])cout<<1;
    //         else cout<<0;
    //     }
    //     cout<<"\n";
    // }

    
    

    //now i will melt original!
    //then melt transpose => &/or left

    //to melt i need to bring all 1s to front!

    fo(i,n){
        int front = 0;
        fo(j,n){
            if(original[i][j])
            {
                front++;
            }
        }
        // cout<<"front is "<<front<<"\n";
        fo(j,front){
            // cout<<"writing";
            original[i][j] = true;
        }
        Fo(j,front,n)
        {
            original[i][j]= 0;
        }
        //now all zeroes are pushed back!
        //find biggest square of zeroes!
    }

    // cout<<"\noriginal melt\n";

    // fo(i,n){
    //     fo(j,n)
    //     {   
    //         if(original[i][j])cout<<1;
    //         else cout<<0;
    //     }
    //     cout<<"\n";
    // }


    //now simply search for biggest sqaaure of zeros!!!!
    //nice!


    vvi dp(n,vi(n,0));//size 0 initial?
    ans = 0;
    //intialize row n col?
    fo(i,n){
        dp[i][0] = !original[i][0];
        ans = max(dp[i][0],ans);
        dp[0][i] = !original[0][i];
        ans = max(ans,dp[0][i]);
    }
        //where there is zero there wil be 1 square

    //now simply move through the dp table!
    
    Fo(i,1,n){
        Fo(j,1,n){
            if(!original[i][j]){
                //now can i make a square with bottom left here?
                //easy just check all three edges up left & diagonal left up
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            }
            ans = max(ans,dp[i][j]);
        }
    }

    



    //now check again for ansleft?
    int ansleft = ans;
    ans = 0;
    original = left;

    //now i will melt original!
    //then melt transpose => &/or left

    //to melt i need to bring all 1s to front!

    fo(j,n){
        int front = 0;
        fo(i,n){
            if(original[i][j])
            {
                front++;
            }
        }
        // cout<<"front is "<<front<<"\n";
        fo(i,front){
            // cout<<"writing";
            original[i][j] = true;
        }
        Fo(i,front,n)
        {
            original[i][j]= 0;
        }
        //now all zeroes are pushed back!
        //find biggest square of zeroes!
    }
    // cout<<"\nafter lefty and melt\n";
    // fo(i,n){
    //     fo(j,n)
    //     {   
    //         if(original[i][j])cout<<1;
    //         else cout<<0;
    //     }
    //     cout<<"\n";
    // }


    //now simply search for biggest sqaaure of zeros!!!!
    //nice!


    //size 0 initial
    fo(i,n)fo(j,n)dp[i][j]=0;

    //intialize row n col?
    fo(i,n){
        dp[i][0] = !original[i][0];
        ans = max(dp[i][0],ans);
        dp[0][i] = !original[0][i];
        ans = max(ans,dp[0][i]);
    }
    // cout<<"\ninit dp\n";
    // fo(i,n){
    //     fo(j,n)
    //     {   
    //         if(dp[i][j])cout<<dp[i][j];
    //         else cout<<0;
    //     }
    //     cout<<"\n";
    // }

    //now simply move through the dp table!
    Fo(i,1,n){
        Fo(j,1,n){
            if(!original[i][j]){
                //now can i make a square with bottom left here?
                //easy just check all three edges up left & diagonal left up
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) +1;
            }
            ans = max(ans,dp[i][j]);
        }
    }


    // cout<<"\nfinal dp\n";
    // fo(i,n){
    //     fo(j,n)
    //     {   
    //         if(dp[i][j])cout<<dp[i][j];
    //         else cout<<0;
    //     }
    //     cout<<"\n";
    // }


    // cout<<ansleft<<","<<ans;
     ans =  max(ans,ansleft);
    
    cout<<ans;

    return 0;
}