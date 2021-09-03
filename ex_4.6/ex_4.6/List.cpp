#include "List.h"
#include <fstream>
#include <iostream>
#include <string>

List::List() // �������������� ������ ������
{
    head = nullptr;
    tail = nullptr;
    Size = 0;
}

List::~List() // �������������
{
    clear();
}


void List::clear()
{
    while (Size)
    {
        pop_front();
    }
}


void List::push_front(int data)
{
    if (Size > 1)
    {
        Node* temp = head; //���� ������ ����������
        head = new Node(data, head); // ������� ����� head � �������� ���� ������ � ������ �� ������
        temp->pPrev = head; // ������ � ������� �������� ��������� �� ����� head
    }
    else if (Size == 1)
    {
        head = new Node(data, head); //������� ����� head-�������
        tail->pPrev = this->head; //� ������ ���������� ��������� ������ �� ����� �������
    }
    else
    {
        head = tail = new Node(data, head, tail);
    }
    Size++;
}


void List::push_back(int data)
{
    if (Size > 1)
    {
        Node* temp = tail; //���� ������ ����������
        tail = new Node(data, nullptr, tail); // ������� ����� tail � �������� ���� ������ � ������ �� ������
        temp->pNext = tail; //������ � �������������� �������� ��������� �� ������
    }
    else if (Size == 1)
    {
        tail = new Node(data, nullptr, tail); //������� ����� �����
        head->pNext = this->tail; // � ������� ������ ������ ��������� �� �����
    }
    else
    {
        head = tail = new Node(data, head, tail);
    }
    Size++;


}


void List::pop_front()
{
    if (Size > 1)
    {
        Node* temp = head; // ������ �������������� ���������� � ������ �� ������
        head = head->pNext; // ������ ������
        delete temp; // ������� ���������� ������
    }
    else if (Size == 1)
    {
        Node* temp = head;
        tail = head = head->pNext;
        delete temp;
    }

    Size--;
}


void List::output(std::string_view fname)
{
    std::ofstream fout(fname.data());
    if (!fout.is_open())
    {
        std::cout << "Unable to open file: " << fname.data() << std::endl;
        return;
    }
    Node* ptr = head;
    while (ptr)
    {
        fout << ptr->data << ' ';
        ptr = ptr->pNext;
    }
}

void List::input(std::string_view fname)
{
    std::ifstream fin(fname.data());
    if (!fin.is_open())
    {
        std::cout << "Unable to open file: " << fname.data() << std::endl;
        return;
    }
    clear();
    while (!fin.eof())
    {
        int tmp;
        fin >> tmp;
        push_back(tmp);
    }
}

void List::pop_back()
{
    if (Size > 1)
    {
        Node* temp = tail; // ������ �������������� ���������� � ������ �� �����
        tail = tail->pPrev; //�������� �����
        delete temp; // ������ ������ �����
    }
    else if (Size == 1)
    {
        Node* temp = tail;
        tail = head = tail->pPrev;
        delete temp;
    }

    Size--;
}


void List::insert(int data, int index)
{
    if (index == 0) push_front(data);

    else if (index == Size || index > Size) push_back(data);


    else if (index <= Size / 2) //���� ����� ������
    {
        Node* previous = this->head; //������� ���� � ������� ������
        for (int i = 0; i < index - 1; i++) //���������� �� ������ �� ����, ������� ��������� �� ������ ���
        {
            previous = previous->pNext;
        }

        Node* newNode = new Node(data, previous->pNext, previous); // ������� ����� ����

        previous->pNext = newNode; //� ����������� ������ ��������� �� ��� �����
        Node* next = newNode->pNext; // � ������ + 1 ������ ��������� �� ����������:
        next->pPrev = newNode;

        Size++;
    }

    else if (index > Size / 2) // ���� ����� �����
    {
        Node* next = this->tail;
        for (int i = Size - 1; index < i; i--)
        {
            next = next->pPrev;
        }

        Node* newNode = new Node(data, next, next->pPrev);

        next->pPrev = newNode;
        Node* previous = newNode->pPrev;
        previous->pNext = newNode;

        Size++;
    }
}


void List::removeAt(int index)
{
    if (index == 0) pop_front(); //���� ������

    else if (index == Size || index > Size) pop_back(); //���� �����


    else if (index <= Size / 2) //���� ����� ������
    {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++) //���� ���������� ����������
        {
            previous = previous->pNext;
        }

        Node* toDelete = previous->pNext; // ���������
        previous->pNext = toDelete->pNext; // ��������� �� ����������� � ���������
        Node* next = toDelete->pNext;
        delete toDelete;
        next->pPrev = previous;

        Size--;
    }

    else if (index > Size / 2) // ���� ����� �����
    {
        Node* next = this->tail;
        for (int i = Size - 1; index < i; i--)
        {
            next = next->pPrev;
        }

        Node* toDelete = next->pPrev;
        next->pPrev = toDelete->pPrev;
        Node* previous = toDelete->pPrev;
        delete toDelete;
        previous->pNext = next;

        Size--;
    }
}


int& List::operator[](const int index)
{
    if (index <= Size / 2) //���� ����� �����
    {
        int counter = 0;
        Node* current = this->head;

        while (current != nullptr) // ���������� �� ����
        {
            if (counter == index) return current->data; // ���� ���, �� ���������� ��������
            current = current->pNext; // ���� ���, �� ���� ������
            counter++;
        }
    }
    else
    {
        int counter = Size - 1;
        Node* current = this->tail;

        while (current != nullptr)
        {
            if (counter == index) return current->data;
            current = current->pPrev;
            counter--;
        }
    }
}


void List::PrintFromHead()
{
    std::cout << "Come the method PrintFromHead:" << std::endl;
    Node* print = head; //���������� �� �����
    while (print)
    {
        std::cout << print->data << std::endl;
        print = print->pNext;
    }
    std::cout << std::endl;
}


void List::PrintFromTail()
{
    std::cout << "Come the method PrintFromTail:" << std::endl;
    Node* print = tail;
    while (print)
    {
        std::cout << print->data << std::endl;
        print = print->pPrev;
    }
    std::cout << std::endl;
}

void List::reverse()
{
    Node* ptr = head;
    while (ptr != 0) {
        Node* tmp = ptr->pNext; // ���������� ��������� �� ���������
        ptr->pNext = ptr->pPrev; // ��������� �� ��������� ������ �� ����������
        ptr->pPrev = tmp; // ��������� �� ���������� ������ �� ���������
        if (tmp == NULL) { //���� ����� �� �����, �� ������ ������� ����� � ������
            tail = head;
            head = ptr;
        }
        ptr = tmp; //������ �� �� ����� �� ��������� ���������

    }
}

int List::at(const int index)
{
    return (*this)[index];
}

void united(List& a, List& b) { //���������� ������ ������� � ����� �������
    b.head->pPrev = a.tail;
    a.tail->pNext = b.head;

}

void List::sort_Head_to_tail()
{
    for (int i = 0; i < Size - 1; i++)
    {
        int maxid = i;
        for (int j = i + 1; j < Size; j++)
        {
            if (at(j) > at(maxid))
            {
                maxid = j;
            }
        }
        int tmp = at(maxid);
        (*this)[maxid] = at(i);
        (*this)[i] = tmp;
    }
}


void List::sort_Tail_to_head()
{
    sort_Head_to_tail();
    reverse();
}

