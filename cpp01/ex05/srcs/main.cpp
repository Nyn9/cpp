#include <string>
#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string level = "DEBUG";

    harl.complain(level);
    level = "INFO";
    harl.complain(level);
    level = "WARNING";
    harl.complain(level);
    level = "ERROR";
    harl.complain(level);

    return 0;
}