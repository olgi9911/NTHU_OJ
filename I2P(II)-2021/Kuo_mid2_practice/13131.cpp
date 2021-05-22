#include <iostream>
//#include "function.h"
#include "13131.h"
using namespace std;
// Partial judge
// Array
Array_MAX_HEAP::Array_MAX_HEAP() {
    Count = 0;
}
void Array_MAX_HEAP::PUSH(const int &num) {
    int idx = Count + 1;
    array[idx] = num;

    while (idx > 1 && array[idx] > array[idx / 2]) {  // e.g. 8->4->2->1 (index)
        swap(array[idx], array[idx / 2]);
        idx /= 2;
    }
    Count++;
}
int Array_MAX_HEAP::MAX() const {
    int ret = -1;
    if (Count > 0) ret = array[1];
    return ret;
}
int Array_MAX_HEAP::POP() {
    int ret = -1;
    if (Count > 0) {
        ret = array[1];
        array[1] = array[Count];
        Count--;
        int idx = 1;
        while ((2 * idx <= Count && array[idx] < array[2 * idx]) ||
               (2 * idx + 1 <= Count && array[idx] < array[2 * idx + 1])) {
            if (2 * idx + 1 > Count || array[2 * idx] >= array[2 * idx + 1]) {
                swap(array[idx], array[2 * idx]);
                idx *= 2;
            } else {
                swap(array[idx], array[2 * idx + 1]);
                idx = 2 * idx + 1;
            }
        }
    }

    return ret;
}
//List
List_MAX_HEAP::List_MAX_HEAP() {
    //root = nullptr;
    Count = 0;
}
void List_MAX_HEAP::PUSH(const int &num) {
    ListNode *tmp = new ListNode(num), *curr = nullptr;
    Count++;

    if (Count == 1) {
        root = tmp;
    } else {
        ListNode *par = findparent(Count, root);
        if (par->right) {
            par->left = tmp;
            curr = par->left;
        } else {
            par->right = tmp;
            curr = par->right;
        }
        curr->parent = par;

        while (curr->parent && curr->value > curr->parent->value) {
            swap(curr->value, curr->parent->value);
            curr = curr->parent;
        }
    }
    delete curr;  //
}
int List_MAX_HEAP::MAX() const {
    int ret = -1;
    if (Count > 0) ret = root->value;
    return ret;
}
int List_MAX_HEAP::POP() {
    int ret = -1;
    if (Count == 1) {
        ret = root->value;
        root = nullptr;
        Count--;
    } else if (Count > 1) {
        ret = root->value;
        ListNode *par = findparent(Count, root);
        if (par->right) {
            root->value = par->right->value;
            par->right = nullptr;
        } else {
            root->value = par->left->value;
            par->left = nullptr;
        }
        ListNode *curr = root;
        int left_right = 0;
        while (1) {
            if (curr->left == NULL && curr->right == NULL)  // No need to do anything
                break;
            else if (curr->left == NULL)
                left_right = 1;
            else if (curr->right == NULL)
                left_right = 0;
            else if (curr->left->value > curr->right->value)
                left_right = 0;
            else if (curr->left->value <= curr->right->value)
                left_right = 1;

            if (left_right == 0 && curr->value < curr->left->value) {
                swap(curr->value, curr->left->value);
                curr = curr->left;
            } else if (left_right == 1 && curr->value < curr->right->value) {
                swap(curr->value, curr->right->value);
                curr = curr->right;
            } else
                break;
        }
        Count--;
        delete curr;  //
    }
    return ret;
}
void List_MAX_HEAP::deleteTree(ListNode *root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
//
int main() {
    int n, a;
    Array_MAX_HEAP A_heap;
    List_MAX_HEAP B_heap;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "A_push") {
            cin >> a;
            A_heap.PUSH(a);
        } else if (s == "L_push") {
            cin >> a;
            B_heap.PUSH(a);
        } else if (s == "max") {
            cout << A_heap.MAX() << "\n";
            cout << B_heap.MAX() << "\n";
        } else if (s == "A_pop") {
            cout << A_heap.POP() << "\n";
        } else if (s == "L_pop") {
            cout << B_heap.POP() << "\n";
        } else if (s == "size") {
            cout << A_heap.count() << "\n";
            cout << B_heap.count() << "\n";
        }
    }
}
