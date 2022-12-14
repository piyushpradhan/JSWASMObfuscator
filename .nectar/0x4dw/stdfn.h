/*
 * This file is part of NectarCPP
 * Copyright (c) 2020 - 2020 Adrien THIERRY
 * https://nectar-lang.org - https://seraum.com/
 *
 * sources : https://github.com/nectar-lang/NectarCPP
 * 
 * NectarCPP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NectarCPP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with NectarCPP.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
namespace NectarCore::Functions
{
	NectarCore::VAR println()
	{
		#ifndef __Nectar_ENV_ARDUINO
		std::cout << std::endl;
		#endif
		return NectarCore::Global::undefined;
	}
	NectarCore::VAR println(NectarCore::VAR _var)
	{
		#ifndef __Nectar_ENV_ARDUINO
		std::cout << _var << std::endl;
		#endif
		return NectarCore::Global::undefined;
	}
	
	NectarCore::VAR print()
	{
		return NectarCore::Global::undefined;
	}
	
	NectarCore::VAR print(NectarCore::VAR _var)
	{
		#ifndef __Nectar_ENV_ARDUINO
		std::cout << _var;
		#endif
		return NectarCore::Global::undefined;
	}
}