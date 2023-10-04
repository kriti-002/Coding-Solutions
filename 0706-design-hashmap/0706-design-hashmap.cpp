class MyHashMap {
public:
    int size=1000001;
    vector<int>vh;
    MyHashMap() {
        vh.resize(size, -1);
    }
    
    void put(int key, int value) {
        vh[key]=value;
    }
    
    int get(int key) {
        return vh[key];
    }
    
    void remove(int key) {
        vh[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */