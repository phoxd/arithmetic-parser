#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

namespace Scanner {
  enum TokenType {NUMBER, OPERATOR};
  class Scanner {
  public:
    std::vector<std::tuple<TokenType, std::string>> tokens;

    Scanner(const std::string &text);
    
    void matchTokens(const std::string &text);

    std::string matchDigits(int position, const std::string &text);
  
    friend std::ostream& operator <<(std::ostream& os, const Scanner& s);
  };
}

#endif

