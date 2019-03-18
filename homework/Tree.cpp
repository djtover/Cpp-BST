
#include "Tree.hpp"

bool Tree::contains(int value)
{

    return false;
}
void Tree::insert(int value)
{
    Tree::addPrivate(value, Tree::start);
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
