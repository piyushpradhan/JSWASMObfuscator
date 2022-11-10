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
#define __Nectar_INIT_RAND_SEED
#if defined(_USE_MATH_DEFINES) && !defined(M_E)
#define _MATH_DEFINES_DEFINED

/* Define _USE_MATH_DEFINES before including math.h to expose these macro
 * definitions for common math constants.  These are placed under an #ifdef
 * since these commonly-defined names are not part of the C/C++ standards.
 */

/* Definitions of useful mathematical constants
 * M_E        - e
 * M_LOG2E    - log2(e)
 * M_LOG10E   - log10(e)
 * M_LN2      - ln(2)
 * M_LN10     - ln(10)
 * M_PI       - pi
 * M_PI_2     - pi/2
 * M_PI_4     - pi/4
 * M_1_PI     - 1/pi
 * M_2_PI     - 2/pi
 * M_2_SQRTPI - 2/sqrt(pi)
 * M_SQRT2    - sqrt(2)
 * M_SQRT1_2  - 1/sqrt(2)
 */

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */



var __Nectar_MATH_E = NectarCore::VAR(M_E);
var __Nectar_MATH_LN2 = NectarCore::VAR(M_LN2);
var __Nectar_MATH_LOG2E = NectarCore::VAR(M_LOG2E);
var __Nectar_MATH_LOG10E = NectarCore::VAR(M_LOG10E);
var __Nectar_MATH_PI = NectarCore::VAR(M_PI);
var __Nectar_MATH_SQRT1_2 = NectarCore::VAR(M_SQRT1_2);
var __Nectar_MATH_SQRT2 = NectarCore::VAR(M_SQRT2);

NectarCore::Type::function_t* __NJS_FN___rx9uxa = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::abs((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ABS=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___rx9uxa);;

NectarCore::Type::function_t* __NJS_FN___cenju3 = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::acos((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ACOS=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___cenju3);;

NectarCore::Type::function_t* __NJS_FN___pvu4rn = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::acosh((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ACOSH=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___pvu4rn);;

NectarCore::Type::function_t* __NJS_FN___1h7ro = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::asin((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ASIN=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___1h7ro);;

NectarCore::Type::function_t* __NJS_FN___zvc02p = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0];
	return NectarCore::VAR(std::asinh((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ASINH=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___zvc02p);;
NectarCore::Type::function_t* __NJS_FN___ckwyvd = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::atan((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ATAN=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___ckwyvd);;
NectarCore::Type::function_t* __NJS_FN___cq2d1 = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0];var  y; if(__Nectar_VARLENGTH > 1)  y = __Nectar_VARARGS[1]; 
	return NectarCore::VAR(std::atan2((double)(x), (double)(y))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ATAN2=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___cq2d1);;
NectarCore::Type::function_t* __NJS_FN___xgy0p = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::atanh((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_ATANH=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___xgy0p);;
NectarCore::Type::function_t* __NJS_FN___4q1av9 = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::cbrt((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_CBRT=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___4q1av9);;
NectarCore::Type::function_t* __NJS_FN___1kfmvk = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::ceil((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_CEIL=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___1kfmvk);;

NectarCore::Type::function_t* __NJS_FN___bk5cjg = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0];
	int n = (int)(x);
	return NectarCore::VAR(n > 0 ? (int)(31 - std::log2(n >> 0)) : 32);
;return NectarCore::Global::undefined;});var __Nectar_MATH_CLZ32=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___bk5cjg);;

NectarCore::Type::function_t* __NJS_FN___pk3w = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::cos((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_COS=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___pk3w);;

NectarCore::Type::function_t* __NJS_FN___oakksa = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::cosh((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_COSH=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___oakksa);;

NectarCore::Type::function_t* __NJS_FN___z2axqk = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return std::exp((double)(x)); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_EXP=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___z2axqk);;

NectarCore::Type::function_t* __NJS_FN___h5zw7n = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::expm1((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_EXPM1=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___h5zw7n);;

NectarCore::Type::function_t* __NJS_FN___jb120j = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR((int)(std::floor((double)(x))));
;return NectarCore::Global::undefined;});var __Nectar_MATH_FLOOR=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___jb120j);;

NectarCore::Type::function_t* __NJS_FN___uath1c = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR((double)((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_FROUND=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___uath1c);;

NectarCore::Type::function_t* __NJS_FN___k9ram = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{
	double max = 0;
	double s = 0;
	for (int i = 0; i < __Nectar_VARLENGTH; i++) {
		double x = std::abs((double)(__Nectar_VARARGS[i]));
		if (x > max) {
			s *= (max / x) * (max / x);
			max = x;
		}
		s += (x == 0 && max == 0) ? 0 : (x / max) * (x / max);
	}
	return NectarCore::VAR(max == INFINITY ? INFINITY : max * std::sqrt(s));
;return NectarCore::Global::undefined;});var __Nectar_MATH_HYPOT=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___k9ram);;

NectarCore::Type::function_t* __NJS_FN___baw8te = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0];var  y; if(__Nectar_VARLENGTH > 1)  y = __Nectar_VARARGS[1];
	return NectarCore::VAR((int)(x) * (int)(y));
;return NectarCore::Global::undefined;});var __Nectar_MATH_IMUL=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___baw8te);;

