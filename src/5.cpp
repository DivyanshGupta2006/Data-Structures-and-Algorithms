#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printPostorder(Node* node) {
    if (node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";
}

Node* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder,
                int& preorderIndex, int inorderStart, int inorderEnd,
                std::unordered_map<int, int>& inorderMap) {
    if (preorderIndex >= preorder.size() || inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootVal = preorder[preorderIndex++];
    Node* root = new Node(rootVal);
    int inorderIndex = inorderMap[rootVal];

    root->left = buildTree(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1, inorderMap);
    root->right = buildTree(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd, inorderMap);

    return root;
}

void solve(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    std::unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    int preorderIndex = 0;
    Node* root = buildTree(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
    
    std::cout << "Postorder traversal: ";
    printPostorder(root);
    std::cout << std::endl;
}

int main() {
    std::vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    solve(preorder, inorder);
    return 0;
}