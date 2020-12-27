#include <iostream>
std::string red() { return "\033[0;31m"; }
std::string boldRed() { return "\033[1;31m"; }
std::string green() { return "\033[0;32m"; }
std::string boldGreen() { return "\033[1;32m"; }
std::string yellow() { return "\033[0;33m"; }
std::string boldYellow() { return "\033[1;33m"; }
std::string blue() { return "\033[0;34m"; }
std::string boldBlue() { return "\033[1;34m"; }
std::string magenta() { return "\033[0;35m"; }
std::string boldMagenta() { return "\033[1;35m"; }
std::string cyan() { return "\033[0;36m"; }
std::string boldCyan() { return "\033[1;36m"; }

std::string reset() { return "\033[0m"; }