/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_MEMORY_H
#define __RPN_MEMORY_H

#include "rpn.h"
#include "rpn_operand.h"

class Memory
    : public std::map<int,Operand>
{
public:
    Memory(): refs(0) {}
    ~Memory() { FLEXT_ASSERT(refs == 0); }

    void Set(int id,const Operand &o)
    {
        (*this)[id] = o;
    }

    Operand &Get(int id)
    {
        iterator it = find(id);
        if(LIKELY(it != end()))
            return it->second;
        else
            throw Error::MemNotSet();
    }

    void Push() { ++refs; }
    bool Pop() { return --refs != 0; }

private:
    int refs;
};

class MemoryPool
    : public std::map<Symbol,Memory *>
{
public:
    Memory *New(Symbol s)
    {
        Memory *m;
        iterator it = find(s);
        if(it == end())
            (*this)[s] = m = new Memory();
        else
            m = it->second;
        m->Push();
        return m;
    }

    bool Free(Symbol s)
    {
        iterator it = find(s);
        if(it == end()) return false;
        Memory *m = it->second;
        if(!m->Pop()) delete m;
        return true;
    }
};

#endif
