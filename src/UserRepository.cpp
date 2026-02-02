#include "UserRepository.h"
#include "users.pb.h"
#include <fstream>

UserRepository::UserRepository(std::string filePath)
    : filePath_(std::move(filePath)) {}

bool UserRepository::load() {
    users_.clear();

    std::ifstream in(filePath_, std::ios::binary);
    if (!in) {
        return true;
    }

    users::UserList protoList;
    if (!protoList.ParseFromIstream(&in)) {
        return false;
    }

    for (const auto& protoUser : protoList.users()) {
        users_.emplace_back(
            protoUser.id(),
            protoUser.name(),
            protoUser.email()
            );
    }

    return true;
}

bool UserRepository::save() const {
    users::UserList protoList;

    for (const auto& user : users_) {
        auto* protoUser = protoList.add_users();
        protoUser->set_id(user.id());
        protoUser->set_name(user.name());
        protoUser->set_email(user.email());
    }

    std::ofstream out(filePath_, std::ios::binary);
    if (!out) {
        return false;
    }

    return protoList.SerializeToOstream(&out);
}

void UserRepository::addUser(const User& user) {
    users_.push_back(user);
}

const std::vector<User>& UserRepository::users() const {
    return users_;
}
