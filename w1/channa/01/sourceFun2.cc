#include "main.ih"

void sourceFun2()
{
  PointerUnion pu = { templateFun };
  cout << "Address of instantiated template function in sourceFun2: "
       << pu.vp << '\n';
}