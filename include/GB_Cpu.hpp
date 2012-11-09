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


#ifndef __GBLXE_GB_CPU_HPP__
#define __GBLXE_GB_CPU_HPP__


#include <bitset>


namespace gblxe  {


class GB_Cpu
{
    typedef  Register     std::bitset<16>;

    public:
        GB_Cpu();
        ~GB_Cpu();

        void fetch();
        void decode();
        void execute();

        void reset();

    private:
        Register AF;
        Register BC;
        Register DE;
        Register HL;
        Register SP;
        Register PC; 

        GB_Memory* memory;
};


}


#endif
