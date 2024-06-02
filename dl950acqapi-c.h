#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef long ScHandle_c;

// We do not rename these constants,
// as it is safe to have multiple `#define`s with the same definition.
// If the original library changes the value, we also have to change this too.
#define SC_SUCCESS				0	//!< success
#define SC_ERROR				1	//!< error

// wire type
#define SC_WIRE_USBTMC			12	//!< USB lineiYTUSBj
#define SC_WIRE_VISAUSB			10	//!< USB lineiVISAUSBj
#define SC_WIRE_VXI11			8	//!< VXI-11
#define SC_WIRE_HISLIP			14	//!< HiSLIP

// mode
#define SC_FREERUN				20
#define SC_TRIGGER				22
#define SC_TRIGGER_ASYNC		23

// type
#define SC_EVENTTYPE_OVERRUN	30
#define SC_EVENTTYPE_TRIGGEREND	31

/*!
 * \brief for Register event callback
 */
typedef void(__stdcall *ScCallback_c)(ScHandle_c handle, int type);

/*!
 * \brief
 */
typedef int ScResult_c;

/*!
* \brief begin the use of the API
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error (already initialized)
*/
ScResult_c ScInit_c(void);

/*!
* \brief end the use of the API
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error (already end or not initialized)
*/
ScResult_c ScExit_c(void);

/*!
* \brief open instrument and get API handle
* \note connect and free run mode
* \param wire wire type
*             (SC_WIRE_USBTMC/SC_WIRE_VISAUSB/SC_WIRE_VXI11/SC_WIRE_HISLIP)
* \param option  serial number / address
*               "192.168.0.1"
* \param mode connection mode
* \param rHndl return handle
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScOpenInstrument_c(int wire, char* address, int mode, ScHandle_c* rHndl);

/*!
* \brief close instrument (disconnect instrument and move trigger mode)
* \param hndl API handle
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScCloseInstrument_c(ScHandle_c hndl);

/*!
* \brief send command to instrument
* \param hndl API handle
* \param command command
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScSetControl_c(ScHandle_c hndl, char* command);

/*!
* \brief receive command reply from instrument
* \param hndl API handle
* \param buff pointer to receive buffer
* \param buffLen size of receive buffer(byte)
* \param receiveLen receive length
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetControl_c(ScHandle_c hndll, char* buff, int buffLen, int* receiveLen);

/*!
* \brief receive binary data from instrument
* \param hndl API handle
* \param buff pointer to receive buffer
* \param buffLength size of receive buffer(byte)
* \parma receiveLength receive length
* \parma endFlg receive end flag
* \retval result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetBinaryData_c(ScHandle_c hndl, char* command, char* buff, int buffLen, int* receiveLen, int* endFlg);

/*!
* \brief acquisition start
* \param hndl API handle
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScStart_c(ScHandle_c hndl);

/*!
* \brief acquisition stop
* \param hndl API handle
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScStop_c(ScHandle_c hndl);

/*!
* \brief LATCH on free run
* \param hndl API handle
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScLatchData_c(ScHandle_c hndl);

/*!
 * \brief get wave data after LATCH
 * \param hndl API handle
 * \param buff pointer to receive buffer
 * \param bufLen size of receive buffer(byte)
 * \param receiveLen length of receive data
 * \param endFlg receive end flag
 * \return result
 * \retval SC_SUCCESS success
 * \retval SC_ERROR error
 */
ScResult_c ScGetLatchRawData_c(ScHandle_c hndl, char* buff, int buffLen, int* receiveLen, int* endFlg);

/*
* \brief set sampling rate
* \param hndl API handle
* \param srate sampling rate
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScSetSamplingRate_c(ScHandle_c handle, double srate);

/*
* \brief get sampling rate
* \param hndl API handle
* \param srate sampling rate
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetSamplingRate_c(ScHandle_c handle, double* srate);

/*!
* \brief get sampling rate
* \param hndl API handle
* \parma chNo channel number
* \param subChNo sub channel number(0:no sub channel, 1-60)
* \param srate sampling rate
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetChannelSamplingRate_c(ScHandle_c hndl, int chNo, int subChNo, double* srate);

/*!
 * \brief get data bit count
 * \param chNo channel number(1`16)
 * \param subChNo sub channel number(0:no sub channel, 1-60)
 * \param bits pointer to valiable of bit count
 * \return result
 * \retval SC_SUCCESS success
 * \retval SC_ERROR error
 */
ScResult_c ScGetChannelBits_c(ScHandle_c hndl, int chNo, int subChNo, int* bits);

/*!
* \brief get gain value when using convert to scaled value
* \note including liniar scale value
* \param hndl API handle
* \parma chNo channel number
* \param subChNo sub channel number(0:no sub channdl, 1-60)
* \parma gain pointer to valiable of gain value
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetChannelGain_c(ScHandle_c hndl, int chNo, int subChNo, double* gain);

/*!
* \brief get offset value when using convert to scale value
* \note including liniar scale value
* \param hndl API handle
* \parma chNo channel number
* \param subChNo sub channel number(0:no sub channel, 1-60)
* \parma offset pointer to valiable of offset value
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetChannelOffset_c(ScHandle_c hndl, int chNo, int subChNo, double* offset);

/*!
* \brief send command to instrument and receive data
* \param hndl API handle
* \param message command
* \param buff pointer to receive buffer
* \param buffLength length of buffer
* \param receiveLength length of receive data
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScQueryMessage_c(ScHandle_c hndl, char* command, char* buff, int buffLen, int* receiveLen);

// Pending: replace with function pointer
// /*!
// * \brief add event listener
// * \param hndl API handle
// * \param listener point to event listener object
// * \return result
// * \retval SC_SUCCESS success
// * \retval SC_ERROR error
// */
// ScResult_c ScAddEventListener_c(ScHandle_c hndl, ScEventListener_c* listener);
// 
// /*!
// * \brief delete event listener
// * \param hndl API handle
// * \param listener pointer to event listener object
// * \return result
// * \retval SC_SUCCESS success
// * \retval SC_ERROR error
// */
// ScResult_c ScRemoveEventListener_c(ScHandle_c hndl, ScEventListener_c* listener);

