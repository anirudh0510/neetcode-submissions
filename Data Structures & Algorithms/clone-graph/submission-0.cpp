/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void DFS(Node* node, Node* clone_node, unordered_map<Node*, Node*>& mpp) {
        for (Node* nb : node->neighbors) {
            if (mpp.find(nb) == mpp.end()) {   //neighbours is not cloned yet
                Node* clone = new Node(nb->val);
                mpp[nb] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(nb, clone, mpp);
            }
            else {
                clone_node->neighbors.push_back(mpp[nb]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        //clone the given node
        Node* clone_node = new Node(node->val);

        //Now , clone its neighbour and recursilvely clone itts neighbours
        //but if a node reappears , use that only for true meaning of deep copy , so store in map<Node* ,clone_node>

        unordered_map<Node*, Node*> mpp;
        mpp[node] = clone_node;

        DFS(node, clone_node, mpp);

        return clone_node;
    }
};