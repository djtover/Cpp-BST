/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main()
{

  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree mytree;

  badkan::TestCase tc("Binary tree");
  tc
      .CHECK_EQUAL(emptytree.size(), 0)
      .CHECK_OK(emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_EQUAL(emptytree.contains(5), true)
      .CHECK_OK(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.contains(5), false)
      .CHECK_THROWS(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size(), 0)

      .CHECK_EQUAL(threetree.size(), 3)
      .CHECK_EQUAL(threetree.root(), 5)
      .CHECK_EQUAL(threetree.parent(3), 5)
      .CHECK_EQUAL(threetree.parent(7), 5)
      .CHECK_EQUAL(threetree.left(5), 3)
      .CHECK_EQUAL(threetree.right(5), 7)
      .CHECK_THROWS(threetree.insert(3))
      .CHECK_THROWS(threetree.left(6))
      .CHECK_OK(threetree.print())

      // My tests
      .CHECK_EQUAL(mytree.size(), 0)
      .CHECK_THROWS(mytree.root())
      .CHECK_OK(mytree.insert(4))
      .CHECK_EQUAL(mytree.size(), 1)
      .CHECK_OK(mytree.insert(2))
      .CHECK_EQUAL(mytree.size(), 2)
      .CHECK_OK(mytree.insert(6))
      .CHECK_EQUAL(mytree.size(), 3)
      .CHECK_EQUAL(mytree.root(), 4)
      .CHECK_THROWS(mytree.parent(4))
      .CHECK_EQUAL(mytree.left(4), 2)
      .CHECK_EQUAL(mytree.right(4), 6)
      .CHECK_THROWS(mytree.left(2))
      .CHECK_THROWS(mytree.right(6))
      .CHECK_THROWS(mytree.insert(4))
      .CHECK_EQUAL(mytree.size(), 3)
      .CHECK_OK(mytree.insert(1))
      .CHECK_EQUAL(mytree.size(), 4)
      .CHECK_OK(mytree.insert(3))
      .CHECK_EQUAL(mytree.size(), 5)
      .CHECK_OK(mytree.insert(5))
      .CHECK_EQUAL(mytree.size(), 6)
      .CHECK_OK(mytree.insert(7))
      .CHECK_EQUAL(mytree.size(), 7)
      .CHECK_EQUAL(mytree.left(2), 1)
      .CHECK_EQUAL(mytree.right(6), 7)
      .CHECK_THROWS(mytree.left(10))
      .CHECK_THROWS(mytree.right(10))
      .CHECK_THROWS(mytree.parent(10))
      .CHECK_EQUAL(mytree.contains(7), true)
      .CHECK_EQUAL(mytree.contains(3), true)
      .CHECK_EQUAL(mytree.contains(7), true)
      .CHECK_EQUAL(mytree.contains(11), false)
      .CHECK_OK(mytree.remove(6))
      .CHECK_EQUAL(mytree.size(), 6)
      .CHECK_EQUAL(mytree.left(7), 5)
      .CHECK_THROWS(mytree.right(7))
      .CHECK_OK(mytree.remove(7))
      .CHECK_EQUAL(mytree.size(), 5)
      .CHECK_EQUAL(mytree.right(4), 5)
      .CHECK_THROWS(mytree.right(5))
      .CHECK_EQUAL(mytree.contains(7), false)
      .CHECK_EQUAL(mytree.contains(6), false)
      .CHECK_OK(mytree.remove(3))
      .CHECK_EQUAL(mytree.size(), 4)
      .CHECK_THROWS(mytree.right(2))
      .CHECK_THROWS(mytree.remove(7))
      .CHECK_OK(mytree.remove(4))
      .CHECK_EQUAL(mytree.size(), 3)
      .CHECK_THROWS(mytree.right(5))
      .CHECK_EQUAL(mytree.root(),5)
       .CHECK_OK(mytree.remove(5))
      .CHECK_EQUAL(mytree.size(), 2)
      .CHECK_THROWS(mytree.right(2))
      .CHECK_EQUAL(mytree.root(),2)
       .CHECK_OK(mytree.remove(2))
      .CHECK_EQUAL(mytree.size(), 1)
      .CHECK_THROWS(mytree.right(1))
      .CHECK_EQUAL(mytree.root(),1)
      .CHECK_OK(mytree.remove(1))
      .CHECK_EQUAL(mytree.size(), 0)
      .CHECK_THROWS(mytree.right(1))
      .CHECK_THROWS(mytree.root())
      
      .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
