# UniquePtr.
The template class supports:
1) Default constructor (creates a null pointer).
2) Constructor from pointer (stores a pointer to the object).
3) Moving constructor and moving assignment pass ownership of the object.
4) Release() method, which detaches the class from ownership of the current resource and returns a pointer to it.
5) Reset(T* ptr = nullptr) method, changes the pointer that the object owns (the old resource is removed).
6) Swap(UniquePtr&) method.
7) Get() method, which returns a pointer to the object.
8) The operator* dereferencing operator.
9) The “arrow” operator-> operator.
10) Explicit operator of conversion to bool (operator bool).
