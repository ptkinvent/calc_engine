/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief An example of how a multiplier and divider engines can plug into
 *        the calculation engine API
 */

#include <iostream>
#include <cstring>
#include "IntStreamer.h"

int main(int argc, char *argv[])
{
    // Parse arguments
    // TODO: We could use something more robust like Boost here, but this will do for now
    if (argc < 3 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        // Print help
        printf("Usage:\n"
                       "    %s <engine_name> <file_list>\n"
                       "    %s <engine_name> <int_1> <int_2> ...\n", argv[0], argv[0]);
        return 0;
    }
    else if (argc == 3)
    {
        std::cout << "Main: Parsing a file" << std::endl;
        cengine::IntStreamer *intStreamer = new cengine::IntStreamer(argv[2]);
    }
    else
    {
        std::cout << "Main: Parsing a list of integers" << std::endl;
        cengine::IntStreamer *intStreamer = new cengine::IntStreamer(argv+=2, argc-2);
    }
}