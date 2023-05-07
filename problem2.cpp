#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* BST(vector<int>& nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int mid = (left + right) / 2;
    Node* root = new Node(nums[mid]);
    root->left = BST(nums, left, mid - 1);
    root->right = BST(nums, mid + 1, right);
    return root;
}

void printInorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
}

int main() {
    vector<int> nums = {9, 11, 18, 3, 4, 12, 3, 4, 2, 20};
    sort(nums.begin(), nums.end());
    Node* root = BST(nums, 0, nums.size() - 1);
    printInorder(root);
    return 0;
}
