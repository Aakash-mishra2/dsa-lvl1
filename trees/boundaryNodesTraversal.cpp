#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class Solution {
    public:
        bool isLeaf(Node* root){
            return !root->left && !root->right;
        }

        void addLeftBoundary(Node* root, vector<int>& res){
            Node* curr = root->left;
            while(curr){
                //If the current node is not a leaf, add its value to the result
                if(!isLeaf(curr)) res.push_back(curr->data);

                //Move to the left child if it exists,
                //otherwise move to the right child

                if(curr->left) curr = curr->left;
                else curr = curr->right;
            }
        }

        void addRightBoundary(Node* root, vector<int>& res){
            Node* curr = root->right;
            vector<int> tmp;
            while(curr){
                if(!isLeaf(curr)) tmp.push_back(curr->data);
                if(curr->right) curr = curr->right;
                else curr = curr->left;
            }
            for(int i = tmp.size()-1; i>=0; --i) res.push_back(tmp[i]);
        }

        void addLeaves(Node* root, vector<int>& res){
            if(isLeaf(root)) {
                res.push_back(root->data);
                return;
            }
            if(root->left) addLeaves(root->left, res);
            if(root->right) addLeaves(root->right, res);
        }

        vector<int> printBoundary(Node* root){
            vector<int> res;
            if(!root) return res;
            if(!isLeaf(root)) res.push_back(root->data);
            //inorder fashion
            addLeftBoundary(root, res);
            addLeaves(root, res);
            addRightBoundary(root, res);

            return res;
        }

};

void printResult(const vector<int>& result){
    for(int val: result){
        cout<<val<<" ";
    }
    cout<<endl;
}


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}
    
