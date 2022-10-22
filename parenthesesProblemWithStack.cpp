#include <iostream>
#include <string>
#include <exception>

using namespace std;

template<typename T>
class Stack {
    private:
        T* arr;
        T* currentPosPtr = nullptr;
        int size = 0;
        int currentMaxSize = 10;
    
        void doubleStackSize() {

            T* prevArr = arr;
            
            arr = new T[currentMaxSize * 2];
            copy(prevArr, prevArr + size, arr);
            
            currentPosPtr = arr + size - 1;
            
            currentMaxSize = currentMaxSize * 2;

            delete[] prevArr;
        }
    public:
        Stack() {
            arr = new T[10];
        }
    
        void push(T item) {
            if (currentPosPtr == nullptr) {
                currentPosPtr = arr;
            } else {
                currentPosPtr++;
            }
            
            *currentPosPtr = item;
            
            size++;
            
            if (size >= currentMaxSize) {
                doubleStackSize();
            }
        }

        void pop() {
            if (size == 1) {
              currentPosPtr = nullptr;
            } else {
              currentPosPtr--;
            }

            size--;
        }

        T peek() {
            if (currentPosPtr != nullptr) {
              return *currentPosPtr;
            } else {
              throw std::runtime_error("Stack is empty, can't call peek()");
            }

        }

        int getSize() {
          return size;
        }
    
        ~Stack() {            
            delete[] arr;
        }
};

bool isValid(string s) {
        Stack<char> charStack;
        
        int size = 1;
        charStack.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            
            if (s[i] == '{' ||
                s[i] == '(' ||
                s[i] == '[') {
                charStack.push(s[i]);
                size++;
                continue;
            }

            if (size == 0) {
              return false;
            }

            if (charStack.peek() == '{' && s[i] == '}' ||
                charStack.peek() == '(' && s[i] == ')' ||
                charStack.peek() == '[' && s[i] == ']'
               ) {
                charStack.pop();
                size--;
            } else {
              return false;
            }
            
            
             
        }
        
        if (size == 0) {
            return true;
        } else {
            return false;
        }
}

int main() {

  string testString = "([([([([([([([([([([([([([([([([([([([([";

  cout << testString.size() << endl;

  cout << isValid(testString) << endl;;

  return 0;
}