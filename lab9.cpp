#include <iostream>
#include <string>
using namespace std;

template<typename T>
class BinaryTree {
    struct Node {
        T vrem;
        Node* left;
        Node* right;
        
        Node(T val) : vrem(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
public:
    bool poisk(T vrem) {
        Node* srav = root;
        
        while (srav) {
            if (vrem == srav->vrem) {
                return true;
            }
            if (vrem < srav->vrem) {
                srav = srav->left;
            } else {
                srav = srav->right;
            }
        }
        return false;
    }
    BinaryTree() : root(nullptr) {}

    void insert(T vrem) {
        if (poisk(vrem)) {
            return;
        }
        if (!root) {
            root = new Node(vrem);
            return;
        }
        Node* srav = root;
        while (true) {
            if (vrem < srav->vrem) {
                if (!srav->left) {
                    srav->left = new Node(vrem);
                    return;
                }
                srav = srav->left;
            } else {
                if (!srav->right) {
                    srav->right = new Node(vrem);
                    return;
                }
                srav = srav->right;
            }
        }
    }
    
        void clearR(Node* node) {
        if (node) {
            clearR(node->left);
            clearR(node->right);
            delete node;
        }
    }
   
    void clear() {
        clearR(root);
        root = nullptr;
    }
    
  
    
  
    bool empty() {
        return root == nullptr;
    }
    
   
    void print() {
        cout << "Дерево:" << endl;
        cout << "====================" << endl;
        printR(root, 0, 40);
        cout << "====================" << endl;
    }
    
private:
   
    void printR(Node* node, int level, int spaces) {
        if (node) {
         
            printR(node->right, level + 1, spaces + 8);
            
         
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }
            cout << node->vrem << endl;
            
          
            printR(node->left, level + 1, spaces + 8);
        }
    }
};
int main() {
    BinaryTree<int> tree;
    
  
    cout << "Добавляем элементы: 5, 3, 7, 2, 4, 3, 7, 8, 1, 9" << endl;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(3);  // повтор
    tree.insert(7);  // повтор 
    tree.insert(8);
    tree.insert(1);
    tree.insert(9);
    
    tree.print();
    
    cout << "Есть ли 3 в дереве: " << tree.poisk(3) << endl;
    cout << "Есть ли 6 в дереве: " << tree.poisk(6) << endl;
    cout << "Есть ли 7 в дереве: " << tree.poisk(7) << endl;
    cout << "Дерево пустое: " << tree.empty() << endl;
    tree.clear();
    cout << "После очистки дерево пустое: " << tree.empty() << endl;
    
    return 0;
}
