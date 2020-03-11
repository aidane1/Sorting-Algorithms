#include <iostream>
#include <stdlib.h>
#include <time.h>

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

    quicksort(numbers, numbers + LENGTH);

    bool is_sorted = true;
    for (int i = 1; i < LENGTH; i++)
    {
        if (numbers[i] < numbers[i - 1])
            is_sorted = false;
    }
    std::cout << is_sorted << "\n";

    return 0;
}