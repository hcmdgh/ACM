#include <iostream>
using namespace std;

class Splay {
#define ROOT nodes[0].child[1]
private:
    static const int MAXN = 100005;
    struct Node {
        int val, father;
        int child[2];  // child[0]:左孩子 child[1]:右孩子
        int sum;
        int repeat;
    } nodes[MAXN];
    int nodes_cnt = 0;

    // 更新node结点的sum值
    void update(int node) {
        Node& _node = nodes[node];
        _node.sum = nodes[_node.child[0]].sum + nodes[_node.child[1]].sum + _node.repeat;
    }

    // 确定当前结点是父亲的左孩子（0）还是右孩子（1）
    int identify(int node) {
        return nodes[nodes[node].father].child[0] == node ? 0 : 1;
    }

    // 建立父子关系
    void connect(int son, int father, int pos) {  // pos为0表示son是父亲的左孩子，pos为1表示son是父亲的右孩子
        nodes[son].father = father;
        nodes[father].child[pos] = son;
    }

    // 将当前结点左旋或右旋
    void rotate(int node) {
        int father = nodes[node].father;
        int father_father = nodes[father].father;
        int father_pos = identify(father);
        int node_pos = identify(node);
        int son = nodes[node].child[node_pos ^ 1];
        connect(son, father, node_pos);
        connect(father, node, node_pos ^ 1);
        connect(node, father_father, father_pos);
        update(father);
        update(node);
    }

    // 伸展操作：将src结点旋转到to结点所在的位置
    void splay(int src, int to) {
        to = nodes[to].father;
        while (nodes[src].father != to) {
            int src_father = nodes[src].father;
            if (nodes[src_father].father == to) {
                rotate(src);
            } else if (identify(src_father) == identify(src)) {
                rotate(src_father);
                rotate(src);
            } else {
                rotate(src);
                rotate(src);
            }
        }
    }

    // 创建新结点，返回结点编号
    int addNode(int val, int father) {
        ++nodes_cnt;
        Node& node = nodes[nodes_cnt];
        node.val = val;
        node.father = father;
        node.sum = node.repeat = 1;
        return nodes_cnt;
    }

    // 销毁结点
    void destroy(int node) {
        Node& _node = nodes[node];
        _node.val = _node.child[0] = _node.child[1] =
                _node.sum = _node.father = _node.repeat = 0;
        if (node == nodes_cnt)
            --nodes_cnt;
    }

    // 查找某个值，返回所在结点的编号（如果不存在则返回0）
    // 查找结束后，将被查找的结点旋转到根，以保证树的结构随机性。
    int find(int val) {
        int now = ROOT;
        while (true) {
            if (nodes[now].val == val) {
                splay(now, ROOT);
                return now;
            }
            int _next = val < nodes[now].val ? 0 : 1;
            if (!nodes[now].child[_next])
                return 0;
            now = nodes[now].child[_next];
        }
    }
};

int main() {


    return 0;
}