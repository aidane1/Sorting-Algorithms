#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

//O(3n) sorting algorithm
int *sort(int *numbers, int length)
{
    int min = numbers[0];
    int max = numbers[0];
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
    }

    std::vector<int> *buckets = new std::vector<int>[max + 1];

    for (int i = 0; i < length; i++)
    {
        buckets[numbers[i]].push_back(numbers[i]);
    }

    int *final = new int[length];

    int index = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (buckets[i].size() > 0)
        {
            std::memcpy(final + index, &(*(buckets[i].begin())), sizeof(int) * buckets[i].size());
            index += buckets[i].size();
        }
    }

    return final;
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

    int *sorted = sort(numbers, LENGTH);

    bool is_sorted = true;
    for (int i = 1; i < LENGTH; i++)
    {
        if (sorted[i] < sorted[i - 1])
            is_sorted = false;
    }
    std::cout << is_sorted << "\n";

    return 0;
}