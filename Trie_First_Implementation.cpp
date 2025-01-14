class Trie {
public:
    struct Node {
        Node* links[26];
        bool flag = 0;
    };

    Node* root;

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if ((node->links)[word[i] - 'a'] == NULL) {
                Node* node1 = new Node();
                (node->links)[word[i] - 'a'] = node1;
            }
            node = (node->links)[word[i] - 'a'];
        }

        (node->flag) = 1;
    }

    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if ((node->links)[word[i] - 'a'] == NULL) {
                return false;
            }
            node = (node->links)[word[i] - 'a'];
        }

        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.length(); i++) {
            if ((node->links)[prefix[i] - 'a'] == NULL) {
                return false;
            }
            node = (node->links)[prefix[i] - 'a'];
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
