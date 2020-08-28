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

typedef long long ll;

using namespace std;


int main() {
    // your code goes here
    ll tc,n;

    cin>>tc;
    while(tc--) {

        cin >> n ;//>> k;
        int f;
        if(n<3){
            cout<<0<<"\n";
            while(n--)cin>>f;
            continue;
        }

        // int j;


        // first you will put all maximums!

        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        
      reverse(arr.begin(),arr.end());

       int a1 = 0,a2=0;
       
       int j,i;

       //checking increasing :D
       for (i = 1; i < n; i++) { 
            if (arr[i] >= arr[i - 1]) 
                continue; 
      
            if (arr[i] < arr[i - 1]) 
                break; 
        }  //incresing array

        if(i == n ){
            cout<<"0\n";
            continue;
        }

        for (j = i + 1; j < n; j++) { 
            if (arr[j] <= arr[j - 1]) 
                continue; 
      
            if (arr[j] > arr[j - 1]) 
                break; 
        }  //decreasing array

        i=j;

        if(i == n){
            cout<<"0\n";
            continue;
        }

        a1 = n-i;

        //now a2 for a other direction curve





        // for (i = 1; i < n; i++) { 
        //     if (arr[i] <= arr[i - 1]) 
        //         continue; 
      
        //     if (arr[i] > arr[i - 1]) 
        //         break; 
        // }  //incresing array

        // if(i == n){
        //     cout<<"0\n";
        //     continue;
        // }

        // for (j = i + 1; j < n; j++) { 
        //     if (arr[j] >= arr[j - 1]) 
        //         continue; 
      
        //     if (arr[j] < arr[j - 1]) 
        //         break; 
        // }  //decreasing array

        // i=j;

        // if(i == n){
        //     cout<<"0\n";
        //     continue;
        // }

        // a2 = n-i+1;








        cout<<a1<<"\n";
    }
    return 0;
}
//
// Created by yozaam on 13/06/20.
//

