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



class BaseEngine
{
public:
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
    /** Different input types allowed */
    enum InputType
    {
        FILE_LIST,    ///< Only accepts files
        INT_LIST,     ///< Only accepts integer lists
        FILE_INT_LIST ///< Accepts both files and integer lists
    };

    InputType _inputType; ///< The type of input allowed for this engine
};

}

#endif
