#include "main.ih"

void sourceFun1()
{
  PointerUnion const pu = { templateFun };
  cout << "Address of instantiated template function in sourceFun1: "
    << pu.vp << '\n';
}
