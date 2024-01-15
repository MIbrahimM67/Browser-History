#include "BrowserHistory.h"

int main()
{
	BrowserHistroy B1;
	B1.visit("qau.com");
	B1.visit("fbise.com");
	B1.visit("iusui.com");
	B1.visit("pakistan.com");
	std::cout << B1.back(1) << std::endl;
	std::cout << B1.back(1) << std::endl;
	std::cout << B1.back(1) << std::endl;
	std::cout << B1.back(1) << std::endl;
	std::cout << B1.back(1) << std::endl; // exceeds the back limit 
	std::cout << std::endl << "now moving forward" << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl; // exceeds the forward limit
	std::cout << std::endl << "now moving backward 2 steps and visiting a new site in between" << std::endl;

	std::cout << B1.back(2) << std::endl;
	B1.visit("nayapakistan.com"); // visiting a new site in between the others
	std::cout << B1.back(5) << std::endl;

	std::cout << std::endl << "now moving forward again to test if the site  'nayapakistan exists in the last or not" << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;
	std::cout << B1.forward(1) << std::endl;








}

