#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int findTheWinner(int n, int k) {
  ListNode *head = new ListNode(1);
  ListNode *temp = head;

  for (int i = 2; i < n + 1; ++i) {
    ListNode *newNode = new ListNode(i);
    temp->next = newNode;
    temp = temp->next;
  }

  ListNode *prev = temp;
  temp->next = head;
  temp = head;

  while (temp->next != temp) {
    for (int i = 1; i < k; ++i) {
      temp = temp->next;
      prev = prev->next;
    }
    prev->next = temp->next;
    temp = prev->next;
  }
  return temp->val;
}

int main() {
  int n = 5, k = 2;
  cout << findTheWinner(n, k);
  return 0;
}