/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief An example of how different calculation engines can plug into the
 *        the API
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
    cengine::BaseEngine::InputType inputType;
    cengine::IntStreamer *intStreamer;

    // Parse arguments
    // NOTE: We could use something like Boost here for more robust arg parsing,
    // but in the interest of keeping this example lightweight this will do for now
    if (argc < 3 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        // Print help
        std::cout << "Usage:" << std::endl
                  << "    " << progArg << " <engine_name> <file>" << std::endl
                  << "    " << progArg << " <engine_name> <list of integers>" << std::endl;
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
    const std::string engineArg = argv[1];
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

    // Construct the desired engine
    cengine::BaseEngine *engine = cengine::BaseEngine::create(it->second);
    if (!engine)
    {
        std::cerr << "Main: Engine does not exist, exiting" << std::endl;
        return 1;
    }

    // Check its allowable input type
    if (!engine->checkInputType(intStreamer->getInputType()))
    {
        std::cerr << "Main: " << it->first << " does not accept this input type, exiting" << std::endl;
        return 1;
    }

    // Run calc() method
    double result;
    try
    {
        result = engine->calc(intStreamer->getInts());
        std::cout << "Main: Result: " << result << std::endl;
    }
    catch(const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Main: Exception in calculation engine" << std::endl;
    }
    catch(const std::overflow_error &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Main: Exception in calculation engine" << std::endl;
    }
    catch (...)
    {
        std::cout << "Main: Exception in calculation engine" << std::endl;
    }

    // Clean up
    delete intStreamer;
    delete engine;
}
