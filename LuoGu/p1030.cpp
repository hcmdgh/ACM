#include <iostream>
#include <string>
#include <map>
using namespace std;

string in_order, post_order;
int length;
map<char, int> char2id;

struct Node {
    int val;
    Node *left_child, *right_child;
};

void addNode(Node* node, int val) {
    if (val < node->val) {
        if (node->left_child) {
            addNode(node->left_child, val);
        } else {
            Node* temp = new Node;
            temp->val = val;
            temp->left_child = temp->right_child = nullptr;
            node->left_child = temp;
        }
    } else {
        if (node->right_child) {
            addNode(node->right_child, val);
        } else {
            Node* temp = new Node;
            temp->val = val;
            temp->left_child = temp->right_child = nullptr;
            node->right_child = temp;
        }
    }
}

void pre_order(Node* node) {
    if (node) {
        cout << in_order[node->val];
        pre_order(node->left_child);
        pre_order(node->right_child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> in_order >> post_order;

    length = in_order.length();
    for (int i = 0; i < length; ++i) {
        char2id[in_order[i]] = i;
    }

    Node* root = new Node;
    root->val = char2id[post_order[length - 1]];
    root->left_child = root->right_child = nullptr;

    for (int i = length - 2; i >= 0; --i) {
        addNode(root, char2id[post_order[i]]);
    }

    pre_order(root);
    cout << endl;

    return 0;
}