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

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const int MOD = 1e9+7;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
int a[N];

//=======================
struct rect 
{ 
    ll left, right, height; 
    rect(ll a, ll b, ll c)
        :left(a),right(b),height(c){

    }
}; 

struct custom_compare final
{
    bool operator()(const rect& i1,const rect& i2) const{ 
        if(i1.left==i2.left)
            return (i1.right<i2.right);
        return (i1.left < i2.left); 
    }
};

void prll(vi& v){
    cout<<"\n";
    for(ll x:v)cout<<x<<",";
    cout<<"\n";
}


void merger(vector< rect > & state){

    stack < rect > stak;

    bool first = 1;
    for(auto ss:state){
        rect s = ss;
        if(first){
            stak.push(s);
            first = 0;
        }else{

            // get interval from stack top 
            rect top = stak.top(); 
      
            // if current interval is not overlapping with stack top, 
            // push it to the stack 
            if ((top.right) <= (s.left)) 
            {
                if(s.left!=s.right)
                    stak.push(s); 
            }    
      
            // Otherwise update the ending time of top if ending of current 
            // interval is more 
            else if ((top.right)< (s.right)) 
            { 
                // top.right = (s.right);
                // (top.height) = max(s.height,top.height);
                // stak.pop(); 
                // stak.push(top); 
                

                if(top.height> s.height){



                    s.left = top.right;

                }else {
                    top.right = s.left;
                }
                stak.pop();
                if(top.left!=top.right)
                stak.push(top);
                if(s.left!=s.right)
                stak.push(s);
            } else if(top.right>=s.right){
                //there is complete consumption here!
                if(top.height<s.height){
                    //now i need to split my interval into 3!
                    stak.pop();
                    rect one(top.left,s.left,top.height);
                    rect three(s.right, top.right, top.height);
                    if(one.left !=one.right)
                    stak.push(one);
                    if(s.left!=s.right)
                    stak.push(s);
                    if(three.left!=three.right)
                    stak.push(three);
                    //nice ?
                    //hope so..
                }
            }
            (top.height) = max(s.height,top.height);

        }
    }
    state.clear();
    // vector<rect> hd;
    // cout << "\n The Merged Intervals are: "; 
    while (!stak.empty()) 
    { 
        auto t = stak.top(); 
        state.push_back(t);//just trying!
        // hd.push_back(t);
        // cout << "[" << (t.left) << "," << (t.right) <<"," << (t.height) << "] "; 
        stak.pop(); 
    } 
    reverse(state.begin(),state.end());
    // return hd;

}

ll perimeter(const vector< rect > & state){
    //here all height differences are stored!
    ll p = 0 , currenth = 0, currentr = 0;
    for(rect rr:state){
        if(rr.left == rr.right)continue;//okay?
        if(currentr != rr.left){
            //they are neighbours no worry!
            //they are not touching!
            //add the value of previous h 
            //and the value of my h 
            p+=currenth + rr.height;
            //i guess that is it?
            p+= 2*(rr.right - rr.left);
        }else{
            p+= 2*(rr.right - rr.left);
            p+= abs(currenth - rr.height);
        }
        
        
        currenth = rr.height;
        currentr = rr.right;
    }
    p+= currenth;//last guys h!
    return p;
}


void print(vi& v){
    cout<<"\n";
    for(int x:v)cout<<x<<",";
    cout<<"\n";
}

void gen(vi&l,vi&h,
    int al ,int bl ,int cl ,int dl ,
    int ah ,int bh ,int ch ,int dh ,
    int k , int n){


    // printf("%d %d %d %d %d %d %d %d %d",al , bl , cl ,dl , ah , bh , ch , dh , n);

    for(int i = k ; i < n ; i++){
        l[i] = (
            (
              ((al%dl)*(l[i-2]%dl))%dl
            + ((bl%dl)*(l[i-1]%dl))%dl
            +  cl%dl
            )%dl
        )+1;
        h[i] = (
            (
              ((ah%dh)*(h[i-2]%dh))%dh
            + ((bh%dh)*(h[i-1]%dh))%dh
            +  ch%dh
            )%dh
        )+1;
    }
}

void solve(int cas) {
    int i;
    int n,k,w;
    cin>>n>>k>>w;
    
    vi l(n) , h(n) , r(n) , p(n);

    fo(i,k){
        cin>>l[i];
    }

    int al , bl , cl ,dl , ah , bh , ch , dh;
    cin>>al>>bl>>cl>>dl;

    fo(i,k){
        cin>>h[i];
    }

    cin>>ah>>bh>>ch>>dh;

    // print(l);
    // print(h);

    gen(l,h,al , bl , cl ,dl , ah , bh , ch , dh , k , n);

    // print(l);
    // print(h);

    fo(i,n){
        r[i] = l[i]+w;
    }
    // //right side
    // ll edge = r[0] , peri = 2*w+2*h[0];
    // ll total = peri , roof = h[0];
    // //now a union kind of operation!
    // p[0] = peri;
    // for(ll i = 1 ; i < n ; i++){
    //     //here do a union and add to total
    //     if(l[i]>r[i-1]){
    //         //no intersection!
    //         //add everything positive height difference
    //         peri = peri + 2*w+2*h[i];

    //         //disjoint :D
    //     }else{
    //         //find the intersection point
    //         int prev = i;
    //         while(r[prev-1]>l[i]){
    //             prev--;
    //             if(h[i] > h[prev]){
    //                 //height at that point
    //                 peri += 2*(h[i] - h[prev]);
    //             }//left border taken care of ;)

    //         }
    //         //now you got the position to insert him at
    //         //later put binarysearch here

            
    //         //now right border?
    //         //maybe no need :D
    //         //lets see if answer is correct!

    //         //now width difference
    //         peri += 2*(r[i] - r[i-1]);
    //     }

    //     total = ((total%MOD ) * (peri%MOD))%MOD;
    //     p[i] = peri;
    // }

    // print(p);

    vector<rect> state;
    ll peri = 2*w+2*h[0];
    ll total = peri;
    p[0] = peri;
    state.push_back(rect(l[0],r[0],h[0]));
    //now a union kind of operation!
    for(ll i = 1 ; i < n ; i++){
        //here do a union and add to total

        state.push_back(rect(l[i],r[i],h[i]));

        //check where he gets placed in the state!
        // for(auto s:state){
        //     // if(l[i]>=s.first.first && r[i]<=s.first.second){
        //     //     //just update the height of that state!
        //     //     //there must be a merge interval style of doing this!
        //     // }

        // }
        merger(state);
        peri = perimeter(state);
        //get the perimeter here 
        total = ((total%MOD )* (peri%MOD))%MOD;
        p[i] = peri;
        //when two states merge only the greater height survives
    }
    // prll(p);
    total %= MOD;
    cout<<"Case #"<<cas<<": "<<total<<"\n";


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    int cas = 1;
    while(t--) {
      solve(cas++);
    }

    return 0;
}