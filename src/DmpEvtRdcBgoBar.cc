/*
 *  $Id: DmpEvtRdcBgoBar.cc, 2014-08-06 23:49:24 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/04/2014
*/

#include "DmpEvtRdcBgoBar.h"

//-------------------------------------------------------------------
_DmpBgoSignal::_DmpBgoSignal()
 :FeeID(-1),FeeChannelID(-1),SideID(-1),DynodeID(-1),ADCCount(-1000)
{}

//-------------------------------------------------------------------
_DmpBgoSignal::_DmpBgoSignal(const _DmpBgoSignal &r){
  FeeID = r.FeeID;
  FeeChannelID = r.FeeChannelID;
  SideID = r.SideID;
  DynodeID = r.DynodeID;
  ADCCount = r.ADCCount;
}

//-------------------------------------------------------------------
DmpEvtRdcBgoBar::DmpEvtRdcBgoBar()
 :fLayerID(-1),
  fBarID(-1)
{
}

//-------------------------------------------------------------------
DmpEvtRdcBgoBar::~DmpEvtRdcBgoBar(){
}

//-------------------------------------------------------------------
short DmpEvtRdcBgoBar::GetSignal(const short &side,const short &dynodeID) const{
  short index = SignalIndex(side,dynodeID);
  if(-1 != index){
    return fSignal[index].ADCCount;
  }
  return -100;
}

//-------------------------------------------------------------------
short DmpEvtRdcBgoBar::GetFeeID(const short &side,const short &dynodeID) const{
  short index = SignalIndex(side,dynodeID);
  if(-1 != index){
    return fSignal[index].FeeID;
  }
  return -100;
}

//-------------------------------------------------------------------
short DmpEvtRdcBgoBar::GetFeeChannelID(const short &side,const short &dynodeID) const{
  short index = SignalIndex(side,dynodeID);
  if(-1 != index){
    return fSignal[index].FeeChannelID;
  }
  return -100;
}

//-------------------------------------------------------------------
short DmpEvtRdcBgoBar::GetGlocalFeeChannelID(const short &side,const short &dynodeID) const{
  short index = SignalIndex(side,dynodeID);
  if(-1 != index){
    return fSignal[index].FeeID*1000 + fSignal[index].FeeChannelID;
  }
  return -100;
}

//-------------------------------------------------------------------
short DmpEvtRdcBgoBar::SignalIndex(const short &side,const short &dynodeID)const{
  for(short i=0;i<fSignal.size();++i){
    if(fSignal[i].SideID == side && fSignal[i].DynodeID == dynodeID){
      return i;
    }
  }
  return -1;
}

