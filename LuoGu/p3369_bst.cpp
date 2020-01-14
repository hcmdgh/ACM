#include <iostream>
using namespace std;

struct BST {
private:
    struct Node {
        int val;  // 结点中存储的值
        Node *left_child, *right_child;  // 左孩子和右孩子
        bool deleted;  // 该结点是否被删除的标记
        int valid_cnt;  // 该结点所在子树中所有存在的结点的总数
        int total_cnt;  // 结点所在子树中所有结点的总数（在BST中无用）

        Node(int val) :
            val(val), left_child(nullptr), right_child(nullptr),
            deleted(false), valid_cnt(1), total_cnt(1) {}
    };
    Node* root = nullptr;

    // 返回某个结点在该结点所在的子树中的排名
    static int node_rank(Node* node) {
        if (node->left_child) {
            // 需要考虑结点已被删除的情况
            return node->left_child->valid_cnt + !node->deleted;
        } else {
            // 如果子树只含有该结点，且该结点已被删除，排名是0
            return !node->deleted;
        }
    }

public:
    // 插入结点
    void insert(int val) {
        Node** cur = &root;
        while (true) {
            if (*cur == nullptr) {
                *cur = new Node(val);
                break;
            } else if (val < (*cur)->val) {
                // 插入结点的同时，更新valid_cnt和total_cnt
                ++(*cur)->valid_cnt;
                ++(*cur)->total_cnt;
                cur = &(*cur)->left_child;
            } else {
                ++(*cur)->valid_cnt;
                ++(*cur)->total_cnt;
                cur = &(*cur)->right_child;
            }
        }
    }

    // 查询val在树中的排名
    // 排名定义为比val小的数的个数+1
    int rank(int val) {
        Node* cur = root;
        int _rank = 1;
        while (cur) {
            if (val > cur->val) {
                _rank += node_rank(cur);
                cur = cur->right_child;
            } else {
                cur = cur->left_child;
            }
        }
        return _rank;
    }

    // 删除值为val的元素
    // 如果存在多个相同的数，只删除一个
    // 如果不存在，则报错
    void erase(int val) {
        Node* cur = root;
        while (cur) {
            --cur->valid_cnt;
            if (val == cur->val && !cur->deleted) {
                // 给待删除的结点打上删除标记，而不是真正意义上的删除
                cur->deleted = true;
                return;
            }
            if (val < cur->val) {
                cur = cur->left_child;
            } else {
                cur = cur->right_child;
            }
        }
        throw "[ERASE] KeyError";
    }

    // 获取排名为k的元素
    // 如果k非法，则报错
    int kth(int rk) {
        Node* cur = root;
        while (cur) {
            int _rank = node_rank(cur);
            if (rk == _rank && !cur->deleted) {
                return cur->val;
            } else if (rk <= _rank) {
                cur = cur->left_child;
            } else {
                rk -= _rank;
                cur = cur->right_child;
            }
        }
        throw "[KTH] KeyError";
    }

    // 获取val的前驱
    // 前驱的定义为：小于val的最大的数
    // 如果前驱不存在，则报错
    int lower(int val) {
        return kth(rank(val) - 1);
    }

    // 获取val的后继
    // 后继的定义为：大于val的最小的数
    // 如果后继不存在，则报错
    int upper(int val) {
        return kth(rank(val + 1));
    }

    // 获取容器的size
    // 即容器中存储的元素的数量
    int size() {
        if (root)
            return root->valid_cnt;
        else
            return 0;
    }
} tree;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    try {
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
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}