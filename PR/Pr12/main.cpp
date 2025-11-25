#include <iostream>
#include "Array.h"
#include "Struct.h"
#include "Swap.h"
#include "Parameter.h"
#include "Overload.h"
#include "Lambda.h"
#include <algorithm>
#include <string>

int main() {
    // 01 Arrays

    int a[5] = { 0 };
    fill(a);
    for (int x : a)
    {
        std::cout << x << ' ';
    };
    std::cout << std::endl;

    {
        int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
        f(a);
        std::cout << sizeof(a) << std::endl;
    }
    {
        int a[3];  // локальний масив без ініціалізації

        std::cout << std::hex;
        for (int i = 0; i < 3; i++) {
            std::cout << a[i] << " ";  // значення теж "сміттєві"
        }
        std::cout << std::endl;

        std::cout << std::dec;
        for (int i = 0; i < 3; i++) {
            std::cout << a[i] << " ";  // значення теж "сміттєві"
        }
       std:: cout << std::endl;
    }

    // 02 Structures

    Point u{ 1,2 };
    u.move(3, 4);
    std::cout << u << std::endl;
    {
        Point u{ 1,2 };
        std::unique_ptr<Point> p = clone(u);
        std::cout << *p << std::endl;
    }

    // 03. swap
    int x = 5, y = 7;

    swap_p(&x, &y);
    swap_r(x, y);
    std::swap(x, y);
    swap<int>(x, y);

    std::string s1("First");
    std::string s2("Second");
    swap(s1, s2);
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;


    // 04. Initialization
    {
        int a = 5;       // C-style
        int b{ 5 };        // C++-style (safer)
        double x = 0.1;
        //int    n{ x };     // error
    }

    // 05. Type deducing
    {
        int i = 0;
        double d = i + 0.5;
    }
    {
        int i = 0;
        auto d = i + 0.5;
    }
    // Home task: substitute types with proper autos and explain them
    /*
    1.  int x = 5;
    2.  double y = x + 0.5;
    3.  const int c = 10;
    4.  int* p = &x;
    5.  int& r = x;
    6.  const int& cr = x;

    7.  std::vector<int> v = { 1,2,3 };
    8.  std::vector<int>::iterator it = v.begin();
    9.  std::vector<int>::const_iterator cit = v.cbegin();

    10. std::map<std::string, int> m;
    11. std::pair<std::string, int> pr{ "age", 30 };

    12. std::string s = "hello";
    13. std::string::size_type n = s.size();
    14. std::string_view sv = s;

    15. const std::vector<int>&rv = v;
    16. auto f = [](int a, int b) { return a + b; };

    17. int a[3] = { 1,2,3 };
    18. int (*fp)(int, int) = std::max;

    19. std::unique_ptr<int> up = std::make_unique<int>(5);
    20. std::shared_ptr<std::string> sp = std::make_shared<std::string>("hi");
    */

    // 06. Parameter parsing
    {
        A x;
        foo(x);
        bar(x);
        std::cout << f() << std::endl;

        fr(5);
        fr(3 + 5);
        int t = 6;
        //fr(t);
        int& s = t;
        //fr(s);
        int&& ss =5;
        //fr(ss);

        lib::hello();      // → v2::hello()
        lib::v1::hello();  // → стара версія

    }

    {
        // 07. Overloading
        f(5);
        f(5.0);
        //f(5l);
        print(42, 0);                   // Printable: 42
        print(std::string( "hello" ), 0); // Printable: hello
        struct X {};                     // у X немає operator<<
        print(X{}, 0);                  // Not printable


        {
            std::cout << std::boolalpha;

            // std::vector<int> HAS value_type
            std::cout << "vector<int>: "
                << has_value_type_v<std::vector<double>> << "\n";

            // int does NOT have value_type
            std::cout << "int: "
                << has_value_type_v<int> << "\n";

            // user-defined struct WITH value_type
            struct X { using value_type = double; };
            std::cout << "X: "
                << has_value_type_v<X> << "\n";

            // user-defined struct WITHOUT value_type
            struct Y {};
            std::cout << "Y: "
                << has_value_type_v<Y> << "\n";
           
            {
                h(A{});   // calls class-version
                h<int>(5);     // calls fallback
            }
        }


    }

    // 08. Structured binding
    {
        auto [x, y] = Point{ 1,2 };
        auto [a, b] = std::pair{ 3,4 };
        // swap them
    }
     // 09. Traps
    {
       
        int a[3] = { 1,2,3 };
        int* p = a;
        //p[3] = 10;   // ?! UB
        //std::cout << p[3] << std::endl;
    }
    // 10. Pointer
    {
        //auto fp = std::max;    //  deduces overload set
        //int (*fp)(int, int) = std::max<int>;
        //auto fp = static_cast<int(*)(int, int)>(std::max);
        auto fp = static_cast<const int& (*)(const int&, const int&)>(std::max<int>);
        std::cout << fp(1, 2) << std::endl;
    }
    // 11. Lambda closure
    {
        int x = 10;
        auto func0 = [&x]() {
            x += 1; std::cout << "Value in the closure: " << x << std::endl; };

        func0();  // Prints 11
        std::function<void(void)> func1 = closureWrapper();
        func1();  // Prints garbage value + 1 =~ garbage value
    } 
    {
        double pi = 3.1415926;
        // class is not considered to support lexical scoping
        class CircleArea
        {
        public:
            CircleArea()
            {
            }
            double operator() (double r) const
            {
                //return pi * r * r;
                return ::pi * r * r;
            }
        };

        double r = 1.0;
        CircleArea circleArea;
        double area = circleArea(r);
        std::cout << area << std::endl;
    }

    {
        double r = 1.0;
        CircleArea circleArea;
        double area = circleArea(r);
        std::cout << area << std::endl;
    }
    {
        int x = 10;
        auto func0 = [&x]() {x += 1; std::cout << "Value in the closure: " << x << std::endl; };
        std::function<void(void)> func1 = closureWrapper1();
        std::function<void(void)> func2 = closureWrapper2();
        func0();
        func0();
        func0();
        std::cout << "-------------------------" << std::endl;
        func1();
        func1();
        func1();
        std::cout << "-------------------------" << std::endl;
        func2();
        func2();
        func2();
    }
    
    return 0;
}

