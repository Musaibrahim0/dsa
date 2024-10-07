#include "singly.h"
#include <iostream>

int main() {
  // Create an instance of the Singly linked list for integers
  Singly<int> list;

  // Test insert_head
  list.insert_head(10);
  list.insert_head(20);
  list.insert_head(30);
  std::cout << "After inserting 30, 20, 10 at head:" << std::endl;
  list.display();

  // Test insert_tail
  list.insert_tail(40);
  list.insert_tail(50);
  std::cout << "After inserting 40, 50 at tail:" << std::endl;
  list.display();

  // Test insert_at_index
  list.insert_at_index(25, 2); // Insert 25 at index 2
  std::cout << "After inserting 25 at index 2:" << std::endl;
  list.display();

  // Test remove_head
  list.remove_head();
  std::cout << "After removing head:" << std::endl;
  list.display();

  // Test remove_tail
  list.remove_tail();
  std::cout << "After removing tail:" << std::endl;
  list.display();

  // Test remove_index
  list.remove_index(1); // Remove the node at index 1
  std::cout << "After removing node at index 1:" << std::endl;
  list.display();

 // Test size
  std::cout << "Current size of the list: " << list.get_size() << std::endl;

  return 0;
}

// int main() {
//   Singly<int> list;

//   int data;
//   int option;

//   while (true) {
//     std::cout << "Available operations:" << std::endl
//               << "0. Exit" << std::endl
//               << "1. Display" << std::endl
//               << "2. Search" << std::endl
//               << "3. Insert head" << std::endl
//               << "4. Insert at index" << std::endl
//               << "5. Insert tail" << std::endl
//               << "6. Remove head" << std::endl
//               << "7. Remove index" << std::endl
//               << "8. Remove tail" << std::endl
//               << "Your option: ";

//     std::cin >> option;

//     switch (option) {
//     case 0:
//       return 0;

//     case 1:
//       list.display();
//       break;

//     case 2:
//       std::cout << "Enter data: ";
//       std::cin >> data;

//       std::cout << list.search(data);
//       break;

//     case 3:
//       std::cout << "Enter data: ";
//       std::cin >> data;

//       list.insert_head(data);
//       break;

//     case 4:
//       std::cout << "Enter index: ";
//       std::cin >> option;

//       std::cout << "Enter data: ";
//       std::cin >> data;

//       list.insert_at_index(data, option);
//       break;

//     case 5:
//       std::cout << "Enter data: ";
//       std::cin >> data;

//       list.insert_tail(data);
//       break;

//     case 6:
//       list.remove_head();
//       break;

//     case 7:
//       std::cout << "Enter index: ";
//       std::cin >> option;

//       list.remove_index(option);
//       break;

//     case 8:
//       list.remove_tail();
//       break;

//     default:
//       std::cout << "Invalid option" << std::endl;
//     }
//   }
// }
