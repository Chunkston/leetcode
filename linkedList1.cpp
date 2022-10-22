#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node(int val, Node* next) {
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList {
    private:
        int size = 0;
        Node* head = NULL;
        Node* tail = NULL;
        
        Node* getNodeAtIndex(int index) {
            Node* currentNode = head;
            for (int i = 0; i < index; i++) {
                currentNode = currentNode->next;
            }
            
            return currentNode;
        };
        
        bool isIndexValid(int index) {
            bool indexIsValid = index < size && index >= 0;
            
            return indexIsValid;
        }
    
    
    public:
        MyLinkedList() {
            
        }
        
        int get(int index) {
            if (!isIndexValid(index)) {
                return -1;
            }
            
            Node* nodeAtIndex = getNodeAtIndex(index);
            
            return nodeAtIndex->val;
        };
        
        void addAtHead(int val) {
            Node* prevHead;
    
            prevHead = head;
            
            
            head = new Node(val, prevHead);
            
            if (tail == NULL) {
                tail = head;
            }
            
            size++;
            
            
        }
        
        void addAtTail(int val) {
            Node* prevTail;
    
            prevTail = tail;
            
            
            tail = new Node(val, NULL);

            if (prevTail != NULL) {
              prevTail->next = tail;
            }
            
            if (head == NULL) {
                head = tail;
            }
            
            size++;
        }
        
        void addAtIndex(int index, int val) {
            if (index == 0) {
                addAtHead(val);
                return;
            }
            
            if (index == size) {
                addAtTail(val);
                return;
            }
            
            if (isIndexValid(index)) {
                Node* nodeBeforeIdx = getNodeAtIndex(index - 1);
                Node* nodeAtIdx = nodeBeforeIdx->next;
                
                nodeBeforeIdx->next = new Node(val, nodeAtIdx);

                size++;
                
            }
            
        }
        
        void deleteAtIndex(int index) {
            if (!isIndexValid(index)) return;
            
            if (index == 0) {
                Node* newHead = head->next;
                
                delete head;
                
                head = newHead;

                size--;
                return;
            }
            
            Node* nodeBeforeIdx = getNodeAtIndex(index - 1);
            Node* nodeAtIdx = nodeBeforeIdx->next;
            Node* nodeAfterIdx = nodeAtIdx->next;
            
            delete nodeAtIdx;
            
            nodeBeforeIdx->next = nodeAfterIdx;

            if (size == index + 1) {
              tail = nodeBeforeIdx;
            }

            size--;
        }

        Node* getHead() {
          return head;
        }

        Node* getTail() {
          return tail;
        }

        int getSize() {
          return size;
        }

        ~MyLinkedList() {
          cout << "Destruct" << endl;

          Node* currentNode = head;
          for (int i = 0; i < size; i++) {
            cout << "IDX: " << i << endl;

            Node* prevNode = currentNode;
            if (currentNode != NULL) {
              currentNode = currentNode->next;
            }
            
            delete prevNode;

          }
          
        }
};

int main()
{
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(0);
    obj->deleteAtIndex(0);
    

    // obj->addAtHead(1);

    
    // cout << "Size1: " << obj->getSize() << endl;
    // cout << "Head 1 Value: " << obj->getHead()->val << endl;
    // cout << "Tail 1 Value: " << obj->getTail()->val << endl;

    // if (obj->getHead()->next == NULL) {
    //   cout << "Head 1 next is NULL" << endl;
    // } else {
    //   cout << "Head 1 next is not NULL, value: " << obj->getHead()->next->val << endl;
    // }

    // if (obj->getTail()->next == NULL) {
    //   cout << "Tail 1 next is NULL" << endl;
    // } else {
    //   cout << "Tail 1 next is not NULL, value: " << obj->getHead()->next->val << endl;
    // }

    // cout << "_____________" << endl;

    // obj->addAtHead(2);

    // cout << "Size1: " << obj->getSize() << endl;
    // cout << "Head 1 Value: " << obj->getHead()->val << endl;
    // cout << "Tail 1 Value: " << obj->getTail()->val << endl;

    // if (obj->getHead()->next == NULL) {
    //   cout << "Head 1 next is NULL" << endl;
    // } else {
    //   cout << "Head 1 next is not NULL, value: " << obj->getHead()->next->val << endl;
    // }

    // if (obj->getTail()->next == NULL) {
    //   cout << "Tail 1 next is NULL" << endl;
    // } else {
    //   cout << "Tail 1 next is not NULL, value: " << obj->getHead()->next->val << endl;
    // }

    // cout << "_____________" << endl;

    // obj->deleteAtIndex(1);

    // cout << "Size1: " << obj->getSize() << endl;
    // cout << "Head 1 Value: " << obj->getHead()->val << endl;
    // // cout << "Tail 1 Value: " << obj->getTail()->val << endl;

    // if (obj->getTail() == NULL) {
    //   cout << "Tail is NULL" << endl;
    // } else {
    //   cout << "Tail is not NULL" << endl;
    // }

    // cout << obj->getTail()->val << endl;

    // if (obj->getHead()->next == NULL) {
    //   cout << "Head 1 next is NULL" << endl;
    // } else {
    //   cout << "Head 1 next is not NULL, value: " << obj->getHead()->next->val << endl;
    // }

    // if (obj->getTail()->next == NULL) {
    //   cout << "Tail 1 next is NULL" << endl;
    // } else {
    //   cout << "Tail 1 next is not NULL, value: " << obj->getHead()->next->val << endl;
    // }

    // cout << "_____________" << endl;


    // obj->addAtTail(3);

    // cout << obj->get(0) << endl;
    // cout << obj->get(1) << endl;
    // cout << obj->get(2) << endl;

    // int param_1 = obj->get(index);
    // obj->addAtHead(2);
    // obj->addAtTail(3);
    // obj->addAtIndex(index,val);
    // obj->deleteAtIndex(index);

    delete obj;

    return 0;
}