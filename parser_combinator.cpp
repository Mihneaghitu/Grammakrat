#include "parser_combinator.h"
#include <malloc.h>
#include <iostream>

ParseResult<char> parseAnyChar(std::string input) {
  if (input.empty()) {
    ErrorResult errRes(ErrorType::unexpectedEof, "Input cannot be empty");
    ParseResult<char> parseResult(errRes);
    return parseResult;
  }

  char* parsed = &input[0];
  std::string remaining = input.substr(1, std::string::npos);
  SuccessResult<char> anyCharRes(remaining, parsed);
  ParseResult<char> parseResult(anyCharRes);

  return parseResult;
}

Combinators* assignCombinators() {
  Combinators* combinators = (Combinators *) malloc(sizeof(Combinators));
  combinators->anyChar = parseAnyChar;

  return combinators;
}

int main() {
  std::string input = "hello";

  Combinators* combinators = assignCombinators();

  ParseResult<char> pr = combinators->anyChar(input);
  std::cout << pr.isSuccess << " " << *pr.successResult.parsed << " " << pr.successResult.remaining;
  return 0;
}
