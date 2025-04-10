/**************************************************************************
 * @file Observer.h
 * @brief Declaration of the Observer superclass to observe the logic of the game
 * /n This is a generic class that can be used to observe entities, scores, etc.
 * @namespace gameModel
 **************************************************************************/

#ifndef DOODLE_GAME_OBSERVER_H
#define DOODLE_GAME_OBSERVER_H

namespace gameModel {
template <typename Type>
class Observer {
public:
    /**
     * Default constructor of the Observer class
     */
    Observer() = default;

    /**
     * Default virtual destructor of the Observer class
     */
    virtual ~Observer() = default;

    /**
     * Pure virtual function
     * \n Updates the observers of the appropriate subject
     * @param subject the subject providing information
     */
    virtual void update(const Type& subject) = 0;
};
} // namespace gameModel

#endif // DOODLE_GAME_OBSERVER_H
