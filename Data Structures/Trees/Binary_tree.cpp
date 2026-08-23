#include <iostream>
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

    void destoryTree(Node* the_root) {
        if (the_root == nullptr) {
            return;
        }
        destoryTree(the_root->left);
        destoryTree(the_root->right);
        delete the_root;
    }

    ~Binary_Tree() {
        destoryTree(root);
    }



};


int main() {
    Binary_Tree tree;
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};


    tree.print_preorder(tree.createTree(v));

}

