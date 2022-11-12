class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    MedianFinder() {
        
    }
    void balance(){
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
           
        }else if(maxHeap.size()+1 < minHeap.size()){
             maxHeap.push(minHeap.top());
             minHeap.pop();
        }
    }
    void addNum(int num) {
        if(maxHeap.size()==0 or maxHeap.top() >num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if(maxHeap.size()== minHeap.size()) return((maxHeap.top()+minHeap.top())/2.0);
        return maxHeap.size() >minHeap.size()? maxHeap.top(): minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */