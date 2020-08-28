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


int r[]={-1,1,0,0};
int c[]={0,0,-1,1};

vector< vector< bool > > drowned;


inline bool safe(vector< vector< int > > & arr , int i , int j , vector< vector< bool > > & vis, int l){
    if(i<0 || i>= arr.size() || j < 0 || j>= arr[0].size())return 0;

    if(vis[i][j])return 0 ;

    if(arr[i][j]<l){ drowned[i][j]=1; return 0;}

    return 1;
}

void dfs(vector< vector< int > > & arr , int i , int j , vector< vector< bool > > & vis, int l){

    vis[i][j] = 1;

    for(int k = 0 ; k < 4 ; k++){
        if(safe(arr, i+ r[k] , j + c[k] , vis , l))
            dfs(arr, i+ r[k] , j + c[k] , vis , l);
    }

}



int main() {
    // your code goes here

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n , m ,x;

    cin>>n>>m;

    drowned.resize(n,vector<bool>(m,0));

    int ans = 0;

    vector< vector< int > > arr(n,vector<int>(m,0));

    set<int> levels;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>x;
            levels.insert(x);
            arr[i][j] = x;
        }
    }

    int count,i,j;



    for(int l : levels){


        vector< vector< bool > > vis(n,vector<bool>(m,0));



         count = 0;
        for( i = 0 ; i < n ; i++){
            for( j = 0 ; j < m ; j++){

               if(drowned[i][j] || arr[i][j]<l)drowned[i][j]=1;
               else if(!vis[i][j]){
                   // hese not visited ;

                   //visit him and his neighbours

                   dfs(arr, i , j , vis,l);

                   count++;
               }
            }
        }
        ans = max(count,ans);
    }

    cout<<ans<<"\n";

    return 0;
}
//
// Created by yozaam on 13/06/20.
//

