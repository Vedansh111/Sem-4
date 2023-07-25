/* 
rpn - expression evaluator

Copyright (c)2006-2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 2410 $
$LastChangedDate: 2007-12-11 09:16:34 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __RPN_OPSTACK_H
#define __RPN_OPSTACK_H

#include "rpn.h"
#include "rpn_opimp.h"


namespace OpStack {

class Size
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        stack.push_back((Real)stack.size());
    }
};


template<typename TI,typename TN>
class DropX
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<TI>();
        int cnt = stack.Int<TN>();
        int sz = (int)stack.size();

        if(ix < 0) ix += sz;

        if(UNLIKELY(ix+cnt > (int)sz))
            throw Error::OpUnderflow();

        int offs = sz-cnt-ix;
        for(int i = 0; i < cnt; ++i)
            stack.erase(stack.begin()+offs);
    }
};

typedef DropX<Stack::_Pop,Stack::_Pop> DropNI;
typedef DropX<Stack::_Pop,Stack::_1> DropI;
typedef DropX<Stack::_0,Stack::_Pop> DropN;
typedef DropX<Stack::_0,Stack::_1> Drop;

class DropAll
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        stack.clear();
    }
};


template<typename TI,typename TN>
class DupX
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<TI>();
        int cnt = stack.Int<TN>();
        int sz = (int)stack.size();

        if(UNLIKELY(cnt > sz))
            throw Error::OpUnderflow();

        if(ix < 0)
            ix += sz;
        else
            if(UNLIKELY(ix >= sz))
                throw Error::OpBounds();

        int offs = sz-1-ix;
        for(int i = 0; i < cnt; ++i,++offs) {
            Operand o = *(stack.begin()+offs);
            stack.Push(o);
        }
    }
};

typedef DupX<Stack::_Pop,Stack::_Pop> DupNI;
typedef DupX<Stack::_Pop,Stack::_1> DupI;
typedef DupX<Stack::_0,Stack::_Pop> DupN;
typedef DupX<Stack::_0,Stack::_1> Dup;
typedef DupX<Stack::_Size1,Stack::_Size> DupAll;


#if 0
class Swap
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        if(stack.size() < 2) throw Error::OpUnderflow();
        Stack::iterator it = stack.end(); 
        Operand &p1 = *--it;
        Operand &p2 = *--it;
        Operand tmp = p1; p1 = p2; p2 = tmp;
    }
};

class SwapI
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<Stack::_Pop>();
        if(ix >= (int)stack.size())
            throw Error::OpUnderflow();
        else if(ix < 0)
            throw Error::OpBounds();
        else {
            Stack::reverse_iterator it = stack.rbegin()+ix;
            Operand tmp = *it;
            *it = stack.back();
            stack.back() = tmp;
        }
    }
};
#endif

template<typename TI,typename TN>
class SwapX
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<TI>();

        int cnt = stack.Int<TN>();
        if(UNLIKELY(cnt <= 0)) return; // nothing to do

        int sz = (int)stack.size();

        if(ix < 0) 
            ix += sz;
        else if(ix == 0)
            return; // nothing to do
        else
            if(UNLIKELY(ix > (int)sz)) 
                throw Error::OpBounds();

        for(int i = 0; i < cnt; ++i)
            swap(*(stack.rbegin()+i),*(stack.rbegin()+ix+i));
    }

private:
    static void swap(Operand &a,Operand &b)
    {
        Operand tmp = a; a = b; b = tmp;
    }
};

typedef SwapX<Stack::_Pop,Stack::_Pop> SwapNI;
typedef SwapX<Stack::_Pop,Stack::_1> SwapI;
typedef SwapX<Stack::_Get,Stack::_Pop> SwapN;
typedef SwapX<Stack::_1,Stack::_1> Swap;


template<typename TI,typename TN>
class RotX
    : public Opcode
{
protected:
    virtual void Do(Stack &stack,const Inputs &inputs,Memory &memory) 
    {
        int ix = stack.Int<TI>();

        int cnt = stack.Int<TN>();
        if(UNLIKELY(cnt == 0)) return; // nothing to do
        
        int sz = (int)stack.size();

        if(ix < 0) 
            ix += sz;
        else
            if(UNLIKELY(ix > (int)sz)) 
                throw Error::OpBounds();

        if(UNLIKELY(ix <= 1)) return; // nothing to do

        int ix2 = ix/2;
        cnt %= ix;
        if(UNLIKELY(cnt > ix2))
            cnt -= ix;
        else if(UNLIKELY(cnt < -ix2))
            cnt += ix;

        // don't know if this way of shifting Operands is the most efficient...
        if(cnt >= 0) {
            stack.insert(stack.begin()+sz-ix,cnt,Operand());
            for(int i = 0; i < cnt; ++i) stack[sz-ix+i] = stack[sz+i];
            stack.erase(stack.begin()+sz,stack.end());
        }
        else {
            stack.insert(stack.end(),-cnt,Operand());
            for(int i = 0; i < -cnt; ++i) stack[sz+i] = stack[sz-ix+i];
            stack.erase(stack.begin()+sz-ix,stack.begin()+sz-ix-cnt);
        }   
    }
};

typedef RotX<Stack::_Pop,Stack::_Pop> RotNI;
typedef RotX<Stack::_Pop,Stack::_1> RotI;
typedef RotX<Stack::_Size1,Stack::_Pop> RotN;
typedef RotX<Stack::_Size,Stack::_1> Rot;

} // namespace

#endif
