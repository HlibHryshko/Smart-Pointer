# smart_pointer
Implementing class that works in the same way as class std::unique_ptr
FUNCTIONS:
- const overloaded get(), which returns the pointer
- release(), which releases the pointer and returns it
- reset(), which resets the pointer with given pointer
- friend function swap(), which swaps 2 pointers;
- bool operators bool() and !
- operators that default pointers have(*, ->)

