// Problem Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    class Trie {
    public:
        struct Node {
            int val;
            Node* links[26];
        };

        Node* root;
        Trie() { root = new Node(); }

        void insert(string& word) {
            Node* node = root;

            for (int i = 0; i < word.length(); i++) {
                if ((node->links)[word[i] - 'a'] == NULL) {
                    Node* node1 = new Node();
                    (node->links)[word[i] - 'a'] = node1;
                }
                node = (node->links)[word[i] - 'a'];
                (node->val) += 1;
            }

            // (node->val) += 1;
        }

        int count(string& s) {
            Node* node = root;

            int ans = 0;

            for (auto& c : s) {
                node = (node->links[c - 'a']);
                ans += (node->val);
            }

            return ans;
        }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* obj = new Trie();

        for (auto& e : words) {
            obj->insert(e);
        }

        vector<int> ans(words.size(), 0);

        for (int i = 0; i < words.size(); i++) {

            ans[i] += (obj->count(words[i]));
        }

        return ans;
    }
};
