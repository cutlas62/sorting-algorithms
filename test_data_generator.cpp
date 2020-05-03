#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <stdio.h>
#include <sys/stat.h>
using namespace std;

void usage (void)
{
    printf("[%s]\n", __FILE__);
    printf("\n");
    printf("Description: Generate random test data for the sorting algorithms. The test files will be created in the folder 'generated/'\n");
    printf("\n");
    printf("Parameters:\n");
    printf("  -h, --help   Show this help information\n");
    printf("  -n <nrows>   Number of rows to create\n");
    printf("  -m <mode>    Randomness mode\n");
    printf("           <mode>:\n");
    printf("           random           Totally random order\n");
    printf("           low_to_high      Numbers ordered from low to high\n");
    printf("           high_to_low      Numbers ordered from high to low\n");
}

int main (int argc, char *argv[])
{
    // Default values
    string file_name = "";
    const char file_directory [] = "test_data/";
    string mode = "random";
    string n_rows = to_string(5000);
    string file_extension = ".txt";

    // User input overrides default values
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
            else if ((arg == "-n") || (arg == "--number"))
            {
                // Check that there are more parameters
                if(i + 1 < argc)
                {
                    n_rows = argv[++i];
                    try
                    {
                        if(stoi(n_rows) <= 0)
                        {
                            printf("Bad parameter, <n_rows> has to be a positive number\n");
                            return -1;
                        }

                    }
                    catch (invalid_argument const &e)
                    {
                        printf("Bad parameter, <n_rows> has to be a positive number\n");
                        return -1;
                    }
                    catch (out_of_range const &e)
                    {
                        printf("Bad parameter, <n_rows> has to be lower than %d\n", INT_MAX);
                        return -1;
                    }

                }
            }
            else if((arg == "-m") || (arg == "--mode"))
            {
                // Check that there are more parameters
                if(i + 1 < argc)
                {
                    mode = argv[++i];
                    if(!((mode == "random") || (mode == "low_to_high") || (mode == "high_to_low")))
                    {
                        printf("Bad parameter, <mode>. Run -h for help\n");
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

    file_name = file_name + file_directory + n_rows + mode + file_extension;

    // Check if directory already exists
    struct stat tmp;
    if(stat (file_directory, &tmp))
    {
        // It doesn't exist
        if(mkdir(file_directory, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))
        {
            printf("Could not create directory %s\n", file_directory);
        }
    }


    ofstream random_file;
    random_file.open (file_name);
    int max_rows = stoi(n_rows);

    // Let's start each file with the number of elements it contains
    random_file << max_rows;

    if(mode == "random")
    {
        printf("Generating %d random values between 0 and %d...\n", max_rows, RAND_MAX);
        for(int i = 0; i < max_rows; i++)
        {
            random_file << endl << rand();
        }

    }
    else if(mode == "low_to_high")
    {
        printf("Generating %d values between 0 and %d from low to high...\n", max_rows, max_rows - 1);
        for(int i = 0; i < max_rows; i++)
        {
            random_file << endl << i;
        }

    }
    else if (mode == "high_to_low")
    {
        printf("Generating %d values between 0 and %d from high to low...\n", max_rows, max_rows - 1);
        for(int i = max_rows; i > 0; i--)
        {
            random_file << endl << i - 1;
        }
    }
    printf("Complete!\n");
    random_file.close();
    return 0;
}