        #include "GenCls_REG.hpp"


        template<class T , class t>
        REG<T,t>::REG (T *p ,u8 per)
        {
            permission=per;
            Reg_Ptr=p;

        }
        template<class T , class t>
        u8 REG<T,t>:: setRegisterValue(t value)
        {
            if(sizeof(t) <= sizeof(T) && permission==1)
            {
                *Reg_Ptr = value;
            }
            else
            {
                return 1;
            }
            return 0;
        }
        template<class T , class t>
        T REG<T,t>::getRegisterValue()
        {
            if(permission==0 | permission==2)
            {
                return *Reg_Ptr;
            }
            else
            {
                return 1;
            }

            return 0;

        }
        template<class T , class t>
        u8 REG<T,t>::setBit(u8 Bit_num)
        {
            if(permission==1 | permission==2 )
            {
                SET_BIT(*Reg_Ptr,Bit_num);
                return 0;

            }
            else
            {
                return 1;
            }


        }
        template<class T , class t>
        u8 REG<T,t>:: clearBit(u8 Bit_num)
        {
             if(permission==1 | permission==2 )
            {
                CLR_BIT(*Reg_Ptr,Bit_num);
                return 0;

            }
            else
            {
                return 1;
            }


        }
        template<class T , class t>
        T REG<T,t>:: getBit(u8 Bit_num)
        {
            if(permission==0 | permission==2)
            {
               return GET_BIT(*Reg_Ptr,Bit_num);

            }
            else
            {
                return 1;
            }


        }
        template<class T , class t>
        u8 REG<T,t>::setPermission(u8 per)
        {
            permission=per;
            return 0;
        }
        template<class T , class t>
        REG<T,t>::~REG()
        {
            CLR_REG(*Reg_Ptr);
        }
