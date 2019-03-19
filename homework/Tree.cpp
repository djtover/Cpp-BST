
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
    Node *ans = findNode(value, start);
    if (ans != NULL)
    {
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
    Node *parent = findNode(value, start);
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
int Tree::parent(int value)
{
    Node *ans = findParent(value, start);
    if (ans == NULL)
    {
        throw std::out_of_range("No parent");
    }
    else
    {
        return ans->key;
    }
}
// A private method to help find the parent of the value they are looking for
Tree::Node *Tree::findParent(int value, Node *p)
{
    if (p != NULL)
    {
        if (value == start->key)
        {
            return NULL;
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
                ;
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
                ;
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
void Tree::print()
{
    printPreOrder(start);
}
// A method to print in Preorder
void Tree::printPreOrder(Node *p)
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
void Tree::remove(int value)
{
    removePrivate(value, start);
    amount--;
}

void Tree::removePrivate(int value, Node *p)
{
    if (start != NULL)
    {
        if (value == start->key)
        {
            removeRoot();
        }
        else
        {
            if (value < p->key)
            {
                if (p->left == NULL)
                {
                    throw std::out_of_range(" Node doesn't exist");
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
            else
            {
                if (p->right == NULL)
                {
                    throw std::out_of_range(" Node doesn't exist");
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
        throw std::out_of_range(" Node doesn't exist");
    }
}
void Tree::removeRoot()
{
    if (start != NULL)
    {
        Node* delP = start;
        int rootKey = start->key;
        int smallInRight;

        if (start->left == NULL && start->right == NULL)
        {
            start = NULL;
            delete delP;
        }
        else if (start->left == NULL && start->right != NULL)
        {
            start = start->right;
            delP->right = NULL;
            delete delP;
        }
        else if (start->left != NULL && start->right == NULL)
        {
            start = start->left;
            delP->left = NULL;
            delete delP;
        }
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
int Tree::right(int value)
{
    Node *parent = findNode(value, start);
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
int Tree::root()
{
    return Tree::start->key;
}
// return the amount of leaves that are in the tree
int Tree::size()
{
    return Tree::amount;
}

int Tree::findSmallest(Node *p)
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
void Tree::removeRegular(Node *parent, Node *p, int left)
{
    if (start != NULL)
    {
        Node *delP;
        int delKey = p->key;
        int smallInRight;

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
        else if(p->left == NULL && p->right !=NULL){
            if(left==0){
                parent->right = p->right;
            }
            else{
                parent->left = p->right;
            }
            p->right =NULL;
            delP = p;
            delete delP;

        }
        else if(p->left != NULL && p->right ==NULL){
            if(left==0){
                parent->right = p->left;
            }
            else{
                parent->left = p->left;
            }
            p->left =NULL;
            delP = p;
            delete delP;
            
        }

        else{
            smallInRight = findSmallest(p->right);
            removePrivate(smallInRight,p);
            p->key = smallInRight;
        }
    }
    else
    {
        throw std::out_of_range("Tree is empty");
    }
}
