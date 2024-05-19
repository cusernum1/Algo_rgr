#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool isValidXML(const string& xml) {
    stack<string> tags; // Стек для хранения открывающихся тегов
    int n = xml.length();
    int i = 0;

    while (i < n) {
        if (xml[i] == '<') {
            i++;
            if (i >= n) return false; // Проверка выхода за границу строки

            bool closingTag = false; // Флаг для определения закрывающего тега
            if (xml[i] == '/') {
                closingTag = true;
                i++;
                if (i >= n) return false; // Проверка выхода за границу строки
            }

            string tag_name = "";
            while (i < n && xml[i] != '>') {
                if (!islower(xml[i])) return false; // Проверка, что символ является строчной буквой
                tag_name += xml[i];
                i++;
            }

            if (i >= n || xml[i] != '>') return false; // Убедиться, что тег закрыт правильно
            i++;

            if (closingTag) {
                if (tags.empty() || tags.top() != tag_name) {
                    return false; // Несоответствие закрывающего тега
                }
                tags.pop(); // Удаляем открывающий тег из стека
            } else {
                tags.push(tag_name); // Кладем открывающий тег в стек
            }
        } else {
            if (!isspace(xml[i])) return false; // Проверка на неожиданные символы вне тегов
            i++;
        }
    }

    return tags.empty(); // Проверка, что все теги закрыты
}
