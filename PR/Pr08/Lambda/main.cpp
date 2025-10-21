#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
// Invent a couple of examples for each case
struct Point
{
	double _x, _y;
};
int main()
{
	// A simple lambda call
	cout << [](int x)->int {return x * x; }(2) << endl;

	// Parameters by value
	[](double x) {return ++x * x; };

	// Memorising a lambda
	auto sqr = [](double x) {return x * x; };
	
	// A structure as parameter
	cout << [](const Point& u) { return sqrt(u._x * u._x + u._y * u._y); }({ 3,4 }) << endl;
	
	// Capture another lambda
	cout << [sqr](const Point& u) { return sqrt(sqr(u._x) + sqr(u._y)); }({ 3,4 }) << endl;
	
	// Pointer as parameter
	Point* p = new Point{ 3,4 };
	cout << [](const Point* u) { return sqrt(u->_x * u->_x + u->_y * u->_y); }(p) << endl;
	
	// Capture values
	double a = 1, b = 2;
	cout << [a, b](const double x) { return 1 / sqrt(a * sin(x) * sin(x) + b * cos(x) * cos(x)); } (1) << endl;
	
	// Capture values and lambda together
	cout << [a, b, sqr](const double x) { return 1 / sqrt(a * sqr(sin(x)) + b * sqr(cos(x))); } (1) << endl;
	
	// Capture reference
	double v[] = { 1,2,3,4,5,6,7,8,9,10 };
	double sum = 0;
	for (double x : v)
	{
		[&sum](double x) {
			sum += x; }(x);
	};
	cout << sum << endl;

	// Capture array
	int k = 0;
	for (double x : v)
	{
		[&v, &k]() {++*(v + k++); }();
	}
	for (double x : v)
	{
		cout << x << ' ';
	};
	cout << endl;

	//Capture all values
	[=](const double x) { return 1 / sqrt(a * sin(x) * sin(x)+ b * cos(x) * cos(x));}(1);

	//Capture all references
	[&]() {double aa = a, bb = b; a = sqrt(aa * bb); b = (aa + bb) / 2; };
	a = 1; b = 2;
	while (a < b)
		[&]() {double aa = a, bb = b; a = sqrt(aa * bb); b = (aa + bb) / 2; }();
	cout << a << ',' << b << endl;

	// Quasi-generic
	auto add = [](auto a, auto b) {
		return a + b;
		};
	std::cout << add(2, 3) << "\n";     // 5
	std::cout << add(2.5, 3.1) << "\n"; // 5.6

	// Specifying result type
	auto length = [](const std::string& str) -> size_t {
		return str.length();
		};
	std::cout << "Length: " << length("Hello") << std::endl;

	// A reserve for the future
	{
		std::vector<int> v = { 1, 2, 3, 4, 5 };
		int total = 0;
		std::for_each(v.begin(), v.end(), [&total](int x) {
			total += x;
			});
		std::cout << "Sum via lambda and for_each = " << total << "\n";
	}
	
	{
		auto printSize = []<typename T>(const T & container) {
			if constexpr (requires { container.size(); }) {
				std::cout << "size = " << container.size() << "\n";
			}
			else {
				std::cout << "Type has no size()\n";
			}
		};
		Point w{ 1, 2 };
		std::vector<int> vv = { 1,2,3 };
		std::string s = "hello";
		printSize(w);
		printSize(vv); // “size = 3”
		printSize(s); // “size = 5”
	}
}