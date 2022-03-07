#ifndef GENCLS_REG_HPP_INCLUDED
#define GENCLS_REG_HPP_INCLUDED
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


#include "Bit_utils.h"
#include "Std_types.h"
template<class T , class t>
class REG
{
    private :
        string permission;
        T *Reg_Ptr;
    public :
        REG(T *p ,string per);
        string setRegisterValue(t value);
        T getRegisterValue();
        string setBit(u8 Bit_num);
        string clearBit(u8 Bit_num);
        T getBit(u8 Bit_num);
        string setPermission(string per);
        ~REG();
};



//#include "GenCls_REG.hpp"


        template<class T , class t>
        REG<T,t>::REG (T *p ,string per)
        {
            if(sizeof(t) <= sizeof(T))
            {
                permission=per;
                Reg_Ptr=p;
                cout << "constructor done correct" << endl;
            }
            else
            {
               cout << "ERROR : size of max num bits > size of register" << endl;
            }



        }
        template<class T , class t>
        string REG<T,t>:: setRegisterValue(t value)
        {
            if(sizeof(t) <= sizeof(T) && (permission=="WRITE" | permission=="R/W"))
            {
                *Reg_Ptr = value;
                return "done";
            }
            else
            {
                return "permission denied";
            }

        }
        template<class T , class t>
        T REG<T,t>::getRegisterValue()
        {
            if(sizeof(t) <= sizeof(T) && (permission=="R/W" | permission=="READ"))
            {
                return *Reg_Ptr;
            }
            else
            {
                return "done";
            }

            return "permission denied";

        }
        template<class T , class t>
        string REG<T,t>::setBit(u8 Bit_num)
        {
            if(sizeof(t) <= sizeof(T) && (permission=="WRITE" | permission=="R/W"))
            {
                SET_BIT(*Reg_Ptr,Bit_num);
                return "done";

            }
            else
            {
                return "permission denied";
            }


        }
        template<class T , class t>
        string REG<T,t>:: clearBit(u8 Bit_num)
        {
             if(sizeof(t) <= sizeof(T) && (permission=="WRITE" | permission=="R/W"))
            {
                CLR_BIT(*Reg_Ptr,Bit_num);
                return "done";

            }
            else
            {
                return "permission denied";
            }


        }
        template<class T , class t>
        T REG<T,t>:: getBit(u8 Bit_num)
        {
            if(sizeof(t) <= sizeof(T) && (permission=="READ" | permission=="R/W"))
            {
               return GET_BIT(*Reg_Ptr,Bit_num);

            }
            else
            {
                return "permission denied";
            }


        }
        template<class T , class t>
        string REG<T,t>::setPermission(string per)
        {


            if(sizeof(t) <= sizeof(T) && (per=="WRITE" | per=="READ" | per=="R/W" | per=="REVERSED"))
            {
                permission=per;
                return "done";
            }
            else
            {
                return "permission denied";
            }

        }
        template<class T , class t>
        REG<T,t>::~REG()
        {
            cout << "desss" << endl;
            CLR_REG(*Reg_Ptr);
        }



#endif // GENCLS_REG_HPP_INCLUDED


