#include <iostream>
#include <vector>
using namespace std;
class AbstractTree {
public:
    virtual void insert(int parent, int value) = 0;
    virtual void display() = 0;
    virtual ~AbstractTree() {}
};

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int val) {
        data = val;
    }
};
class GeneralTree : public AbstractTree {
private:
    TreeNode* root;

    TreeNode* findNode(TreeNode* node, int value) {
        if (node == NULL)
            return NULL;

        if (node->data == value)
            return node;

        for (auto child : node->children) {
            TreeNode* found = findNode(child, value);
            if (found != NULL)
                return found;
        }
        return NULL;
    }

    void displayTree(TreeNode* node, int level) {
        if (node == NULL) return;

        for (int i = 0; i < level; i++)
            cout << "  ";

        cout << node->data << endl;

        for (auto child : node->children)
            displayTree(child, level + 1);
    }

public:
    GeneralTree() {
        root = NULL;
    }

    void insert(int parent, int value) {
        if (root == NULL) {
            root = new TreeNode(value);
            return;
        }

        TreeNode* parentNode = findNode(root, parent);
        if (parentNode != NULL)
            parentNode->children.push_back(new TreeNode(value));
        else
            cout << "Parent not found!" << endl;
    }

    void display() {
        displayTree(root, 0);
    }
};

int main() {
    GeneralTree tree;

    tree.insert(0, 1);   
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(2, 4);
    tree.insert(2, 5);

    cout << "General Tree Structure:" << endl;
    tree.display();

    return 0;
}
    