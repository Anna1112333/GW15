
#include <iostream>
#include <variant>
#include <vector>


std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;
	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}
void Pr_var(std::variant<int, std::string, std::vector<int >> m)
{
	if (std::holds_alternative<int>(m))
		std::cout << std::get<int>(m);
	else if (std::holds_alternative<std::string>(m))
		std::cout << std::get<std::string>(m);
	else
		for (int x : (std::get<std::vector<int>>(m)))
			std::cout << x << " ";
}

int main()
{
	auto m = get_variant();
	Pr_var(m);
}