NectarCore::Type::function_t* __NJS_FN___mbts1f = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::log((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_LOG=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___mbts1f);;

NectarCore::Type::function_t* __NJS_FN___ysfo7u = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::log1p((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_LOG1P=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___ysfo7u);;

NectarCore::Type::function_t* __NJS_FN___hj1udi = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::log2((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_LOG2=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___hj1udi);;

NectarCore::Type::function_t* __NJS_FN___d9vvvb = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::log10((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_LOG10=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___d9vvvb);;

NectarCore::Type::function_t* __NJS_FN___wzobv9 = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{
	double max = -INFINITY;
	for (int i = 0; i < __Nectar_VARLENGTH; i++) {
		double n = (double)(__Nectar_VARARGS[i]);
		if (n > max) {
			max = n;
		}
	}
	return NectarCore::VAR(max);
;return NectarCore::Global::undefined;});var __Nectar_MATH_MAX=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___wzobv9);;

NectarCore::Type::function_t* __NJS_FN___c8vbk = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{
	double min = INFINITY;
	for (int i = 0; i < __Nectar_VARLENGTH; i++) {
		double n = (double)(__Nectar_VARARGS[i]);
		if (n < min) {
			min = n;
		}
	}
	return NectarCore::VAR(min);
;return NectarCore::Global::undefined;});var __Nectar_MATH_MIN=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___c8vbk);;

NectarCore::Type::function_t* __NJS_FN___6c4rv6 = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0];var  x2; if(__Nectar_VARLENGTH > 1)  x2 = __Nectar_VARARGS[1]; 
	return NectarCore::VAR(std::pow((double)(x), (double)(x2))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_POW=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___6c4rv6);;

NectarCore::Type::function_t* __NJS_FN___t39sq = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{ 
	return NectarCore::VAR((double)(std::rand()) / (double)(RAND_MAX));
;return NectarCore::Global::undefined;});var __Nectar_MATH_RANDOM=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___t39sq);;

NectarCore::Type::function_t* __NJS_FN___p8sepo = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR((int)(std::round((double)(x))));
;return NectarCore::Global::undefined;});var __Nectar_MATH_ROUND=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___p8sepo);;

NectarCore::Type::function_t* __NJS_FN___2jyl7n = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0];
	double n = (double)(x);
	if (n == 0) { return NectarCore::VAR(0); }
	else { return NectarCore::VAR(n > 0 ? 1 : -1); };
;return NectarCore::Global::undefined;});var __Nectar_MATH_SIGN=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___2jyl7n);;

NectarCore::Type::function_t* __NJS_FN___0g4nv = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::sin((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_SIN=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___0g4nv);;

NectarCore::Type::function_t* __NJS_FN___msnl6r = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::sinh((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_SINH=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___msnl6r);;

NectarCore::Type::function_t* __NJS_FN___bgxzz8 = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::sqrt((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_SQRT=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___bgxzz8);;

NectarCore::Type::function_t* __NJS_FN___fjo9ym = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::tan((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_TAN=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___fjo9ym);;

NectarCore::Type::function_t* __NJS_FN___a6xx0p = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR(std::tanh((double)(x))); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_TANH=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___a6xx0p);;

NectarCore::Type::function_t* __NJS_FN___3mb40n = new NectarCore::Type::function_t([](var __Nectar_THIS, NectarCore::VAR* __Nectar_VARARGS, int __Nectar_VARLENGTH) -> NectarCore::VAR{var x; if(__Nectar_VARLENGTH > 0) x = __Nectar_VARARGS[0]; 
	return NectarCore::VAR((int)(x)); 
;return NectarCore::Global::undefined;});var __Nectar_MATH_TRUNC=NectarCore::VAR(NectarCore::Enum::Type::Function, __NJS_FN___3mb40n);;
