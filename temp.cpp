#include <iostream>
#include <cctype>
int main()
{

	std::cout << "Please enter [Y/N]: ";
	char yesOrNo;
	std::cin >> yesOrNo;

	yesOrNo = toupper(yesOrNo);

	while (yesOrNo != 'Y' && yesOrNo != 'N')
	{
		std::cout << "Error invalid input please try again " << std::endl;
		std::cout << "Please enter [Y/N]: ";
		std::cin >> yesOrNo;
		yesOrNo = toupper(yesOrNo);
	}


	std::cout << "You entered " << yesOrNo << std::endl;

	return 0;
}