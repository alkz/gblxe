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


#ifndef __GBLXE_GB_HPP__
#define __GBLXE_GB_HPP__


namespace gblxe  {


class GB
{
    public:
        GB();
        ~GB();

        bool start();
        void stop();

        bool is_running() const  { return running; };

    private:
        GB_Cpu*     CPU;
        GB_Memory*  memory;
        GB_Cart*    cart;
        GB_Video*   video;
        GB_Sound*   sound;

        bool running;
};


}


#endif
