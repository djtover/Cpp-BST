#include <iostream>
#include <cstdlib>
using namespace std;
class Tree
{
  private:
    // A struct for a Node to use in the BST
    struct Node
    {
        int key;
        Node *right;
        Node *left;
    };
    // The fields for the BST
    Node *start;
    int amount;
    // A private method to create a Node
    Node *createNode(int value)
    {
        Node *newNode = new Node();

        newNode->key = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    void addPrivate(int value, Node *p)
    {
        if (start == NULL)
        {
            start = createNode(value);
        }
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
        else
        {
            cout << "That value has been entered already" << endl;
        }
    }
    // Start of public methods
  public:
    //Constructor
    Tree()
    {
        Tree::start = NULL;
        Tree::amount = 0;
    }
    // Declaration for all the methods
    void insert(int value);
    void remove(int value);
    int size();
    bool contains(int value);
    Node *root();
    int parent(int value);
    int left(int value);
    int right(int value);
    void print();
};