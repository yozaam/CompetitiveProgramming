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
    ll tc;

    cin>>tc;
    while(tc--){

        string pb ;

        cin>>pb;

        ll res = pb.size() ; // first visit is bound to happen even if no neg!
        //whenever some negativity add that negativity index

        vector<int> negvec(pb.size());
        ll cur = 0 ;
        for(int i = 0 ; i < pb.length() ; i++ ){
            // calc negatviity of each index

            if(pb[i] == '+'){
                cur++;
            }else{
                cur--;// neg score is only if no is negative
            }
            negvec[i] = cur; //at this index negativity is such
        }


        ll neg = 0 ;


        for(int i = 0 ; i < pb.length() ; i++){

            //add i to ans if neg score is there.

            //default tolerance each time is ?
            // it is how much has already been done? or is it i?


            if(negvec[i] < 0 && pb[i]=='-' )  {
                //there is some negativity. more than is tolerated in this iteration of the loop
                //add to the ans?
                res += i+1; // how many elements have i handled?
                if(i == pb.size()-1 ){
                    if(negvec[i] == -1)res-=pb.size();
                }
            }

        }





        ll ans = res;



        cout<<ans<<"\n";

    }
    return 0;
}
