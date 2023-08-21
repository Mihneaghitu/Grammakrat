#ifndef GRAMMA_KRAT
#define GRAMMA_KRAT

#include <string>
#include <variant>

enum ErrorType {
  notAnError,
  unexpectedChar,
  unexpectedString,
  unexpectedEof,
  expectedEof
  /* add more */
};

struct ErrorResult {
  ErrorType errorType;
  std::string message;
  int line;
  int column;

  ErrorResult() {}
  ErrorResult(ErrorType errType, std::string msg): errorType(errType), message(msg), line(0), column(0) {}
  ErrorResult(ErrorType errType, std::string msg, int l, int c): errorType(errType), message(msg), line(l), column(c) {}
};

template<typename T>
struct SuccessResult {
  std::string remaining;
  T* parsed;

  SuccessResult() {}
  SuccessResult(std::string rem, T* alreadyParsed): remaining(rem), parsed(alreadyParsed) {}
};

template<typename T>
struct ParseResult {
  bool isSuccess;
  ErrorResult errorResult;
  SuccessResult<T> successResult;

  ParseResult(ErrorResult errRes) : isSuccess(false), errorResult(errRes) {}
  ParseResult(SuccessResult<T> succRes) : isSuccess(true), successResult(succRes)  {}
};

template<typename T>
using Parser = ParseResult<T> (*)(std::string);

class Combinators {
  public:
    Parser<char> anyChar;

};

extern Combinators*  assignCombinators();


#endif
