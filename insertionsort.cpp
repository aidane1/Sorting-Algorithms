#include <iostream>
#include <stdlib.h>
#include <time.h>


#define LENGTH 1000000

#define MAX 1000000

void insertionsort(int *start, int *end) {
    int i = 1;
    int length = end - start;
    while (i < length) {
        int j = i;
        while (j > 0 && start[j - 1] > start[j]) {
            std::swap(start[j], start[j - 1]);
            j--;
        }
        i++;
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

    insertionsort(numbers, numbers + LENGTH);

    bool is_sorted = true;
    for (int i = 1; i < LENGTH; i++)
    {
        if (numbers[i] < numbers[i - 1])
            is_sorted = false;
    }
    std::cout << is_sorted << "\n";

    return 0;
}