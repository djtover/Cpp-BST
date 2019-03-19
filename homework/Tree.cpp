
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
bool Tree::contains(int value)
{

    return false;
}

//A method to insert a value to the tree
void Tree::insert(int value)
{
    Tree::addPrivate(value, start);
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
        cout << "That value has been entered already" << endl;
    }
}

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
int Tree::parent(int value)
{
    return 0;
}
void Tree::print()
{
    printPreOrder(start);
}
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
void Tree::remove(int value)
{
}
int Tree::right(int value)
{
    return 0;
}
int Tree::root()
{
    return Tree::start->key;
}
int Tree::size()
{
    return Tree::amount;
}
