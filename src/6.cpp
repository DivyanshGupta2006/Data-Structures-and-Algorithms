#include <iostream>
#include <vector>
#include <unordered_map>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printPreorder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

Node* buildTree(const std::vector<int>& inorder, const std::vector<int>& postorder,
                int& postorderIndex, int inorderStart, int inorderEnd,
                std::unordered_map<int, int>& inorderMap) {
    if (postorderIndex < 0 || inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootVal = postorder[postorderIndex--];
    Node* root = new Node(rootVal);
    int inorderIndex = inorderMap[rootVal];

    root->right = buildTree(inorder, postorder, postorderIndex, inorderIndex + 1, inorderEnd, inorderMap);
    root->left = buildTree(inorder, postorder, postorderIndex, inorderStart, inorderIndex - 1, inorderMap);

    return root;
}

void solve(const std::vector<int>& inorder, const std::vector<int>& postorder) {
    std::unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    int postorderIndex = postorder.size() - 1;
    Node* root = buildTree(inorder, postorder, postorderIndex, 0, inorder.size() - 1, inorderMap);

    std::cout << "Preorder traversal: ";
    printPreorder(root);
    std::cout << std::endl;
}

int main() {
    std::vector<int> inorder = {1, 2, 3};
    std::vector<int> postorder = {1, 3, 2};
    solve(inorder, postorder);
    return 0;
}