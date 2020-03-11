#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

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

int *partition(int *left, int *right)
{
    int val = *left;

    int *i = left;
    int *j;

    for (j = left + 1; j < right; j++)
    {
        if (*j <= val)
        {
            i++;
            std::swap(*i, *j);
        }
    }
    std::swap(*i, *left);
    return i;
}

void quicksort(int *start, int *end)
{
    if (start >= end)
        return;
    int *partition_pointer = partition(start, end);
    quicksort(start, partition_pointer);
    quicksort(partition_pointer + 1, end);
}

void insertionsort(int *start, int *end)
{
    int i = 1;
    int length = end - start;
    while (i < length)
    {
        int j = i;
        while (j > 0 && start[j - 1] > start[j])
        {
            std::swap(start[j], start[j - 1]);
            j--;
        }
        i++;
    }
}

void i_sort(int *start, int *end, int maxdepth)
{
    int length = end - start;
    if (length <= 1)
        return;
    else if (length < 16)
    {
        insertionsort(start, end);
    }
    else if (!maxdepth)
        heapsort(start, end);
    else
    {
        int *partition_pointer = partition(start, end);
        i_sort(start, partition_pointer, maxdepth - 1);
        i_sort(partition_pointer + 1, end, maxdepth - 1);
    }
}

void introsort(int *start, int *end)
{
    int maxdepth = std::log2(end - start) * 2;
    i_sort(start, end, maxdepth);
}

#define LENGTH 10000000

#define MAX 10000000

int main()
{
    srand(time(NULL));

    int *numbers = new int[LENGTH];

    for (int i = 0; i < LENGTH; i++)
    {
        numbers[i] = rand() % MAX;
    }

    introsort(numbers, numbers + LENGTH);

    bool is_sorted = true;
    for (int i = 1; i < LENGTH; i++)
    {
        if (numbers[i] < numbers[i - 1])
            is_sorted = false;
    }
    std::cout << is_sorted << "\n";

    return 0;
}