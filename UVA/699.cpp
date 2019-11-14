#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};
int sum[200];
int leftmost;
int rightmost;

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;
    Node* root = new Node;
    root->val = val;
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void explore(Node* root, int cur) {
    leftmost = min(leftmost, cur);
    rightmost = max(rightmost, cur);
    sum[cur] += root->val;
    if (root->left) {
        explore(root->left, cur - 1);
    }
    if (root->right) {
        explore(root->right, cur + 1);
    }
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    ios::sync_with_stdio(false);
    Node* root;
    int t = 0;
    while (root = buildTree()) {
        memset(sum, 0, sizeof(sum));
        leftmost = rightmost = 100;
        explore(root, 100);
        ++t;
        cout << "Case " << t << ":" << endl;
        cout << sum[leftmost];
        for (int i = leftmost + 1; i <= rightmost; ++i) {
            cout << ' ' << sum[i];
        }
        cout << endl << endl;
        deleteTree(root);
    }

    return 0;
}
