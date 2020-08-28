

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
    int tc;
    int n ;

    cin>>tc;

    while(tc--){

        n = 0;

        string ans = "YES";


        cin>>n;

        // cout<<"n is "<<n;

        bool no = false;

        int fives = 0, tens = 0 , fifteens = 0, coin;

        while(n--){

            cin>>coin;

            if(coin==5)
                fives++; // no change
            else if(coin == 10){
                fives--,tens++; //take ten give five
            }
            else if(coin == 15){
                fifteens++;
                if(tens>0)tens--; //try to give ten
                else fives-=2;    // okay give two fives idm
            }

            //if anything is negative no becomes true and break
            if(tens<0 || fives<0 || fifteens<0){
                no =1 ;
                break;
            }
        }



        string stri;

        if(no){
            ans = "NO";
            if(n>0)
                getline(cin,stri);
            // cout<<"str.size() is"<<stri.size();
        }

        cout<<ans<<"\n";

    }
    return 0;
}

