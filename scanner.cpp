#include <iostream>
#include <string>

namespace Scanner {
  // lookahead pointer
  // consumer for token
  // string
  // store tokens in array
  enum TokenType {NUMBER, OPERATOR};
  class Scanner {
  private:
    int beginPosition;
    int endPosition;
    int currentPosition;
    int linePosition;
    std::string currentToken;
    std::string inputText;
    std::string inputLength;
    TokenType currentType;
    std::vector<std::string> tokens;

  public:
    Scanner(std::string inputText_) {
      lookahead = 0;
      linePosition = 1;
      inputText = inputText_;
      inputLength = inputText.size();
    }
    void matchToken() {
      std::string start_char = inputText[currentPosition];
      if(std::isdigit(start_char)) {
	std::string matched_digits;
	for(int i=currentPosition; i<inputLength; i++) {
	  std::string current_char = inputText[i];
	  if(std::isdigit(current_char)) {
	    matched_digits.append(current_char);
	    endPosition++;
	  } else break;
	}


      }
    }
  }
}
