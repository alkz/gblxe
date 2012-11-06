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


#include "GB.hpp"


namespace gblxe  {


GB::GB()
{
    cpu     =   new GB_Cpu();
    memory  =   new GB_Memory();
    cart    =   new GB_Cart();
    video   =   new GB_Video();
    sound   =   new GB_Sound();

    cart_present = false;
}


GB::~GB()
{
    if(cpu)  {
        delete cpu;
    }

    if(memory)  {
        delete memory;
    }

    if(cart)  {
        delete cart;
    }

    if(video)  {
        delete video;
    }

    if(sound)  {
        delete sound;
    }
}


void
GB::run()
throw(GBException)
{
    if(! cart_present)  
        throw( GBException(GBException::CART_NOT_PRESENT) );

    while(1)  {
        cpu->fetch();
        cpu->decode();
        cpu->execute();

        /* TODO */
    }
}


void
GB::insert_cart(const std::string& filename)
throw(GBException)
{
    cart.loadRom(filename);
}


}
