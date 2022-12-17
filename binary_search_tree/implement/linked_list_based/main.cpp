#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node *node, int value)
{
    if (node == NULL)
        return createNode(value);
    
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    
    return node;

}

Node* leftMostNode(Node *node)
{
    Node *curNode = node;
    while (curNode->left != NULL)
    {
        curNode = curNode->left;
    }
    return curNode;
}

Node* deleteNode(Node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // hasn't subnode
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // has 1 subnode
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // has 2 subnode
        Node *replaceNode = leftMostNode(root->right);
        root->data = replaceNode->data;
        root->right = deleteNode(root->right, replaceNode->data);
    }
    return root;
}

Node* search(Node *root, int value)
{
    if (root == NULL)
        return root;
    
    if (value < root->data)
        return search(root->left, value);
    if (value > root->data)
        return search(root->right, value);
    return root;
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int leftChildDepth = maxDepth(root->left);
    int rightChildDepth = maxDepth(root->right);

    int result = max(leftChildDepth, rightChildDepth) + 1;
    return result;
}

bool isLeaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

bool traverse(Node *root, int currentSum, int targetSum)
{
    if (root == NULL)
        return false;

    currentSum = currentSum + root->data;
    if (isLeaf(root))
    {
        
        return currentSum == targetSum;
    }

    bool leftResult = traverse(root->left, currentSum, targetSum);
    bool rightResult = traverse(root->right, currentSum, targetSum);

    if (leftResult == true || rightResult == true)
        return true;
    return false;
}
bool hasPathSum(Node *root, int targetSum)
{
    int currentSum = 0;
    return traverse(root, currentSum, targetSum);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 15);
    root = insert(root, 1);
    root = insert(root, 0);

    inorderTraversal(root);
    // cout << "Max depth: " << maxDepth(root) << endl;
    // cout << "Has path sum: " << hasPathSum(root, 13) << endl;

    return 0;
}