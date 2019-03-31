
#include "Tree.hpp"
#include <stdexcept>

ariel::Tree::~Tree(){
    removeSubtree(start);
}
void ariel::Tree::removeSubtree(Node* p){
    if(p != NULL){
        if(p->left != NULL){
            removeSubtree(p->left);
        }
        if(p->right != NULL){
            removeSubtree(p->right);
        }
        delete p;
    }
}

// A method to create a node
ariel::Tree::Node *ariel::Tree::createNode(int value)
{
    Node *newNode = new Node();

    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// A method to see if the tree contains a certain value
bool ariel::Tree::contains(int value)
{
    Node *ans = findNode(value, start);
    if (ans != NULL)
    {
        return true;
    }

    return false;
}

//A method to insert a value to the tree
void ariel::Tree::insert(int value)
{
    addPrivate(value, start);
    amount++;
}

// A private method to add to the tree using the pointer
void ariel::Tree::addPrivate(int value, Node *p)
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
ariel::Tree::Node *ariel::Tree::findNode(int value, Node *p)
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
        else if (value > p->key)
        {
            return findNode(value, p->right);
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
// A method to find the left value of the value that they are looking for
int ariel::Tree::left(int value)
{
    Node *parent = findNode(value, start);
    if (parent == NULL)
    {
        throw std::out_of_range("Node doesn't exist");
    }
    if (parent->left == NULL)
    {
        throw std::out_of_range("No left node");
    }
    else
    {
        return parent->left->key;
    }
}
// Find the parent of the value that they are looking for
int ariel::Tree::parent(int value)
{
    Node *ans = findParent(value, start);
    if (ans == NULL)
    {
        throw std::out_of_range("Value doesn't exist");
    }
    else
    {
        return ans->key;
    }
}
// A private method to help find the parent of the value they are looking for
ariel::Tree::Node *ariel::Tree::findParent(int value, Node *p)
{
    if (p != NULL)
    {
        if (value == start->key)
        {
            throw std::out_of_range("Root node doesn't have a parent");

            // return NULL;
        }
        if (value < p->key)
        {
            if (p->left == NULL)
            {
                return NULL;
            }
            else if (value == p->left->key)
            {
                return p;
            }
            else
            {
                return findParent(value, p->left);
            }
        }
        else
        {
            if (p->right == NULL)
            {
                return NULL;
            }
            else if (value == p->right->key)
            {
                return p;
            }
            else
            {
                return findParent(value, p->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}
// print method
void ariel::Tree::print()
{
    printPreOrder(start);
}
// A method to print in Preorder
void ariel::Tree::printPreOrder(Node *p)
{
    if (start != NULL)
    {
        cout << p->key << " ";
        if (p->left != NULL)
        {
            printPreOrder(p->left);
        }
        if (p->right != NULL)
        {
            printPreOrder(p->right);
        }
    }
    else
    {
        cout << "The Tree is empty" << endl;
    }
}
// A method to remove the node of the value they are looking for
void ariel::Tree::remove(int value)
{
    removePrivate(value, start);
    amount--;
}
// A private method to help the removal
void ariel::Tree::removePrivate(int value, Node *p)
{
    // if the tree is empty
    if (start != NULL)
    {
        // if the input value is the root value then remove root
        if (value == start->key)
        {
            removeRoot();
        }
        else
        {
            // if input value is less then go left
            if (value < p->key)
            {
                if (p->left == NULL)
                {
                    throw std::out_of_range("Node doesn't exist");
                }
                else if (value == p->left->key)
                {
                    removeRegular(p, p->left, 1);
                }
                else
                {
                    removePrivate(value, p->left);
                }
            }
            // if input value is greater then go right
            else
            {
                if (p->right == NULL)
                {
                    throw std::out_of_range("Node doesn't exist");
                }
                else if (value == p->right->key)
                {
                    removeRegular(p, p->right, 0);
                }
                else
                {
                    removePrivate(value, p->right);
                }
            }
        }
    }
    else
    {
        throw std::out_of_range("Node doesn't exist");
    }
}
// A private method to help remove the root
void ariel::Tree::removeRoot()
{
    // if the tree isn't empty
    if (start != NULL)
    {
        Node *delP = start;
        int rootKey = start->key;
        int smallInRight;
        // if the root has no children
        if (start->left == NULL && start->right == NULL)
        {
            start = NULL;
            delete delP;
        }
        // if the root only has a right child
        else if (start->left == NULL && start->right != NULL)
        {
            start = start->right;
            delP->right = NULL;
            delete delP;
        }
        // if the root only has a left child
        else if (start->left != NULL && start->right == NULL)
        {
            start = start->left;
            delP->left = NULL;
            delete delP;
        }
        // if the root has 2 children
        else
        {
            smallInRight = findSmallest(start->right);
            removePrivate(smallInRight, start);
            start->key = smallInRight;
        }
    }
    else
    {
        throw std::out_of_range("No node to remove");
    }
}
// A method to find the right child of the value they are looking for
int ariel::Tree::right(int value)
{
    Node *parent = findNode(value, start);
    if (parent == NULL)
    {
        throw std::out_of_range("Node doesn't exist");
    }
    if (parent->right == NULL)
    {
        throw std::out_of_range("No right node");
    }
    else
    {
        return parent->right->key;
    }
}
// return the value of root
int ariel::Tree::root()
{
    if (start == NULL)
    {
        throw std::out_of_range("Root doesn't exist");
    }
    return Tree::start->key;
}
// return the amount of leaves that are in the tree
int ariel::Tree::size()
{
    return Tree::amount;
}
// A private method to find the smallest number in a tree starting from a certain point
int ariel::Tree::findSmallest(Node *p)
{
    if (start == NULL)
    {
        throw std::out_of_range("empty tree");
    }
    else
    {
        if (p->left != NULL)
        {
            return findSmallest(p->left);
        }
        else
        {
            return p->key;
        }
    }
}
// A private method to help remove a non-root node from the tree
void ariel::Tree::removeRegular(Node *parent, Node *p, int left)
{
    // if the tree isn't empty
    if (start != NULL)
    {
        Node *delP;
        int delKey = p->key;
        int smallInRight;
        // if the node that is gonna be removed has no children
        if (p->left == NULL && p->right == NULL)
        {
            delP = p;
            if (left == 0)
            {
                parent->right = NULL;
            }
            else
            {
                parent->left = NULL;
            }
            delete delP;
        }
        // if the node that is gonna be removed has one right child

        else if (p->left == NULL && p->right != NULL)
        {
            if (left == 0)
            {
                parent->right = p->right;
            }
            else
            {
                parent->left = p->right;
            }
            p->right = NULL;
            delP = p;
            delete delP;
        }
        // if the node that is gonna be removed has one left child

        else if (p->left != NULL && p->right == NULL)
        {
            if (left == 0)
            {
                parent->right = p->left;
            }
            else
            {
                parent->left = p->left;
            }
            p->left = NULL;
            delP = p;
            delete delP;
        }
        // if the node that is gonna be removed has two children

        else
        {
            smallInRight = findSmallest(p->right);
            removePrivate(smallInRight, p);
            p->key = smallInRight;
        }
    }
    else
    {
        throw std::out_of_range("Tree is empty");
    }
}
