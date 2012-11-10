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


#include "Cpu.hpp"

namespace gblxe  {

Cpu::Cpu(Memory* mem, Cart* crt, Video* vid, Sound* snd)
    : memory(mem), cart(crt), video(vid), sound(snd)
{
    // put default value registers
    reset();
}


Cpu::~Cpu()
{
    memory = NULL;
    cart   = NULL;
    video  = NULL;
    sound  = NULL;
}


void
Cpu::reset()
{
    is_halted = false;

    AF = 0x01b0;
    BC = 0x0013;
    DE = 0x00d8;
    HL = 0x014d;
    SP = 0xfffe;
    PC = 0x0100;

    // HW registers
    memory[0xff05] = 0;          // TIMA
    memory[0xff05] = 0;          // TIMA
    memory[0xff05] = 0;          // TIMA
    memory[0xff06] = 0;          // TMA
    memory[0xff07] = 0;          // TAC
    memory[0xff10] = 0x0080;     // NR10
    memory[0xff11] = 0x00bf;     // NR11
    memory[0xff12] = 0x00f3;     // NR12
    memory[0xff14] = 0x00bf;     // NR14
    memory[0xff16] = 0x003f;     // NR21
    memory[0xff17] = 0;          // NR22
    memory[0xff19] = 0x00bf;     // NR24
    memory[0xff11] = 0x007f;     // NR30
    memory[0xff1b] = 0x00ff;     // NR31
    memory[0xff1c] = 0x009f;     // NR32
    memory[0xff1e] = 0x00bf;     // NR33
    memory[0xff20] = 0x00ff;     // NR41
    memory[0xff21] = 0;          // NR42
    memory[0xff22] = 0;          // NR43
    memory[0xff23] = 0x00bf;     // NR30
    memory[0xff24] = 0x0077;     // NR50
    memory[0xff25] = 0x00f3;     // NR51
    memory[0xff26] = 0x00f1;     // NR52
    memory[0xff40] = 0x0091;     // LCDC
    memory[0xff42] = 0;          // SCY
    memory[0xff43] = 0;          // SCX
    memory[0xff45] = 0;          // LYC
    memory[0xff47] = 0x00fc;     // BGP
    memory[0xff48] = 0x00ff;     // OBP0
    memory[0xff49] = 0x00ff;     // OBP1
    memory[0xff4a] = 0;          // WY
    memory[0xff4b] = 0;          // WX
    memory[0xffff] = 0;          // IE
}


void
Cpu::execute()
{

}

}
