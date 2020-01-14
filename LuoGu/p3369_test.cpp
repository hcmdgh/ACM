#include <iostream>
#include <vector>
#include <map>
#include <random>
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
        vector<Node *> nodes;
        while (cur) {
//            --cur->valid_cnt;
            nodes.emplace_back(cur);
            if (val == cur->val && !cur->deleted) {
                // 给待删除的结点打上删除标记，而不是真正意义上的删除
                cur->deleted = true;
                for (Node* node : nodes) {
                    --node->valid_cnt;
                }
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

    void clear() {
//        root = nullptr;
    }
} tree;

const int ROUND = 5;  // 测试轮数
const int UPPER_BOUND = 100;  // 容器中元素的最大值
const int LOWER_BOUND = -100;  // 容器中元素的最小值
const int MAX_SIZE = 100;  // 当容器尺寸超过时，结束测试
const int RANK_TIME = 10;  // 查询排名的次数

map<int, int> _map;

void compare_size() {
    int cnt = 0;
    for (auto item : _map) {
        cnt += item.second;
    }
    if (cnt != tree.size())
        throw "size";
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rd_op(1, 7);
    uniform_int_distribution<> rd_num(LOWER_BOUND, UPPER_BOUND);
    uniform_int_distribution<> rd_rank(-100, MAX_SIZE + 100);

    try {
        for (int t = 0; t < ROUND; ++t) {
            _map.clear();
            tree.clear();
            while (tree.size() <= MAX_SIZE) {
                int op = rd_op(gen);
                if (op == 1) {
                    int val = rd_num(gen);
                    ++_map[val];
                    tree.insert(val);
                    compare_size();
//                    printf("insert:%d\n", tree.size());
                } else if (op == 2) {
                    int val = rd_num(gen);
                    if (_map[val] > 0) {
                        --_map[val];
                        tree.erase(val);
                    } else {
                        bool valid = false;
                        try {
                            tree.erase(val);
                        } catch (const char *msg) {
                            valid = true;
                        }
                        if (!valid)
                            throw "erase";
                        compare_size();
                    }
//                    printf("erase:%d\n", tree.size());
                } else if (op == 3) {
                    for (int i = 0; i < RANK_TIME; ++i) {
                        int val = rd_num(gen);
                        auto val_iter = _map.lower_bound(val);
                        int rank = 1;
                        for (auto iter = _map.begin(); iter != val_iter; ++iter) {
                            if (iter->first < val) {
                                rank += iter->second;
                            }
                        }
                        if (rank != tree.rank(val))
                            throw "rank";
                    }
                } else if (op == 4) {
                    for (int i = 0; i < RANK_TIME; ++i) {
                        int rank = rd_rank(gen);
                        vector<int> nums;
                        for (auto item : _map) {
                            for (int j = 0; j < item.second; ++j) {
                                nums.emplace_back(item.first);
                            }
                        }
                        bool valid;
                        if (rank < 1 || rank > nums.size()) {
                            valid = false;
                            try {
                                tree.kth(rank);
                            } catch (const char *msg) {
                                valid = true;
                            }
                        } else {
                            valid = nums[rank - 1] == tree.kth(rank);
                        }
                        if (!valid)
                            throw "kth";
                    }
                } else if (op == 5) {

                } else if (op == 6) {
                    int val = rd_num(gen);
                    auto iter = _map.upper_bound(val);
                    while (iter != _map.end() && iter->second == 0)
                        ++iter;
                    bool valid;
                    if (iter == _map.end()) {
                        valid = false;
                        try {
                            tree.upper(val);
                        } catch (const char *msg) {
                            valid = true;
                        }
                    } else {

                        valid = iter->first == tree.upper(val);
                    }
                    if (!valid)
                        throw "upper";
                } else {
                    compare_size();
                }
            }
        }
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}