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




#define fo(start,n) for(size_t i = start; i < n; ++i)


// unordered_map<int,int>mp;
// mp.reserve(1024);            //FAST UMAP
// mp.max_load_factor(0.25);
typedef long long ll;



using namespace std;



int main() {
    // your code goes here
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tc;
    cin>>tc;
    while(tc--) {

        ll n , m ,a, b;

        unordered_map<ll , ll> parent;
        unordered_map<ll , unordered_set<ll> > kids;


        cin>>n>>m;

        vector<ll> p(n),h(n),visits(n),bad(n);

        fo(i,n){
            cin>>p[i];
            visits[i] = p[i];
        }

        fo(i,n){
            cin>>h[i];
            if(h[i] < 0)
                bad[i] = 0 - h[i];
            //happiness index of the city
        }

        fo(i,n-1){
            cin>>a >> b;
            --a,--b;
            parent[b] = a;
            kids[a].insert(b);
        }

        // std::vector<bool> added(0);

        // fo(i,n){
        //    visits[ parent[i] ] += p[i];
        // }//how to add in a bottom up fashion :D
        
        //gonna do a dfs remove him from kids after adding to stack!
        stack<ll> top;

        top.push(0);
        bool ok =  1;


        while(!top.empty()){
            //push all kids
            ll root = top.top();
            // cout<<"ROOT"<<root<<"\n";
            if(kids[root].empty()){
                if(root == 0){
                    top.pop();
                    break;
                }
                //he is a leaf node!
                visits[ parent[ root ] ]
                    += visits[root];
                //put him onto his parent and kill him

                //8 people visited 
                //happiness is -3
                //thus bad guys will have to be
                int i = root;
                if(bad[i] > abs(h[i])){
                   if((visits[i] - abs(bad[i]))%2){
                    // ok  = 0 ; 
                    // // cout<<"d";
                    // goto end;
                    }else{
                        bad[parent[i]] += bad[i];
                        bad[i] += (visits[i] - abs(bad[i]))/2;
                        //these many bad passed / lived guys here!
                    } 
                }
                
                
                //now also add the bad moods to above ans!
                kids[ parent[root ] ].erase(root);
                //he has done his duty now
                top.pop();
            }
            for(ll kid : kids[root]){
                //add all his kids!
                top.push(kid);
                // kids[root].erase(kid);
                //dont want to visit him again ;)
            }

        }


        fo(i,n){
            // cout<<visits[i]<<" ";
            if(abs(h[i]) > visits[i] || 
                (visits[i] - abs(h[i]))%2){
                ok = 0;
                break;
            }else if(bad[i] > bad[parent[i]]){
                ok = 0;
                // cout<<i;
                break;
            }
        }
        //everyone's values added to parent value!
        //for any parent value it should be possible to create the happiness index with that no. of visits!
        
        end:
        if(ok){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

