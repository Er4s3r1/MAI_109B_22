#include "../include/BinaryTree.hpp"

int main() {
    Tree<int> bintr;
    int choice, value;
    bool exitProgram = false;

    while (!exitProgram) {
        std::cout << "1. Insert Node" << std::endl;
        std::cout << "2. Delete Node" << std::endl;
        std::cout << "3. Display Tree" << std::endl;
        std::cout << "4. Check if Leaves are at Same Level" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to be inserted: ";
                std::cin >> value;
                bintr.insert(value);
                break;
            case 2:
                std::cout << "Enter value to be deleted: ";
                std::cin >> value;
                bintr.remove(value);
                break;
            case 3:
                std::cout << "Tree: ";
                bintr.display();
                break;
            case 4:
                if (bintr.areLeavesAtSameLevel()) {
                    std::cout << "Leaves are at the same level" << std::endl;
                } else {
                    std::cout << "Leaves are not at the same level" << std::endl;
                }
                break;
            case 5:
                std::cout << "Exiting program..." << std::endl;
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
