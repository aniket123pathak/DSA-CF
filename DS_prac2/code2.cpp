#include <iostream>
using namespace std;

// Node structure tailored for a Single (Right) Threaded Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool rthread; // True if 'right' points to an in-order successor

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        // By default, the right pointer of a new leaf is a thread
        rthread = true; 
    }
};

class SingleThreadedBinaryTree {
private:
    Node* root;

    // Helper function to find the leftmost node in a subtree
    Node* leftmost(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    SingleThreadedBinaryTree() {
        root = nullptr;
    }

    // 1. INSERTION OPERATION
    void insert(int key) {
        Node* newNode = new Node(key);

        // Edge case: Empty tree
        if (root == nullptr) {
            root = newNode;
            cout << "Inserted " << key << " as root.\n";
            return;
        }

        Node* curr = root;
        Node* parent = nullptr;

        // Find the correct position in the BST
        while (curr != nullptr) {
            parent = curr;
            if (key == curr->data) {
                cout << "Duplicate key " << key << " not allowed.\n";
                delete newNode; 
                return;
            }

            if (key < curr->data) {
                // Left pointers behave like a normal BST
                curr = curr->left;
            } else {
                // For right pointers, we must check if it's a thread or a child
                if (!curr->rthread) {
                    curr = curr->right;
                } else {
                    break; // Reached a thread, found our insertion point
                }
            }
        }

        // Wire up the new node
        if (key < parent->data) {
            // Inserting as a left child
            parent->left = newNode;
            newNode->right = parent;   // The successor of a left child is its parent
            newNode->rthread = true;
        } else {
            // Inserting as a right child
            newNode->right = parent->right; // New node's successor is parent's successor
            newNode->rthread = true;
            parent->right = newNode;        // Parent now has a real right child
            parent->rthread = false;        // Remove the thread from parent
        }
        cout << "Inserted " << key << " successfully.\n";
    }

    // 2. SEARCH OPERATION
    bool search(int key) {
        Node* curr = root;
        
        while (curr != nullptr) {
            if (curr->data == key) {
                return true; // Key found
            }
            
            if (key < curr->data) {
                curr = curr->left; // Normal left traversal
            } else {
                // If moving right, ensure we don't accidentally follow a thread
                if (!curr->rthread) {
                    curr = curr->right;
                } else {
                    return false; // Thread means no actual right child exists
                }
            }
        }
        return false;
    }

    // 3. IN-ORDER TRAVERSAL (Without Recursion or Stack)
    void inorderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        // Step 1: Start at the absolute leftmost node of the tree
        Node* curr = leftmost(root);

        cout << "In-order Traversal: ";
        
        // Step 2: Traverse using right pointers and threads
        while (curr != nullptr) {
            cout << curr->data << " ";
            
            // If the right pointer is a thread, simply follow it to the successor
            if (curr->rthread) {
                curr = curr->right;
            } 
            // If the right pointer is a real child, go to the leftmost node of that right subtree
            else {
                curr = leftmost(curr->right);
            }
        }
        cout << "\n";
    }
};

// Driver code to demonstrate functionality
int main() {
    SingleThreadedBinaryTree stbt;

    cout << "--- Single Threaded Binary Tree Operations ---\n";
    
    // Insertion
    stbt.insert(20);
    stbt.insert(10);
    stbt.insert(30);
    stbt.insert(5);
    stbt.insert(15);
    stbt.insert(25);
    stbt.insert(35);

    // Traversal
    stbt.inorderTraversal();

    // Search
    int target1 = 15;
    int target2 = 40;
    
    cout << "\n--- Search Operations ---\n";
    cout << "Searching for " << target1 << ": " << (stbt.search(target1) ? "Found" : "Not Found") << "\n";
    cout << "Searching for " << target2 << ": " << (stbt.search(target2) ? "Found" : "Not Found") << "\n";

    return 0;
}