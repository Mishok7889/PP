#include <iostream>

int main()
{
    {
        int x = 10;
        int* p = &x;

        std::cout << "x = " << x << "\n";
        std::cout << "&x = " << &x << "\n";
        std::cout << "p = " << p << "\n";
        std::cout << "*p = " << *p << "\n";
    }
    {
        int x = 10;
        int* p = &x;
        *p = 20;

        std::cout << "x = " << x << "\n"; // 20
    }
    {
        int y = 5;
        int& r = y;

        std::cout << "y = " << y << ", r = " << r << "\n";
        r = 15;
        std::cout << "y = " << y << ", r = " << r << "\n"; // both 15
    }
    {
        int z = 7;
        int& r1 = z;
        int& r2 = z;

        r1 = 50;
        std::cout << "z = " << z << ", r2 = " << r2 << "\n"; // every one 50
    }
    {
        int a = 3;
        int* p = &a;
        int** pp = &p;

        std::cout << "a = " << a << "\n";
        std::cout << "*p = " << *p << "\n";
        std::cout << "**pp = " << **pp << "\n";
    }
    {
        int* q = nullptr;

        if (q == nullptr)
            std::cout << "q is null: "<<q<<'\n';
    }
    {
        int m = 1, n = 2;

        // The link must be initialized immediately.
        int& ref = m;
        // int& bad; // ❌ error: uninitialized link

        // A pointer can be declared without initialization.
        int* p;
        p = &m; // now points to m
        p = &n; // now points to n

        // Link is "pinned" permanently
        // ref = n; // this is not a reassignment! ref remains an alias for m,
        // and simply writes the value of variable n into m

        std::cout << "m = " << m << ", ref = " << ref << "\n";
        std::cout << "p -> " << *p << "\n";
    }
    {
        {
            std::cout << "=== nullptr and pointer arithmetic ===\n";

            int* q = nullptr;          // null pointer
            int* p = q + 1;            // pointer arithmetic
            //nullptr + 1; Error

            std::cout << "q (nullptr) = " << q << "\n";
            std::cout << "p = q + 1 = " << p << " (sizeof(int) added)\n";

            if (q) std::cout << "q is not null\n";
            else std::cout << "q is null\n";

            if (p) std::cout << "p is not null\n"; // will print, because p == 4 (or sizeof(int))
            else std::cout << "p is null\n";

            // Dereferencing p is unsafe!
            // Uncommenting the next line will likely crash the program:
            // int k = *p; //undefined behavior

            q = new int(10);
            p = new int(20);
            std::cout << "p= " << p << (std::dec) <<':' << (std::size_t)p << std::endl;
            std::cout << "q= " << q << (std::dec) <<':' << (std::size_t)q << std::endl;

            if (p > q)
                std::cout << "q is first" << std::endl;
            else
                std::cout << "p is first" << std::endl;

            std::cout << "p-q= " << p - q << std::endl;
            delete p;
            //std::cout << *p << std::endl;
            {
                int k = 100;
                delete q;
                q = &k;
            }
            std::cout << *q << std::endl;
            { 
                int n = 200; 
            }
            std::cout << *q << std::endl;
            *q = 300;
            std::cout << *q << std::endl;
            std::cout << "\n=== bad_alloc example ===\n";
            try {
                int* p = new int(42); // allocate memory for one int
                std::cout << "Success: *p = " << *p << "\n";
                delete p; // free memory
            }
            catch (std::bad_alloc& e) {
                std::cout << "Allocation failed: " << e.what() << "\n";
            }

            try {
                // trying to allocate a huge amount of memory
                size_t n = static_cast<size_t>(-1);
                int* arr = new int[n]; // this throws std::bad_alloc
                delete[] arr;
            }
            catch (std::bad_alloc& e) {
                std::cout << "Caught bad_alloc: " << e.what() << "\n";
            }

            std::cout << "Program continues safely after bad_alloc.\n";
            {
                size_t n = 1e9;
                int* arr = new(std::nothrow) int[n]; // не кидає виняток
                if (!arr) {
                    std::cout << "Could not allocate memory (nullptr)\n";
                }
                else {
                    std::cout << "Array created!\n";
                    delete[] arr;
                }
            }
            {
                size_t n = static_cast<size_t>(-1);
                int* arr = new(std::nothrow) int[n]; // не кидає виняток
                if (!arr) {
                    std::cout << "Could not allocate memory (nullptr)\n";
                }
                else {
                    std::cout << "Array created!\n";
                    delete[] arr;
                }
            }
        }
        
    }
}