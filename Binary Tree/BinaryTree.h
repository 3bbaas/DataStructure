#ifndef BT_
#define BT_


//class treeNode {
//public:
//    int data;
//    treeNode *left;
//    treeNode *right;
//
//    treeNode() { data = 0, left = right = nullptr; }
//};
//
//void inOrder(treeNode *node);
//
//void postOrder(treeNode *node);
//
//void preOrder(treeNode *node);
//
//treeNode *insert(treeNode *node, int _item);
//
//treeNode *deleteItem(treeNode *node, int _item);

#endif //BT_
/*
/// ------ Inorder Traversal ------
void inOrder(treeNode *node) {
    if (node == nullptr)return;
    inOrder(node->left);
    std::cout << "Item " << node->data << ' ';
    inOrder(node->right);
}

/// ------ PreOrder Traversal ------
void preOrder(treeNode *node) {
    if (node == nullptr)return;
    std::cout << "Item " << node->data << ' ';
    preOrder(node->left);
    preOrder(node->right);
}

/// ------ PostOrder Traversal ------
void postOrder(treeNode *node) {
    if (node == nullptr)return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << "Item " << node->data << ' ';
}

treeNode *insert(treeNode *node, int _item) {
    if (node == nullptr) {
        treeNode *newNode = new treeNode();
        newNode->data = _item;
        node = newNode;
    } else if (node->data < _item)
        node->right = insert(node->right, _item);
    else
        node->right = insert(node->left, _item);
    return node;
}

bool search(treeNode *node, int _item) {
    if (node == nullptr)return false;
    else if (node->data == _item)return true;
    else if (node->data < _item) search(node->right, _item);
    else search(node->left, _item);
    return false;
}

treeNode *deleteItem(treeNode *node, int _item) {
    if (node == nullptr)return nullptr;
    else if (node->right == nullptr &&
             node->left == nullptr && _item == node->data)

}
 **/