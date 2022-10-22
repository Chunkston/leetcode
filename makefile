parenthesesProblemWithStack: parenthesesProblemWithStack.cpp
	g++ -fsanitize=address -g3 -std=c++11 parenthesesProblemWithStack.cpp -o parenthesesProblemWithStack.exe
	./parenthesesProblemWithStack.exe

linkedList1: linkedList1.cpp
	g++ -fsanitize=address -g3 -std=c++11 linkedList1.cpp -o linkedList1.exe
	./linkedList1.exe

binaryTree1: binaryTree1.cpp
	g++ -fsanitize=address -g3 -std=c++11 binaryTree1.cpp -o binaryTree1.exe
	./binaryTree1.exe