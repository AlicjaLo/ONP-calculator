#include <iostream>

using namespace std;

class Node {
    int val;
    Node* nxt;
public:
    Node(int x):val(x), nxt(nullptr) {};
    void add(Node* n) {
        if (nxt == nullptr)
            nxt = n;
        else
            nxt->add(n);
    }
    void add(int x) {
        if (nxt == nullptr)
            nxt = new Node(x);
        else
            nxt->add(x);
    }
    Node* rem(int x) {
        Node* helper;
        if (nxt != nullptr && nxt->val == x) {
            helper = nxt;
            nxt = nxt->nxt;
            delete helper;
            return this;
        }
        if (nxt == nullptr) {
            return this;
        }
        if (val == x && nxt != nullptr) {
            helper = nxt;
            val = nxt->val;
            nxt = nxt->nxt;
            delete helper;
            return this;
        }
        if (val == x && nxt == nullptr) {
            delete this;
            return nullptr;
        }
        nxt = nxt->rem(x);
        return this;
    }
    void print() {
        cout << val << " ";
        if (nxt != nullptr)
            nxt->print();
    }
    int sum(int cnt = 0) {
        if (nxt != nullptr) {
            cnt += val;
            return nxt->sum(cnt);
        }
        return cnt + val;
    }
    double avg(double sum=0, double cnt = 0){
        if (nxt != nullptr){
            cnt++;
            sum += val;
            return nxt->avg(sum,cnt);
        }
        return (sum + val) / ++cnt;
    }
	~Node(){
		delete nxt;
	}
};


int main() {
    Node* fst = new Node(3);
    fst->add(4);
    fst->add(1);
    fst->add(5);
    fst->add(9);
    fst->add(10);
    fst->print();
    cout << "\n" << fst->sum() << "\n";
    cout << "\n" << fst->avg() << "\n";
    fst->rem(4);
    fst->rem(8);
    fst->rem(10);
    fst->rem(3);
    fst->rem(9);
    fst->rem(1);
    return 0;
}
