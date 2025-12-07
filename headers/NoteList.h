#ifndef NOTE_LIST_H
#define NOTE_LIST_H

#include "Note.h"
#include <iostream>
#include <string>
#include <iomanip>

struct Node
{
    NOTE data;
    Node * next;

};

class NoteList
{
private:
    Node* first;
public:
    NoteList();
    ~NoteList();

    void add(const NOTE& note);
    void removeByPhone(const std::string phone);

    bool findByPhone(const std::string& phone) const;

    void editByPhone(const std::string& phone);
    void printAll() const;

};


#endif // NOTE_LIST_H