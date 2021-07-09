#ifndef AUTOMATON_H_
#define AUTOMATON_H_

#include <math.h>

/**
 * @brief Cellular automaton data model
 *
 * Represents the inner workings of the elementary cellular automaton.
 */
class Automaton {
public:
    /**
     * @brief Allocate memory and initialise neighbourhood, state and
     * rule arrays as all false and set initial rule
     *
     * @param _stateLength Memory allocated in number of cells in state array
     */
    Automaton (int _stateLength, int _rule);

    /**
     * @brief Free memory
     */
    virtual ~Automaton();

    /**
     * @brief Initialise automaton state arrays
     */
    void init();

    /**
     * @brief Set state arrays to all false
     */
    void reset();

   /**
    * @brief Set rule to apply and store binary representation
    *
    * @param _rule Rule used to calculate next state
    */
    void setRule (int _rule);

   /**
    * @brief Returns rule currently set
    */
    int getRule();

   /**
    * @brief Determine bit representation of rule and store it
    *
    * Binary representation of current rule is calculated
    * and stored in heap allocated member array.
    */
    void calculateRuleBits ();

   /**
    * @brief Returns rule bits array
    *
    * @return array of rule bits
    */
    bool* getRuleBits();

    /**
     * @brief Calculate next state, then current state becomes next state
     */
    void advanceState();

    /**
     * @brief Return pointer to current automaton state
     *
     * @return Pointer to heap allocated current state array
     */
    bool* getState();

private:
   /**
    * @brief Allocated state memory in number of cells
    */
    int stateLength;

    /**
     * @brief Pointer to the heap allocated current automaton state array
     */
    bool *state;

    /**
     * @brief Pointer to the heap allocated next automaton state array
     */
    bool *nextState;

   /**
    * @brief Pointer to the heap allocated cell neighbourhood array
    */
    bool *neighbourhoodBits;

    /**
     * @brief Rule to apply
     */
    int rule;

   /**
    * @brief Pointer to heap allocated rule binary representation
    *
    * Array of bools representing bits of the current rule.
    * Bits are in reverse order, i.e., LSB at index zero.
    */
    bool *ruleBits;
};

#endif // AUTOMATON_H_
