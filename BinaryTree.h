#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinaryTree {
public:
    BinaryTree(int value);
    ~BinaryTree();

    void insert(int value);
    bool contains(int value) const;
    void print_in_order() const;
    void print_pre_order() const;
    void print_post_order() const;


private:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    void destroy_tree();
};

#endif // BINARY_TREE_H
