#pragma once

#include <string>
#include <cstdint>

class User {
public:
    User(uint64_t id, std::string name, std::string email);

    uint64_t id() const;
    const std::string& name() const;
    const std::string& email() const;

private:
    uint64_t id_;
    std::string name_;
    std::string email_;
};
