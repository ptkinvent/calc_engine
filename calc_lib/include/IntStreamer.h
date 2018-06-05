/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Reads in a stream of integers and supplies them using getNext()
 */

#ifndef CALC_INT_STREAMER_H
#define CALC_INT_STREAMER_H

#include <string>
#include <vector>

namespace cengine
{

class IntStreamer
{
public:
    /**
     * Constructor. Reads in integers from a file.
     * @param filename
     */
    IntStreamer(std::string filename);

    /**
     * Constructor. Reads in integers from a character array
     * @param ints Character array of numbers
     * @param num_ints Size of character array
     */
    IntStreamer(char **ints, int num_ints); // TODO: Make this take a char array?

    /**
     * Destructor
     */
    ~IntStreamer();

private:
    std::vector<int> _ints;
};

}


#endif
