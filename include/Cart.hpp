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


#ifndef __GBLXE_CART_HPP__
#define __GBLXE_CART_HPP__

#include <fstream>
#include <string>

#include "Types.hpp"
#include "Exception.hpp"

namespace gblxe  {

class Cart
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


    public:
        Cart();
        ~Cart();

        void loadRom(const std::string&) throw(Exception);

    private:
        ROMType type;

        unsigned long romSize;
        unsigned long ramSize;
        unsigned long fileSize;

        std::string title;
        u8 cgb;

        u8* data;

        bool is_loaded;
};

}

#endif
