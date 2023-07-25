/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_OPCODE_H
#define __RPN_OPCODE_H

#include "rpn.h"
#include "rpn_command.h"

class Stack;
class Memory;

// Opcodes are commands that are registered in the system and take no arguments
// (and therefore need not be allocated)
class Opcode
    : public Command
{
public:
	virtual ~Opcode() {}

protected:
    virtual bool Resident() const { return true; }
};


class Meta
{
public:
	virtual ~Meta() {}

    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory,Command *function) = 0;
};


template<typename T>
class Registry
    : std::map<Symbol,T *>
{
public:
    T *Find(Symbol s)
    {
       typename std::map<Symbol,T *>::iterator it = this->find(s);
       return LIKELY(it != this->end())?it->second:NULL;
    }

    void Register(const char *s,T *op)
    {
        Symbol sym = flext::MakeSymbol(s);
        FLEXT_ASSERT(this->find(sym) == this->end());
        (*this)[sym] = op;
    }
};

#endif
