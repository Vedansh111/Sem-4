/* 
hr - high resolution (double precision) math library

Copyright (c)2006,2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 1744 $
$LastChangedDate: 2007-12-11 10:43:52 -0500 (Tue, 11 Dec 2007) $
$LastChangedBy: thomas $
*/

#ifndef __HR_MSG_H
#define __HR_MSG_H

#include "hr.h"

class hr_msg
    : public flext_base
    , public hr
{
    FLEXT_HEADER(hr_msg,flext_base)

    void output(int o,bool v)
    {
        ToSysBool(o,v);
    }
    
    void output(int o,float v)
    {
        ToSysFloat(o,v);
    }

    void output(int o,double v)
    {
        ToSysDouble(o,v);
    }
};


template <class op>
class UnaryMsg
    : public hr_msg
    , private op
{
    FLEXT_HEADER_S(UnaryMsg,hr_msg,setup)

public:
    UnaryMsg()
    {
        first = 0;

        AddInAnything("triggering operand");
        AddOutAnything("result");
    }
    
    void m_bang() { output(0,op::operate(first)); }
    void m_first(double f) { first = f; m_bang(); }
    void m_first2(float f1,float f2) { m_first((double)f1+(double)f2); }

private:

    double first;

    FLEXT_CALLBACK(m_bang)
    FLEXT_CALLBACK_F(m_first)
    FLEXT_CALLBACK_FF(m_first2)

    static void setup(t_classid c)
    {
        FLEXT_CADDMETHOD(c,0,m_bang);
        FLEXT_CADDMETHOD(c,0,m_first);
        FLEXT_CADDMETHOD_FF(c,0,sym_list,m_first2);
        FLEXT_CADDMETHOD_FF(c,0,"double",m_first2);
    }
};

template <class op>
class BinaryMsg
    : public hr_msg
    , private op
{
    FLEXT_HEADER_S(BinaryMsg,hr_msg,setup)

public:
    BinaryMsg(int argc,const t_atom *argv)
    {
        first = 0;
        second = get(argc,argv);
                
        AddInAnything("triggering operand");
        AddOutAnything("result");
        AddInAnything("argument");
    }
    
    void m_bang() { output(0,op::operate(first,second)); }
    void m_first(double f) { first = f; m_bang(); }
    void m_first2(float f1,float f2) { m_first((double)f1+(double)f2); }
    void m_second(double f) { second = f; }
    void m_second2(float f1,float f2) { m_second((double)f1+(double)f2); }
    
protected:
    double first,second;

private:    
    FLEXT_CALLBACK(m_bang)
    FLEXT_CALLBACK_F(m_first)
    FLEXT_CALLBACK_FF(m_first2)
    FLEXT_CALLBACK_F(m_second)
    FLEXT_CALLBACK_FF(m_second2)

    static void setup(t_classid c)
    {
        FLEXT_CADDMETHOD(c,0,m_bang);
        FLEXT_CADDMETHOD(c,0,m_first);
        FLEXT_CADDMETHOD_FF(c,0,sym_list,m_first2);
        FLEXT_CADDMETHOD_FF(c,0,"double",m_first2);
        FLEXT_CADDMETHOD(c,1,m_second);
        FLEXT_CADDMETHOD_FF(c,1,sym_list,m_second2);
        FLEXT_CADDMETHOD_FF(c,1,"double",m_second2);
    }
};

template <class op>
class unary_op
    : public UnaryMsg<op>
{
    FLEXT_HEADER_T(unary_op,UnaryMsg<op>)
};

template <class op>
class binary_op
    : public BinaryMsg<op>
{
    FLEXT_HEADER_T(binary_op,BinaryMsg<op>)
    binary_op(int argc,const t_atom *argv): thisParent(argc,argv) {}
};
#endif
