#include "TextTask.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

void printDashSentencesFromFile(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error(
            "Ошибка: не удалось открыть файл\n"
        );
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text = buffer.str();
    file.close();

    std::string sentence;
    size_t start = 0;

    while (start < text.size()) {
        // ищем ближайший разделитель '.', '?', '!'
        size_t posDot = text.find('.', start);
        size_t posQ = text.find('?', start);
        size_t posE = text.find('!', start);

        // выбираем ближайший разделитель
        size_t endPos = std::min(
            posDot == std::string::npos ? text.size() : posDot,
            std::min(
                posQ == std::string::npos ? text.size() : posQ,
                posE == std::string::npos ? text.size() : posE
            )
        );

        sentence = text.substr(start, endPos - start + 1); // включаем разделитель
        start = endPos + 1; // сдвигаем старт на следующий символ после разделителя

        // пропускаем пробелы в начале предложения
        size_t i = 0;
        while (i < sentence.size() && std::isspace(static_cast<unsigned char>(sentence[i]))) {
            ++i;
        }

        if (i < sentence.size() && sentence[i] == '-') {
            std::cout << sentence << std::endl;
        }
    }
}
