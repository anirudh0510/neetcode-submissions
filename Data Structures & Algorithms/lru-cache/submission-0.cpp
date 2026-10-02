class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

    unordered_map<int, Node*> mpp;

    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the doubly linked list
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Add a node at the front
    void addFront(Node* node) {
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {

        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];

        // This key was recently used, so move it to front
        remove(node);
        addFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // If key already exists
        if (mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            node->value = value;

            // Mark it as recently used
            remove(node);
            addFront(node);

            return;
        }

        // If cache is full
        if (mpp.size() == capacity) {

            // Tail's previous node is the least recently used
            Node* lru = tail->prev;

            mpp.erase(lru->key);

            remove(lru);

            delete lru;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // Store it in map
        mpp[key] = newNode;

        // New node is most recently used
        addFront(newNode);
    }
};