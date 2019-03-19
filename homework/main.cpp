#include <iostream>
#include <cstdlib>
#include "Tree.cpp"
using namespace std;

int main(){
    Tree t;

    t.print();

    t.insert(3);
    t.insert(7);
    t.insert(1);
    t.insert(-1);
    t.insert(4);
    t.insert(5);
    try{
      cout<< "t.left(1)="<< t.left(1) << endl;
      cout<< "t.left(4)="<< t.left(4) << endl;
    }
    catch(const std:: exception& ex){
        cout<<"caught exception"<< ex.what()<< endl;
    }
    


    return 0;
}