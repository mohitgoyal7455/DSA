class Solution {
public:
    int countPrimeSetBits(int left, int right) {
    unordered_set<int>primes={2,3,5,7,11,13,17,19,23};
    int prime_count=0;
    for(int i=left;i<=right;i++){
     int setbit=__builtin_popcount(i);
        if(primes.find(setbit)!=primes.end())
          prime_count +=1;
    }

        
    return prime_count;
    }
    
};