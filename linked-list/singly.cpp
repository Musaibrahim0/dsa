#include <cstddef>
#include <iostream>

class List {

  struct Node {
    int data;
    Node *next;
  };

  Node *head;

public:
  List() : head(NULL) {}

  void append(int data) {
    Node *tmp = new Node;
    tmp->data = data;

    // since tmp is the last node its next should be null
    tmp->next = NULL;

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

    // delete tmp;
    return;
  }

  void remove(int index) {
    // find the node to delete
    Node *node = head;
    int idx = 0;

    while (node != NULL) {
      if (idx != index) {
        idx++;
        node = node->next;
      } else {
        break; // node found
      }
    }

    // delete the node
    std::cout << node->data << std::endl;

    delete node;
  }

  unsigned size() {
    Node *node = head;
    unsigned size = 0;

    while (node->next != NULL) {
      size++;
      node = node->next;
    }
    delete node;

    return size;
  }

  void display() {
    std::cout << std::endl << "\033[34m";

    Node *node = head;

    while (node != NULL) {
      std::cout << node->data << "-->";
      node = node->next;
    }

    // delete node;

    std::cout << "NULL"
              << "\033[0m" << std::endl;
  }
};

int main() {
  List list;

  int choice;
  int input;

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
      std::cin >> input;

      list.append(input);
      break;

    case 3:
      std::cout << "Enter index: ";
      std::cin >> input;

      if (input > list.size()) {
        std::cerr << "Index exceeds list size" << std::endl;
        break;
      }

      list.remove(input);
      break;

    default:

      std::cerr << "Invalid choice. Try again." << std::endl;
    }
  }

  return 0;
}
