/**
 * @author P. Sahay
 * @date 6/3/18
 * @copyright P. Sahay
 * @brief Base engine class to inherit from
 */

#ifndef CALC_BASE_ENGINE_H
#define CALC_BASE_ENGINE_H

/**
 * @namespace cengine
 */
namespace cengine
{

enum InputType
{
    FILE_LIST,    ///< Only accepts files
    INT_LIST,     ///< Only accepts integer lists
    FILE_INT_LIST ///< Accepts both files and integer lists
};



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
     * Constructor
     */
    BaseEngine() = default; // TODO: Populate _inputType for base class?

    /**
     * Performs the calculation for this calculation engine
     * @param prevTotal Output from the previous calculation
     * @param num New integer
     * @return New output after calculation
     */
    virtual int calc(int prevTotal, int num) = 0;

private:
    InputType _inputType; ///< The type of input allowed for this
};

}

#endif
