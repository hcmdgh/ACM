#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct Node {
    char val;
    Node *left, *right;
};

map<char, Node*> char2node;

Node* getNode(char val) {
    if (val == '*')
        return nullptr;
    if (char2node.count(val) > 0) {
        return char2node[val];
    } else {
        Node* temp = new Node;
        temp->val = val;
        temp->left = temp->right = nullptr;
        char2node[val] = temp;
        return temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        char node, left_child, right_child;
        cin >> node >> left_child >> right_child;
        if (root == nullptr) {
            root = getNode(node);
        }
        Node* node_ptr = char2node[node];
        node_ptr->left = getNode(left_child);
        node_ptr->right = getNode(right_child);
    }

    stack<Node *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        Node* top = nodes.top();
        nodes.pop();
        cout << top->val;
        if (top->right)
            nodes.push(top->right);
        if (top->left)
            nodes.push(top->left);
    }
    cout << endl;

    return 0;
}