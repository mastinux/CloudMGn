//
// Generated file, do not edit! Created by nedtool 4.6 from src/CloudAppJob.msg.
//

#ifndef _CLOUDMGN_CLOUDAPPJOB_M_H_
#define _CLOUDMGN_CLOUDAPPJOB_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace cloudMGn {

/**
 * Class generated from <tt>src/CloudAppJob.msg:21</tt> by nedtool.
 * <pre>
 * //
 * // CloudAppJob message definition for M/G/n simulations
 * //
 * message CloudAppJob
 * {
 *     //@customize(true);
 *     simtime_t startTime; 		// time the message is sent
 *     simtime_t queuingTime; 		// total time spent standing in queues
 *     simtime_t serviceTime;  	// total time spent in servers
 *     simtime_t delayTime;    	// total time spent in delay modules
 *     int queueCount;             // the number of queue modules visited by the job
 *     int delayCount;             // the number of delay modules visited by the job
 *     int appId;					// ID of thc considered cloud App
 * }
 * </pre>
 */
class CloudAppJob : public ::cMessage
{
  protected:
    simtime_t startTime_var;
    simtime_t queuingTime_var;
    simtime_t serviceTime_var;
    simtime_t delayTime_var;
    int queueCount_var;
    int delayCount_var;
    int appId_var;
    int jobId_var;

  private:
    void copy(const CloudAppJob& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CloudAppJob&);

  public:
    CloudAppJob(const char *name=NULL, int kind=0);
    CloudAppJob(const CloudAppJob& other);
    virtual ~CloudAppJob();
    CloudAppJob& operator=(const CloudAppJob& other);
    virtual CloudAppJob *dup() const {return new CloudAppJob(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getStartTime() const;
    virtual void setStartTime(simtime_t startTime);
    virtual simtime_t getQueuingTime() const;
    virtual void setQueuingTime(simtime_t queuingTime);
    virtual simtime_t getServiceTime() const;
    virtual void setServiceTime(simtime_t serviceTime);
    virtual simtime_t getDelayTime() const;
    virtual void setDelayTime(simtime_t delayTime);
    virtual int getQueueCount() const;
    virtual void setQueueCount(int queueCount);
    virtual int getDelayCount() const;
    virtual void setDelayCount(int delayCount);
    virtual int getAppId() const;
    virtual void setAppId(int appId);
    virtual int getJobId() const;
    virtual void setJobId(int jobId);
};

inline void doPacking(cCommBuffer *b, CloudAppJob& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CloudAppJob& obj) {obj.parsimUnpack(b);}

} // namespace cloudMGn

#endif // ifndef _CLOUDMGN_CLOUDAPPJOB_M_H_

