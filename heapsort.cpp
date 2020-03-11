#include <iostream>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10000000

#define MAX 10000000

void heapify(int *array, int length, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (length > left && array[left] > array[largest])
        largest = left;
    if (length > right && array[right] > array[largest])
        largest = right;
    if (largest != index)
    {
        std::swap(array[index], array[largest]);

        heapify(array, length, largest);
    }
}

void heapsort(int *start, int *end)
{
    for (int i = (end - start) / 2 - 1; i >= 0; i--)
    {
        heapify(start, (end - start), i);
    }
    for (int i = (end - start) - 1; i >= 0; i--)
    {
        std::swap(start[0], start[i]);
        heapify(start, i, 0);
    }
}

int main()
{
    srand(time(NULL));

    int *numbers = new int[LENGTH];

    for (int i = 0; i < LENGTH; i++)
    {
        numbers[i] = rand() % MAX;
    }

    heapsort(numbers, numbers + LENGTH);

    bool is_sorted = true;
    for (int i = 1; i < LENGTH; i++)
    {
        if (numbers[i] < numbers[i - 1])
            is_sorted = false;
    }
    std::cout << is_sorted << "\n";

    return 0;
}