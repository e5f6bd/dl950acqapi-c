#include <DL950ACQAPI.h>
#include "dl950acqapi-c.h"

ScResult_c ScInit_c(void) {
  return ScInit();
}

ScResult_c ScExit_c(void) {
  return ScExit();
}

ScResult_c ScOpenInstrument_c(int wire, char* address, int mode, ScHandle_c* rHndl) {
  return ScOpenInstrument(wire, address, mode, rHndl);
}

ScResult_c ScCloseInstrument_c(ScHandle_c hndl) {
  return ScCloseInstrument(hndl);
}

ScResult_c ScSetControl_c(ScHandle_c hndl, char* command) {
  return ScSetControl(hndl, command);
}

ScResult_c ScGetControl_c(ScHandle_c hndll, char* buff, int buffLen, int* receiveLen) {
  return ScGetControl(hndll, buff, buffLen, receiveLen);
}

ScResult_c ScGetBinaryData_c(ScHandle_c hndl, char* command, char* buff, int buffLen, int* receiveLen, int* endFlg) {
  return ScGetBinaryData(hndl, command, buff, buffLen, receiveLen, endFlg);
}

ScResult_c ScStart_c(ScHandle_c hndl) {
  return ScStart(hndl);
}

ScResult_c ScStop_c(ScHandle_c hndl) {
  return ScStop(hndl);
}

ScResult_c ScLatchData_c(ScHandle_c hndl) {
  return ScLatchData(hndl);
}

ScResult_c ScGetLatchRawData_c(ScHandle_c hndl, char* buff, int buffLen, int* receiveLen, int* endFlg) {
  return ScGetLatchRawData(hndl, buff, buffLen, receiveLen, endFlg);
}

ScResult_c ScSetSamplingRate_c(ScHandle_c handle, double srate) {
  return ScSetSamplingRate(handle, srate);
}

ScResult_c ScGetSamplingRate_c(ScHandle_c handle, double* srate) {
  return ScGetSamplingRate(handle, srate);
}

ScResult_c ScGetChannelSamplingRate_c(ScHandle_c hndl, int chNo, int subChNo, double* srate) {
  return ScGetChannelSamplingRate(hndl, chNo, subChNo, srate);
}

ScResult_c ScGetChannelBits_c(ScHandle_c hndl, int chNo, int subChNo, int* bits) {
  return ScGetChannelBits(hndl, chNo, subChNo, bits);
}

ScResult_c ScGetChannelGain_c(ScHandle_c hndl, int chNo, int subChNo, double* gain) {
  return ScGetChannelGain(hndl, chNo, subChNo, gain);
}

ScResult_c ScGetChannelOffset_c(ScHandle_c hndl, int chNo, int subChNo, double* offset) {
  return ScGetChannelOffset(hndl, chNo, subChNo, offset);
}

ScResult_c ScQueryMessage_c(ScHandle_c hndl, char* command, char* buff, int buffLen, int* receiveLen) {
  return ScQueryMessage(hndl, command, buff, buffLen, receiveLen);
}

// Pending: replace with function pointer
// ScResult_c ScAddEventListener_c(ScHandle_c hndl, ScEventListener_c* listener) {
//   return ScAddEventListener(hndl, listener);
// }
// 
// ScResult_c ScRemoveEventListener_c(ScHandle_c hndl, ScEventListener_c* listener) {
//   return ScRemoveEventListener(hndl, listener);
// }

ScResult_c ScAddCallback_c(int hndl, ScCallback_c func, int type) {
  return ScAddCallback(hndl, func, type);
}

ScResult_c ScRemoveCallback_c(ScHandle_c hndl, ScCallback_c func) {
  return ScRemoveCallback(hndl, func);
}

ScResult_c ScGetChannelType_c(ScHandle_c hndl, int chNo, int subChNo, char* type) {
  return ScGetChannelType(hndl, chNo, subChNo, type);
}

ScResult_c ScGetChAcqData_c(int chNo, int subChNo, char* buff, int length, int* chOffset, int* chSize, unsigned int* timeSec, unsigned int* timeTick) {
  return ScGetChAcqData(chNo, subChNo, buff, length, chOffset, chSize, timeSec, timeTick);
}

ScResult_c ScSet10GMode_c(ScHandle_c hndl, int onoff) {
  return ScSet10GMode(hndl, onoff);
}

ScResult_c ScGet10GMode_c(ScHandle_c hndl, int *onoff) {
  return ScGet10GMode(hndl, onoff);
}

ScResult_c ScGetLatchAcqCount_c(ScHandle_c hndl, __int64* count) {
  return ScGetLatchAcqCount(hndl, count);
}

ScResult_c ScGetAcqDataLength_c(ScHandle_c hndl, int chNo, int subChNo, __int64* length) {
  return ScGetAcqDataLength(hndl, chNo, subChNo, length);
}

ScResult_c ScGetAcqData_c(ScHandle_c hndl, int chNo, int subChNo, char* buff, int buffLen, int* receiveLen, int* endFlg, unsigned int* timeSec, unsigned int* timeTick) {
  return ScGetAcqData(hndl, chNo, subChNo, buff, buffLen, receiveLen, endFlg, timeSec, timeTick);
}

ScResult_c ScSetTriggerTimeout_c(ScHandle_c hndl, int timeout) {
  return ScSetTriggerTimeout(hndl, timeout);
}

ScResult_c ScGetTriggerTimeout_c(ScHandle_c hndl, int *timeout) {
  return ScGetTriggerTimeout(hndl, timeout);
}

ScResult_c ScGetAcqCount_c(ScHandle_c hndl, __int64* count) {
  return ScGetAcqCount(hndl, count);
}

ScResult_c ScSetAcqCount_c(ScHandle_c hndl, __int64 count) {
  return ScSetAcqCount(hndl, count);
}

ScResult_c ScGetTriggerTime_c(ScHandle_c hndl, char* buff) {
  return ScGetTriggerTime(hndl, buff);
}

ScResult_c ScResumeAcquisition_c(ScHandle_c hndl) {
  return ScResumeAcquisition(hndl);
}

ScResult_c ScGetMaxHistoryCount_c(ScHandle_c hndl, int *count) {
  return ScGetMaxHistoryCount(hndl, count);
}

ScResult_c ScGetChannelScale_c(ScHandle_c hndl, int chNo, int subChNo, double* upper, double* lower) {
  return ScGetChannelScale(hndl, chNo, subChNo, upper, lower);
}
