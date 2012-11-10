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


#ifndef __GBLXE_CPU_HPP__
#define __GBLXE_CPU_HPP__

#include "Types.hpp"

namespace gblxe  {

class Cpu
{
    public:
        Cpu(Memory*, Cart*, Video*, Sound*);
        ~Cpu();

        void reset();

    private:
        Register AF;
        Register BC;
        Register DE;
        Register HL;
        Register SP;
        Register PC; 

        Memory*   memory;
        Cart*     cart;
        Video*    video;
        Sound*    sound;
};

}

#endif
