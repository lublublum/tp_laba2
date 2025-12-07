#include "Note.h"
#include <iostream>

// Конструкторы и деструктор

NOTE::NOTE() {
    surname = {};
    name = {};
    phone = {};
    for (int i = 0; i < 3; i++) {
        birthday[i] = 0;
    }
    std::cout << "\033[33mNote base constructor called, phone = " << this->phone << "\033[0m\n";
}

NOTE::NOTE(const std::string surname, const std::string name,
    const std::string phone, const int birthday[3])
    : surname(surname),  name(name), phone(phone){
    for (int i = 0; i < 3; i++) {
        this->birthday[i] = birthday[i];
    }
    std::cout << "\033[33mNote constructor called, phone = " << this->phone << "\033[0m\n";
}

NOTE::NOTE(const NOTE& other)
    : surname(other.surname), name(other.name), phone(other.phone) {
    for (int i = 0; i < 3; i++) {
        this->birthday[i] = other.birthday[i];
    }
    std::cout << "\033[33mNote copy constructor called, phone = " << this->phone << "\033[0m\n";
}

NOTE::~NOTE() {
    std::cout << "\033[33mNote destructor called, phone = " << this->phone << "\033[0m\n";
}

// setters

void NOTE::setSurname(const std::string surname) {this->surname = surname;}

void NOTE::setName(const std::string name) {this->name = name;}

void NOTE::setPhone(const std::string phone) { this->phone = phone; }

void NOTE::setBirthday(const int birthday[3]) {
    for (int i = 0; i < 3; i++) {
        this->birthday[i] = birthday[i];
    }
}

// getters

const std::string NOTE::getSurname() const {
    return surname;
}
const std::string NOTE::getName() const {
    return name;
}
const std::string NOTE::getPhone() const {
    return phone;
}
const int* NOTE::getBirthday() const {
    return birthday;
}

// Операторы ввода/вывода
std::istream& operator>>(std::istream& in, NOTE& note)
{
    std::string surname, name, phone;
    int birthday[3];

    std::cout << "Фамилия: ";
    in >> surname;

    std::cout << "Имя: ";
    in >> name;

    std::cout << "Телефон: ";
    in >> phone;

    std::cout << "День рождения (день месяц год): ";
    in >> birthday[0] >> birthday[1] >> birthday[2];

    note.setSurname(surname);
    note.setName(name);
    note.setPhone(phone);
    note.setBirthday(birthday);

    return in;
}


std::ostream& operator<<(std::ostream& out, const NOTE& note)
{
    const int* d = note.getBirthday();

    out << note.getSurname() << "\t\t"
        << note.getName() << "\t\t"
        << note.getPhone() << "\t\t"
        << d[0] << '.' << d[1] << '.' << d[2];

    return out;
}

