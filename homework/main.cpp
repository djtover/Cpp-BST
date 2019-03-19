#include <iostream>
#include <cstdlib>
#include "Tree.cpp"
using namespace std;

int main()
{
    Tree t;

    t.print();

    // t.insert(3);
    // t.insert(7);
    // t.insert(1);
    // t.insert(-1);
    // t.insert(-1);
    // t.insert(4);
    // t.insert(5);
    try
    {
        t.insert(3);
        t.insert(7);
        t.insert(1);
        t.insert(-1);
        t.insert(4);
        t.insert(5);
        cout << "t.left(1)=" << t.left(1) << endl;
        cout << "t.parent(5)=" << t.parent(5) << endl;
        cout << "t.right(3)=" << t.right(3) << endl;
        cout << "t.size()=" << t.size() << endl;
        cout << "t.root()=" << t.root() << endl;
        cout << "t.contains(4)=" << t.contains(4) << endl;
        cout << "t.contains(6)=" << t.contains(6) << endl;
    }
    catch (const std::exception &ex)
    {
        cout << "caught exception" << ex.what() << endl;
    }

    return 0;
}