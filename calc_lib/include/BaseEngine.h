/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 */

#ifndef CALC_BASEENGINE_H
#define CALC_BASEENGINE_H

#include <vector>
#include <memory>


/**
 * @brief Collection of classes belonging to calculation engine library
 */
namespace cengine
{

/**
 * @brief Base engine class to inherit from
 */
class BaseEngine
{
public:
    /**
     * Engine types
     */
    enum EngineType
    {
        TYPE_MULT = 0, ///< Multiplier engine type
        TYPE_DIV,      ///< Divider engine type
    };

    /**
     * Different input types allowed
     */
    enum InputType
    {
        FILE_LIST = 1, ///< Only accepts integer lists from files
        ARGS_LIST = 2, ///< Only accepts integer lists from command line args
    };

    /**
     * Checks if the given input type matches this engine's allowed input type
     * @param inputType File or argument input type
     * @return True if passes check, false if fails
     */
    virtual bool checkInputType(InputType inputType) { return inputType & _allowedInputType; }

    /**
     * Performs the calculation for this calculation engine
     * @param ints Integers to calculate on
     * @return Success state, 0 for success, 1 for fail
     */
    virtual double calc(std::vector<int> ints) = 0;

    /**
     * Factory method. Creates an engine of the given type
     * @param e Engine type to create
     * @return Newly created engine
     */
    static std::shared_ptr<BaseEngine> create(EngineType e);

protected:
    /**
     * The type of input allowed for this engine.
     * NOTE: This does not enforce the best type safety here. Given more time
     * one could make the enum classed and override operator| and operator&.
     */
    int _allowedInputType;
};

}

#endif
