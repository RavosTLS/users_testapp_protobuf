#pragma once

#include "User.h"
#include <string>
#include <vector>

class UserRepository {
public:
    explicit UserRepository(std::string filePath);

    bool load();
    bool save() const;

    void addUser(const User& user);
    const std::vector<User>& users() const;

private:
    std::string filePath_;
    std::vector<User> users_;
};
