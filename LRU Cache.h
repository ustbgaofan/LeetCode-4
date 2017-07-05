// LRU Cache
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


class LRUCache {
public:
    LRUCache(int capacity) {
        c = capacity;    
    }
    
    int get(int key) {
        if (h.find(key) == h.end()) return -1;
        l.splice(l.begin(), l, h[key]);
        return l.begin()->v;
    }
    
    void put(int key, int value) {
        if (h.find(key) != h.end()) {
            l.splice(l.begin(), l, h[key]);
            l.begin()->v = value;
        } else {
            if (l.size() < c) {
                l.push_front(Node(key, value));
            } else {
                l.splice(l.begin(), l, --l.end());
                h.erase(l.begin()->k);
                l.begin()->k = key;
                l.begin()->v = value;
            }
            h[key] = l.begin();
        }
    }
    
private:
    struct Node {
        int k;  
        int v;
        Node(int k, int v): k(k), v(v) {}
    };
    int c;
    list<Node> l;
    unordered_map<int, list<Node>::iterator> h;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
