/****************************************************************************
* This file is part of gblxe.                                               *
* Copyleft alkz                                                             *
*                                                                           *
* gblxe is free software: you can redistribute it and/or modify             *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation, either version 3 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* xzHTTPd is distributed in the hope that it will be useful.                *
* but WITHOUT ANY WARRANTY; without even the implied warranty o.            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See th.              *
* GNU General Public License for more details.                              *
*                                                                           *
* You should have received a copy of the GNU General Public License         *
* along with xzHTTPd. If not, see <http://www.gnu.org/licenses/>.           *
****************************************************************************/


#ifndef __GBLXE_REGISTER_HPP__
#define __GBLXE_REGISTER_HPP__


#include "Types.hpp"


namespace gblxe  {

class Register8
{
    public:
        Register8() {};
        Register8(u8 _value) : value(_value) {};
        ~Register8() {};

        void setBit(u8 bit) { if(bit < 8) value |= (1<<bit); };
        void clearBit(u8 bit) { if(bit < 8) value ^= (1<<bit); };

        void set(u8 _value) { value = _value; };
        u8 get() const { return value; };

        std::string toString() const;

    public:
        Register8& operator++(int) { value++; return *this; };
        Register8& operator--(int) { value--; return *this; };

    private:
        u8 value;
};


class Register16
{
    public:
        Register16() {};
        Register16(u16 value) : high( (value >> 8) & 0xff ), low( value & 0xff ) {};
        ~Register16() {};

        void setBit(u8 bit)   { if(bit < 16) { (bit >= 8) ? high.setBit(bit-8) : low.setBit(bit); } };
        void clearBit(u8 bit) { if(bit < 16) { (bit >= 8) ? high.clearBit(bit-8) : low.clearBit(bit); } };

        Register8* getLow() { return &low; }; 
        Register8* getHigh() { return &high; }; 

        void set(u16 value) { high.set( (value >> 8) & 0xff ); low.set(value & 0xff); };
        u16 get() const { return ( (high.get() << 8) + low.get() ); };

        std::string toString() const { return (high.toString() + low.toString()); };

    public:
        Register16& operator++(int);
        Register16& operator--(int);

    private:
        Register8 low;
        Register8 high;
};

}

#endif
