
#include "Tree.hpp"
#include <stdexcept>

// A method to create a node
Tree::Node *Tree::createNode(int value)
{
    Node *newNode = new Node();

    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// A method to see if the tree contains a certain value
int Tree::contains(int value)
{
    Node* ans = findNode(value, start);
    if(ans!= NULL){
        return 1;
    }

    return 0;
}

//A method to insert a value to the tree
void Tree::insert(int value)
{
    Tree::addPrivate(value, start);
    amount++;
}

// A private method to add to the tree using the pointer
void Tree::addPrivate(int value, Node *p)
{
    //Check if the starting point is Null
    if (start == NULL)
    {
        start = createNode(value);
    }
    // if the value is less than the value of the pointer then go left
    else if (value < p->key)
    {
        if (p->left != NULL)
        {
            addPrivate(value, p->left);
        }
        else
        {
            p->left = createNode(value);
        }
    }
    // if the value is more than the value of the pointer then go right
    else if (value > p->key)
    {
        if (p->right != NULL)
        {
            addPrivate(value, p->right);
        }
        else
        {
            p->right = createNode(value);
        }
    }
    // if the value is equal to the value of the pointer
    else
    {
                throw std::out_of_range("that value has been entered already");

    }
}
    // A private method to find the Node that they are looking for
Tree::Node *Tree::findNode(int value, Node *p)
{
    if (p != NULL)
    {
        if (value == p->key)
        {
            return p;
        }
        else if (value < p->key)
        {
            return findNode(value, p->left);
        }
        else
        {
            return findNode(value, p->right);
        }
    }
    else
    {
       return NULL;
    }
}
// A method to find the left value of the value that they are looking for
int Tree::left(int value)
{
    Node* parent = findNode(value, start);
    if(parent->left == NULL){
        throw std::out_of_range("No left node");
    }
    else{
        return parent->left->key;
    }
}
// Find the parent of the value that they are looking for
int Tree::parent(int value)
{
    Node* ans = findParent(value, start);
    if(ans == NULL){
        throw std::out_of_range("No parent");
    }
    else{
        return ans->key;
    }   
}
// A private method to help find the parent of the value they are looking for
    Tree::Node* Tree::findParent(int value , Node* p){
        if(p != NULL){
            if(value == start->key){
                return NULL;
            }
            if(value < p->key){
                if(p->left == NULL){
                    return NULL;
                }
                else if (value == p->left->key) {
                    return p;;
                }
                else{
                    return findParent(value, p->left);
                }
                
            }
            else {
                if(p->right == NULL){
                    return NULL;
                }
               else if (value == p->right->key) {
                    return p;;
                }
                else{
                    return findParent(value, p->right);
                }
            }
        }
        else{
            return NULL;
        }
    }
    // print method
void Tree::print()
{
    printPreOrder(start);
}
// A method to print in Preorder
void Tree::printPreOrder(Node *p)
{
    if(start != NULL){
        cout << p->key << " ";
        if(p->left !=NULL){
            printPreOrder(p->left);
        }
        if(p->right != NULL){
            printPreOrder(p->right);        }

    }
    else{
        cout << "The Tree is empty"<< endl;
    }
}
// A method to remove the node of the value they are looking for
void Tree::remove(int value)
{
}
// A method to find the right child of the value they are looking for
int Tree::right(int value)
{
    Node* parent = findNode(value, start);
    if(parent->right == NULL){
        throw std::out_of_range("No right node");
    }
    else{
        return parent->right->key;
    }
}
// return the value of root
int Tree::root()
{
    return Tree::start->key;
}
// return the amount of leaves that are in the tree
int Tree::size()
{
    return Tree::amount;
}
