#include "User.h"

User::User(uint64_t id, std::string name, std::string email)
    : id_(id),
    name_(std::move(name)),
    email_(std::move(email)) {}

uint64_t User::id() const {
    return id_;
}

const std::string& User::name() const {
    return name_;
}

const std::string& User::email() const {
    return email_;
}
