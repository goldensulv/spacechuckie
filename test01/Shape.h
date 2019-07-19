// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

namespace my {

    class Shape
    {
    
    public:
        virtual void update() = 0;

    //  Ease-of-use getters
        virtual float x() const = 0;
        virtual float y() const = 0;
        virtual float left() const = 0;
        virtual float right() const = 0;
        virtual float top() const = 0;
        virtual float bottom() const = 0;
    };

}



#endif /* SHAPE_H */
