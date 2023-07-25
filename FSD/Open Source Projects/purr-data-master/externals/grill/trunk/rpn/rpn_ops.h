/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_OPS_H
#define __RPN_OPS_H

#include "rpn.h"
#include <stdlib.h>

namespace Basic {

// no args ////////////////////////////////////////////////////////////////////////////////////////////////////

class Pi { public: template <typename R> static R operate() { return (R)M_PI; } };
class Random { public: template <typename R> static R operate() { return (R)::rand()/(R)RAND_MAX; } };
class Time { public: template <typename R> static R operate() { return (R)flext::GetOSTime(); } };

// unary ///////////////////////////////////////////////////////////////////////////////////////////////////////

class Neg { public: template <typename R> static R operate(R x) { return -x; } };
class Inv { public: template <typename R> static R operate(R x) { return (R)1./x; } };

class Inc { public: template <typename R> static R operate(R x) { return x+(R)1; } };
class Dec { public: template <typename R> static R operate(R x) { return x-(R)1; } };

class Int { public: template <typename R> static R operate(R x) { return (R)int(x); } };
class Ceil { public: template <typename R> static R operate(R x) { return ::ceil(x); } };
class Floor { public: template <typename R> static R operate(R x) { return ::floor(x); } };
class Round { public: template <typename R> static R operate(R x) { return ::floor(x+(R)0.5); } };

class Abs { public: template <typename R> static R operate(R x) { return ::fabs(x); } };

class Sqr { public: template <typename R> static R operate(R x) { return x*x; } };
class Sqrt { public: template <typename R> static R operate(R x) { return ::sqrt(x); } };

class Exp { public: template <typename R> static R operate(R x) { return ::exp(x); } };
class Ln { public: template <typename R> static R operate(R x) { return ::log(x); } };
class Lg { public: template <typename R> static R operate(R x) { return ::log10(x); } };
class Ld { public: template <typename R> static R operate(R x) { return ::log(x)/(R)M_LN2; } };

class Sin { public: template <typename R> static R operate(R x) { return ::sin(x); } };
class Cos { public: template <typename R> static R operate(R x) { return ::cos(x); } };
class Tan { public: template <typename R> static R operate(R x) { return ::tan(x); } };
class Asin { public: template <typename R> static R operate(R x) { return ::asin(x); } };
class Acos { public: template <typename R> static R operate(R x) { return ::acos(x); } };
class Atan { public: template <typename R> static R operate(R x) { return ::atan(x); } };
class Sinh { public: template <typename R> static R operate(R x) { return ::sinh(x); } };
class Cosh { public: template <typename R> static R operate(R x) { return ::cosh(x); } };
class Tanh { public: template <typename R> static R operate(R x) { return ::tanh(x); } };

// binary ///////////////////////////////////////////////////////////////////////////////////////////////////////

class Plus { public: template <typename R> static R operate(R x,R y) { return x+y; } };
class Minus { public: template <typename R> static R operate(R x,R y) { return x-y; } };
class Times { public: template <typename R> static R operate(R x,R y) { return x*y; } };
class Over { public: template <typename R> static R operate(R x,R y) { return x/y; } };
class Mod { public: template <typename R> static R operate(R x,R y) { return ::fmod(x,y); } };
class Power { public: template <typename R> static R operate(R x,R y) { return ::pow(x,y); } };
class Log { public: template <typename R> static R operate(R x,R base) { return ::log(x)/::log(base); } };

class Atan2 { public: template <typename R> static R operate(R x,R y) { return ::atan2(x,y); } };

class Min { public: template <typename R> static R operate(R x,R y) { return x < y?x:y; } };
class Max { public: template <typename R> static R operate(R x,R y) { return x > y?x:y; } };

class Eq { public: template <typename R> static R operate(R x,R y) { return x == y?(R)1:(R)0; } };
class Ne { public: template <typename R> static R operate(R x,R y) { return x != y?(R)1:(R)0; } };
class Gt { public: template <typename R> static R operate(R x,R y) { return x > y?(R)1:(R)0; } };
class Lt { public: template <typename R> static R operate(R x,R y) { return x < y?(R)1:(R)0; } };
class Ge { public: template <typename R> static R operate(R x,R y) { return x >= y?(R)1:(R)0; } };
class Le { public: template <typename R> static R operate(R x,R y) { return x <= y?(R)1:(R)0; } };

class And { public: template <typename R> static R operate(R x,R y) { return x && y?(R)1:(R)0; } };
class Or { public: template <typename R> static R operate(R x,R y) { return x || y?(R)1:(R)0; } };
class Xor { public: template <typename R> static R operate(R x,R y) { return (R)((x?1:0)^(y?1:0)); } };

class BitAnd { public: template <typename R> static R operate(R x,R y) { return (R)((int)x&(int)y); } };
class BitOr { public: template <typename R> static R operate(R x,R y) { return (R)((int)x|(int)y); } };
class BitXor { public: template <typename R> static R operate(R x,R y) { return (R)((int)x^(int)y); } };

} // namespace Op


#endif

