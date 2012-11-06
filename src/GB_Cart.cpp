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
    type = NONE;
    romSize = 0;
    ramSize = 0;
}


GB_Cart::~GB_Cart()
{
}


void
GB_Cart::loadRom(const std::string& filename)
throw(GBException)
{
    std::ifstream f(filename.c_str(), std::ios::binary);
    int i;
    unsigned char checksum = 0;

    static const unsigned char nintendo_logo[] =
                "\xce\xed\x66\x66\xcc\x0d\x00\x0b\x03\x73\x00\x83"
                "\x00\x0c\x00\x0d\x00\x08\x11\x1f\x88\x89\x00\x0e"
                "\xdc\xcc\x6e\xe6\xdd\xdd\xd9\x99\xbb\xbb\x67\x63"
                "\x6e\x0e\xec\xcc\xdd\xdc\x99\x9f\xbb\xb9\x33\x3e";


    if(f.is_open())  {
        f.seekg(0, std::ios::end);
        fileSize = f.tellg();
        f.seekg(0);

        data = new unsigned char[fileSize];

        f.read((char*)data, fileSize);

        // Check nintendo logo (0x0104-0x0134)
        for(i = 0x0104; i <= 0x0133; i++)  {
            if(data[i] != nintendo_logo[i-0x0104])  {
                throw( GBException(GBException::WRONG_NINTENDO_LOGO) );
            }
        }

        // Get ROM title(16 chars, 0 filled)
        for(i = 0x0134; i < (0x0134 + 16); i++)  {
            title[i] = data[i];
        }

        // Get CGB Flags
        cgb = data[0x0143];

        // Get ROM type
        type = ROMType(data[0x0147]);

        // Get ROM size
        switch(data[0x0148])  {
            case 0x00:     // 32KByte
                romSize = 32 * 1024;
                break;
            case 0x01:     // 64KByte
                romSize = 64 * 1024;
                break;
            case 0x02:     // 128KByte
                romSize = 128 * 1024;
                break;
            case 0x03:     // 256KByte
                romSize = 256 * 1024;
                break;
            case 0x04:     // 512KByte
                romSize = 512 * 1024;
                break;
            case 0x05:     // 1MByte
                romSize = 1024 * 1024;
                break;
            case 0x06:     // 2MByte
                romSize = 2 * 1024 * 1024;
                break;
            case 0x07:     // 4MByte
                romSize = 4 * 1024 * 1024;
                break;
            case 0x52:     // 1.1MByte
                romSize = 1024 * 1024 + 100 * 1024;
                break;
            case 0x53:     // 1.2MByte
                romSize = 1024 * 1024 + 200 * 1024;
                break;
            case 0x54:     // 1.5MByte
                romSize = 1024 * 1024 + 500 * 1024;
                break;
        }

        // Get internal RAM size
        switch(data[0x0149])  {
            case 0x00:    // None
                ramSize = 0;
                break;
            case 0x01:
                ramSize = 2 * 1024;   // 2KByte
                break;
            case 0x02:
                ramSize = 8 * 1024;   // 4KByte
                break;
            case 0x03:
                ramSize = 32 * 1024;  // 32KByte
                break;
        }

        // Calulate header checksum, and compare wiht one in the cart
        for(i = 0x0134; i <= 0x014d; i++)  {
            checksum += data[i];
        }

        checksum += 25;

        if((checksum & 0xff) != 0)
            throw( GBException(GBException::BAD_HEADER_CHECKSUM) );
        else
            is_loaded = true;
    } else  {
        throw( GBException(GBException::CANNOT_OPEN_ROM_FILE) );
    }
}


}
