// design the class in the most optimal way


struct Node {
    int key;
    int value;
    Node* prev, *next;
    
    Node(int a, int b){
        key = a, value = b;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
  private:
  public:
    // Constructor for initializing the cache capacity with the given value.
    int cacheSize;
    unordered_map<int,Node*> mp;
    Node* head, *tail;
    LRUCache(int cap) {
        cacheSize=cap;
        tail = new Node(-1,-1);
        head = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node = mp[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* old = mp[key];
            remove(old);
            delete old;
        }
        Node* node = new Node(key,value);
        mp[key] = node;
        add(node);
        
        if(mp.size()>cacheSize){
            Node* todelete = tail->prev;
            remove(todelete);
            mp.erase(todelete->key);
            delete todelete;
        }
    }
    
    void add(Node* node){
        Node* nextnode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextnode;
        nextnode->prev = node;
    }
    void remove(Node* node){
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
};

//GFG POTD solution for 27 January
