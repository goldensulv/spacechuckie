// Collidable.cpp

#include "Collidable.h"

namespace my {

    bool Collidable::areColliding(Shape& a, Shape& b)
    {
        return ((a.right() >= b.left() && (a.y() <= b.top() && a.y() >= b.bottom()))
            ||  (a.bottom() >= b.top() && (a.x() <= b.right() && a.x() >= b.left()))
            ||  (a.left() <= b.right() && (a.y() <= b.top() && a.y() >= b.bottom())));
    }

} //end my
