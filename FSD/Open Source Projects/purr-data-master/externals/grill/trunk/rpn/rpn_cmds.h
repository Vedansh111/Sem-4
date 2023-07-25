/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_CMDS_H
#define __RPN_CMDS_H

#include "rpn.h"
#include "rpn_opimp.h"
#include "rpn_stack.h"

class Variable
    : public Command
{
public:
    Variable(int ix): index(ix) {}

protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) { stack.push_back(inputs[index]); }

    const int index;
};

class Constant
    : public Command
{
public:
    Constant(Operand c): constant(c) {}

protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) { stack.push_back(constant); }

    const Operand constant;
};


class MetaCmd
    : public Command
{
public:
    MetaCmd(Meta *m,Command *f): meta(m),function(f) { FLEXT_ASSERT(function); }
    ~MetaCmd() { if(!function->Resident()) delete function; }

protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        meta->Do(stack,inputs,memory,function);
    }

    Meta *meta;
    Command *function;
};

#endif
