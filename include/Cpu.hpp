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
        enum RegisterName
            {
            AF, BC, DE, HL, 
            SP, PC,
            A = 0, F = 0,
            B = 1, C = 1,
            D = 2, E = 2,
            H = 3, L = 3,
            TIMA = 0xff05,
            TMA, TAC, 
            NR10 = 0xff10, NR11, NR12, 
            NR14 = 0xff14, 
            NR21 = 0xff16, NR22, 
            NR24 = 0xff19,
            NR30 = 0xff1a, NR31, NR32, 
            NR33 = 0xff1e,
            NR41 = 0xff20, NR42, NR43, NR30, NR50, NR51, NR52, 
            LCDC = 0xff40,
            SCY = 0xff42,  SCX,  
            LYC = 0xff45,  
            BGP = 0xff47,
            OBP0, OBP1, 
            WY, WX, 
            IE = 0xffff 
            };

    public:
        Cpu(Memory*, Cart*, Video*, Sound*);
        ~Cpu();

        void execute();

        void reset();

    private:
        Register register_file[8];
        int total_cycles;
        int cycles;
        int instr_length;

        Memory*   memory;
        Cart*     cart;
        Video*    video;
        Sound*    sound;

        bool is_halted;
        bool is_stopped;
        bool interrups_enabled;

    private:
        /* __Instruction Set__ 
         *
         * r16  =  generic entire register
         * r8   =  generic half register
         * ra16 =  content of address in generic entire register
         * ra8  =  content of address in generic half register
         * 
         * u8  means immediate 8 bit data
         * u16 means immediate 16 bit data
         * a8  means 8 bit unsigned data, which are added to $FF00 in certain instructions
         * a16 means 16 bit address
         * s8  means 8 bit signed data, which are added to program counter
         *
         */
 
         void NOP();
         void STOP();
         void HALT();
         void DI();
         void EI();

         void LD_r16_u16    (RegisterName, u16); 
         void LD_ra16_r8    (RegisterName, RegisterName);
         void LD_a16_r16    (u16, RegisterName);
         void LD_r8_ra16    (RegisterName, RegisterName);
         void LD_r8_u8      (RegisterName, u8);
         void LD_r8_r8      (RegisterName, RegisterName);
         void LD_r8_ra16    (RegisterName, RegisterName);
         void LD_ra16+_r8   (RegisterName, RegisterName);
         void LD_ra16-_r8   (RegisterName, RegisterName);
         void LD_r8_ra16+   (RegisterName, RegisterName);
         void LD_r8_ra16-   (RegisterName, RegisterName);

         void LDH_a8_A      (u8, RegisterName);
         void LDH_A_a8      (RegisterName, u8);
         void LDH_a16_A     (u16, RegisterName);
         void LDH_A_a16     (RegisterName, u16);

         void LD_HL_SP+s8   (RegisterName, RegisterName, s8);
         void LD_r16_r16    (RegisterName, RegisterName);

         void INC_r16   (RegisterName); 
         void INC_ra16  (RegisterName); 
         void DEC_r16   (RegisterName);
         void DEC_r8    (RegisterName);
         void INC_r8    (RegisterName); 

         void RLCA();
         void RRCA();
         void RLA();
         void RRA();

         void CPL();
         void CCF();
         void DAA();
         void SCF();

         void ADD_r8_r8     (RegisterName, RegisterName);
         void ADD_r8_ra16   (RegisterName, RegisterName);
         void ADD_r16_r16   (RegisterName, RegisterName);
         void ADD_r8_u8     (RegisterName, u8);
         void ADD_r8_s8     (RegisterName, s8);

         void SUB_r8    (RegisterName);
         void SUB_ra16  (RegisterName);
         void SUB_u8    (u8);

         void AND_r8    (RegisterName);
         void AND_ra16  (RegisterName);
         void AND_u8    (u8);

         void XOR_r8    (RegisterName);
         void XOR_ra16  (RegisterName);
         void XOR_u8    (u8);

         void OR_r8     (RegisterName);
         void OR_ra16   (RegisterName);
         void OR_u8     (u8);

         void CP_r8    (RegisterName);
         void CP_ra16  (RegisterName);
         void CP_u8    (u8);

         void ADC_r8_r8    (RegisterName, RegisterName);
         void ADC_r8_ra16  (RegisterName, RegisterName);
         void ADC_r8_u8    (RegisterName, u8);

         void SBC_r8_r8    (RegisterName, RegisterName);
         void SBC_r8_ra16  (RegisterName, RegisterName);
         void SBC_r8_u8    (RegisterName, u8);

         // Jumps
        
         void JR_NZ_s8   (s8);
         void JR_NC_s8   (s8);
         void JR_Z_s8    (s8);
         void JR_C_s8    (s8);
         void JP_NZ_a16  (u16);
         void JP_NC_a16  (u16);
         void JP_Z_a16   (u16);
         void JP_C_a16   (u16);

         void JR_s8    (s8);
         void JP_a16   (u16);
         void JP_ra16  (RegisterName);
       
         // Pass register AF to check bit Z, and PC
         void RET_NZ();
         void RET_NC();
         void RET_Z();
         void RET_C();

         void RETI();

         void CALL_a16      (u16);
         void CALL_NZ_a16   (u16);
         void CALL_NC_a16   (u16);
         void CALL_Z_a16    (u16);
         void CALL_C_a16    (u16);

         // Stack 

         void POP_r16   (RegisterName);
         void PUSH_r16  (RegisterName);

         // Pass SP and PC
         void RST_n(u8);


         // GBC Instructions(Pass even AF register to set flags)
         void RLC_r8    (RegisterName);
         void RLC_ra16  (RegisterName);
         void RRC_r8    (RegisterName);
         void RRC_ra16  (RegisterName);

         void RL_r8    (RegisterName);
         void RL_ra16  (RegisterName);
         void RR_r8    (RegisterName);
         void RR_ra16  (RegisterName);

         void SLA_r8    (RegisterName);
         void SLA_ra16  (RegisterName);
         void SRA_r8    (RegisterName);
         void SRA_ra16  (RegisterName);

         void SWAP_r8    (RegisterName);
         void SWAP_ra16  (RegisterName);
         void SRL_r8     (RegisterName);
         void SRL_ra16   (RegisterName);

         void BIT_n_r8    (u8, RegisterName);
         void BIT_n_ra16  (u8, RegisterName);

         void RES_n_r8    (u8, RegisterName);
         void RES_n_ra16  (u8, RegisterName);
         void SET_n_r8    (u8, RegisterName);
         void SET_n_ra16  (u8, RegisterName);

};

}

#endif
