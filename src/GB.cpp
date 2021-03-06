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
    cpu     =   new Cpu();
    memory  =   new Memory();
    cart    =   new Cart();
    video   =   new Video();
    sound   =   new Sound();

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
throw(Exception)
{
    if(! cart_present)  
        throw( Exception(Exception::CART_NOT_PRESENT) );

    cpu->init();

    while(1)  {
        cpu->execute();

        /* TODO */
    }
}


void
GB::insert_cart(const std::string& filename)
throw(Exception)
{
    cart.loadRom(filename);
}

}
