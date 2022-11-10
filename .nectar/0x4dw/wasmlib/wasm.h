/*
 * This file is part of NectarJS
 * Copyright (c) 2017 - 2020 Adrien THIERRY
 * http://nectarjs.com - https://seraum.com/
 *
 * sources : https://github.com/nectarjs/nectarjs
 * 
 * NectarJS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NectarJS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with NectarJS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once
#include <emscripten.h>
#include <emscripten/bind.h>

std::vector<std::pair<std::string, NectarCore::VAR>> __Nectar_INTERNAL_BIND;

NectarCore::Type::function_t* __NJS_FN___7vcneq = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var _script; if(__Nectar_VARLENGTH > 0) _script = __Nectar_VARARGS[0];
	emscripten_run_script(__Nectar_Get_String(_script));
;return NectarCore::Global::undefined;});var __Nectar_WASM_RUN_SCRIPT=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___7vcneq);

NectarCore::Type::function_t* __NJS_FN___nwrkcp = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var _name; if(__Nectar_VARLENGTH > 0) _name = __Nectar_VARARGS[0];var  _function; if(__Nectar_VARLENGTH > 1)  _function = __Nectar_VARARGS[1];
	__Nectar_INTERNAL_BIND.push_back(std::make_pair(__Nectar_Get_String(_name), _function));
;return NectarCore::Global::undefined;});var __Nectar_WASM_BIND=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___nwrkcp);

std::string __Nectar_EM_BIND(std::string _name, std::string _data) 
{
    for (auto it = begin (__Nectar_INTERNAL_BIND); it != end (__Nectar_INTERNAL_BIND); ++it) 
	{
		if(it->first.compare(_name) == 0)
		{
			return (std::string)(it->second(_data));
			break;
		}
	}
	return "undefined";
}

int __Nectar_EM_BIND_INT(std::string _name, int _data) 
{
    for (auto it = begin (__Nectar_INTERNAL_BIND); it != end (__Nectar_INTERNAL_BIND); ++it) 
	{
		if(it->first.compare(_name) == 0)
		{
			return (int)(it->second(_data));
			break;
		}
	}
	return 0;
}


EMSCRIPTEN_BINDINGS(nectar_module) 
{
    emscripten::function("callNectar", &__Nectar_EM_BIND);
	emscripten::function("callNectarInt", &__Nectar_EM_BIND_INT);
}
