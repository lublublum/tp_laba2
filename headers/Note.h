#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <string>
#include <iomanip>

class NOTE {
private:
    std::string surname;
    std::string name;
    std::string phone;
    int birthday[3]; // [day, month, year]

public:
    // Конструкторы и деструктор
    NOTE();
    NOTE(const std::string surname, const std::string name,
        const std::string phone, const int birthday[3]);
    NOTE(const NOTE& other);
    ~NOTE();

    // setters
    void setSurname(const std::string surname);
    void setName(const std::string name);
    void setPhone(const std::string phone);
    void setBirthday(const int birthday[3]);

    // getters
    const std::string getSurname()const;
    const std::string getName()const;
    const std::string getPhone()const;
    const int* getBirthday()const;

    // Перегрузка операторов ввода/вывода
    friend std::istream& operator>>(std::istream& in, NOTE& note);
    friend std::ostream& operator<<(std::ostream& out, const NOTE& note);

};

#endif
