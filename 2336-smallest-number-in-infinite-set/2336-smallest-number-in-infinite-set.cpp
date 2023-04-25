class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    int curr;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        int res;
        if(!pq.empty()){
            res= pq.top();
            pq.pop();
            st.erase(res);
        }else{
            res=curr;
            curr++;
        }
        return res;
    }
    
    void addBack(int num) {
        if(curr<= num or st.find(num)!= st.end()) return;
        pq.push(num);
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */