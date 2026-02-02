#include "UserRepository.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage:\n"
        << "  user_testapp_protobuf list <file>\n"
        << "  user_testapp_protobuf add  <file>\n";
        return 1;
    }

    std::string command = argv[1];
    std::string filePath = argv[2];

    UserRepository repo(filePath);

    if (!repo.load()) {
        std::cerr << "Failed to load file\n";
        return 1;
    }

    if (command == "list") {
        for (const auto& user : repo.users()) {
            std::cout << "ID: " << user.id()
            << " | Name: " << user.name()
            << " | Email: " << user.email()
            << '\n';
        }
    }
    else if (command == "add") {
        uint64_t id;
        std::string name;
        std::string email;

        std::cout << "Enter id: ";
        std::cin >> id;
        std::cin.ignore();

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Enter email: ";
        std::getline(std::cin, email);

        repo.addUser(User{id, name, email});

        if (!repo.save()) {
            std::cerr << "Failed to save file\n";
            return 1;
        }

        std::cout << "User added successfully\n";
    }
    else {
        std::cerr << "Unknown command\n";
        return 1;
    }

    return 0;
}
