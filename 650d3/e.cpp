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

int main() {
    // your code goes here
    ll tc,n,k;
    cin>>tc;
    while(tc--){


        cin>>n>>k;

        string s;

        cin>>s;

        int ans = 0;

        //got n got k

        map<char,int> fre;

        fre.clear();
        for(char c : s){
            fre[c]++;
        }

        // got fre of each alphabet.
        //now i need to see the biggest k alpaaaaaaaaaaa
        if(k>s.size()){
            for(int fac = s.size() ; fac>0 ; fac--){
//                for a bot in a world a lirrle bot in a li
                if(k%fac==0){
                    ans = fac;
                    break;
                }
            }

        }else{
            vector<int> fs;
            for(auto a:fre){
                fs.push_back(a.second);
//                cout<<"ASEC"<<a.second;
            }
            sort(fs.begin(),fs.end(),greater<int>());
            int sans = 0,mxi = 0;
            if(fs.size()>=k)
                mxi = k-1; else mxi = fs.size()-1;
                ans = fs[mxi];// at this position the repeadter is there
            // we hace at least these many, now we see remainder of each other one
            //if they are biffer thant they get included
            for(int fac = mxi ; fac>=0 ; fac--){
//                for a bot in a world a lirrle bot in a li
                if((fac+1)%k==0){
                    sans = 0 ;
                    sans = (fac+1)*fs[fac];
                    ans = max(ans,sans);
                }
            }
        }

        cout<<ans<<"\n";

    }
    return 0;
}
