#pragma once
#include <string_view>

class List
{

public:

    int GetSize() { return Size; } //геттер для size

    //1
    void push_front(int data); // вставка в начало
    void push_back(int data); // вставка в конец
    void insert(int data, int index); // вставка по индексу
    //2
    void PrintFromHead(); // печать с головы
    void PrintFromTail(); // печать с хвоста
    //3
    int at(const int index);
    int& operator[](const int index); // итератор
    //4
    void output(std::string_view fname); //запись в файл

    //5
    void input(std::string_view fname); //чтение с файла
    //6
    void removeAt(int index); // удаление по индексу
    void pop_front(); // удаление из начала
    void pop_back(); // удаление из конца
    //7
    void clear(); //обнуляем список
    //8
    void sort_Head_to_tail();
    void sort_Tail_to_head();

    void reverse();
    List(); // конструктор
    ~List(); // деструктор

private:

    class Node // узел в нашем списке
    {
    public:
        Node(int data, Node* pNext = nullptr, Node* pPrev = nullptr) // конструктор
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

        int data;
        Node* pNext;
        Node* pPrev;
    };

    Node* head; // создаем голову
    Node* tail; // создаем хвост
    int Size; //размер
    friend void united(List& a, List& b);
};

