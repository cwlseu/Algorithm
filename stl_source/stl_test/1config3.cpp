#include <iostream>
using namespace std;
class alloc{

};
template <class T, class Alloc = alloc>
class vector{
public:
	void swap(vector<T, Alloc>&)
	{
		std::cout << "swap()" <<std::endl;
	};
	// #ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
	inline void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		std::cout << "swap inline" << std::endl;
		x.swap(y);
	}
	// #endif
};
int main(int argc, char const *argv[])
{
	vector<int> x,y;
	x.swap(y);
	x.swap(x, y);
	return 0;
}
