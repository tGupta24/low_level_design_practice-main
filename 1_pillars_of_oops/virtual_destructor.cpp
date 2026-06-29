// 🔹 Virtual Destructor in C++

// Definition (short):
// A virtual destructor ensures that when a base class pointer points 
// to a derived class object and we delete the pointer, 
// both base and derived destructors are called properly.

// Why used?
// - To avoid memory leaks when deleting derived objects through base pointers.
// - Without virtual destructor → only base destructor runs, derived resources not freed.
// - With virtual destructor → derived destructor runs first, then base destructor.

// Example:
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base created\n"; }
    virtual ~Base() { cout << "Base destroyed\n"; } // ✅ virtual
};

class Derived : public Base {
public:
    Derived() { cout << "Derived created\n"; }
    ~Derived() { cout << "Derived destroyed\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  
    return 0;
}

/*
Output with virtual destructor:
Base created
Derived created
Derived destroyed
Base destroyed

Without virtual destructor:
Base created
Derived created
Base destroyed   // ❌ Derived destructor skipped
*/
