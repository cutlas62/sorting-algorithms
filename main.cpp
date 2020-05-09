#include "utils.h"
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdbool.h>

using namespace std;



statistics_t bitonic_sort(int *arr, int n);             // In progress
statistics_t bubble_sort(int *arr, int n);              // Done
statistics_t cocktail_shaker_sort(int *arr, int n);     // Done
statistics_t gcc_std_sort(int *arr, int n);
statistics_t gcc_std_stable_sort(int *arr, int n);
statistics_t gnome_sort(int *arr, int n);
statistics_t gravity_sort(int *arr, int n);
statistics_t heap_sort(int *arr, int n);
statistics_t insertion_sort(int *arr, int n);           // Done
statistics_t merge_sort(int *arr, int n);               // Done
statistics_t quick_sort(int *arr, int n);               // Done
statistics_t radix_sort(int *arr, int n);
statistics_t selection_sort(int *arr, int n);           // Done
statistics_t shell_sort(int *arr, int n);				// Done



statistics_t (*sort_fun)(int *arr, int n);

//TODO implement the two sorting modes

void usage (void)
{
    printf("[%s]\n", __FILE__);
    printf("Description: Test different sorting algorithms with generated test data\n");
    printf("Parameters:\n");
    printf("  -h, --help               Display this information\n");
    printf("  -m, --mode <mode>        Sorting order\n");
    printf("                             <mode> can be 'low_to_high' or 'high_to_low'. By default it's 'low_to_high'\n");
    printf("  -f, --file               Input file with random data to sort. This file has to be in test_data/\n");
    printf("  -v, --verbose            Display both the unsorted and sorted data\n");
    printf("  -s, --stats              Display algorithms statistics\n");
    printf("  -a, --alg <algorithm>    Select the sorting algorithm to test. Posible <algorithm> are:\n");
    printf("                             bitonic, bubble, cocktail_shaker, gcc_std, gcc_std_stable,\n");
    printf("                             gnome, gravity, heap, insertion, merge, quick, radix, selection, shell\n");
    printf("Examples:\n");
    printf("  ./main -s -v -f 100random.txt -a cocktail_shaker\n");
    printf("  ./main -s -a bubble\n");
}


int main (int argc, char *argv[])
{
    // Default values
    string mode = "low_to_high";
    string file = "test_data/100random.txt";
    bool verbose = false;
    bool print_stats = false;

    // ser input overrides default values
    if(argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            string arg = argv[i];
            if ((arg == "-h") || (arg == "--help"))
            {
                usage();
                return 0;
            }
            else if((arg == "-m") || (arg == "--mode"))
            {
                // Check that there are more parameters
                if(i + 1 < argc)
                {
                    mode = argv[++i];
                    if(!((mode == "low_to_high") || (mode == "high_to_low")))
                    {
                        printf("Bad parameter, <mode>. Run -h for help\n");
                        return -1;
                    }
                }
            }
            else if((arg == "-f") || (arg == "--file"))
            {
                // Check that there are more parameters
                if(i + 1 < argc)
                {
                    file = "test_data/";
                    file += argv[++i];
                    struct stat buffer;
                    if(stat (file.c_str(), &buffer))
                    {
                        printf("%s is not a valid file\n", file.c_str());
                        return -1;
                    }
                }
            }
            else if((arg == "-v") || (arg == "--verbose"))
            {
                verbose = true;
            }
            else if((arg == "-s") || (arg == "--stats"))
            {
                print_stats = true;
            }
            else if((arg == "-a") || (arg == "--alg"))
            {
                // Check that there are more parameters
                if(i + 1 < argc)
                {
                    string sorting_alg = argv[++i];
                    if (sorting_alg == "bitonic")
                    {
                        sort_fun = &bitonic_sort;
                    }
                    else if (sorting_alg == "bubble")
                    {
                        sort_fun = &bubble_sort;
                    }
                    else if (sorting_alg == "cocktail_shaker")
                    {
                        sort_fun = &cocktail_shaker_sort;
                    }
                    else if (sorting_alg == "gcc_std")
                    {
                        sort_fun = &gcc_std_sort;
                    }
                    else if (sorting_alg == "gcc_std_stable")
                    {
                        sort_fun = &gcc_std_stable_sort;
                    }
                    else if (sorting_alg == "gnome")
                    {
                        sort_fun = &gnome_sort;
                    }
                    else if (sorting_alg == "gravity")
                    {
                        sort_fun = &gravity_sort;
                    }
                    else if (sorting_alg == "heap")
                    {
                        sort_fun = &heap_sort;
                    }
                    else if (sorting_alg == "insertion")
                    {
                        sort_fun = &insertion_sort;
                    }
                    else if (sorting_alg == "merge")
                    {
                        sort_fun = &merge_sort;
                    }
                    else if (sorting_alg == "quick")
                    {
                        sort_fun = &quick_sort;
                    }
                    else if (sorting_alg == "radix")
                    {
                        sort_fun = &radix_sort;
                    }
                    else if (sorting_alg == "selection")
                    {
                        sort_fun = &selection_sort;
                    }
                    else if (sorting_alg == "shell")
                    {
                        sort_fun = &shell_sort;
                    }
                    else
                    {
                        printf("%s is not a valid sorting algorithm\n", sorting_alg.c_str());
                        return -1;
                    }

                }
            }
            else
            {
                printf("ERROR: Unkwnown parameter %s\n", arg.c_str());
                return -1;
            }
        }
    }
    if(sort_fun == nullptr)
    {
        printf("No sorting algorithm selected. Run -h for help\n");
        return -1;
    }



    // Load values to sort from the file
    string line = "";
    int n_rows = 0;
    ifstream random_file (file);
    if(random_file.is_open())
    {
        if(getline(random_file, line))
        {
            n_rows = stoi(line);
        }
        int random_array [n_rows] = {0};
        int i = 0;
        while ( getline (random_file, line) )
        {
            random_array[i] = stoi(line);
            i++;
        }
        random_file.close();
        if(verbose)
        {
            printf("Random array:\n");
            print_array(&random_array[0], n_rows);
            printf("\n");
        }

        // Sort the array!
        statistics_t stats = {0};
        stats = sort_fun(&random_array[0], n_rows);

        if(verbose)
        {
            printf("Sorted array:\n");
            print_array(&random_array[0], n_rows);
            printf("\n");
        }

        if(print_stats)
        {
            printf("\nStats:\n");
            printf("\tTotal time: %lu micros (%.3f seconds)\n", stats.time, stats.time / 1000000.0);
            printf("\tArray accesses: %lu\n", stats.array_accesses);
            printf("\tComparisons : %lu\n", stats.comparisons);
        }
    }
    else
    {
        printf("Could not open file '%s'\n", file.c_str());
        return -1;
    }
}