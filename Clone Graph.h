// Clone Graph
/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// DFS, time complexity O(E), space complexity O(V) 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &hash) {
        if (!node) return NULL;
        if (hash.find(node->label) != hash.end()) return hash[node->label];
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        hash[node->label] = newNode;
        for (int i=0; i<node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i], hash));
        }
        return newNode;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> hash;
        return cloneGraph(node, hash);
    }
};

// BFS, time complexity O(E), space complexity O(V) 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
        hash[node] = new UndirectedGraphNode(node->label);
        while (!q.empty()) {
            UndirectedGraphNode *front = q.front();
            q.pop();
            for (int i=0; i<front->neighbors.size(); ++i) {
                UndirectedGraphNode *neighbor = front->neighbors[i];
                if (hash.find(neighbor) == hash.end()) {
                    q.push(neighbor);
                    hash[neighbor] = new UndirectedGraphNode(neighbor->label);
                }
                hash[front]->neighbors.push_back(hash[neighbor]);
            }
        }
        return hash[node];
    }
};