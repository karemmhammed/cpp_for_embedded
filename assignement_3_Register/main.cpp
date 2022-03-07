#include "GenCls_REG.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;





int main()
{
    u8 portA;
    string status;
    u8 *p = &portA;
    string per="WRITE";
    REG<u8 , u16> port(p , per);
    status = port.setRegisterValue(500);
    cout << status << endl;
    status = port.setPermission(per);
    cout << status << endl;
    status = port.setRegisterValue(255);
    cout << status << endl;
    status = port.setBit(2);
    cout << status << endl;

return 0;
}

