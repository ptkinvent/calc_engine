/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Reads in a stream of integers and supplies them using getNext()
 */

#include <fstream>
#include <iostream>
#include "IntStreamer.h"

cengine::IntStreamer::IntStreamer(std::string filename)
{
    std::ifstream infile;
    int num;

    filename = filename + ".txt";

    // Open the file
    infile.open(filename);

    // Error checking
    if (!infile)
    {
        std::cerr << "IntStreamer: Unable to open file " << filename << std::endl;
        exit(1); // Terminate with error. Ideally this error should be caught
    }

    // Read contents of the file
    while (infile >> num)
    {
        _ints.push_back(num);
    }

    // Close the file
    infile.close();

    for (auto i : _ints)
    {
        std::cout << "IntStreamer: Found " << i << std::endl;
    }
}



cengine::IntStreamer::IntStreamer(char **ints, int num_ints)
{
    for (unsigned int i=0; i < num_ints; i++)
    {
        _ints.push_back(std::stoi(ints[i])); // TODO: More error checking here
    }

    for (auto i : _ints)
    {
        std::cout << "IntStreamer: Found " << i << std::endl;
    }
}



cengine::IntStreamer::~IntStreamer()
{

}