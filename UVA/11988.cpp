#include <iostream>
#include <string>
using namespace std;

struct Node {
    char ch;
    Node* next;
};

int main() {
    ios::sync_with_stdio(false);
    string str;
    while (cin >> str) {
        Node *head, *tail, *cur;
        head = tail = new Node;
        head->next = nullptr;
        cur = head;
        for (char ch : str) {
            if (ch == '[') {
                cur = head;
            } else if (ch == ']') {
                cur = tail;
            } else {
                Node* new_node = new Node;
                new_node->ch = ch;
                new_node->next = cur->next;
                cur->next = new_node;
                if (new_node->next == nullptr)
                    tail = new_node;
                cur = new_node;
            }
        }
        cur = head->next;
        while (cur) {
            cout << cur->ch;
            cur = cur->next;
        }
        cout << endl;
        cur = head;
        while (cur) {
            Node* temp = cur->next;
            delete cur;
            cur = temp;
        }
    }

    return 0;
}