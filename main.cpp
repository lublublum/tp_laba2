#include <iostream>
#include "NoteList.h"
#include "TextTask.h"


void printMenu()
{
    std::cout << "\n========= МЕНЮ =========\n";
    std::cout << "1. Добавить запись\n";
    std::cout << "2. Удалить по номеру телефона\n";
    std::cout << "3. Найти по номеру телефона\n";
    std::cout << "4. Показать все записи\n";
    std::cout << "5. Редактировать запись по телефону\n";
    std::cout << "6. Обработать текстовый файл (предложения с тире)\n";
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
            try
            {
                NOTE note;
                std::cin >> note;
                list.add(note);
                std::cout << "Запись добавлена.\n";
            }
            catch (const std::exception& e)
            {
                std::cout << "\033[31mОшибка: " << e.what() << "\033[0m\n";
            }
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

        case 5: {
            std::string phone;
            std::cout << "Введите номер телефона: ";
            std::cin >> phone;

            try {
                list.editByPhone(phone);
            }
            catch (const std::exception& e) {
                std::cout << "\033[31mОшибка: " << e.what() << "\033[0m\n";
            }
            break;
        }

        case 6: {
            char filename[256];
            std::cout << "Введите имя файла: ";
            std::cin >> filename;

            std::cout << "\033[36mРезультат обработки:\n\033[32m";
            printDashSentencesFromFile(filename);
            std::cout << "\033[36mКонец вывода обработки:\033[0m\n";
            break;
        }

        case 0:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Неверный пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}
