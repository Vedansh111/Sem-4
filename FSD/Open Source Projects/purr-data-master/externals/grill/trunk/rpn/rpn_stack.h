/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_STACK_H
#define __RPN_STACK_H

#include "rpn.h"
#include "rpn_operand.h"

class Stack
    : public Operands
{
public:
    Operand &Get(int offs = 0)
    {
        FLEXT_ASSERT(offs >= 0);
        if(UNLIKELY(offs >= (int)size())) 
            throw Error::OpUnderflow();
        if(UNLIKELY(offs)) {
            reverse_iterator it = rbegin();
            it += offs;
            return *it;
        }
        else
            return back();
    }

    Operand Pop()
    {
        Operand op = Get();
        pop_back();
        return op;
    }

    void Push(const Operand &op) 
    { 
        push_back(op); 
    }

    template<typename T> int Int() { return T::Get(*this); }

    class _Pop 
    { 
    public: 
        static int Get(Stack &s) 
        { 
            Operand ix = s.Pop();
            if(LIKELY(ix.Scalar()))
                return (int)(Real)ix;
            else
                return (int)((Vector &)ix)[0];
        } 
    };

    class _Get
    { 
    public: 
        static int Get(Stack &s) 
        { 
            const Operand &ix = s.Get();
            if(LIKELY(ix.Scalar()))
                return (int)(Real)ix;
            else
                return (int)((Vector &)ix)[0];
        } 
    };

    class _Size { public: static int Get(Stack &s) { return (int)s.size(); } };
    class _Size1 { public: static int Get(Stack &s) { return (int)s.size()-1; } };

    template<int N> class _N { public: static int Get(Stack &s) { return N; } };
    typedef _N<0> _0;
    typedef _N<1> _1;
};

#endif
