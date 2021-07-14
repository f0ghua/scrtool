#include <iostream>
#include "std_dllapi.h"

//#ifdef __cplusplus
//extern "C"{
//#endif

//void PrScrn();

//#ifdef __cplusplus
//}
//#endif

using namespace std;

int main()
{
//    PrScrn();
    Function<void> f("PrScrn.dll", "PrScrn");

    f();

    cout << "Hello World!" << endl;
    return 0;
}
