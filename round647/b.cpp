

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

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    int tc,ans;
    cin>>tc;
    while(tc--){

        ll n ;

        cin>>n;

        vector<int> s;

        while(n--){
            cin>>ans;
            s.push_back(ans);
        }
        //fill all elements then sort
        sort(s.begin(),s.end());

        //now lets create a set of possible values for k
        vector<int> prev;
        set<int> kays;
        //if a ^ b  =  c then   a ^  c  = b

        //thus a ^ {all other elements} = k;

        //get all possible values of k for first element

        // add to set

        for(int i = 0 ; i<s.size() ; i++)
            prev.push_back(s[0]^s[i]);
        //just initilize it so something is there to insert :) at the beginning

        sort(prev.begin(),prev.end());
        vector<int>res;//store the intersection

        for(int i = 0 ; i< s.size() ; i++){

            //clear kays
            kays.clear();
            for( int j = 0 ; j< s.size() ; j++){

                kays.insert(s[i]^s[j]);

            }

            // these are all possible k vals for this iteration, now i will do an intersection with previous iteration
            // since k is used on all elements to produce element in the set
            res.clear();
            for(int i:prev){
                if(kays.find(i)!=kays.end())
                    res.push_back(i);//intersection! found him
            }
            //now
            prev = res;


            //at any time if size is zero means no k possible
            if(prev.size() == 0)break;
        }

        if(prev.size() == 0 ){cout<<-1<<"\n";  continue;} //  on to NEXT testcase ( cant leave the code )

        ans = -1;

        //prev stores global intersection of keys :O

        for(int k : prev){
            set<int> tester;
            if(k == 0)continue;
            for(int og: s){
                tester.insert(k^og);
            }
            //if they are ans
            if(tester.size() == s.size())//has to be one to one mapping then
            {
                ans = k;
                break;
            }
            else
                ans = -1;
        }

        cout<<ans<<"\n";
    }
    return 0;
}
