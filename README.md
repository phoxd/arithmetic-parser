# Context-free grammar

``` bnf
<expression> :== <expression> '+' <term> | <expression> '-' <term> | <term>
<term> :== <term> '*' <factor> | <term> '/' <factor>
<factor> :== <digit> { <digit> } | '(' <expression ')'
<digit> :== 0..9
```
Taken from page 49 _Compilers: Principles, Techniques, and Tools (2nd Edition)_

## C++ implementation

The easy way is to tokenize string into digits and special symbols. So we could make use of vector with tuple of type enum and string.

``` cpp
std::vector<std::tuple<enum,std::string>> tokens;
```

