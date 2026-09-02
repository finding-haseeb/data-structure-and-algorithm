class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node() {
        key = value = -1;
        prev = next = NULL;
    }

    Node(int k, int value) {
        key = k;
        this->value = value;
        next = prev = NULL;
    }
};


class LRUCache {
public:

    int capacity;
    unordered_map<int, Node*> mpp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        // Make it most recently used
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            node->value = value;

            // Make it most recently used
            remove(node);
            insert(node);

            return;
        }

        // Cache is full
        if(mpp.size() == capacity) {

            Node* node = tail->prev;

            remove(node);

            mpp.erase(node->key);

            delete node;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        insert(newNode);

        mpp[key] = newNode;
    }
};