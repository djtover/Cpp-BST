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

    // Declaration of private methods
    Node *createNode(int value);
    void addPrivate(int value, Node *p);
    void removePrivate(int value, Node* p);
    void removeRoot();
    void removeRegular(Node* parent, Node* p, int left);
    Node* findNode(int value, Node* p);
    void printPreOrder(Node* p);
    Node* findParent(int value , Node* p);
    int findSmallest(Node* p);
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
    int contains(int value);
    int root();
    int parent(int value);
    int left(int value);
    int right(int value);
    void print();
};