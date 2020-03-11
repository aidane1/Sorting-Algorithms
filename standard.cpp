#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

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

    std::sort(numbers, numbers + LENGTH);

    bool is_sorted = true;
    for (int i = 1; i < LENGTH; i++)
    {
        if (numbers[i] < numbers[i - 1])
            is_sorted = false;
    }
    std::cout << is_sorted << "\n";

    return 0;
}