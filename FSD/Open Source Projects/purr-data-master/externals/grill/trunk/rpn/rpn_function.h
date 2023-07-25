/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_FUNCTION_H
#define __RPN_FUNCTION_H

#include "rpn.h"
#include "rpn_command.h"

class Functions
    : std::map<Symbol,Commands *>
{
public:
    ~Functions()
    {
        for(iterator it = begin(); it != end(); ++it) 
            delete it->second;
    }

    Commands *Find(Symbol s) 
    {
        iterator it = find(s);
        Commands *cmd;
        if(it == end())
            // if not found make new
            (*this)[s] = cmd = new Commands;
        else
            cmd = it->second;
        return cmd;
    }
};

class Function
    : public Command
{
public:
    Function(Commands *f): function(f) { FLEXT_ASSERT(function); }

protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory)
    {
        function->Do(stack,inputs,memory);
    }

    // the functions is held by a Functions map... needn't be deleted here
    Commands *function;
};

#endif
