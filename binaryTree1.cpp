#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node {
  
  int data;
  Node* left;
  Node* right;

  Node(int data, Node* left, Node* right) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

int findSum(Node* root) {
  int totalSum = 0;

  if (root == nullptr) return totalSum;

  stack<Node*> nodeStack;

  Node* currentNode = root;


  while (true) {

    if (currentNode != nullptr) {
      nodeStack.push(currentNode);
      currentNode = currentNode->left;
    } else {
      if (nodeStack.empty()) break;
      currentNode = nodeStack.top();
      nodeStack.pop();
      totalSum += currentNode->data;
      currentNode = currentNode->right;
    }

    
    
  }

  return totalSum;

}

// depth first
void preOrderPrint(Node* root) {

  if (root == nullptr) return;

  stack<Node*> nodeStack;

  Node* currentNode;

  nodeStack.push(root);

  while(!nodeStack.empty()) {
    currentNode = nodeStack.top();
    nodeStack.pop();
    cout << currentNode->data << ", ";

    if (currentNode->right != nullptr) {
      nodeStack.push(currentNode->right);
    }

    if (currentNode->left != nullptr) {
      nodeStack.push(currentNode->left);
    }
  }

  cout << endl;

}

void preOrderPrintRecursiveHelper(Node* root) {
  if (root == nullptr) return;

  cout << root->data << ", ";
  preOrderPrintRecursiveHelper(root->left);
  preOrderPrintRecursiveHelper(root->right);
}

void preOrderPrintRecursive(Node* root) {
  preOrderPrintRecursiveHelper(root);
  cout << endl;
}

int main() {

  Node l2Left(5, nullptr, nullptr);
  Node l2Right(6, nullptr, nullptr);

  Node l1Left(3, &l2Left, &l2Right);
  Node l1Right(4, nullptr, nullptr);

  Node root(2, &l1Left, &l1Right);

  cout << findSum(&root) << endl;

  preOrderPrint(&root);
  preOrderPrintRecursive(&root);

  return 0;
}