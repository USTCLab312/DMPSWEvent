/*
 *  $Id: DmpEvtRdcBgoBar.h, 2014-08-06 23:18:22 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/04/2014
*/

#ifndef DmpEvtRdcBgoBar_H
#define DmpEvtRdcBgoBar_H

#include "TObject.h"

struct _DmpBgoSignal{
  _DmpBgoSignal();
  //:FeeID(-1),FeeChannelID(-1),SideID(-1),DynodeID(-1),ADCCount(-1){}
  _DmpBgoSignal(const _DmpBgoSignal &right);
  
  short FeeID;      // 0x{0,1,a,b,8,9...} 
  short FeeChannelID;   // 0~156,78
  short SideID;     // 0, 1
  short DynodeID;   // 2, 5, 8
  short ADCCount;
  ClassDef(_DmpBgoSignal,1)
};

class DmpEvtRdcBgoBar : public TObject{
/*
 *  DmpEvtRdcBgoBar
 *
 *      this class is used to save output of Rdc for Bgo
 *
 *   one object mean one Bgo bar, a set of signal
 *
 */
public:
  DmpEvtRdcBgoBar();
  ~DmpEvtRdcBgoBar();
  short GetLayerID() const {return fLayerID;}
  short GetBarID() const {return fBarID;}   // in one layer
  short GetGlobalBarID() const {return fLayerID*100+fBarID;} // in whole layer
  void  AddOneSignal(const _DmpBgoSignal &value) {fSignal.push_back(value);}
  std::vector<_DmpBgoSignal> GetSignal() const {return fSignal;}
  short GetSignal(const short &side,const short &dynodeID) const;

  short GetFeeID(const short &side,const short &dynodeID) const;
  short GetFeeChannelID(const short &side,const short &dynodeID) const;
  short GetGlocalFeeChannelID(const short &side,const short &dynodeID) const;
private:
  short SignalIndex(const short &side, const short &dynodeID)const;

private:
  short     fLayerID;           // layer id
  short     fBarID;             // bar id
  std::vector<_DmpBgoSignal>    fSignal;        // signal

  ClassDef(DmpEvtRdcBgoBar,1)
};

#endif

