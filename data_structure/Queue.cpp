#include<iostream>

template <typename T>
struct Node {
  T data;
  Node* next;
  Node(T data) : data(data), next(nullptr){};
};

template <typename T>
class Queue {
  public:
    void push(T data) {
      Node<T>* n = new Node<T>(data);
      if (isEmpty()) {
        head = n;
        tail = n;
      }
      else {
        tail->next = n;
        tail = n;
      }
      length++;

    }

    void pop() {
      if (isEmpty())
        return;
      Node<T> *tmp = head;
      head = head->next;
      length--;
      delete tmp;
    }

    T getFront() {
      if (head)
        return head->data;
      else
        throw;
    }

    T getBack() {
      if (tail)
        return tail->data;
      else
        throw;
    }

    bool isEmpty() {
      return length == 0;
    }

  private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;
};

int main() {
  Queue<int> *q = new Queue<int>();
  q->push(3);
  q->push(2);
  q->push(1);
  printf("front : %d\n", q->getFront()) ;
  printf("back : %d\n", q->getBack());
  q->pop();
  printf("front : %d\n", q->getFront());
  printf("back : %d\n", q->getBack());
  q->pop();
  printf("front : %d\n", q->getFront());
  printf("back : %d\n", q->getBack());
  q->pop();
  printf("isEmpty : %s\n", (q->isEmpty() ? "true" : "false"));

  system("pause");
  return 0;
}