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


#include "Register.hpp"

namespace gblxe  {

std::string
Register8::toString() const
{
    u8 tmp = value;
    std::string toReturn = "";

    while(tmp)  {
        toReturn += ((tmp%2)+'0');
        tmp /= 2;
    }

    for(int i = toReturn.length(); i < 8; i++)  {
        toReturn += "0";
    }
    std::reverse(toReturn.begin(), toReturn.end());
    return toReturn;
}


Register16&
Register16::operator++(int)
{
    u16 value = (low.get() + (high.get() << 8))+1;
    low.set(value & 0xff);
    high.set( (value >> 8) & 0xff );

    return *this;
}


Register16&
Register16::operator--(int)
{
    u16 value = (low.get() + (high.get() << 8))-1;
    low.set(value & 0xff);
    high.set( (value >> 8) & 0xff );

    return *this;
}

}
