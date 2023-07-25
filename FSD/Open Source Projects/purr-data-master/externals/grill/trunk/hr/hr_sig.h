/* 
hr - high resolution (double precision) math library

Copyright (c)2006,2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 1742 $
$LastChangedDate: 2007-11-15 06:18:36 -0500 (Thu, 15 Nov 2007) $
$LastChangedBy: thomas $
*/

#ifndef __HR_SIG_H
#define __HR_SIG_H

#include "hr.h"

class hr_dsp
	: public flext_dsp
	, public hr
{
	FLEXT_HEADER(hr_dsp,flext_dsp)

public:
};

template <class op>
class UnaryDspOp
{
public:
	template<int N>
	class Unroll
	{
	public:
		static void Operate(const int n,t_sample *const *dst,const t_sample *const *src) 
		{ 
			for(int i = 0; i < n; ) {
				for(int j = 0; j < N; ++j,++i) {
					double d = op::operate(double(src[0][i])+double(src[1][i]));
					float f = static_cast<float>(d);
					dst[0][i] = f;
					dst[1][i] = float(d-f);
				}
			}
		}
	};
};

template <class op>
class BinaryDspOp
{
public:
	template <int N>
	class Unroll
	{
	public:
		static void Operate(const int n,t_sample *const *dst,const t_sample *const *src) 
		{ 
			for(int i = 0; i < n; ) {
				for(int j = 0; j < N; ++j,++i) {
					double d = op::operate(double(src[0][i])+double(src[1][i]),double(src[2][i])+double(src[3][i]));
					float f = static_cast<float>(d);
					dst[0][i] = f;
					dst[1][i] = float(d-f);
				}
			}
		}

		static void Operate(const int n,t_sample *const *dst,const t_sample *const *src,const double arg) 
		{ 
			for(int i = 0; i < n; ) {
				for(int j = 0; j < N; ++j,++i) {
					double d = op::operate(double(src[0][i])+double(src[1][i]),arg);
					float f = static_cast<float>(d);
					dst[0][i] = f;
					dst[1][i] = float(d-f);
				}
			}
		}
	};
};


template <class op>
class UnaryDsp
	: public hr_dsp
	, private op
{
	FLEXT_HEADER(UnaryDsp,hr_dsp)

public:
	UnaryDsp()
	{
		AddInSignal(2);
		AddOutSignal(2);
	}
	
	virtual void CbSignal() { (this->*dspfunc)(); }

	virtual bool CbDsp()
	{ 
		const int n = Blocksize();
		if(n%8 == 0)
			dspfunc = &thisType::template dsp_sig<8>;
		else
			dspfunc = &thisType::template dsp_sig<1>;
		return true;
	}
	
private:	
	void (thisType::*dspfunc)();

	template<int N>
	void dsp_sig() { typedef typename op::template Unroll<N> Unroller; Unroller::Operate(Blocksize(),OutSig(),InSig()); }
};

template <class op>
class BinaryDsp
	: public hr_dsp
	, private op
{
	FLEXT_HEADER_S(BinaryDsp,hr_dsp,setup)

public:
	BinaryDsp(int argc,const t_atom *argv)
	{
		AddInSignal(2);
		if(argc) {
			AddInAnything();
			second = get(argc,argv);
		}
		else
			AddInSignal(2);
		AddOutSignal(2);
	}
	
	virtual void CbSignal() { (this->*dspfunc)(); }
	
	virtual bool CbDsp()
	{ 
		const int n = Blocksize();
		if(CntInSig() == 4)
			if(n%8 == 0)
				dspfunc = &thisType::template dsp_sigsig<8>;
			else
				dspfunc = &thisType::template dsp_sigsig<1>;
		else
			if(n%8 == 0)
				dspfunc = &thisType::template dsp_sigarg<8>;
			else
				dspfunc = &thisType::template dsp_sigarg<1>;
		return true;
	}
	
protected:
	double second;
	
	void m_second(double f) { second = f; }
	void m_second2(float f1,float f2) { m_second((double)f1+(double)f2); }
	
private:	

	void (thisType::*dspfunc)();

	template<int N>
	void dsp_sigsig() { typedef typename op::template Unroll<N> Unroller; Unroller::Operate(Blocksize(),OutSig(),InSig()); }

	template<int N>
	void dsp_sigarg() { typedef typename op::template Unroll<N> Unroller; Unroller::Operate(Blocksize(),OutSig(),InSig(),second); }

	FLEXT_CALLBACK_F(m_second)
	FLEXT_CALLBACK_FF(m_second2)

	static void setup(t_classid c)
	{
		FLEXT_CADDMETHOD(c,2,m_second);
		FLEXT_CADDMETHOD_FF(c,2,sym_list,m_second2);
		FLEXT_CADDMETHOD_FF(c,2,"double",m_second2);
	}
};

template <class op>
class unary_dsp
	: public UnaryDsp<UnaryDspOp<op> >
{
	FLEXT_HEADER_T(unary_dsp,UnaryDsp<UnaryDspOp<op> >)
};

template <class op>
class binary_dsp
	: public BinaryDsp<BinaryDspOp<op> >
{
	FLEXT_HEADER_T(binary_dsp,BinaryDsp<BinaryDspOp<op> >)
	binary_dsp(int argc,const t_atom *argv): thisParent(argc,argv) {}
};

#endif
