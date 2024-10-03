#include <iostream>

// Color code for output
const std::string RED = "\033[91m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

// A class to represent linked list
class List {
  struct Node { // Each node in the list
    int data;
    Node *next;
  } *head;

public:
  List() : head(NULL) {}

  void insertAtHead(int data) {}

  void insertAtIndex(int data) {}

  void insertAtTail(int data) {
    Node *newNode = new Node;
    newNode->data = data;

    // since newNode would be the last node
    newNode->next = NULL;

    // in case list is empty
    if (this->head == NULL) {
      this->head = newNode;
      return;
    }

    // find the last node
    Node *last = head;
    while (last->next != NULL) {
      last = last->next;
    }

    // update the current tail with new
    last->next = newNode;
  }

  void deleteFromTail(int index) {
    if (index > this->getSize()) {
      std::cerr << RED << "Index out of bound\n" << RESET;
    }

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

    // TODO: delete the node

    delete node;
  }

  unsigned getSize() {
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
    std::system("clear");
    std::cout << std::endl << BLUE;

    Node *node = head;

    while (node != NULL) {
      std::cout << node->data << "-->";
      node = node->next;
    }

    delete node;

    std::cout << "NULL" << RESET << std::endl;
  }
};

int main() {
  List list;

  int input;

  while (true) {
    std::cout << "\nSelect an option\n"
              << "1. Display list\n"
              << "2. Insert at head\n"
              << "3. Insert in middle\n"
              << "4. Insert at tail\n"
              << "5. Delete from head\n"
              << "6. Delete from middle\n"
              << "7. Delete from tail\n"
              << "8. Search item\n"
              << "0. Exit\n"
              << "Enter choice: ";

    std::cin >> input;

    switch (input) {
    case 0:
      return 0;

    case 1:
      list.display();
      break;

    case 2:
      std::cerr << RED << "Not implemented yet!\n" << RESET;
      break;

    case 3:
      std::cerr << RED << "Not implemented yet!\n" << RESET;
      break;

    case 4:
      std::cout << "Enter data: ";
      std::cin >> input;

      list.insertAtTail(input);
      break;

    case 5:
      std::cerr << RED << "Not implemented yet!\n" << RESET;
      break;

    case 6:
      std::cerr << RED << "Not implemented yet!\n" << RESET;
      break;

    case 7:
      std::cout << "Enter index: ";
      std::cin >> input;

      list.deleteFromTail(input);
      break;

    case 8:
      std::cerr << RED << "Not implemented yet!\n" << RESET;
      break;

    default:
      std::cerr << RED << input << "is not a valid choice" << std::endl << RESET;
    }
  }

  return 0;
}
