#include <iostream>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int value;
    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    Node* find(int v) {
        if (v == value)
            return this;
        if (v > value) {
            if(right != nullptr)
                return right->find(v);
            return nullptr;
        }
        if (left != nullptr)
            return left->find(v);
        return nullptr;
    }
    void insert(int v) {
        if (v == value)
            return;
        if (v > value) {
            if(right == nullptr) {
                right = new Node(v);
            } else {
                right->insert(v);
            }
            return;
        }
        if(left == nullptr) {
            left = new Node(v);
        } else {
            left->insert(v);
        }
    }
    void inOrder() {
        if(left != nullptr)
            left->inOrder();
        cout << value << endl;
        if(right != nullptr)
            right->inOrder();
    }
};

int main() {
    Node* root = new Node(1);
	root.insert(3);
	root.insert(-1);
	root.insert(10);
	root.insert(1);
	root.insert(2);
	root.inOrder();
}
