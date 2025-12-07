#include "TextTask.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

void printDashSentencesFromFile(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл.\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        char ch;

        // Пропускаем пробельные символы в начале строки
        while (ss.get(ch)) {
            if (!std::isspace(static_cast<unsigned char>(ch)))
                break;
        }

        // Проверяем: первый НЕпробельный символ — тире
        if (ch == '-') {
            std::cout << line << '\n';
        }
    }

    file.close();
}
