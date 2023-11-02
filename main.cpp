#include <iostream>
#include <cassert>
#include "QuartenarySearchTree.h"
#include "Object1.h"
#include "Object2.h"

// Custom exception for undefined situation
class UndefinedSituationException : public std::exception {
public:
    const char *what() const throw() {
        return "Undefined situation occurred!";
    }
};

int main()
{
     Object2 obj6(100);
     Object2 obj7(23);
     Object2 obj8(75);
     Object2 obj9(111);
     Object2 obj10(211); 

    Object2 initialElements2[] = {obj6,obj7,obj8,obj9,obj10};
    QuartenarySearchTree<Object2> tree(initialElements2, 5);

    Object2 element;
    Object2 element1;
    
while (true) {
        try {
            int choice;
            std::cout << "\n---- Menu ----\n";
            std::cout << "1. Insert an element\n";
            std::cout << "2. Delete an element\n";
            std::cout << "3. Preorder traversal\n";
            std::cout << "4. Postorder traversal\n";
            std::cout << "5. Quit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            assert(choice >= 1 && choice <= 5);

            switch (choice) {
                case 1: {
                    std::cout << "Enter the element to insert: ";
                    std::cin >> element;
                    assert(element.isValid()); // Use isValid() method if exists in Object2 class
                    Object2 obj(element);
                    tree.insert(obj);
                    break;
                }
                case 2: {
                    std::cout << "Enter the element to delete: ";
                    std::cin >> element1;
                    assert(element1.isValid()); // Use isValid() method if exists in Object2 class
                    Object2 obj1(element1);
                    tree.remove(obj1);
                    break;
                }
                case 3:
                    std::cout << "Preorder traversal: ";
                    tree.preorder();
                    break;
                case 4:
                    std::cout << "Postorder traversal: ";
                    tree.postorder();
                    break;
                case 5:
                    return 0;
                default:
                    throw UndefinedSituationException();
            }
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            // Additional error handling or logging can be done here
        }
    }
    return 0;
}