class MyHashSet {
public:
    static const int SIZE = 1009;
    vector<list<int>> table;

    MyHashSet() {
        table.resize(SIZE);
    }

    int hash(int key) {
        return key % SIZE;
    }

    void add(int key) {
        int idx = hash(key);
        for (int x : table[idx])
            if (x == key)
                return;
        table[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hash(key);
        table[idx].remove(key);
    }

    bool contains(int key) {
        int idx = hash(key);
        for (int x : table[idx])
            if (x == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */