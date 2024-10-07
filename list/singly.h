#ifndef LIST_LIBRARY_H
#define LIST_LIBRARY_H
#include <iostream>

template <typename T> class Singly {
  struct Node {
    T data;
    Node *next;
  } *head;

  unsigned size;

public:
  Singly() : head(nullptr), size(0) {}

  ~Singly() {
    Node *current = head;
    while (current) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }

  void insert_head(T data) {
    Node *new_node = new Node;
    new_node->data = data;

    if (head == nullptr) {
      new_node->next = nullptr;
      head = new_node;
      size++;
      return;
    }

    new_node->next = head;
    head = new_node;
    size++;
  }

  void insert_tail(T data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr) {
      head = new_node;
      size++;
      return;
    }

    Node *last = head;

    while (last->next != nullptr) {
      last = last->next;
    }

    last->next = new_node;

    size++;
  }

  void insert_at_index(T data, unsigned position) {
    if (position > size)
      return; // Out of bounds

    if (position == 0) {
      insert_head(data);
      return;
    }

    Node *new_node = new Node{data, nullptr};
    Node *current = head;

    for (unsigned i = 0; i < position - 1; i++) {
      current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    size++;
  }

  void remove_head() {
    if (head == nullptr)
      return;

    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
  }

  void remove_tail() {
    if (head == nullptr)
      return; // Empty list

    if (head->next == nullptr) {
      delete head;
      head = nullptr;
    } else {
      Node *current = head;
      while (current->next->next != nullptr) {
        current = current->next;
      }
      delete current->next;
      current->next = nullptr;
    }
    size--;
  }
  void remove_index(unsigned position) {
    if (position >= size)
      return; // Out of bounds

    if (position == 0) {
      Node *temp = head;
      head = head->next;
      delete temp;
    } else {
      Node *current = head;
      for (unsigned i = 0; i < position - 1; i++) {
        current = current->next;
      }
      Node *temp = current->next;
      current->next = temp->next;
      delete temp;
    }
    size--;
  }

  long int search(T data) {
    Node *current = head;
    while (current != nullptr) {
      if (current->data == data) {
        return current->data;
      }
    }
    return -1;
  }

  void display() {
    Node *current = head;

    std::cout << "size: " << size << std::endl;

    while (current != nullptr) {
      std::cout << current->data << "-->";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    delete current;
  }

  unsigned get_size() { return size; }
};

#endif // LIST_LIBRARY_H
