#ifndef LIST_LIBRARY_H
#define LIST_LIBRARY_H
#include <iostream>

template<typename T>
class Singly {
    struct Node {
        T data;
        Node *next;
    } *head;

    unsigned size{};

public:
    Singly() : head(nullptr), size(0) {
    }


    /**
    * Checks the total number of element in the list.
    *
    * @return The total number of elements
     */
   unsigned get_size() const { return size; } // NOLINT(*-use-nodiscard)

    /**
    * Checks if the linked list is empty or not.
    *
    * @return true if empty else false
     */
    bool is_empty() {
        if (head == nullptr)
            return true;
        return false;
    }
};

#endif //LIST_LIBRARY_H
