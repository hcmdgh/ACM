#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

int in_order_sequence[10000];
int post_order_sequence[10000];

Node* buildTree(int in_begin, int in_end, int post_begin, int post_end) {
    if (in_begin > in_end)
        return nullptr;
    int root_node = post_order_sequence[post_end];
    Node* root = new Node(root_node);
    int cur = in_begin;
    while (in_order_sequence[cur] != root_node) {
        ++cur;
    }
    int cnt = cur - in_begin;
    root->left = buildTree(in_begin, cur - 1, post_begin, post_begin + cnt - 1);
    root->right = buildTree(cur + 1, in_end, post_begin + cnt, post_end - 1);
    return root;
}

int min_path;
int min_node;
void dfs(Node* root, int val) {
    if (root->left == nullptr && root->right == nullptr) {
        if (val < min_path) {
            min_path = val;
            min_node = root->val;
        } else if (val == min_path && root->val < min_node) {
            min_node = root->val;
        }
    } else {
        if (root->left) {
            dfs(root->left, val + root->left->val);
        }
        if (root->right) {
            dfs(root->right, val + root->right->val);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string in_order, post_order;
    while (getline(cin, in_order) && getline(cin, post_order)) {
        stringstream ss1(in_order);
        int cnt = 0;
        int node;
        while (ss1 >> node) {
            in_order_sequence[cnt++] = node;
        }
        stringstream ss2(post_order);
        cnt = 0;
        while (ss2 >> node) {
            post_order_sequence[cnt++] = node;
        }

        Node* root = buildTree(0, cnt - 1, 0, cnt - 1);

        min_path = INT_MAX;
        min_node = INT_MAX;
        dfs(root, root->val);

        cout << min_node << endl;
    }

    return 0;
}
