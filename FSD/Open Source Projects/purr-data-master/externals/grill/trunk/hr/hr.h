/* 
hr - high resolution (double precision) math library

Copyright (c)2006,2007 Thomas Grill (gr@grrrr.org)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

$LastChangedRevision: 1741 $
$LastChangedDate: 2007-11-15 06:10:03 -0500 (Thu, 15 Nov 2007) $
$LastChangedBy: thomas $
*/

#ifndef __HR_H
#define __HR_H

#include <flext.h>

class hr
	: public flext
{
public:
	static double get(int argc,const t_atom *argv)
	{
		double v = 0;
		if(argc >= 1 && CanbeFloat(argv[0])) {
			v += GetAFloat(argv[0]);
			if(argc >= 2 && CanbeFloat(argv[1]))
				v += GetAFloat(argv[1]);
		}
		return v;
	}
};

#endif