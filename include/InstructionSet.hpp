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
         */
        
        static void NOP();
        static void STOP();
        static void HALT();
        static void DI();
        static void EI();

        static void LD_r16_d16(Register&, u16); 
        static void LD_ra16_r8(u16&, Register&);
        static void LD_a16_r16(u16&, Register&);
        static void LD_r8_ra16(Register&, u16);
        static void LD_r8_d8(Register&, u8);
        static void LD_r8_r8(Register&, Register&);
        static void LD_r8_ra16(Register&, u8);
        static void LD_ra16+_r8(Register&, u8);
        static void LD_ra16-_r8(Register&, u8);
        static void LD_r8_ra16+(u8&, Register&);
        static void LD_r8_ra16-(u8&, Register&);

        static void LDH_a8_A(u8*, Register&);
        static void LDH_A_a8(Register&, u8*);
        static void LDH_a16_A(u16*, Register&);
        static void LDH_A_a16(Register&, u16*);

        static void LD_HL_SP+s8(Register&, Register&, s8);
        static void LD_r16_r16(Register&, Register&);

        static void INC_r16(Register&); 
        static void INC_ra16(u16&); 
        static void DEC_r16(Register&);
        static void DEC_r8(Register&);
        static void INC_r8(Register&); 

        // Implicit destination A register(first param)
        static void RLCA(Register&);
        static void RRCA(Register&);
        static void RLA(Register&);
        static void RRA(Register&);

        // Implicit destination A register(first param)
        static void CPL(Register&);
        static void CCF(Register&);
        static void DAA(Register&);
        static void SCF(Register&);

        static void ADD_r8_r8(Register&, Register&);
        static void ADD_r8_ra16(Register&, u16);
        static void ADD_r16_r16(Register&, Register&);
        static void ADD_r8_d8(Register&, u8);
        static void ADD_r8_s8(Register&, s8);

        // Implicit destination A register(first param)
        static void SUB_r8(Register&, Register&);
        static void SUB_ra16(Register&, u16);
        static void SUB_d8(Register&, u8);

        // Implicit destination A register(first param)
        static void AND_r8(Register&, Register&);
        static void AND_ra16(Register&, u16);
        static void AND_d8(Register&, u8);

        // Implicit destination A register(first param)
        static void XOR_r8(Register&, Register&);
        static void XOR_ra16(Register&, u16);
        static void XOR_d8(Register&, u8);

        // Implicit destination A register(first param)
        static void OR_r8(Register&, Register&);
        static void OR_ra16(Register&, u16);
        static void OR_d8(Register&, u8);

        // Implicit destination A register(first param)
        static void CP_r8(Register&, Register&);
        static void CP_ra16(Register&, u16);
        static void CP_d8(Register&, u8);

        static void ADC_r8_r8(Register&, Register&);
        static void ADC_r8_ra16(Register&, u16);
        static void ADC_r8_r8(Register&, u8);

        static void SBC_r8_r8(Register&, Register&);
        static void SBC_r8_ra16(Register&, u16);
        static void SBC_r8_d8(Register&, u8);

        // Jumps
        
        // Pass register AF to check bit Z
        static void JR_NZ_s8(Register&, Register&, s8);
        static void JR_NC_s8(Register&, Register&, s8);
        static void JR_Z_s8(Register&, Register&, s8);
        static void JR_C_s8(Register&, Register&, s8);
        static void JP_NZ_a16(Register&, Register&, u16);
        static void JP_NC_a16(Register&, Register&, u16);
        static void JP_Z_a16(Register&, Register&, u16);
        static void JP_C_a16(Register&, Register&, u16);

        static void JR_s8(Register&, Register&);
        static void JP_a16(Register&, u16);
        static void JP_ra16(Register&, u16);
       
        // Pass register AF to check bit Z, and PC
        static void RET_NZ(Register&, Register&);
        static void RET_NC(Register&, Register&);
        static void RET_Z(Register&, Register&);
        static void RET_C(Register&, Register&);

        static void RETI(Register&);

        // Pass SP, and PC
        static void CALL_a16(Register&, Register&);
        static void CALL_NZ_a16(Register&, Register&, Register&);
        static void CALL_NC_a16(Register&, Register&, Register&);
        static void CALL_Z_a16(Register&, Register&, Register&);
        static void CALL_C_a16(Register&, Register&, Register&);


        // Stack 

        // Pass SP
        static void POP_r16(Register&, Register&);
        static void PUSH_r16(Register&, Register&);

        // Pass SP and PC
        static void RST_n(Register&, Register&, u8);

};

}

}

#endif
