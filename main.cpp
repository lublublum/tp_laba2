#include <iostream>
#include "NoteList.h"

void printMenu()
{
    std::cout << "\n========= МЕНЮ =========\n";
    std::cout << "1. Добавить запись\n";
    std::cout << "2. Удалить по номеру телефона\n";
    std::cout << "3. Найти по номеру телефона\n";
    std::cout << "4. Показать все записи\n";
    std::cout << "0. Выход\n";
    std::cout << "========================\n";
    std::cout << "Выбор: ";
}

int main()
{
    NoteList list;
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            NOTE note;
            std::cin >> note;
            list.add(note);
            std::cout << "Запись добавлена.\n";
            break;
        }
        case 2: {
            std::string phone;
            std::cout << "Введите номер телефона: ";
            std::cin >> phone;
            list.removeByPhone(phone);
            break;
        }
        case 3: {
            std::string phone;
            std::cout << "Введите номер телефона: ";
            std::cin >> phone;
            list.findByPhone(phone);
            break;
        }
        
        case 4:
            list.printAll();
            break;

        case 0:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Неверный пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}
