# DataStructures
## C++ practice

Practice OOP basics and algorithms


## Notes to self
1. DeckOfCards reminds me of the move semantics and r-value reference. It is only used for implementing operator= function! It makes it possible to assign something to the parameter.
See this [link](https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners)
2. As shown with this [link](https://stackoverflow.com/questions/15704565/efficient-way-to-return-a-stdvector-in-c), it's fine
to return a local vector after C++11, because `vector` has move semantics, the local vector will be moved on return. As this awesome [Post](https://isocpp.org/blog/2013/02/no-really-moving-a-return-value-is-easy-stackoverflow) explains.
3. Use C++17 optional for nullable things. Check out the [Examples](https://en.cppreference.com/w/cpp/utility/optional).
Here's a [better one](https://devblogs.microsoft.com/cppblog/stdoptional-how-when-and-why/)
4. Run `cmake .` and `make` to get the executable. Run `git clean -d -f -x` for cleaning untracked files.
5. Subclass calling superclass constructor with initialization lists.
6. Vector concatenation, copy construction. (DeckOfCards.cpp)