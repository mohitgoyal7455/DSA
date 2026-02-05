class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas=0,totcost=0;
        for(int val: gas){
            totgas+=val;
            }
        for(int val:cost){
            totcost+=val;
        }
        if(totgas<totcost){
            return -1;
        }    
        int start=0,currGas=0;
        for(int i=0;i<gas.size();i++){
            currGas+=(gas[i]-cost[i]);
            if(currGas<0){
                start=i+1;
                currGas=0;
            }
        }
        return start;
        
    }
};