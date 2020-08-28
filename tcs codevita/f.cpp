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

    vi setup(1,0), setdown(1,0);

    unordered_map<string, bool> pos;

    pos["H2"]=1;
    pos["Q3"]=1;
    pos["Q4"]=1;

    pos["H1"]=0;
    pos["Q2"]=0;
    pos["Q1"]=0;

    bool side = 0 ; //always starts at 0

    bool serve = true;//it is a serve right now!

    bool fault = false;

    string s;

    int scoreup = 0 , scoredown = 0;


    while(cin>>s){


        //do score comparisons here!


        if(side == pos[s]){
            //you just lost a point!
            if(serve && !fault){
                fault = 1;
            } 
            else if(side == 1){
                scoreup++;
                fault = 0;
            }else{
                scoredown++;
                fault = 0 ;
            }
            //after hitting in your own side, what happens?
            serve = 1;//end of this play
        }else{
            //you hit in the right side ;)
            if(serve && s!="H2"){
                fault = 0 ;//reset fault it is a success
            }else if (serve && s=="H2"){
                if(!fault){
                    fault = 1;
                }else {
                    scoreup++;//you faulted!
                    fault = 0;
                    serve=1;
                }
            }else {
                if(side = 1){
                    scoredown++;
                }else {
                    scoreup++;
                }
                
            }
        }

    }

    return 0;
}