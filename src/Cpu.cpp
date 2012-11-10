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
    total_cycles = 0;
    interrupt_enabled = true;

    register_file[AF] = 0x01b0;
    register_file[BC] = 0x0013;
    register_file[DE] = 0x00d8;
    register_file[HL] = 0x014d;
    register_file[SP] = 0xfffe;
    register_file[PC] = 0x0100;


    // HW registers
    memory[TIMA] = 0;          // TIMA
    memory[TMA] = 0;           // TMA
    memory[TAC] = 0;           // TAC
    memory[NR10] = 0x0080;     // NR10
    memory[NR11] = 0x00bf;     // NR11 
    memory[NR12] = 0x00f3;     // NR12
    memory[NR14] = 0x00bf;     // NR14
    memory[NR21] = 0x003f;     // NR21
    memory[NR22] = 0;          // NR22
    memory[NR24] = 0x00bf;     // NR24
    memory[NR30] = 0x007f;     // NR30
    memory[NR31] = 0x00ff;     // NR31
    memory[NR32] = 0x009f;     // NR32
    memory[NR33] = 0x00bf;     // NR33
    memory[NR41] = 0x00ff;     // NR41
    memory[NR42] = 0;          // NR42 
    memory[NR42] = 0;          // NR43
    memory[NR30] = 0x00bf;     // NR30
    memory[NR50] = 0x0077;     // NR50
    memory[NR51] = 0x00f3;     // NR51
    memory[NR52] = 0x00f1;     // NR52
    memory[LCDC] = 0x0091;     // LCDC
    memory[SCY] = 0;           // SCY
    memory[SCX] = 0;           // SCX
    memory[LYC] = 0;           // LYC
    memory[BGP] = 0x00fc;      // BGP
    memory[OBP0] = 0x00ff;     // OBP0
    memory[OBP1] = 0x00ff;     // OBP1
    memory[WY] = 0;            // WY
    memory[WX] = 0;            // WX
    memory[IE] = 0;            // IE
}


void
Cpu::execute()
{
}




/* ====================== __Instruction Set__  */

void
Cpu::NOP()
{
    cycles = 4;
    total_cycles += 4;
    instr_length = 1;
}


void
Cpu::STOP()
{
    is_stopped = true;

    cycles = 4;
    total_cycles += 4;
    instr_length = 2;
}


void
Cpu::HALT()
{
    is_halted = true;

    cycles = 4;
    total_cycles += 4;
    instr_length = 1;
}


void
Cpu::DI()
{
}




}
