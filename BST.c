#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findMin(root->left);
}

struct Node* findMax(struct Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findMax(root->right);
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void displayMenu() {
    printf("1. Insert node\n");
    printf("2. Delete node\n");
    printf("3. Search\n");
    printf("4. Find minimum value\n");
    printf("5. Find maximum value\n");
    printf("6. Inorder Traversal\n");
    printf("7. Preorder Traversal\n");
    printf("8. Postorder Traversal\n");
    printf("9. Exit\n");
}

int main(void) {
    struct Node* root = NULL;
    int choice, value;

    while(1){
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found.\n", value);
                } else {
                    printf("%d not found.\n", value);
                }
                break;
            case 4:
                if (root != NULL) {
                    struct Node* minNode = findMin(root);
                    printf("Min value: %d\n", minNode->data);
                } else {
                    printf("BST is empty.\n");
                }
                break;
            case 5:
                if (root != NULL) {
                    struct Node* maxNode = findMax(root);
                    printf("Max value: %d\n", maxNode->data);
                } else {
                    printf("BST is empty.\n");
                }
                break;
            case 6:
                inorderTraversal(root);
                printf("\n");
                break;
            case 7:
                preorderTraversal(root);
                printf("\n");
                break;
            case 8:
                postorderTraversal(root);
                printf("\n");
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    };
    return 0;}
