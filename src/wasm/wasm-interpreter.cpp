#include "wasm-interpreter.h"

namespace wasm {

Flow::Flow() {
}

Flow::Flow(Literal value) : value(value) {
}

Flow::Flow(Name breakTo) : breakTo(breakTo) {
}

bool Flow::breaking() { 
   return breakTo.is(); 
}

void Flow::clearIf(Name target) {
   if (breakTo == target) 
         breakTo.clear();
}

#ifdef WASM_INTERPRETER_DEBUG
int Indenter::indentLevel = 0;

Indenter::Indenter(const char* entry) : entryName(entry) {
  ++indentLevel;
}
Indenter::~Indenter() {
  print();
  std::cout << "exit " << entryName << '\n';
  --indentLevel;
}
void Indenter::print() {
  std::cout << indentLevel << ':';
  for (int i = 0; i <= indentLevel; ++i) {
    std::cout << ' ';
  }
}
#endif // WASM_INTERPRETER_DEBUG

} // namespace wasm
