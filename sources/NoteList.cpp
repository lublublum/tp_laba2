#include "NoteList.h"

bool dateIsLarge(const int date_1[3], const int date_2[3])
{
    int d1, d2;
    d1 = (date_1[2] * 10000) + (date_1[1] * 100) + date_1[0];
    d2 = (date_2[2] * 10000) + (date_2[1] * 100) + date_2[0];

    return d1 > d2;
}
NoteList::NoteList() {
    first = nullptr;
}

NoteList::~NoteList() {
    Node* cur = first;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void NoteList::add(const NOTE& note) {
    Node* newNode = new Node;
    newNode->data = note;
    newNode->next = nullptr;

    if (first == nullptr) { // Если список пуст
        first = newNode;
        return;
    }

    if (dateIsLarge(first->data.getBirthday(), note.getBirthday())) {// Если вставка в начало
        newNode->next = first;
        first = newNode;
        return;
    }

    // Поиск места вставки
    Node* current = first;
    while (current->next != nullptr &&
        dateIsLarge(note.getBirthday(), current->next->data.getBirthday()))
    {
        current = current->next;
    }
    //  Вставка
    newNode->next = current->next;
    current->next = newNode;
}
void NoteList::removeByPhone(const std::string phone) {
    if (first == nullptr)
        return;

    // 1. Удаление первого элемента
    if (first->data.getPhone() == phone) {
        Node* toDelete = first;
        first = first->next;
        delete toDelete;
        return;
    }

    // 2. Поиск элемента
    Node* current = first;
    while (current->next != nullptr &&
        current->next->data.getPhone() != phone)
    {
        current = current->next;
    }

    // 3. Если найден — удалить
    if (current->next != nullptr) {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
    }
}

bool NoteList::findByPhone(const std::string& phone) const
{
    Node* cur = first;

    while (cur) {
        if (cur->data.getPhone() == phone) {
            std::cout << "Запись найдена:\n";
            std::cout << "-----------------------------\n";
            std::cout << cur->data << '\n';
            return true;
        }
        cur = cur->next;
    }

    std::cout << "Человек с номером телефона "
        << phone << " не найден.\n";
    return false;
}



void NoteList::printAll() const
{
    if (first == nullptr) {
        std::cout << "Список пуст.\n";
        return;
    }

    std::cout  << "Фамилия\t\tИмя\t\tТелефон\t\tДата рождения\n";
    std::cout << "----------------------------------------------------------------\n";


    Node* cur = first;
    while (cur) {
        std::cout << cur->data << '\n';
        cur = cur->next;
    }
}