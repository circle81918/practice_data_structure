#include <iostream>

struct Node {
  int val;
  Node *prev;
  Node *next;
  Node(int val) : val(val), prev(nullptr), next(nullptr){};
};

class DoubleLinkedList {
  public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), length(0){};
    void InsertHead(int val) {
      Node *n = new Node(val);
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

    void InsertTail(int val) {
      Node *n = new Node(val);
      n->prev = tail;
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

      Node* tmp = head->next;
      delete head;
      head = tmp;
      tmp->prev = nullptr;
      length--;
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

      Node* tmp = tail->prev;
      delete tail;
      tail = tmp;
      tmp->next = nullptr;
      length--;
    }

    void traverse() {
      Node* cur = head;
      printf("len = %zu\n", length);
      while (cur) {
        printf("%d\n", cur->val);
        cur = cur->next;
      }
    }

  private:
    Node* head;
    Node* tail;
    size_t length;
};

int main() {
  DoubleLinkedList* list = new DoubleLinkedList();
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