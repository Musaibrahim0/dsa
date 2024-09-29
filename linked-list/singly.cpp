#include <cstddef>
#include <iostream>

class List {

  struct Node {
    int data;
    Node *next;
  };

  Node *head;

public:
  List() : head(nullptr) {}

  void append(int data) {
    Node *tmp = new Node;
    tmp->data = data;

    // since tmp is the last node its next should be null
    tmp->next = nullptr;

    // check if head is null
    // if it is then assign tmp node to head
    if (this->head == NULL) {
      this->head = tmp;
      return;
    }

    // if it is not then traverse till the end of list and assign the last node
    // pointer to tmp
    Node *last = head;
    while (last->next != NULL) {
      last = last->next;
    }

    last->next = tmp;
    return;
  }

  void display() {

    std::cout << std::endl << "\033[34m";

    Node *node = head;

    while (node != NULL) {
      std::cout << node->data << "-->";
      node = node->next;
    }

    std::cout << "nullptr"
              << "\033[0m" << std::endl;
  }
};

int main() {
  List list;

  int choice;
  int data;

  while (true) {
    std::cout << "\nSelect option\n"
              << "1. Display list\n"
              << "2. Append node\n"
              << "3. Delete node\n"
              << "0. Exit\n"
              << "Enter choice: ";

    std::cin >> choice;

    switch (choice) {
    case 0:
      return 0;

    case 1:
      list.display();
      break;

    case 2:
      std::cout << "Enter data: ";
      std::cin >> data;

      list.append(data);
      break;

    case 3:
      std::cout << "TODO: not implemented\n";
      break;

    default:

      std::cout << "Invalid choice. Try again." << std::endl;
    }
  }

  return 0;
}
