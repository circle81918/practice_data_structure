#include <iostream>

struct Node {
  int val;  
  Node* next;
};

class LinkedList {
  public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {};
    void InsertTail(int val) {
      Node *n = new Node();
      n->val = val;
      n->next = nullptr;
      if (length == 0) {
        head = n;
        tail = n;
      }
      else {
        tail->next = n;
        tail = n;
      }
      length++;
    }
    
    void InsertHead(int val) {
      Node *n = new Node();
      n->val = val;
      n->next = nullptr;
      if (length == 0) {
        head = n;
        tail = n;
      }
      else {
        n->next = head;
        head = n;
      }
      length++;
    }

    void deleteTail() {
      if (length == 0)
        return;
      if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
        return;
      }
      Node *tmp = head;
      while (tmp->next) {
        if (tmp->next == tail) {
          delete tail;
          tail = tmp;
          tail->next = nullptr;
          length--;
          break;
        }
        tmp = tmp->next;
      }
    }

    void deleteHead() {
      if (length == 0)
        return;
      if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
        return;
      }
      Node *tmp = head->next;
      delete head;
      head = tmp;
      length--;
    }

    void traverse() {
      Node* cur = head;
      printf("len = %d\n", length);
      while (cur) {
        printf("%d\n", cur->val);
        cur = cur->next;
      }
    }

  private:
    Node* head;
    Node* tail;
    int length;

};

int main() {
  LinkedList *list = new LinkedList();
  list->deleteHead();
  list->InsertTail(1);
  list->InsertTail(2);
  list->InsertHead(3);
  list->deleteHead();
  list->deleteTail();
  list->deleteHead();
  list->deleteHead();
  list->deleteHead();

  system("pause");
  return 0;
}