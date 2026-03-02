#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool rightThread;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        rightThread = false;
    }
};

class SingleThreadedBST {
private:
    Node* root;

    Node* leftmost(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    SingleThreadedBST() {
        root = nullptr;
    }

    // 1. Insertion
    void insert(int val) {
        Node* newNode = new Node(val);
        
        if (root == nullptr) {
            root = newNode;
            cout << "Inserted root: " << val << "\n";
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            
            if (val == current->data) {
                cout << "Value " << val << " already exists.\n";
                delete newNode;
                return;
            }

            if (val < current->data) {
                if (current->left == nullptr) {
                    break; 
                }
                current = current->left;
            } else {
                if (current->rightThread == false) {
                    current = current->right;
                } else {
                    break; 
                }
            }
        }

        if (val < parent->data) {
            parent->left = newNode;
            newNode->right = parent;
            newNode->rightThread = true;
        } else {
            newNode->right = parent->right;
            newNode->rightThread = parent->rightThread;
            parent->right = newNode;
            parent->rightThread = false;
        }
        
        cout << "Inserted: " << val << "\n";
    }

    // 2. Search
    void search(int val) {
        Node* current = root;
        
        while (current != nullptr) {
            if (val == current->data) {
                cout << "Found: " << val << " in the tree.\n";
                return;
            }
            
            if (val < current->data) {
                current = current->left;
            } else {
                if (current->rightThread == false) {
                    current = current->right;
                } else {
                    break; 
                }
            }
        }
        cout << "Value " << val << " not found.\n";
    }

    // 3. In-order Traversal (No recursion or stack needed)
    void inorder() {
        cout << "In-order Traversal: ";
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        Node* current = leftmost(root);
        
        while (current != nullptr) {
            cout << current->data << " ";
            
            if (current->rightThread) {
                current = current->right;
            } else {
                current = leftmost(current->right);
            }
        }
        cout << "\n";
    }

    // 4. Find In-order Successor
    void findSuccessor(int val) {
        Node* current = root;
        Node* target = nullptr;

        while (current != nullptr) {
            if (val == current->data) {
                target = current;
                break;
            }
            if (val < current->data) {
                current = current->left;
            } else {
                if (current->rightThread == false) {
                    current = current->right;
                } else {
                    break;
                }
            }
        }

        if (target == nullptr) {
            cout << "Cannot find successor. Node " << val << " not in tree.\n";
            return;
        }

        Node* succ = nullptr;
        if (target->rightThread) {
            succ = target->right;
        } else {
            succ = leftmost(target->right);
        }

        if (succ != nullptr) {
            cout << "In-order successor of " << val << " is: " << succ->data << "\n";
        } else {
            cout << val << " has no in-order successor (it is the maximum value).\n";
        }
    }

    // 5. Display 
    void display() {
        cout << "\n--- Tree Structure Data ---\n";
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        cout << "Node | Left Child | Right Pointer | Is Right a Thread?\n";
        cout << "------------------------------------------------------\n";
        
        Node* current = leftmost(root);
        while (current != nullptr) {
            cout << "  " << current->data << "  | ";
            
            if (current->left != nullptr) {
                cout << "    " << current->left->data << "      | ";
            } else {
                cout << "   NULL    | ";
            }

            if (current->right != nullptr) {
                cout << "      " << current->right->data << "      | ";
            } else {
                cout << "     NULL    | ";
            }

            cout << "       " << (current->rightThread ? "Yes" : "No ") << " \n";

            if (current->rightThread) {
                current = current->right;
            } else {
                current = leftmost(current->right);
            }
        }
        cout << "------------------------------------------------------\n";
    }
};

int main() {
    SingleThreadedBST tree;

    // 1. Insertion
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "\n";

    // 2. In-order Traversal
    tree.inorder();

    cout << "\n";

    // 3. Search
    tree.search(15);
    tree.search(99);

    cout << "\n";

    // 4. Find Successor
    tree.findSuccessor(15);
    tree.findSuccessor(35);

    // 5. Display
    tree.display();

    return 0;
}