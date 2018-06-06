/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Reads in a stream of integers and supplies them using getNext()
 */

#include <fstream>
#include <iostream>
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

    // Read contents of the file. fstream takes care of int overflow and bad data
    while (infile >> num)
    {
        if (num > INTMAX_MAX)
        {
            std::cerr << "IntStreamer: Integer overflow, skipping entry" << num << std::endl;
            continue;
        }
        _ints.push_back((int) num);
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
        _ints.push_back(std::stoi(ints[i])); // TODO: More error checking here
    }
}



cengine::IntStreamer::~IntStreamer()
{

}
