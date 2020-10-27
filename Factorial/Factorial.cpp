#include <iostream>

int factorial(const int n) {
	int f = 1;
	for (size_t i = 1; i <= n; i++)
	{
		f = f * i;
	}
	return f;
}

int main() {
	std::cout << "Enter n: ";
	int n;
	std::cin >> n;
	std::cout << factorial(n);
	return 0;
}