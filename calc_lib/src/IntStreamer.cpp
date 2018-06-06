/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Reads in a stream of integers and supplies them using getNext()
 */

#include <fstream>
#include <iostream>
#include <limits>
#include "IntStreamer.h"

cengine::IntStreamer::IntStreamer(const std::string &filename) : _inputType(BaseEngine::FILE_LIST)
{
    std::ifstream infile;
    long long int num;

    // Open the file
    infile.open(filename + ".txt");

    // Error checking
    if (!infile)
    {
        std::cerr << "IntStreamer: Unable to open file " << filename << ".txt" << std::endl;
        return;
    }

    // Read contents of the file. fstream takes care of most corner cases here
    // Read file contents into a long long and check if result would fit in int
    while (infile >> num)
    {
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        {
            std::cerr << "IntStreamer: Integer overflow, skipping entry" << num << std::endl;
            continue;
        }

        // Store integer into list
        try
        {
            _ints.push_back((int)num);
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "IntStreamer: Warning, failed to store integer to due to bad alloc" << std::endl;
            continue;
        }
        catch (...)
        {
            std::cerr << "IntStreamer: Warning, failed to store integer" << std::endl;
            continue;
        }
    }

    // Close the file
    infile.close();
}



cengine::IntStreamer::IntStreamer(char **ints, int num_ints) : _inputType(BaseEngine::ARGS_LIST)
{
    for (unsigned int i=0; i < num_ints; i++)
    {
        if (ints[i] == nullptr || *ints[i] == '\0')
        {
            continue;
        }

        // Read string into integer
        int num;
        try
        {
            // TODO: Known issue with stoi() causes '0.5' to be read as zero
            // Given more time this would be dealt with
            num = std::stoi(ints[i]);
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "IntStreamer: Warning, invalid integer exception, ignoring corrupt data" << std::endl;
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "IntStreamer: Warning, integer out of range exception, ignoring corrupt data" << std::endl;
            continue;
        }
        catch (...)
        {
            std::cerr << "IntStreamer: Warning, ignoring corrupt data" << std::endl;
            continue;
        }

        // Store integer into list
        try
        {
            _ints.push_back(num);
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "IntStreamer: Warning, failed to store integer to due to bad alloc" << std::endl;
            continue;
        }
        catch (...)
        {
            std::cerr << "IntStreamer: Warning, failed to store integer" << std::endl;
            continue;
        }

    }
}
