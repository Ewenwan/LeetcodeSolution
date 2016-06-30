# Add and Search Word - Data structure design

标签： Trie back_tracking

---

## 题目描述
Design a data structure that supports the following two operations:
```
void addWord(word)
bool search(word)
```
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:
```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```
## 思路分析
同样是使用Trie树建立单词的索引。只不过在search的时候，如果读入的字符是`.`，那么需要我们遍历当前所有可能的字符来确定是否存在这个单词。
使用递归search的方法如下：
```
// 在node处寻找word[idx]
bt_regexMatch(word, idx, trie_node)
    if(trie_node == null)    return false
    if(idx == word.size())   return trie_node->word
    if(word[idx] != '.')
        return bt_regexMatch(word, idx+1, trie_node->child[word[idx]-'a'])
    else
       for j = 0->26
           if bt_regexMatch(word, idx+1, trie_node->child[j]) return true;
    return false
```
## 代码
```
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():word(false), child(vector<TrieNode*>(26, nullptr)){
    }
private:
    vector<TrieNode*> child;
    bool word;
    friend class Trie;
};
class Trie {
    bool bt_regexMatch(const string& word, size_t idx, TrieNode* p) {
        if(p == nullptr)    return false;
        if(idx == word.size())   return p->word;
        char ch = word[idx];
        if(ch == '.') {
            for(int j = 0; j < 26; ++j) {
                TrieNode* q = p->child[j];
                if(bt_regexMatch(word, idx+1, q))   return true;
            }
        } else {
            TrieNode* q = p->child[ch - 'a'];
            return bt_regexMatch(word, idx+1, q);
        }
        return false;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(const string& word) {
        TrieNode* p = root, *q;
        size_t i = 0;
        while(i < word.size()) {
            char ch = word[i];
            q = p;
            p = p->child[ch - 'a'];
            if(p == nullptr)    break;
            ++i;
        }
        if(i == word.size()) {
            p->word = true;
            return;
        }
        while(i < word.size()) {
            p = new TrieNode();
            q->child[word[i] - 'a'] = p;
            q = p;
            ++i;
        }
        p->word = true;
    }
    // Return if there is any word in the trie
    // that match the pattern
    bool regexMatch(const string& word) {
        return bt_regexMatch(word, 0, root);
    }
private:
    TrieNode* root;
};
class WordDictionary {
    Trie tree;
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        tree.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return tree.regexMatch(word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
```




