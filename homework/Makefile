#!make -f

# demo: TreeDemo.o Tree.o
# 	clang++-5.0 -std=c++17 TreeDemo.cpp -o demo

# test: TreeTest.o Tree.o
# 	clang++-5.0 -std=c++17 TreeTest.cpp -o test

# Tree.o: Tree.cpp
# 	clang++-5.0 -std=c++17 --compile Tree.cpp -o a.out

# TreeTest.o: badkan.hpp Tree.hpp

# cTreeDemo.o: Tree.hpp

# clean:
# 	rm -f *.o demo test


#!make -f

demo: TreeDemo.o Tree.o
	clang++-5.0 -std=c++17 $^ -o demo

test: TreeTest.o Tree.o
	clang++-5.0 -std=c++17 $^ -o test

%.o: %.cpp
	clang++-5.0 -std=c++17 --compile $< -o $@

TreeTest.o: badkan.hpp Tree.hpp

TreeDemo.o: Tree.hpp

clean:
	rm -f *.o demo test
