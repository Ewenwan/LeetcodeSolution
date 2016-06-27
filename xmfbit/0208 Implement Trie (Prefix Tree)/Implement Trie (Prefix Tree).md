# Implement Trie (Prefix Tree)

标签： Trie

---

## 题目描述
Implement a trie with `insert`, `search`, and `startsWith` methods. 

## 思路分析
这道题目要求实现 [Trie](https://en.wiki2.org/wiki/Trie) 这种数据结构。如图所示，是一种应用于快速检索英文单词的Trie树的实现。

![应用于英文单词的Trie树结构][trie.png]

在 [这里](https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/) 也有一篇不错的关于Trie树的入门介绍。

代码的原理很简单，就是建立一个26叉树。为了表明某个节点是前缀还是整个词，我们需要加入一个布尔量`word`表示该节点的状态。这样，才能区分`word`和`prefix`。代码中的`search`方法和`startsWith`中就可以看出两者的不同。

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
public:
	Trie() {
		root = new TrieNode();
	}
	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* p = root, *q;
		size_t i = 0;
		while(i < word.size()) {
			char ch = word[i];
			q = p;
			p = p->child[ch - 'a'];
			if(p == nullptr)	break;
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

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* p = root, *q = root;
		size_t i = 0;
		while(i < word.size()) {
			char ch = word[i];
			q = p;
			p = p->child[ch - 'a'];
			if(p == nullptr) break;
			++i;
		}
		return i == word.size() && p->word;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		size_t i = 0;
		TrieNode* p = root;
		while(i < prefix.size()) {
			char ch = prefix[i];
			p = p->child[ch - 'a'];
			if(p == nullptr)	break;
			++i;
		}
		return i == prefix.size();
	}
private:
	TrieNode* root;
};
```