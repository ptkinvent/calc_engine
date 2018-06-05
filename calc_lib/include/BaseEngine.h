/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Base engine class to inherit from
 */

#ifndef CALC_BASEENGINE_H
#define CALC_BASEENGINE_H

#include <vector>


/**
 * @namespace cengine
 * @brief Collection of classes belonging to calculation engine
 */
namespace cengine
{

class BaseEngine
{
public:
    /**
     * Engine types
     */
    enum EngineType
    {
        /** Types */
        TYPE_MULT = 0,
        TYPE_DIV,

        /** Total number of types */
        TYPE_NUM,

        /** Invalid type */
        TYPE_INVALID = 255,
    };

    /**
     * Different input types allowed
     */
    enum InputType
    {
        FILE_LIST = 1, ///< Only accepts files
        ARGS_LIST = 2, ///< Only accepts integer lists
    };

    /**
     * Checks if the given input type matches this engine's allowed input type
     * @param inputType File or argument input type
     * @return True if passes check, false if fails
     */
    virtual bool checkInputType(InputType inputType) { return inputType & _allowedInputType; }

    /**
     * Performs the calculation for this calculation engine
     * @param prevTotal Output from the previous calculation
     * @param num New integer
     * @return New output after calculation
     */
    virtual double calc(std::vector<int> ints) = 0;

    /**
     * Factory method. Creates an engine of the given type
     * @param e Engine type to create
     * @return Newly created engine
     */
    static BaseEngine* create(EngineType e);

protected:
    /**
     * The type of input allowed for this engine. NOTE: This does not enforce
     * the best type safety here. Probably the enum itself should be classed
     * and operator| and operator& should be overridden.
     */
    int _allowedInputType;
};

}

#endif
