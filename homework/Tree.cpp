
#include "Tree.hpp"

    // A method to create a node
Tree::Node* Tree::createNode(int value)
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
    Tree::addPrivate(value, Tree::start);
}

// A private method to add to the tree using the pointer
 void Tree::addPrivate(int value, Node *p)
    {
        //Check if the starting point is Null
        if (p == NULL)
        {
            p = createNode(value);
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
int Tree::left(int value)
{
    return 0;
}
int Tree::parent(int value)
{
    return 0;
}
void Tree::print()
{
}
void Tree::remove(int value)
{
}
int Tree::right(int value)
{
    return 0;
}
Tree::Node *Tree::root()
{
    return Tree::start;
}
int Tree::size()
{
    return Tree::amount;
}
