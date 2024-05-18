# SBLib
A library meant to serve as a competitor to the standard library.

## Points of Discussion

- Header only library or translation unites
- What needs a strict api vs open, a more public and open interface
- Do we need to standardize our primitives? (yes, short and long are implementation dependent)
    - Can we just used stdint?
    - Or should we add our own
- Do we need our own allocator? (probably not)
- How do we handle iterators?
   - C++ method (each class has their iterator definition with the same interface)
   - Inheritance (create a common iterator interface, then each classes iterator inherits from that)
       - Does this work?
