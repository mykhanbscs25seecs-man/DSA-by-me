#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Binary_Tree {

    class Node {
        public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;
    int index = -1;
public:
    Node *createTree(vector<int> v ){
        if (index == -1) {
            this->destoryTree(root); //in order to delete the previous tree and inside if as we dont want to call this recursively.
        }

        index++;
        if (v[index] == -1) {
            return nullptr;
        }

        Node *newnode = new Node();
        newnode->data = v[index];

        newnode->left = createTree(v);
        newnode->right = createTree(v);

        root = newnode;
        return newnode;
    }

    void print_preorder(Node* the_root) {

        if (the_root == nullptr) {
            return;
        }


        cout << the_root->data << endl;
        print_preorder(the_root->left);
        print_preorder(the_root->right);

    }

    void inorder(Node* the_root) {
        if (the_root == nullptr) {
            return;
        }
        inorder(the_root->left);
        cout << the_root->data << endl;
        inorder(the_root->right);
    }

    void postorder(Node* the_root) {
        if (the_root == nullptr) {
            return;
        }
        postorder(the_root->left);
        postorder(the_root->right);
        cout << the_root->data << endl;
    }

    void destoryTree(Node* the_root) {
        if (the_root == nullptr) {
            return;
        }
        destoryTree(the_root->left);
        destoryTree(the_root->right);
        delete the_root;
    }

    void LevelOrderTraversal(Node* root) { //iterative apporoach
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != nullptr) {
                q.push(temp->left);

            }
            if (temp->right != nullptr) {
                q.push(temp->right);

            }
            //extra code just print elements on their level, a little output formatting, nothing more.
            if (temp->left != nullptr && temp->right != nullptr) {
                cout << endl;
            }
        }
    }

    ~Binary_Tree() {
        destoryTree(root);
    }



};


int main() {
    Binary_Tree tree;
    vector<int> v = {1,2,-1,8,-1,-1,3,4,-1,-1,5,9,-1,-1,0,-1,-1};


    tree.LevelOrderTraversal(tree.createTree(v));

}

