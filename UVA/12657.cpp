#include <iostream>
using namespace std;

int N, M;
struct Node {
    int box;
    Node *next, *prev;
};
Node* box_pos[100005];

int main() {
    ios::sync_with_stdio(false);
    int cnt = 0;
    while (cin >> N >> M) {
        ++cnt;
        Node* head = new Node;
        head->next = head->prev = head;
        for (int i = 1; i <= N; ++i) {
            Node* new_node = new Node;
            new_node->box = i;
            new_node->next = head;
            new_node->prev = head->prev;
            head->prev->next = new_node;
            head->prev = new_node;
            box_pos[i] = new_node;
        }
        bool reversed = false;
        while (M--) {
            int command, X, Y;
            cin >> command;
            if (command == 4) {
                reversed = !reversed;
            } else {
                cin >> X >> Y;
                if (reversed)
                    command = 3 - command;
                if (command == 1) {
                    Node* nodeX = box_pos[X];
                    Node* nodeY = box_pos[Y];
                    if (nodeX->next != nodeY) {
                        nodeX->prev->next = nodeX->next;
                        nodeX->next->prev = nodeX->prev;
                        nodeX->prev = nodeY->prev;
                        nodeX->next = nodeY;
                        nodeY->prev->next = nodeX;
                        nodeY->prev = nodeX;
                    }
                } else if (command == 2) {
                    Node* nodeX = box_pos[X];
                    Node* nodeY = box_pos[Y];
                    if (nodeX->prev != nodeY) {
                        nodeX->prev->next = nodeX->next;
                        nodeX->next->prev = nodeX->prev;
                        nodeX->prev = nodeY;
                        nodeX->next = nodeY->next;
                        nodeY->next->prev = nodeX;
                        nodeY->next = nodeX;
                    }
                } else {
                    box_pos[X]->box = Y;
                    box_pos[Y]->box = X;
                    swap(box_pos[X], box_pos[Y]);
                }
            }
        }
        Node* cur = reversed ? head->prev : head->next;
        long long sum = 0;
        for (int i = 0; i < (N + 1) / 2; ++i) {
            sum += cur->box;
            cur = reversed ? cur->prev->prev : cur->next->next;
        }
        cout << "Case " << cnt << ": " << sum << endl;
    }

    return 0;
}