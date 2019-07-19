// Collidable.h
#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "Shape.h"

namespace my {

    class Collidable
    {

    public:
        virtual ~Collidable() {};

        static bool areColliding(Shape& a, Shape& b);

    };

} //end my


#endif /* COLLIDABLE_H */
