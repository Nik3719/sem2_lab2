#include"Array.h"


int& Array::operator[](int index)
{
    return this->arr[index];
}



void Array::MINSERT(int elem, int index)
{
    if (capacity == 0)
    {
        this->MPUSH(elem);
    }

    if (index > currentLen)
    {
        cout << " Такого индекса нет!\n";
        return;
    }
    if (currentLen == capacity)
    {
        int* newArr = new int[capacity * 2];
        for (int i = 0; i < index; i++)
        {
            newArr[i] = this->MGET(i);
        }
        newArr[index] = elem;
        for (int i = index + 1; i < currentLen + 1; i++)
        {
            newArr[i] = this->MGET(i);
        }
        delete[]arr;
        this->arr = newArr;
        currentLen++;
    }
    else
    {
        for (int i = currentLen; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
        this->arr[index] = elem;
        currentLen++;
    }



}


int Array::MGET(int index)
{

    if (index >= currentLen)
    {
        return -1;


    }
    return arr[index];
}


void Array::MPUSH(int elem)
{
    if (capacity == 0)
    {
        capacity = 2;
        currentLen = 1;
        arr = new int[capacity];
        arr[currentLen - 1] = elem;


    }
    else if (currentLen == capacity)
    {
        int* newArr = new int[currentLen];
        for (int i = 0; i < currentLen; i++)
        {
            newArr[i] = arr[i];
        }

        this->capacity = (this->currentLen) * 2;
        delete[]arr;
        arr = new int[capacity];
        for (int i = 0; i < currentLen; i++)
        {
            arr[i] = newArr[i];
        }
        this->currentLen = this->currentLen + 1;
        delete[]newArr;
        arr[currentLen - 1] = elem;



    }
    else
    {
        this->arr[currentLen++] = elem;
    }
}


Array::Array(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity * 2;
        this->currentLen = capacity;
        this->arr = new int[this->capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            arr[i] = 0;
        }
    }
}


Array::~Array()
{
    delete[]arr;
    arr = nullptr;
}

Array::Array(Array& other)
{
    other.capacity = this->capacity;
    other.currentLen = this->currentLen;
    other.arr = new int[other.capacity];
    for (int i = 0; i < this->currentLen; ++i)
    {
        other.arr[i] = this->arr[i];
    }
}


Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] arr;

        currentLen = other.currentLen;
        capacity = other.capacity;
        arr = new int[capacity];
        for (int i = 0; i < currentLen; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

int Array::MLEN()
{
    return this->currentLen;
}

void Array::MDEL(int index)
{
    if (index >= currentLen)
    {
        cout << " Такого индекса нет!\n";
        return;
    }
    for (int i = index; i < currentLen - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    currentLen--;
}
void Array::PRINT()
{
    for (size_t i = 0; i < currentLen; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Array::MSET(int elem, int index)
{
    if (index >= currentLen)
    {
        cout << "Такого индекса нет!\n";
        return;
    }
    arr[index] = elem;

}


