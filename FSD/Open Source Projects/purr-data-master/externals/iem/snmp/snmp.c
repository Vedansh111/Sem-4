/******************************************************
 *
 * snmp - implementation file
 *
 * copyleft (c) IOhannes m zm�lnig
 *
 *   1603:forum::f�r::uml�ute:2007
 *
 *   institute of electronic music and acoustics (iem)
 *
 ******************************************************
 *
 * license: GNU General Public License v.2
 *
 ******************************************************/

#include "m_pd.h"


void snmpget_setup();

void snmp_setup(void)
{
  post("snmp4pd: SimpleNetworkManagementProtocol objects for PureData");
  post("snmp4pd: copyleft (c) IOhannes m zmoelnig 2006-2007");
  snmpget_setup();
}
