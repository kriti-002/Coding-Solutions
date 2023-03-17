class TrieNode{
     public:
        TrieNode *child[26]={NULL};
        bool isEnd;
};
class Trie {
private:
     TrieNode* root;
public: 
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * t= root;
        //t->isEnd=false;
        for(int i=0; i<word.length(); i++){
            int idx= word[i]-'a';
            if(!t->child[idx]) t->child[idx]=new TrieNode();
            t=t->child[idx];     
        }
        t->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode *t= root;
        for(int i=0; i<word.length(); i++){
            int idx= word[i]-'a';
            if(!t->child[idx]) return false;
            t=t->child[idx];
        }
        return t->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *t= root;
        for(int i=0; i<prefix.length(); i++){
            int idx= prefix[i]-'a';
            if(!t->child[idx]) return false;
            t=t->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */