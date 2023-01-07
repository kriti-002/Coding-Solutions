class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0, totCost=0, start=0, curr_gas=0, n=gas.size();
        for(int i=0;i<n;i++){
            totGas+=gas[i]; totCost+=cost[i];
            curr_gas+=gas[i]-cost[i];
            if(curr_gas < 0){
                start=i+1;
                curr_gas=0;
            }
        }
        if(totGas < totCost) return -1;
        return start;
    }
};