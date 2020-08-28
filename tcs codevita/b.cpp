//
// Created by yohaan vakil for codevita
//

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//All Required Header Files 
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
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626

typedef vector<int>     vi;
typedef vector<vi>      vvi;

void work(){
  int n, i,buffer;
  cin>>n;

  vi fre(3);
  //frequency of each modulo ;)
  //1 and 2 cant be adjacent 
  //0 and 0 can't be adjacent




  fo(i,n){
    cin>>buffer;
    fre[buffer%3]++;
  }

  //each mod 1 or mod 2 needs a zero
  //each zero needs a mod 1 or a mod 2 after it!
  //0102 or 0201
  if(abs(fre[0] - (fre[1]+fre[2])) < 2)cout<<"Yes\n";
  else cout<<"No\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 0 ;
    cin>>t;
    while(t--){
      work();
    }

    return 0;
}