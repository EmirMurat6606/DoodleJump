/*****************************************************************************************
 * @file Subject.h
 * @brief This file contains the declaration of the Subject class which is an observable
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_SUBJECT_H
#define DOODLE_GAME_SUBJECT_H

#include "Observer.h"
#include <list>
#include <memory>

namespace gameModel {
template <typename Type>
class Subject {

    std::list<std::shared_ptr<Observer<Type>>> observers_;

public:
    /**
     * Default constructor of the Subject class
     */
    Subject() = default;

    /**
     * Virtual destructor of the Subject class
     */
    virtual ~Subject() = default;

    /**
     * This function attaches the observer to the subject
     */
    void attach(const std::shared_ptr<Observer<Type>>& observer) { observers_.push_back(observer); }

    /**
     * This function detaches the observer from the subject
     */
    void detach(const std::shared_ptr<Observer<Type>>& observer) { observers_.remove(observer); }

    /**
     * This function notifies the observer when the subject changes
     */
    void notify(const Type& subject) const {
        for (const auto& observer : observers_) {
            observer->update(subject);
        }
    }
};
} // namespace gameModel

#endif // DOODLE_GAME_SUBJECT_H
