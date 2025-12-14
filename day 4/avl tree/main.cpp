#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVL
{
public:
    Node* root;

    AVL()
    {
        root = NULL;
    }

    /// calculate the height ///
    int height(Node* n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    /// calculate balance factor ///
    int getBalance(Node* n)
    {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

    // Right Rotation (LL)
    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left Rotation (RR)
    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Insert
    Node* insert(Node* node, int key)
    {
        // 1) BST Insert
        if (node == NULL)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; // مفيش duplicates

        // 2) تحديث الارتفاع
        node->height = 1 + max(height(node->left),
                               height(node->right));

        // 3) حساب balance
        int balance = getBalance(node);

        // 4) حالات الروتيشن

        // LL
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // RR
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // LR
        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Wrapper
    void insert(int key)
    {
        root = insert(root, key);
    }

    // Inorder Traversal
    void inorder(Node* r)
    {
        if (r == NULL)
            return;

        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    void printInorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVL tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder Traversal of AVL Tree:\n";
    tree.printInorder();

    return 0;
}
