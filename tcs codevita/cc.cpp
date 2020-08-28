#include <iostream>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    
    	int l , r , k;
      	cin>>l>>r>>k;
      	int n = r-l+1;
  		//so basically all position can have any of the r-l+1 values right
  		//like for 4,5 k = 3 then _ _ _ 3 pos 2 options 2*2*2 = 2^k
      	unsigned long long ans = pow((r-l+1),k);
  
  		if((n%2) == 0){
        	//there is no extra odd/even element! can just /2
          	ans /=2;
          	//half of all permutations will have even sum?
          	//oeoeoe oooooe yes
        }else {
        	//count odd even elements
        	ans = 0;
        	int odd,even;
        	if((l%2)||(r%2)){
        		 odd = n/2 + 1;
        		 even = n - odd;
        	}else {
        		odd = even = n/2;
        	}
        	//now each position can be a odd or even number!
        	for (int i =  0 ; i < odd ; i+=2){
        		//how many odd elements in current permutation
        		//when i = 0  zero odd elements so 
        		ans+= (pow(even,k-i) + pow(odd,i)  );//nice! these many even positions
        		//remaining odd

        	}
        }
  

      	

  		cout<<ans;
    

  	return 0;
}


