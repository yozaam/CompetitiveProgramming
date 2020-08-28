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

typedef pair<int,int> pi;

typedef vector<int>     vi;
typedef vector<vi>      vvi;

int m , n;

int layerof(int x, int y){
    return min(
        min(abs(m - x - 1),abs(x-0)) 
        , min(abs(n - y -1 ),abs(y-0))
    );
}

int gett(int x, int y){
    int l = layerof(x,y);
    //now position of it inside the layer
    //which side is it on?
    //length of a column in this layer is ?
    int leftmost = l;
    int topmost = l;


    int rightmost = n - l -1;
    int downmost = m - l -1;//now we can know which side?

    int row = rightmost-leftmost +1;
    int col = -topmost + downmost +1;

    int total = row+row+col + col -1-1-1-1 ;//this is the total?

    //pivot0 = 0 ; ofc

    int pivot1 = col-1;
    int pivot2 = pivot1+row-1;
    int pivot3 = pivot2+col-1;

    if(y  == leftmost)return (x-topmost);//this is dist~
    else if(x == downmost)return (pivot1+y-leftmost);
    else if(x == topmost)return (pivot3 +rightmost-y);
    else return (downmost+pivot2-x);
    // int pos = 0;

    // int startx = l , starty = l;//top left
    // //now our current x y how far is it?
    //  if(y == l){
    //     //leftmost column
    //     pos = x - startx;//easy and simple!
    //  }else if( y == (starty+row-1)){

    //  }

     // //top row!
     //    //top row starts at col+row+col-3 //-1 three times
     //    pos = 2*col + row - 3;//great job
     //    pos += (startx + col  - x);//maybe idk
}

int len(int l){
    int leftmost = l;
    int topmost = l;


    int rightmost = n - l -1;
    int downmost = m - l -1;//now we can know which side?

    int row = rightmost-leftmost +1;
    int col =  -topmost+ downmost +1;

    return( row+row+col + col -1-1-1-1 );//this is the total?
}

pi reget(int l , int pos){
    int leftmost = l;
    int topmost = l;


    int rightmost = n - l -1;
    int downmost = m - l -1;//now we can know which side?

    int row = rightmost-leftmost +1;
    int col = -topmost + downmost +1;

    int total = row+row+col + col -1-1-1-1 ;//this is the total?

    //pivot0 = 0 ; ofc

    int pivot1 = col-1;
    int pivot2 = pivot1+row-1;
    int pivot3 = pivot2+col-1;


    //i should have used python!!!!


    //same as previous functino just easier :)
    if(pos <= pivot1) 
        return make_pair(topmost + pos, leftmost);
    else if  ( pos <= pivot2) 
        return make_pair(downmost, leftmost + pos - pivot1);
    else if( pos <= pivot3) 
        return make_pair(downmost - (pos - pivot2), rightmost);
    else 
        return make_pair(topmost, rightmost - (pos - pivot3));
}



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int   i , j , l;

    cin>>m>>n;

    vvi mat(m,vi(n)), ans(m,vi(n)); //m x n matrix 

    fo(i,m)fo(j,n)cin>>mat[i][j];

    // fo(i,m){
    //     fo(j,n)cout<<mat[i][j];
    //     cout<<"\n";
    // }

    // cout<<"h";
    vi rot(min(m,n)/2);


    fo(i,rot.size())cin>>rot[i];//got the rotations required !
    
    bool clockwise = 1;
    // fo(i,n){
    //     fo(j,m){
    //         //get the current layer!
    //         int layer = layerof(i,j);

    //         int rotation = rot[layer];
    //         // if(layer%2)rotation=0-rotation;
            
    //         int pos ;
    //         if(clockwise) pos = (gett(i,j) - rotation);
    //         else pos = gett(i,j) + rotation;
    //         clockwise = !clockwise;
    //         // cout<<"\n"<<i<<j<<"i,j"<<pos<<" ";
    //         // cout<<"len(l)"<<len(layer);
    //         if(pos!=0)pos = (pos+len(layer))%len(layer);
    //         // cout<<"2";
    //         // cout<<"\n"<<i<<j<<"i,j"<<pos<<" ";

    //         pi from = reget(layer,pos);
    //         // cout<<"3";
    //         // cout<<"\n"<<layer<<" in "<<i<<j<<"put"<<from.first<<from.second<<"\n";
    //         ans[i][j] = mat[from.first][from.second];

    //     }
    // }

    fo(i,min(n,m)){
        
    }

    fo(i,m){
        fo(j,n)cout<<ans[i][j];
        cout<<"\n";
    }

    return 0;
}