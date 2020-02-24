#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Scanner.h"

namespace Scanner {
  Scanner::Scanner(const std::string &text) {
    Scanner::matchTokens(text);
  }
    
  void Scanner::matchTokens(const std::string &text) {
    if(text.size() == 0) return;
    int line_position = 1;
    int position = 0;

    while (position < text.size()) {
      char current_char = text[position];
      switch(current_char) {
      case '\n':
	line_position++;
      case '\r':
      case '\t':
      case ' ':
	position++;
	break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	{
	  std::string token = matchDigits(position, text);
	  tokens.push_back(std::make_tuple(NUMBER, token));
	  position += token.size();
	  break;
	}
      case '+':
      case '-':
      case '*':
      case '/':
      case '(':
      case ')':
	tokens.push_back(std::make_tuple(OPERATOR, std::string(1, current_char)));
	position++;
	break;
      default:
	std::printf("Unexpected character (%c) at line %d and position %d\n", current_char, line_position, position);
	return;
      }
    }

  }

  std::string Scanner::matchDigits(int position, const std::string &text) {
    std::string digits;
    for(int i=position, len=text.size(); i<len; i++) {
      if(std::isdigit(text[i])) {
	digits += text[i];
      } else break;
    }
    return digits;
  }
  
  std::ostream& operator <<(std::ostream& os, const Scanner& s) {
    for(int i=0, len=s.tokens.size(); i<len; i++) {
      if(i > 0) os << ", ";
      os << std::get<1>(s.tokens[i]);
    }
    os << std::endl;
    return os;
  }
}

