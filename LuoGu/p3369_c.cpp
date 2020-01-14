#include <iostream>
#include <vector>
using namespace std;

const double ALPHA = 0.7;

class ScapegoatTree {
//public:
//    ScapegoatTree() {
//        root = null = new Node;
//        root = nullptr;
//    }

private:
    struct Node {
        Node *left_child, *right_child;
        int val, size, cnt;
        bool deleted;

        Node(int val) {
            left_child = right_child = nullptr;
            size = cnt = 0;
            deleted = false;
            this->val = val;
        }

        bool is_bad() {
            return left_child->cnt > ALPHA * cnt + 5
                   || right_child->cnt > ALPHA * cnt + 5;
        }

        void maintain() {
            size = !deleted + left_child->size + right_child->size;
            cnt = 1 + left_child->cnt + right_child->cnt;
        }
    };

    Node *root = nullptr;

    static void dfs(Node* node, vector<Node *>& vec) {
        if (node) {
            dfs(node->left_child, vec);
            if (!node->deleted) {
                vec.emplace_back(node);
            }
            dfs(node->right_child, vec);
            if (node->deleted) {
                delete(node);
            }
        }
    }

    static Node* build(const vector<Node *>& vec, int L, int R) {
        if (L >= R)
            return nullptr;
        int mid = (L + R) >> 1;
        Node* node = vec[mid];
        node->left_child = build(vec, L, mid);
        node->right_child = build(vec, mid + 1, R);
        node->maintain();
        return node;
    }

    static void rebuild(Node*& node) {
        vector<Node *> vec;
        dfs(node, vec);
        // TODO 与题解不同
        node = build(vec, 0, vec.size());
    }

    static void _insert(int val, Node*& node) {
        if (node == nullptr) {
            node = new Node(val);
//            node->left_child = node->right_child = nullptr;
//            node->deleted = false;
//            node->size = node->cnt = 1;
//            node->val = val;
        } else {
            ++node->size;
            ++node->cnt;
            if (val >= node->val) {
                _insert(val, node->right_child);
            } else {
                _insert(val, node->left_child);
            }
            if (node->is_bad()) {
                rebuild(node);
            }
        }
    }

    static void _erase(Node* node, int rk) {
        if (!node->deleted && rk == node->left_child->size + 1) {
            node->deleted = true;
            --node->size;
        } else {
            --node->size;
            if (rk <= node->left_child->size + !node->deleted) {
                _erase(node->left_child, rk);
            } else {
                _erase(node->right_child, rk - node->left_child->size - !node->deleted);
            }
        }
    }

public:
    void insert(int val) {
        _insert(val, root);
    }

    int rank(int val) {
        int ans = 1;
        Node* cur = root;
        while (cur) {
            if (cur->val >= val) {
                cur = cur->left_child;
            } else {
                ans += cur->left_child->size + !cur->deleted;
                cur = cur->right_child;
            }
        }
        return ans;
    }

    int kth(int k) {
        Node* cur = root;
        while (cur) {
            if (!cur->deleted && cur->left_child && cur->left_child->size + 1 == k) {
                return cur->val;
            } else if (cur->left_child->size >= k) {
                cur = cur->left_child;
            } else {
                k -= cur->left_child->size + !cur->deleted;
                cur = cur->right_child;
            }
        }
        // TODO 原题解无返回值
        return -1;
    }

    void erase(int val) {
        _erase(root, rank(val));
    }

    int lower(int val) {
        return kth(rank(val) - 1);
    }

    int upper(int val) {
        return kth(rank(val + 1));
    }
} tree;
int N;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    while (N--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 1) {
            tree.insert(x);
        } else if (opt == 2) {
            tree.erase(x);
        } else if (opt == 3) {
            printf("%d\n", tree.rank(x));
        } else if (opt == 4) {
            printf("%d\n", tree.kth(x));
        } else if (opt == 5) {
            printf("%d\n", tree.lower(x));
        } else {
            printf("%d\n", tree.upper(x));
        }
    }

    return 0;
}