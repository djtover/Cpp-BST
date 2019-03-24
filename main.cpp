#include <iostream>
#include <cstdlib>
#include "Tree.cpp"
using namespace std;

int main()
{
    ariel::Tree t;

    t.print();

    try
    {
        cout << t.size() << " should be 0" << endl;
        t.insert(5);
        cout << t.size() << " should be 1" << endl;
        cout << t.contains(5) << " should be true" << endl;
        t.remove(5);
        cout << t.contains(5) << " should be false" << endl;
        t.remove(5);
    }
    catch (const std::exception &ex)
    {
        cout << "caught exception " << ex.what() << endl;
    }

    return 0;
}