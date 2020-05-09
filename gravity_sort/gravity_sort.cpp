#include "../utils.h"


statistics_t gravity_sort(int *arr, int n)
{	printf("Due to memory constaints, let's use a shorter array for this algorithm\n");
    printf("Sorting array with gravity sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_time = microsSinceEpoch();

    int test_array [] = {9, 8, 7, 6, 5, 4, 3, 2, 11, 9, 8, 7, 4, 3, 12, 8, 7, 6, 65, 4, 3, 2, 151, 9, 8, 7, 4, 3, 12, 8, 17, 6, 5, 4, 23, 2, 11, 9, 8, 7, 4, 33, 12, 8, 7, 6, 35, 41, 3, 2, 11, 9, 8, 7, 4, 3, 12};


    // Get the maximum value in order to create our 2D array
    int max = 0;
    int n_t = sizeof(test_array) / sizeof(test_array[0]);

    printf("Test array: ");
    for(int i = 0; i < n_t; i++)
    {
        printf("%d ", test_array[i]);
    }
    printf("\n");

    for(int i = 0; i < n_t; i++)
    {
        if(test_array[i] > max)
        {
            max = test_array[i];
        }
    }

    // Create the gravity array
    bool gravity_array [max][n_t] = {0};


    // Populate the gravity array
    for(int i = 0; i < n_t; i++)
    {
        int cur = test_array[i];
        for(int j = 0; j < cur; j++)
        {
            gravity_array[j][i] = 1;
        }
    }


    // Count how many elements are in each column
    for(int i = 0; i < max; i++)
    {

        int count = 0;
        for(int j = 0; j < n_t; j++)
        {
            if(gravity_array[i][j])
            {
                gravity_array[i][j] = 0;
                count++;
            }
        }

        // And move them all to the bottom
        for(int j = 0; j < count; j++)
        {
            gravity_array[i][n_t - j - 1] = 1;
        }

    }


    // Finally, reconstruct the original array
    for(int i = 0; i < n_t; i++)
    {
        test_array[i] = 0;
        for(int j = 0; j < max; j++)
        {
            if(gravity_array[j][i])
            {
                test_array[i]++;
            }
            else
            {
                continue;
            }
        }
    }
    printf("\n\n");

    printf("Sorted array:\n");
    print_array(&test_array[0], n_t);
    ret.time = microsSinceEpoch() - start_time;
    return ret;
}