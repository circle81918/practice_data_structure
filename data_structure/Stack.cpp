#include <iostream>

struct StackNode {
  int val;
  StackNode* prev;
};
class Stack {
  public:
    Stack() : top(nullptr) {};
    void push(int val) {
      StackNode *n = new StackNode();
      n->val = val;
      n->prev = nullptr;
      if (top == nullptr)
        top = n;
      else {
        n->prev = top;
        top = n;
      }
    }
    int pop() {
      if (top == nullptr)
        throw;
      else {
        int ret = top->val;
        StackNode* prev = top->prev;
        delete top;
        top = prev;
        return ret;
      }
    }
    int peek() {
      if (top)
        return top->val;
      else
        throw;
    }
    bool isEmpty() {
      if (top == nullptr)
        return true;
      else
        return false;
    }

  private:
    StackNode* top;
};

int main() {
  Stack *stk = new Stack();
  stk->push(1);
  stk->push(2);
  stk->push(3);
  printf("top : %d\n", stk->peek());
  stk->pop();
  printf("top : %d\n", stk->peek());
  stk->pop();
  printf("top : %d\n", stk->peek());
  stk->pop();
  printf("is empty : %s\n", (stk->isEmpty()) ? "true" : "false");
  
  system("pause");
  return 0;
}