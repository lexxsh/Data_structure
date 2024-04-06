#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree(int value) : value(value), left(nullptr), right(nullptr) {}

BinaryTree::~BinaryTree() {
    destroy_tree();
}

void BinaryTree::insert(int new_value) {
    if (value == NULL) { // 루트가 비어 있는 경우
        value = new_value;
        left = nullptr;
        right = nullptr;
    }
    else {
        // 기존의 삽입 로직 유지
        if (new_value < value) {
            if (left == nullptr) {
                left = new BinaryTree(new_value);
            }
            else {
                left->insert(new_value);
            }
        }
        else if (new_value > value) {
            if (right == nullptr) {
                right = new BinaryTree(new_value);
            }
            else {
                right->insert(new_value);
            }
        }
    }
}

bool BinaryTree::contains(int search_value) const {
    if (value == search_value) {
        return true;
    }
    else if (search_value < value && left != nullptr) {
        return left->contains(search_value);
    }
    else if (search_value > value && right != nullptr) {
        return right->contains(search_value);
    }
    return false;
}

void BinaryTree::print_pre_order() const {
    std::cout << value << ' ';
    if (left != nullptr) {
        left->print_pre_order();
    }
    if (right != nullptr) {
        right->print_pre_order();
    }
}

void BinaryTree::print_in_order() const {
    if (left != nullptr) {
        left->print_in_order();
    }
    std::cout << value << ' ';
    if (right != nullptr) {
        right->print_in_order();
    }
}

void BinaryTree::print_post_order() const {
    if (left != nullptr) {
        left->print_post_order();
    }
    if (right != nullptr) {
        right->print_post_order();
    }
    std::cout << value << ' ';
}

void BinaryTree::destroy_tree() {
    if (left != nullptr) {
        left->destroy_tree();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->destroy_tree();
        delete right;
        right = nullptr;
    }
}


#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree tree(5);
    tree.insert(2);
    tree.insert(-4);
    tree.insert(3);
    tree.insert(18);


    std::cout << "Inorder:" << std::endl;
    tree.print_in_order();
    std::cout << std::endl;

    std::cout << "Preorder:" << std::endl;
    tree.print_pre_order();
    std::cout << std::endl;

    std::cout << "Postorder:" << std::endl;
    tree.print_post_order();
    std::cout << std::endl;
    tree.insert(1);
   
    std::cout << "Preorder:" << std::endl;
    tree.print_pre_order();
    std::cout << std::endl;
    //std::cout << "Contains 30? " << tree.contains(30) << std::endl;
    //std::cout << "Contains 100? " << tree.contains(100) << std::endl;

    return 0;
}

