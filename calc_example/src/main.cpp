/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief An example of how a multiplier and divider engines can plug into
 *        the calculation engine API
 * @details Produces an executable which can be run as
 * `calc <engine_name> <file_list>` or `calc <engine_name> <list of integers>`
 */

#include <iostream>
#include <cstring>
#include <unordered_map>
#include "IntStreamer.h"
#include "BaseEngine.h"


int main(int argc, char *argv[])
{
    const std::string progArg = argv[0]; // Executable name
    const std::string engineArg = argv[1]; // Desired engine type
    cengine::BaseEngine::InputType inputType;
    cengine::IntStreamer *intStreamer;

    // Parse arguments
    // NOTE: We could use something like Boost here for more robust arg parsing,
    // but in the interest of keeping this example lightweight this will do for now
    if (argc < 3 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        // Print help
        std::cout << "Usage:" << std::endl
                  << "    " << progArg << "<engine_name> <file_list>" << std::endl
                  << "    " << progArg << "<engine_name> <list of integers>" << std::endl;
        return 0;
    }
    else if (argc == 3)
    {
        // Pass the file name to IntStreamer
        intStreamer = new cengine::IntStreamer(argv[2]);
    }
    else
    {
        // Pass the char* array slice containing the integers and its length
        intStreamer = new cengine::IntStreamer(argv+2, argc-2);
    }

    // Create mapping from strings to engine types
    std::unordered_map<std::string, cengine::BaseEngine::EngineType> umap;
    umap = {
            { "mult", cengine::BaseEngine::TYPE_MULT },
            { "div",  cengine::BaseEngine::TYPE_DIV  },
    };

    // Find the desired engine in the map
    auto it = umap.find(engineArg);
    if (it == umap.end())
    {
        std::cerr << "Main: Unknown engine type \"" << engineArg << "\", exiting" << std::endl;
        std::cout << "      Possible engine types are:" << std::endl;
        for (auto type : umap)
        {
            std::cout << "      - " << type.first << std::endl;
        }
        return 1;
    }

    // Construct the desired engine and run its calc() method
    cengine::BaseEngine *engine = cengine::BaseEngine::create(it->second);
    if (!engine->checkInputType(intStreamer->getInputType()))
    {
        std::cerr << "Main: " << it->first << " does not accept this input type, exiting" << std::endl;
        return 1;
    }
    double result = engine->calc(intStreamer->getInts());
    std::cout << "Result: " << result << std::endl;

    // Cleanup
    delete intStreamer;
    delete engine;
}
