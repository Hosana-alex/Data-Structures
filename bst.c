#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new BST node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert a new node with given data in BST
Node* insert(Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    // Return the (unchanged) node pointer
    return node;
}

// In-order traversal of BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order traversal of BST
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal of BST
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Search for a value in BST
Node* search(Node* root, int key) {
    // Base cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

// Driver code
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("pre-order traversal of the BST: ");
    preorderTraversal(root);
    printf("\n");

    printf("post-order traversal of the BST: ");
    postorderTraversal(root);
    printf("\n");

    printf("Searching for 40 in the BST: ");
    Node* res = search(root, 40);
    if (res != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
