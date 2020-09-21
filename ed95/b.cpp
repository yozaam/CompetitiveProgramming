
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

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

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const int MOD = 1000000007;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
size_t   k , i , j  ,t , n;
//=======================
vi a , l;
int bestk;

vi b;

void go(int pos, int prefix, int neg){

    if(pos == n){
        if(bestk>neg){
            bestk =  neg;
            b = a;
        }
        
        return ;
    }

    if(l[pos]){
        neg = (prefix+a[pos])<0 ? pos:neg;
        go(pos+1,prefix+a[pos],neg);
        //have to take him :(
        //is he negative?
    }else {

        //  // neg = (prefix+a[pos])<0 ? pos:neg;
        //         // go(pos+1,prefix+a[pos],neg);
        // //minmax didn't work
        // //try everything
        // for(i = pos +1; i< n ; ++i){
        //     if(l[i]){
               
        //         continue;
        //     }
        //         cout<<"\n"<<a[i] <<" x "<<a[pos];
        //        int mm  = i , mmv = a[i];
        //        a[mm] = a[pos] , a[pos] = mmv;

        //         neg = (prefix+a[pos])<0 ? pos:neg;
        //         go(pos+1,prefix+a[pos] ,neg);

        //         //back to normal
        //         a[pos] = a[mm],a[mm] = mmv;
        //         cout<<"\n=>"<<a[i]<<"x"<<a[pos];

        // }

      


        //here i will take the min , or the max ;)
        //who is unlocked max after this position
        int mm = pos , mmv = a[pos];
        for(i = pos ; i< n ; ++i){
            if(l[i])continue;

            if(mmv>a[i]){
                mm = i, mmv = a[i];
            }
        }

        a[mm] = a[pos] , a[pos] = mmv;

        neg = (prefix+a[pos])<0 ? pos:neg;
        go(pos+1,prefix+a[pos] ,neg);

        //back to normal
        
        a[pos] = a[mm],a[mm] = mmv;

        mm = pos , mmv = a[pos];
        for(i = pos ; i< n ; ++i){
            if(l[i])continue;

            if(mmv<a[i]){
                mm = i, mmv = a[i];
            }
        }

        a[mm] = a[pos] , a[pos] = mmv;

        neg = (prefix+a[pos])<0 ? pos:neg;
        go(pos+1,prefix+a[pos] ,neg);

        //back to normal
        
        a[pos] = a[mm],a[mm] = mmv;



        //oof try all ALL
        for(i = pos ; i< n ; ++i){
            if(l[i]){continue;}
            ll mm = pos , mmv = a[pos];

            // if(mmv<a[i]){
            //     mm = i, mmv = a[i];
            // }
            a[mm] = a[pos] , a[pos] = mmv;

            neg = (prefix+a[pos])<0 ? pos:neg;
            go(pos+1,prefix+a[pos] ,neg);

            //back to normal
            
            a[pos] = a[mm],a[mm] = mmv;

        }

        

  
    }

}
void solve() {

    //backtrack?
    //how?
    //if you reach a value having k> bestk then prune!
    //100! time complexity :'('


    //greedy!
    //if their is a number bigger NO NO NO HOW TO DO IT!!

    // binary search? BSTA?
    //if there is a k ==5 all k>5 possible? ya!

    //how about two choices at every step?


    //wait.....
    //if total sum of elements is 0!
    //then try to take all negatives in front?

    //either take smallest or biggest at each step!

    //100 ^ 2 options..
    //good work.

    //if locked continue, else pick smallest from the tree, then pick biggest and try ;)

    cin>>n;

    //GREEDY ? IF YOU CAN MAKE IT POSITIVE MAKE , ELSE MAKE NEGATIVE?
    //LETS SEE ;)

    bestk = n;

    a.resize(n) ; l.resize(n) ; b.resize(n);

    fo(i,n)cin>>a[i];

    fo(i,n)cin>>l[i];

    //now recursions 

    //level order traversal, as soon as positive just break out!

    go(0 , 0 , 0);



    // cout<<bestk<<"\t so ";

    fo(i,n)cout<<b[i]<<" ";
    cout<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}