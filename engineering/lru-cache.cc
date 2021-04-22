struct Node{
    int key, val;
    Node *prev, *next;
    Node(int k, int v): key(k), val(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
        c = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    ~LRUCache() {
        Node *iter = head->next;
        while(iter != tail) {
            Node *tmp = iter;
            iter = iter->next;
            delete tmp;
        }
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if (mem.find(key) == mem.end()) return -1;
        
        Node *now = mem[key];
        attach_node(detach_node(now));
        return now->val;
    }
    
    void set(int key, int value) {
        if (size == 0) return;
        
        Node *now = NULL;
        if (mem.find(key) != mem.end()) {
            now = detach_node(mem[key]);
            now->val = value;
        } else {
            if (c == size) {
                mem.erase(tail->prev->key);
                now = detach_node(tail->prev);
                now->key = key;
                now->val = value;
            } else {
                now = new Node(key, value);
                ++c;
            }
            mem[key] = now;
        }
        
        attach_node(now);
    }
private:
    int size;
    int c;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mem;
    
    Node* detach_node(Node *now) {
        now->prev->next = now->next;
        now->next->prev = now->prev;
        return now;
    }
    
    
    Node* attach_node(Node *now) {
        now->next = head->next;
        now->prev = head;
        
        head->next = now;
        now->next->prev = now;
        
        return now;
    }
};
