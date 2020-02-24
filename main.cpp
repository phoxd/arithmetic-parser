#include <iostream>
#include "Scanner.h"
//#include "Parser.cpp"

int main() {
  std::string sum = "324+45/34 -3425";
  Scanner::Scanner s(sum);
  std::cout << s;
  return 0;
}
