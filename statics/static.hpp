#ifndef STATIC_HPP
#define STATIC_HPP

struct API
{
    // Constructor
    API();
    // Destructor
    ~API();
    // Static member variables
    static const int POSITIVE;
    static const int NEGATIVE;
    // Static member functions
    static int getPositive();
    static int getNegative();
};

#endif