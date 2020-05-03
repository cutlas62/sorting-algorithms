#include <iostream>
#include <fstream>
#include <string>
#include <stdbool.h>

using namespace std;

//TODO add statistics

void bubble_sort(int *arr, int n)
{
	bool sorted = true;
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n - i - 1; j++){
    		if (*(arr + j) > *(arr + j + 1)){
    			sorted = false;
    			// Swap them!
    			int tmp = *(arr + j);
    			*(arr + j) = *(arr + j + 1);
    			*(arr + j + 1) = tmp;
    		}
    	}
    	if(sorted){
    		break;
    	}
    }
}

void usage (void)
{
	// TODO
}

void print_array(int *arr, int n)
{
    int n_columns = 5;
    int n_rows = n / n_columns;
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            printf("%d", *(arr + i * n_columns + j));
            printf("\t");
        }
        printf("\n");
    }
}

int main (int argc, char *argv[])
{
    // Sort the values from low to high by default
    string mode = "low_to_high";
    string file = "../test_data/generated/100random.txt";
    bool verbose = false;

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
                    file = "../test_data/generated/";
                    file += argv[++i];
                    // TODO check that the file exists
                }
            }
            else if((arg == "-v") || (arg == "--verbose"))
            {
                verbose = true;
            }
            else
            {
                printf("ERROR: Unkwnown parameter %s\n", arg.c_str());
                return -1;
            }
        }
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
            //TODO check n_rows
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
        bubble_sort(&random_array[0], n_rows);

        if(verbose)
        {
            printf("Sorted array:\n");
            print_array(&random_array[0], n_rows);
            printf("\n");
        }
    }
    else
    {
        printf("Could not open file '%s'\n", file.c_str());
        return -1;
    }


}