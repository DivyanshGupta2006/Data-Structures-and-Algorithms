#include <iostream>

template<typename T>
class NodeWithParent {
public:
    T value;
    NodeWithParent *left;
    NodeWithParent *right;
    NodeWithParent *parent;

    NodeWithParent(const T &data) : value(data), left(nullptr), right(nullptr), parent(nullptr) {}
};

// All functions in your BST would need to be updated to manage the parent pointer.
// For example, an insert function would look like this:
template<typename T>
NodeWithParent<T>* insert(NodeWithParent<T>* node, const T& data, NodeWithParent<T>* parent) {
    if (node == nullptr) {
        NodeWithParent<T>* newNode = new NodeWithParent<T>(data);
        newNode->parent = parent;
        return newNode;
    }

    if (data < node->value) {
        node->left = insert(node->left, data, node);
    } else if (data > node->value) {
        node->right = insert(node->right, data, node);
    }
    return node;
}

int main() {
    NodeWithParent<int>* root = nullptr;
    NodeWithParent<int>* parent = nullptr;

    root = insert(root, 50, parent);
    insert(root, 30, parent);
    insert(root, 70, parent);

    std::cout << "Root's left child: " << root->left->value << std::endl;
    std::cout << "Parent of root's left child: " << root->left->parent->value << std::endl;

    return 0;
}