/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_OP_MEMORY_H
#define __RPN_OP_MEMORY_H

#include "rpn.h"
#include "rpn_opimp.h"

#include "rpn_stack.h"
#include "rpn_memory.h"

namespace OpMemory {

class Set
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<Stack::_Pop>();
        memory.Set(ix,stack.Get());
    }
};

class Get
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<Stack::_Pop>();
        stack.Push(memory.Get(ix));
    }
};

} // namespace

#endif
