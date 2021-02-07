# inheritance.without.pointers

Here we use the magic of C++17's std::any to emulate the inheritance mechanism at compile-time.

The template magic inside interface.hh is a generic wrapper for any interface user wants to implement. User will write
their classes as they usually do, but instead of using a base class pointer to refer to child classes, they will
be using this wrapper via the mechanism of implicit/explicit conversion.


Largely inspired by Jonathan's post: https://www.fluentcpp.com/2021/01/29/inheritance-without-pointers/