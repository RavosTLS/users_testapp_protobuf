# Пользователи
Тестовое приложение для знакомства с protobuf

**Стек:** C++, CMake, proto3

## Сборка
- protoc --cpp_out=generated proto/users.proto
- mkdir build
- cd build
- cmake ..
- make

## Работа с программой
- Просмотр списка пользователей: ./user_testapp_protobuf list <файл>
- Добавить пользователя: ./user_testapp_protobuf add <файл>
