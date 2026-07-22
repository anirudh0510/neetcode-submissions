class PrefixTree {
public:
    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            flag = false;
            for (int i = 0; i < 26; i++)
                links[i] = nullptr;
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

    PrefixTree() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return true;
    }
};

/**
 * Your PrefixTree object will be instantiated and called as such:
 * PrefixTree* obj = new PrefixTree();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */