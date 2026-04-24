class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int m=0;
        int count=0;
         for(int i=0;i<n;i++){
            if(moves[i]=='L'){
                m=m-1;
            }
            else if(moves[i]=='R'){
                m=m+1;
            }
            else{
                count++;
            }
         }
            
         return abs(m)+count;

        
    }
};