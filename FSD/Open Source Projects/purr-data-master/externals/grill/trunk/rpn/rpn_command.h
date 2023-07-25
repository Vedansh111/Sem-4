/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_COMMAND_H
#define __RPN_COMMAND_H

#include "rpn.h"
#include "rpn_operand.h"

typedef Operands Inputs;

class Stack;
class Memory;

class Command
{
public:
	virtual ~Command() {}

    virtual bool Resident() const { return false; }

    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) = 0;
};

class Commands
    : public std::vector<Command *>
{
public:
    ~Commands()
    {
        for(iterator it = begin(); it != end(); ++it)
            if(!(*it)->Resident()) delete *it;
    }

    void Do(Stack &stack,const Inputs &inputs,Memory &memory)
    {
        for(iterator it = begin(); it != end(); ++it)
            (*it)->Do(stack,inputs,memory);
    }
};

#endif
