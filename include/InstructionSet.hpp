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


#ifndef __GBLXE_INSTRUCTION_SET_HPP__
#define __GBLXE_INSTRUCTION_SET_HPP__

#include "Types.hpp"
#include "Cpu.hpp"

namespace gblxe  {

class InstructionSet()
{
    public:
        /* r16  =  generic entire register
         * r8   =  generic half register
         * ra16 =  content of address in generic entire register
         * ra8  =  content of address in generic half register
        
         * d8  means immediate 8 bit data
         * d16 means immediate 16 bit data
         * a8  means 8 bit unsigned data, which are added to $FF00 in certain instructions
         * a16 means 16 bit address
         * s8  means 8 bit signed data, which are added to program counter
         *
         * Instruction returns machine cycles needed
         */
        
        static int NOP();
        static int STOP();
        static int HALT();
        static int DI();
        static int EI();

        static int LD_r16_d16(Register&, u16); 
        static int LD_ra16_r8(u16&, Register&);
        static int LD_a16_r16(u16&, Register&);
        static int LD_r8_ra16(Register&, u16);
        static int LD_r8_d8(Register&, u8);
        static int LD_r8_r8(Register&, Register&);
        static int LD_r8_ra16(Register&, u8);
        static int LD_ra16+_r8(Register&, u8);
        static int LD_ra16-_r8(Register&, u8);
        static int LD_r8_ra16+(u8&, Register&);
        static int LD_r8_ra16-(u8&, Register&);

        static int LDH_a8_A(u8*, Register&);
        static int LDH_A_a8(Register&, u8*);
        static int LDH_a16_A(u16*, Register&);
        static int LDH_A_a16(Register&, u16*);

        static int LD_HL_SP+s8(Register&, Register&, s8);
        static int LD_r16_r16(Register&, Register&);

        static int INC_r16(Register&); 
        static int INC_ra16(u16&); 
        static int DEC_r16(Register&);
        static int DEC_r8(Register&);
        static int INC_r8(Register&); 

        // Implicit destination A register(first param)
        static int RLCA(Register&);
        static int RRCA(Register&);
        static int RLA(Register&);
        static int RRA(Register&);

        // Implicit destination A register(first param)
        static int CPL(Register&);
        static int CCF(Register&);
        static int DAA(Register&);
        static int SCF(Register&);

        static int ADD_r8_r8(Register&, Register&);
        static int ADD_r8_ra16(Register&, u16);
        static int ADD_r16_r16(Register&, Register&);
        static int ADD_r8_d8(Register&, u8);
        static int ADD_r8_s8(Register&, s8);

        // Implicit destination A register(first param)
        static int SUB_r8(Register&, Register&);
        static int SUB_ra16(Register&, u16);
        static int SUB_d8(Register&, u8);

        // Implicit destination A register(first param)
        static int AND_r8(Register&, Register&);
        static int AND_ra16(Register&, u16);
        static int AND_d8(Register&, u8);

        // Implicit destination A register(first param)
        static int XOR_r8(Register&, Register&);
        static int XOR_ra16(Register&, u16);
        static int XOR_d8(Register&, u8);

        // Implicit destination A register(first param)
        static int OR_r8(Register&, Register&);
        static int OR_ra16(Register&, u16);
        static int OR_d8(Register&, u8);

        // Implicit destination A register(first param)
        static int CP_r8(Register&, Register&);
        static int CP_ra16(Register&, u16);
        static int CP_d8(Register&, u8);

        static int ADC_r8_r8(Register&, Register&);
        static int ADC_r8_ra16(Register&, u16);
        static int ADC_r8_r8(Register&, u8);

        static int SBC_r8_r8(Register&, Register&);
        static int SBC_r8_ra16(Register&, u16);
        static int SBC_r8_d8(Register&, u8);

        // Jumps
        
        // Pass register AF to check bit Z
        static int JR_NZ_s8(Register&, Register&, s8);
        static int JR_NC_s8(Register&, Register&, s8);
        static int JR_Z_s8(Register&, Register&, s8);
        static int JR_C_s8(Register&, Register&, s8);
        static int JP_NZ_a16(Register&, Register&, u16);
        static int JP_NC_a16(Register&, Register&, u16);
        static int JP_Z_a16(Register&, Register&, u16);
        static int JP_C_a16(Register&, Register&, u16);

        static int JR_s8(Register&, Register&);
        static int JP_a16(Register&, u16);
        static int JP_ra16(Register&, u16);
       
        // Pass register AF to check bit Z, and PC
        static int RET_NZ(Register&, Register&);
        static int RET_NC(Register&, Register&);
        static int RET_Z(Register&, Register&);
        static int RET_C(Register&, Register&);

        static int RETI(Register&);

        // Pass SP, and PC
        static int CALL_a16(Register&, Register&);
        static int CALL_NZ_a16(Register&, Register&, Register&);
        static int CALL_NC_a16(Register&, Register&, Register&);
        static int CALL_Z_a16(Register&, Register&, Register&);
        static int CALL_C_a16(Register&, Register&, Register&);


        // Stack 

        // Pass SP
        static int POP_r16(Register&, Register&);
        static int PUSH_r16(Register&, Register&);

        // Pass SP and PC
        static int RST_n(Register&, Register&, u8);


        // GBC Instructions(Pass even AF register to set flags)
        static int RLC_r8(Register&, Register&);
        static int RLC_ra16(Register&, Register&);
        static int RRC_r8(Register&, Register&);
        static int RRC_ra16(Register&, Register&);

        static int RL_r8(Register&, Register&);
        static int RL_ra16(Register&, Register&);
        static int RR_r8(Register&, Register&);
        static int RR_ra16(Register&, Register&);

        static int SLA_r8(Register&, Register&);
        static int SLA_ra16(Register&, Register&);
        static int SRA_r8(Register&, Register&);
        static int SRA_ra16(Register&, Register&);

        static int SWAP_r8(Register&, Register&);
        static int SWAP_ra16(Register&, Register&);
        static int SRL_r8(Register&, Register&);
        static int SRL_ra16(Register&, Register&);

        static int BIT_n_r8(Register&, u8, Register&);
        static int BIT_n_ra16(Register&, u8, Register&);

        static int RES_n_r8(u8, Register&);
        static int RES_n_ra16(u8, Register&);
        static int SET_n_r8(u8, Register&);
        static int SET_n_ra16(u8, Register&);
};

}

}

#endif
