// LRU Cache
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.
*/


// list + hash
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct Node {
    int key;  // for deletion in hash
    int value;
    Node(int k, int v): key(k), value(v) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        nodes.splice(nodes.begin(), nodes, hash[key]);
        //hash[key] = nodes.begin();
        return nodes.begin()->value; 
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            nodes.splice(nodes.begin(), nodes, hash[key]);
            //hash[key] = nodes.begin();
            nodes.begin()->value = value;
        } else {
            if (nodes.size() < maxSize) {
                nodes.push_front(Node(key, value));
            } else {
                nodes.splice(nodes.begin(), nodes, --nodes.end());
                hash.erase(nodes.begin()->key);
                nodes.begin()->key = key;
                nodes.begin()->value = value;
            }
            hash[key] = nodes.begin();
        }
    }
	
	void print() {
    	cout<<"~~~~~";
    	for (list<Node>::iterator it=nodes.begin(); it!=nodes.end(); ++it) {
    		cout<<it->key<<" ";
    	}
    	cout<<endl;
    }

private:
    list<Node> nodes;
    unordered_map<int, list<Node>::iterator> hash;
    int maxSize;
};

int main() {
	LRUCache c(3);
	c.set(1,1), c.set(2,2), c.set(3,3), c.set(4,4);
	c.print();
	c.set(2,3), c.set(3,4), c.set(4,5);
	c.print();
	c.set(1,2);
	c.print();
	cout<<c.get(2)<<" "<<c.get(3)<<endl;
	c.print();
	return 0;
}