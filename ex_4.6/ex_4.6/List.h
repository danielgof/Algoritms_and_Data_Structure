#pragma once
#include <string_view>

class List
{

public:

    int GetSize() { return Size; } //������ ��� size

    //1
    void push_front(int data); // ������� � ������
    void push_back(int data); // ������� � �����
    void insert(int data, int index); // ������� �� �������
    //2
    void PrintFromHead(); // ������ � ������
    void PrintFromTail(); // ������ � ������
    //3
    int at(const int index);
    int& operator[](const int index); // ��������
    //4
    void output(std::string_view fname); //������ � ����

    //5
    void input(std::string_view fname); //������ � �����
    //6
    void removeAt(int index); // �������� �� �������
    void pop_front(); // �������� �� ������
    void pop_back(); // �������� �� �����
    //7
    void clear(); //�������� ������
    //8
    void sort_Head_to_tail();
    void sort_Tail_to_head();

    void reverse();
    List(); // �����������
    ~List(); // ����������

private:

    class Node // ���� � ����� ������
    {
    public:
        Node(int data, Node* pNext = nullptr, Node* pPrev = nullptr) // �����������
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

        int data;
        Node* pNext;
        Node* pPrev;
    };

    Node* head; // ������� ������
    Node* tail; // ������� �����
    int Size; //������
    friend void united(List& a, List& b);
};

