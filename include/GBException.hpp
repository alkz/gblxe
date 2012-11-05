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


#ifndef __GBLXE_GBEXCEPTION_HPP__
#define __GBLXE_GBEXCEPTION_HPP__


namespace gblxe  {


class GBException : public std::exception
{
    public:
        static const unsigned int CART_NOT_PRESENT       =    1001;
        static const unsigned int CANNOT_OPEN_ROM_FILE   =    1002;
        static const unsigned int WRONG_NINTENDO_LOGO    =    1003;

    public:
        GBException(unsigned int);
        virtual ~GBException() throw();

        virtual const char* what() const throw();

    private:
        std::string description;
};


#endif
