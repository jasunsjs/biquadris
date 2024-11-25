#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Subject {
    private:
        std::vector<Observer> observers; 
    public:
        void attach( Observer* o );
        void detach( Observer* o );
        void update();
        virtual ~Subject() = default;

};

#endif