/*!
* \brief add call back
* \param hndl API handle
* \param func call back function
* \param type event type
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScAddCallback_c(int hndl, ScCallback_c func, int type);

/*!
* \brief remove call back
* \param hndl API handle
* \param func call back function
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScRemoveCallback_c(ScHandle_c hndl, ScCallback_c func);

/*!
* \brief get channel type
* \param hndl API handle
* \parma chNo channel number
* \param subChNo sub channel number(0:no sub channel, 1-60)
* \parma type pointer to valiable of channel type
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetChannelType_c(ScHandle_c hndl, int chNo, int subChNo, char* type);

/*!
 * \brief get wave data after LATCH
 * \parma chNo channel number
 * \param subChNo sub channel number(0:no sub channel, 1-60)
 * \param buff pointer to receive buffer
 * \param length size of receive buffer(byte)
 * \param chOffset offset of target ch data
 * \param chSize bit size of target ch data
 * \param timeSec sec size of target ch data
 * \param timeTick tick size of target ch data
 * \return result
 * \retval SC_SUCCESS success
 * \retval SC_ERROR error
 */
ScResult_c ScGetChAcqData_c(int chNo, int subChNo, char* buff, int length, int* chOffset, int* chSize, unsigned int* timeSec, unsigned int* timeTick);

/*!
* \brief set 10G mode
* \param hndl API handle
* \parma onoff 10G mode
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScSet10GMode_c(ScHandle_c hndl, int onoff);

/*!
* \brief get 10G mode
* \param hndl API handle
* \parma onoff 10G mode
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGet10GMode_c(ScHandle_c hndl, int *onoff);

/*!
* \brief get latch acquition count 
* \param hndl API handle
* \parma count acq count
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetLatchAcqCount_c(ScHandle_c hndl, __int64* count);

/*!
 * \brief get wave data after LATCH
 * \param hndl API handle
 * \parma chNo channel number
 * \param subChNo sub channel number(0:no sub channel, 1-60)
 * \param length data length
 * \return result
 * \retval SC_SUCCESS success
 * \retval SC_ERROR error
 */
ScResult_c ScGetAcqDataLength_c(ScHandle_c hndl, int chNo, int subChNo, __int64* length);

/*!
 * \brief get wave data after LATCH
 * \param hndl API handle
 * \parma chNo channel number
 * \param subChNo sub channel number(0:no sub channel, 1-60)
 * \param buff pointer to receive buffer
 * \param bufLen size of receive buffer(byte)
 * \param receiveLen length of receive data
 * \param endFlg receiving completion flag
 * \param timeSec head of receiving data time(UnixTime)
 * \param timeTick head of receiving data time(nano sec)
 * \return result
 * \retval SC_SUCCESS success
 * \retval SC_ERROR error
 */
ScResult_c ScGetAcqData_c(ScHandle_c hndl, int chNo, int subChNo, char* buff, int buffLen, int* receiveLen, int* endFlg, unsigned int* timeSec, unsigned int* timeTick);

/*!
* \brief set trigger time out
* \param hndl API handle
* \parma timeout trigger timeout
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScSetTriggerTimeout_c(ScHandle_c hndl, int timeout);

/*!
* \brief get trigger time out
* \param hndl API handle
* \parma timeout trigger timeout
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetTriggerTimeout_c(ScHandle_c hndl, int *timeout);

/*!
* \brief get acquition count
* \param hndl API handle
* \parma count acq count
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetAcqCount_c(ScHandle_c hndl, __int64* count);

/*!
* \brief set acquition count
* \param hndl API handle
* \parma count acq count
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScSetAcqCount_c(ScHandle_c hndl, __int64 count);

/*!
* \brief get trigger time
* \param hndl API handle
* \parma buff trigger time
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetTriggerTime_c(ScHandle_c hndl, char* buff);

/*!
* \brief send dl950 trigger enable
* \param hndl API handle
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScResumeAcquisition_c(ScHandle_c hndl);

/*!
* \brief get max history count
* \param hndl API handle
* \param count max history count
* \return result
* \retval SC_SUCCESS success
* \retval SC_ERROR error
*/
ScResult_c ScGetMaxHistoryCount_c(ScHandle_c hndl, int *count);

/*!
 * \brief get waveform scale
 * \param hndl API handle
 * \parma chNo channel number
 * \param subChNo sub channel number(0:no sub channel, 1-60)
 * \param upper pointer to upper scale
 * \param lower pointer to lower scale
 * \return result
 * \retval SC_SUCCESS success
 * \retval SC_ERROR error
 */
ScResult_c ScGetChannelScale_c(ScHandle_c hndl, int chNo, int subChNo, double* upper, double* lower);

#ifdef __cplusplus
}
#endif
