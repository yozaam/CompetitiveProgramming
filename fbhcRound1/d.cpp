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
#include <tuple>
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
typedef pair<ll, ll>  pii;
typedef vector<ll>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const ll MOD = 1e9+7;
const ll N = 2e6+13, M = N;
//=======================
vi g[N];
ll a[N];

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

void gen(vi&l,vi&h,vi&w,
    ll al ,ll bl ,ll cl ,ll dl ,
    ll ah ,ll bh ,ll ch ,ll dh ,
    ll aw ,ll bw ,ll cw ,ll dw,
    ll k , ll n){


    // prllf("%d %d %d %d %d %d %d %d %d",al , bl , cl ,dl , ah , bh , ch , dh , n);

    for(ll i = k ; i < n ; i++){
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
        w[i] = (
            (
              ((aw%dw)*(w[i-2]%dw))%dw
            + ((bw%dw)*(w[i-1]%dw))%dw
            +  cw%dw
            )%dw
        )+1;
    }
}

void merger(multiset< rect , custom_compare> & state 
    ,multiset< rect , custom_compare>::iterator itr){

    stack < rect > stak;

    // cout << "\n The normal Intervals are: "; 
    // for (auto t :  state) 
    // { 
       
    //     cout << "[" << (t.left) << "," << (t.right) <<"," << (t.height) << "] "; 
        
    // } 



    // multiset< rect , custom_compare>::iterator ss = state.begin();

    // bool first = 1;
    // int stopper = itr->right;//after this he has no effect!
    // while(ss!=itr){
    //     first = 0;
    //     stak.push(*ss);
    //     ss++;
    // }

    // for(;ss!=state.end();ss++){
    //     rect s = *ss;
    //     if(first){
    //         stak.push(s);
    //         first = 0;
    //     }else{
    //         // get interval from stack top 
    //         rect top = stak.top(); 
    //         // if current interval is not overlapping with stack top, 
    //         // push it to the stack 
    //         if ((top.right) <= (s.left)) 
    //         {
    //             if(s.left!=s.right)
    //                 stak.push(s); 
    //         }    
    //         // Otherwise update the ending time of top if ending of current 
    //         // interval is more 
    //         else if ((top.right)< (s.right)) 
    //         { 
    //             if(top.height> s.height){
    //                 s.left = top.right;
    //             }else {
    //                 top.right = s.left;
    //             }
    //             stak.pop();
    //             if(top.left!=top.right)
    //             stak.push(top);
    //             if(s.left!=s.right)
    //             stak.push(s);
    //         } else if(top.right>=s.right){
    //             //there is complete consumption here!
    //             if(top.height<s.height){
    //                 //now i need to split my interval into 3!
    //                 stak.pop();
    //                 rect one(top.left,s.left,top.height);
    //                 rect three(s.right, top.right, top.height);
    //                 if(one.left!=one.right)
    //                 stak.push(one);
    //                 if(s.left!=s.right)
    //                 stak.push(s);
    //                 if(three.left!=three.right)
    //                 stak.push(three);
    //                 //nice ?
    //                 //hope so..
    //             }
    //         }
    //     }
    //     // if(ss!=state.end()&& ss->left > stopper){
    //     //     while(ss!=state.end()){
    //     //         stak.push(*ss);
    //     //             ss++;
    //     //     }
    //     //     break;
    //     // }
    // }

    auto lefty = itr,pre = itr, righty = itr;
    lefty--;righty++;
    while( lefty->right >= itr->left){
        
        if(lefty->height > itr->height)
            (*itr).left = lefty->right;
        else (*lefty).right  = itr->left;
        if(lefty == state.begin())break;
        lefty--;
        itr--;
    }
    itr= pre;
    while(righty->left<itr->right)
    {
        if(righty->height>itr->height){
            (*itr).right = righty->left;
        }else {
            (*righty).left = itr ->right;
        }

        if(righty == state.end())break;

        itr++;
        righty++;
    }

    // state.clear();
    // vector<rect> hd;
    // cout << "\n The Merged Intervals are: "; 
    // while (!stak.empty()) 
    // { 
    //     auto t = stak.top(); 
    //     state.insert(t);//just trying!
    //     // hd.push_back(t);
    //     // cout << "[" << (t.left) << "," << (t.right) <<"," << (t.height) << "] "; 
    //     stak.pop(); 
    // } 
    // reverse(hd.begin(),hd.end());
    // return hd;

}

ll perimeter(const multiset< rect , custom_compare> & state){
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


void solve(ll cas) {
    ll i;
    ll n,k;
    cin>>n>>k;
    
    vi l(n) , w(n) , r(n) , h(n) , p(n);

    fo(i,k){
        cin>>l[i];
    }

    ll al , bl , cl ,dl , ah , bh , ch , dh;

    cin>>al>>bl>>cl>>dl;

    fo(i,k){
        cin>>w[i];
    }

    ll aw,bw,cw,dw;

    cin>>aw>>bw>>cw>>dw;

    fo(i,k){
        cin>>h[i];
    }

    cin>>ah>>bh>>ch>>dh;

    // prll(l);
    // prll(h);

    gen( l,  h,  w, 
         al, bl , cl ,dl ,
         
         ah , bh , ch , dh ,

         aw,bw,cw,dw, k , n
         );

    // prll(l);
    // prll(h);

    //r is right l is left
    fo(i,n){
        r[i] = l[i]+w[i];
    }

    //now all h are increasing right, 
    //i just find out

    multiset<rect,custom_compare > state ;
    ll peri = 2*w[0]+2*h[0];
    ll total = peri;
    p[0] = peri;
    state.insert(rect(l[0],r[0],h[0]));
    //now a union kind of operation!
    for(ll i = 1 ; i < n ; i++){
        //here do a union and add to total

        auto itr = state.insert(rect(l[i],r[i],h[i]));

        //check where he gets placed in the state!
        // for(auto s:state){
        //     // if(l[i]>=s.first.first && r[i]<=s.first.second){
        //     //     //just update the height of that state!
        //     //     //there must be a merge interval style of doing this!
        //     // }

        // }    
        merger(state,itr);
        
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

    ll t = 1 , cas = 1;
    cin >> t;
    while(t--) {
      solve(cas++);
    }

    return 0;
}