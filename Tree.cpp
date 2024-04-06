#include <iostream>
using namespace std;

class TreeNode {
public:
    static const int MAX_CHILDREN = 10;
    char value;
    int numChildren;
    TreeNode** children;

    TreeNode(char val, int num) : value(val), numChildren(num) {
        children = new TreeNode * [numChildren];
        for (int i = 0; i < numChildren; ++i) {
            children[i] = nullptr;
        }
    }

    static void printTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << " ";
        for (int i = 0; i < node->numChildren; ++i) {
            printTree(node->children[i]);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode('A', 3);
    root->children[0] = new TreeNode('B', 2);
    root->children[1] = new TreeNode('C', 1);
    root->children[2] = new TreeNode('D', 0);

    root->children[0]->children[0] = new TreeNode('E', 0);
    root->children[0]->children[1] = new TreeNode('F', 0);
    root->children[1]->children[0] = new TreeNode('G', 0);

    cout << "Pre-order traversal: ";
    TreeNode::printTree(root);

    return 0;
}
