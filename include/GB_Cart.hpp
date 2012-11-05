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


#ifndef __GBLXE_GB_CART_HPP__
#define __GBLXE_GB_CART_HPP__


#include <fstream>

#include "GBException.hpp"


namespace gblxe  {


class GB_Cart
{
    public:
        enum ROMType 
            { 
            ROM_ONLY,
            ROM_MBC1,                 
            ROM_MBC1_RAM,
            ROM_MBC1_RAM_BATT,
            ROM_MBC,
            ROM_MBC2_BATTERY,        
            ROM_RAM,        
            ROM_RAM_BATTERY,         
            ROM_MMM01,         
            ROM_MMM01_SRAM,          
            ROM_MMM01_SRAM_BATT,
            ROM_MBC3_TIMER_BATT,     
            ROM_MBC3_TIMER_RAM_BATT,
            ROM_MBC3,
            ROM_MBC3_RAM,
            ROM_MBC3_RAM_BATT,
            ROM_MBC5,
            ROM_MBC5_RAM,
            ROM_MBC5_RAM_BATT,
            ROM_MBC5_RUMBLE,
            ROM_MBC5_RUMBLE_SRAM,
            ROM_MBC5_RUMBLE_SRAM_BATT,
            Pocket_Camera,
            Bandai_TAMA5,
            Hudson_HuC_1,
            Hudson_HuC_3,

            NONE
            };

    private:
        static const unsigned char nintento_logo[] =
                    {
                    "\xce\xed\x66\x66\xcc\x0d\x00\x0b\x03\x73\x00\x83"
                    "\x00\x0c\x00\x0d\x00\x08\x11\x1f\x88\x89\x00\x0e"
                    "\xdc\xcc\x6e\xe6\xdd\xdd\xd9\x99\xbb\xbb\x67\x63"
                    "\x6e\x0e\xec\xcc\xdd\xdc\x99\x9f\xbb\xb9\x33\x3e"
                    };

    public:
        GB_Cart();
        ~GB_Cart();

        void loadRom(std::string&) throw(GBException);

    private:
        ROMType type;

        unsigned long romSize;
        unsigned long ramSize;
        std::string title;

        unsigned char* data;

        bool is_loaded;
};


}


#endif
