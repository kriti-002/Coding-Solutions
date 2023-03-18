class BrowserHistory {
    stack<string> history, future;
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while(!future.empty()) future.pop();
    }
    
    string back(int steps) {
        while(steps-- > 0 && history.size() >=2){
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps-- > 0  && !future.empty()){
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */