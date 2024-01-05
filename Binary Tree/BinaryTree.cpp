#include <iostream>

using namespace std;

class treeNode {

public:
    int data;
    treeNode *left;
    treeNode *right;

    treeNode() { data = 0, left = right = nullptr; }
};

class Tree {

public:
    treeNode *root;

    Tree() { root = nullptr; }

    treeNode *insert(treeNode *node, int _item) {
        if (node == nullptr) {
            treeNode *newNode = new treeNode();
            newNode->data = _item;
            node = newNode;
        } else if (node->data > _item) node->left = insert(node->left, _item);
        else node->right = insert(node->right, _item);
        return node;
    }

    void insert(int _item) {
        root = insert(root, _item);
    }

    void postorder(treeNode *node) {
        if (node == nullptr)return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void preorder(treeNode *node) {
        if (node == nullptr)return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(treeNode *node) {
        if (node == nullptr)return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    bool search(treeNode *node, int _item) {
        if (node == nullptr)return false;
        else if (node->data == _item)return true;
        else if (node->data > _item) return search(node->left, _item);
        else return search(node->right, _item);
    }

    treeNode *findMin(treeNode *node) {
        if (node == nullptr)return nullptr;
        else if (node->left == nullptr)return node;
        else return findMin(node->left);
    }

    treeNode *findMax(treeNode *node) {
        if (node == nullptr)return nullptr;
        else if (node->right == nullptr)return node;
        else return findMax(node->right);
    }

    void MaxMin(treeNode *node) {
        treeNode *min = findMin(node);
        treeNode *max = findMax(node);
        if (min == nullptr)cout << "No elements";
        else cout << "Min Element is " << min->data << '\n';
        if (max == nullptr)cout << "No elements";
        else cout << "Min Element is " << max->data << '\n';
    }

    treeNode *Delete(treeNode *node, int _item) {
        if (node == nullptr)
            return nullptr;
        else if (node->data > _item)
            node->left = Delete(node->left, _item);
        else if (node->data < _item)
            node->right = Delete(node->right, _item);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                node = nullptr;
            } else if (node->left != nullptr && node->right == nullptr) {
                node->data = node->left->data;
                delete node->left;
                node->left = nullptr;
            } else if (node->left == nullptr && node->right != nullptr) {
                node->data = node->right->data;
                delete node->right;
                node->right = nullptr;
            } else {
                treeNode *_node = findMax(node->left);
                node->data = _node->data;
                node->left = Delete(node->left, _node->data);
            }
        }
        return node;
    }
};

int n;

bool ok(int k) {
    cin >> n;
    for (int i = 1; i <= k; ++i) {
        if (i == n)return true;
    }
    return false;
}

int main() {
    string introBT = R"(
===============
1-> insert
2-> display "inorder"
3-> display "postorder"
4-> display "preorder"
5-> delete
6-> search
7-> Min & Max
===============
)";
    Tree tree;
    cout << introBT;
    int q;
    while (ok(7)) {
        if (n == 1)
            cin >> q, tree.insert(q);
        else if (n == 2)
            tree.inorder(tree.root);
        else if (n == 3)
            tree.postorder(tree.root);
        else if (n == 4)
            tree.preorder(tree.root);
        else if (n == 5)
            cin >> q, tree.Delete(tree.root, q);
        else if (n == 6)
            cin >> q, cout << tree.search(tree.root, q);
        else if (n == 7)
            tree.MaxMin(tree.root);
        cout << introBT;
    }
}