//
// Created by Yohaan Vakil on 20/04/20.
//

//
// Created by Yohaan Vakil on 20/04/20.
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


using namespace std;





long cost(vector<bool> dif , long a , long b,long lvl = 1){

    if(lvl<1)return 0;
    if(lvl == 1){

        while( !dif[a++] );

        while( !dif[b--]);
        a--;b++;

        cout<<"\na is "<<a<<" b is "<<b<<"at lvl "<<lvl<<endl;

        return (b-a+1);
    }

    int oc = 0,maxoc = 0,sp = 0;


    for(long i = a ; i <b ; i++){
        if(!dif[i]){
            oc ++;
            if(oc>maxoc){
                maxoc=oc;
                sp = i;
            }
        }
    }

    lvl --;
    if(lvl == 1 ){
        return cost(dif,sp,b,lvl)+cost(dif,a,sp,lvl);
    }
    return min(  cost(dif,sp,b,lvl-1)+cost(dif,a,sp,lvl)   ,   cost(dif,a,sp,lvl-1)+cost(dif,sp,b,lvl)  );


}



int main() {
    // your code goes here
    string s,r;
    long tc;
    long k = 0,l=0,a,b;
    cin>>tc;
    while(tc--){

        cin>>s;
        cin>>r;
        k = 0;l=0;

        vector<bool> dif(s.length());
        long ans ;


        for(long i = 0 ; i < s.length(); i++){
            if(s[i] != r[i]){
              dif[i] = 1;
              k++;
            }
        }

        //now go through it and find a boundary a and b
        a = 0;

        b = s.length()-1;
        ans = b+b;
        while(k--){
            cout<<"\nk is"<<k;
            ans = min(ans,k*cost(dif,a,b,k));
        }


        cout<<ans;

    }
    return 0;
}
