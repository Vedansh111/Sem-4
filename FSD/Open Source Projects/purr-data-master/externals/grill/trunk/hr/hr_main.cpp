/* 
hr - high resolution (double precision) math library

Copyright (c)2006,2011 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 3743 $
$LastChangedDate: 2011-03-09 17:23:18 -0500 (Wed, 09 Mar 2011) $
$LastChangedBy: thomas $
*/

#define HR_VERSION "0.1.2"

#undef FLEXT_ATTRIBUTES

#include "hr_msg.h"
#include "hr_sig.h"
#include "hr_ops.h" 

#define HELPNAME "hr"

#define HR_MSG_UNARY(NAME,OP) \
class unary_##OP: public unary_op<Operators::OP> { \
	FLEXT_HEADER(unary_##OP,unary_op<Operators::OP>) \
}; \
FLEXT_LIB("hr." NAME "," HELPNAME,unary_##OP)

#define HR_MSG_BINARY(NAME,OP) \
class binary_##OP: public binary_op<Operators::OP> { \
	FLEXT_HEADER(binary_##OP,binary_op<Operators::OP>) \
public: \
	binary_##OP(int argc,const t_atom *argv): thisParent(argc,argv) {} \
}; \
FLEXT_LIB_V("hr." NAME "," HELPNAME,binary_##OP)

#define HR_DSP_UNARY(NAME,OP) \
class unary_dsp_##OP: public unary_dsp<Operators::OP> { \
	FLEXT_HEADER(unary_dsp_##OP,unary_dsp<Operators::OP>) \
}; \
FLEXT_LIB_DSP("hr." NAME "~" "," HELPNAME,unary_dsp_##OP)

#define HR_DSP_BINARY(NAME,OP) \
class binary_dsp_##OP: public binary_dsp<Operators::OP> { \
	FLEXT_HEADER(binary_dsp_##OP,binary_dsp<Operators::OP>) \
public: \
	binary_dsp_##OP(int argc,const t_atom *argv): thisParent(argc,argv) {} \
}; \
FLEXT_LIB_DSP_V("hr." NAME "~" "," HELPNAME,binary_dsp_##OP)

#define HR_UNARY(NAME,OP) \
	HR_MSG_UNARY(NAME,OP) \
	HR_DSP_UNARY(NAME,OP)

#define HR_BINARY(NAME,OP) \
	HR_MSG_BINARY(NAME,OP) \
	HR_DSP_BINARY(NAME,OP)

HR_UNARY("sqr",sqr)
HR_UNARY("sqrt",sqrt)
HR_UNARY("abs",abs)
HR_UNARY("exp",exp)
HR_UNARY("ln",ln)
HR_UNARY("sin",sin)
HR_UNARY("cos",cos)
HR_UNARY("tan",tan)
HR_UNARY("asin",asin)
HR_UNARY("acos",acos)
HR_UNARY("atan",atan)
HR_UNARY("sinh",sinh)
HR_UNARY("cosh",cosh)
HR_UNARY("tanh",tanh)
HR_UNARY("floor",floor)
HR_UNARY("ceil",ceil)

#if 0
// not defined for VC++
HR_UNARY("asinh",asinh)
HR_UNARY("acosh",acosh)
HR_UNARY("atanh",atanh)
#endif

HR_BINARY("+",plus)
HR_BINARY("-",minus)
HR_BINARY("!-",rminus)
HR_BINARY("*",times)
HR_BINARY("/",over)
HR_BINARY("!/",rover)
HR_BINARY("%",mod)
HR_BINARY("!%",rmod)
HR_BINARY("**",power)
HR_BINARY("!**",rpower)
HR_BINARY("min",min)
HR_BINARY("max",max)
HR_BINARY("atan2",atan2)

HR_BINARY("==",eq)
HR_BINARY("!=",ne)
HR_BINARY(">",gt)
HR_BINARY(">=",ge)
HR_BINARY("<",lt)
HR_BINARY("<=",le)

#define HR_UNARY_SETUP(NAME) \
	FLEXT_SETUP(unary_ ## NAME); \
	FLEXT_DSP_SETUP(unary_dsp_ ## NAME)

#define HR_BINARY_SETUP(NAME) \
	FLEXT_SETUP(binary_ ## NAME); \
	FLEXT_DSP_SETUP(binary_dsp_ ## NAME)


static void hr_main()
{
	post("----------------------------------------");
	post("hr - double precision math objects");
    post("version " HR_VERSION " (c)2006-2011 Thomas Grill");
#ifdef FLEXT_DEBUG
    post("");
    post("DEBUG BUILD - " __DATE__ " " __TIME__);
#endif
	post("----------------------------------------");


    HR_UNARY_SETUP(sqr)
	HR_UNARY_SETUP(sqrt)
	HR_UNARY_SETUP(abs)
	HR_UNARY_SETUP(exp)
	HR_UNARY_SETUP(ln)
	HR_UNARY_SETUP(sin)
	HR_UNARY_SETUP(cos)
	HR_UNARY_SETUP(tan)
	HR_UNARY_SETUP(asin)
	HR_UNARY_SETUP(acos)
	HR_UNARY_SETUP(atan)
	HR_UNARY_SETUP(sinh)
	HR_UNARY_SETUP(cosh)
	HR_UNARY_SETUP(tanh)
#if 0
	HR_UNARY_SETUP(asinh)
	HR_UNARY_SETUP(acosh)
	HR_UNARY_SETUP(atanh)
#endif
	HR_UNARY_SETUP(floor)
	HR_UNARY_SETUP(ceil)

	HR_BINARY_SETUP(plus)
	HR_BINARY_SETUP(minus)
	HR_BINARY_SETUP(rminus)
	HR_BINARY_SETUP(times)
	HR_BINARY_SETUP(over)
	HR_BINARY_SETUP(rover)
	HR_BINARY_SETUP(mod)
	HR_BINARY_SETUP(rmod)
	HR_BINARY_SETUP(power)
	HR_BINARY_SETUP(rpower)
	HR_BINARY_SETUP(min)
	HR_BINARY_SETUP(max)
	HR_BINARY_SETUP(atan2)

	HR_BINARY_SETUP(eq)
	HR_BINARY_SETUP(ne)
	HR_BINARY_SETUP(gt)
	HR_BINARY_SETUP(ge)
	HR_BINARY_SETUP(lt)
	HR_BINARY_SETUP(le)
}

FLEXT_LIB_SETUP(hr,hr_main)
