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


#include "GBException.hpp"


namespace gblxe  {

GBException::GBException(unsigned int code)
{
    switch(code)  {
        case CART_NOT_PRESENT:
            description = "Game Boy cartridge is not present, call insert_cart(filename) method.";
            break;

        case CANNOT_OPEN_ROM_FILE:
            description = "Cannot Open rom file, check path or permissions.";
            break;

        case WRONG_NINTENDO_LOGO:
            description = "Incorrect Rom file(Bad NintendoLogo).";
            break;

        default:
            description = "You did it wrong.";
    }
}


GBException::~GBException()
{
}


const char*
GBException::what()
{
    return descprition.c_str();
}


}
