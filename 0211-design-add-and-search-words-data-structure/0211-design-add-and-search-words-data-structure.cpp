class Trie{
  public:
  Trie *child[26];
  bool isEnd;
    Trie(){
        isEnd=false;
        memset(child, 0, sizeof(child));
    }
};
class WordDictionary {
    Trie *root;
    bool help(string word, Trie* root, int idx){
        if(idx== word.length()) return root->isEnd;
        
        char c= word[idx];
        if(c!='.'){
            root=root->child[c-'a'];
            return root and help(word, root, idx+1);
        }else{
            for(int i=0; i<26; i++){
                if(root->child[i] and help(word, root->child[i], idx+1)) return true;
            }
            return false;
        }
    }
public:
    WordDictionary() {
        root=new Trie();
    }
    void addWord(string word) {
        Trie *t= root;
        for(int i=0; i<word.length(); i++){
            int idx= word[i]-'a';
            if(!t->child[idx]) t->child[idx]=new Trie();
            t=t->child[idx];
        }
        t->isEnd=true;
    }
    
    bool search(string word) {
        return help(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */