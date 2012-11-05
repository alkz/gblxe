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


#include "GB_Cart.hpp"


namespace gblxe  {


GB_Cart::GB_Cart()
{
    is_loaded = false;
    type = ROMType::NONE;
    romSize = 0;
    ramSize = 0;
}


GB_Cart::~GB_Cart()
{
}


void
GB_Cart::loadRom(std::string& filename)
{
    std::ifstream f(filename.c_str());

    if(f.is_open())  {
        f.seekg(0, std::ios::end);
        romSize = f.tellf();
        f.seekg(0);

        f.read(data, romSize);

        // Check nintendo logo (0x0104-0x0134)
        f.seekg(0x104);
        for(int i = 0; i < (0x0134-0x0104)+1; i++)  {
            if(data[i] != nintendo_logo[i])  {
                throw(GBException::WRONG_NINTENDO_LOGO);
            }
        }

        // ...

    } else  {
        throw(GBException::CANNOT_OPEN_ROM_FILE);
    }
}


}
