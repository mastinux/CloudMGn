//
// Generated file, do not edit! Created by nedtool 4.6 from src/CloudAppJob.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "CloudAppJob_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}



namespace cloudMGn {

// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(CloudAppJob);

CloudAppJob::CloudAppJob(const char *name, int kind) : ::cMessage(name,kind)
{
    this->startTime_var = 0;
    this->queuingTime_var = 0;
    this->serviceTime_var = 0;
    this->delayTime_var = 0;
    this->queueCount_var = 0;
    this->delayCount_var = 0;
    this->appId_var = 0;
}

CloudAppJob::CloudAppJob(const CloudAppJob& other) : ::cMessage(other)
{
    copy(other);
}

CloudAppJob::~CloudAppJob()
{
}

CloudAppJob& CloudAppJob::operator=(const CloudAppJob& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void CloudAppJob::copy(const CloudAppJob& other)
{
    this->startTime_var = other.startTime_var;
    this->queuingTime_var = other.queuingTime_var;
    this->serviceTime_var = other.serviceTime_var;
    this->delayTime_var = other.delayTime_var;
    this->queueCount_var = other.queueCount_var;
    this->delayCount_var = other.delayCount_var;
    this->appId_var = other.appId_var;
}

void CloudAppJob::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->startTime_var);
    doPacking(b,this->queuingTime_var);
    doPacking(b,this->serviceTime_var);
    doPacking(b,this->delayTime_var);
    doPacking(b,this->queueCount_var);
    doPacking(b,this->delayCount_var);
    doPacking(b,this->appId_var);
}

void CloudAppJob::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->startTime_var);
    doUnpacking(b,this->queuingTime_var);
    doUnpacking(b,this->serviceTime_var);
    doUnpacking(b,this->delayTime_var);
    doUnpacking(b,this->queueCount_var);
    doUnpacking(b,this->delayCount_var);
    doUnpacking(b,this->appId_var);
}

simtime_t CloudAppJob::getStartTime() const
{
    return startTime_var;
}

void CloudAppJob::setStartTime(simtime_t startTime)
{
    this->startTime_var = startTime;
}

simtime_t CloudAppJob::getQueuingTime() const
{
    return queuingTime_var;
}

void CloudAppJob::setQueuingTime(simtime_t queuingTime)
{
    this->queuingTime_var = queuingTime;
}

simtime_t CloudAppJob::getServiceTime() const
{
    return serviceTime_var;
}

void CloudAppJob::setServiceTime(simtime_t serviceTime)
{
    this->serviceTime_var = serviceTime;
}

simtime_t CloudAppJob::getDelayTime() const
{
    return delayTime_var;
}

void CloudAppJob::setDelayTime(simtime_t delayTime)
{
    this->delayTime_var = delayTime;
}

int CloudAppJob::getQueueCount() const
{
    return queueCount_var;
}

void CloudAppJob::setQueueCount(int queueCount)
{
    this->queueCount_var = queueCount;
}

int CloudAppJob::getDelayCount() const
{
    return delayCount_var;
}

void CloudAppJob::setDelayCount(int delayCount)
{
    this->delayCount_var = delayCount;
}

int CloudAppJob::getAppId() const
{
    return appId_var;
}

void CloudAppJob::setAppId(int appId)
{
    this->appId_var = appId;
}

// TODO metodi da usare per utilizzare i dati nel file delle tracce
int CloudAppJob::getJobId() const
{
    return jobId_var;
}

void CloudAppJob::setJobId(int jobId)
{
    this->jobId_var = jobId;
}

class CloudAppJobDescriptor : public cClassDescriptor
{
  public:
    CloudAppJobDescriptor();
    virtual ~CloudAppJobDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(CloudAppJobDescriptor);

CloudAppJobDescriptor::CloudAppJobDescriptor() : cClassDescriptor("cloudMGn::CloudAppJob", "cMessage")
{
}

CloudAppJobDescriptor::~CloudAppJobDescriptor()
{
}

bool CloudAppJobDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CloudAppJob *>(obj)!=NULL;
}

const char *CloudAppJobDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CloudAppJobDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int CloudAppJobDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *CloudAppJobDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "startTime",
        "queuingTime",
        "serviceTime",
        "delayTime",
        "queueCount",
        "delayCount",
        "appId",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int CloudAppJobDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "startTime")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "queuingTime")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceTime")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayTime")==0) return base+3;
    if (fieldName[0]=='q' && strcmp(fieldName, "queueCount")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayCount")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "appId")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CloudAppJobDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *CloudAppJobDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int CloudAppJobDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CloudAppJob *pp = (CloudAppJob *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CloudAppJobDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CloudAppJob *pp = (CloudAppJob *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getStartTime());
        case 1: return double2string(pp->getQueuingTime());
        case 2: return double2string(pp->getServiceTime());
        case 3: return double2string(pp->getDelayTime());
        case 4: return long2string(pp->getQueueCount());
        case 5: return long2string(pp->getDelayCount());
        case 6: return long2string(pp->getAppId());
        default: return "";
    }
}

bool CloudAppJobDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CloudAppJob *pp = (CloudAppJob *)object; (void)pp;
    switch (field) {
        case 0: pp->setStartTime(string2double(value)); return true;
        case 1: pp->setQueuingTime(string2double(value)); return true;
        case 2: pp->setServiceTime(string2double(value)); return true;
        case 3: pp->setDelayTime(string2double(value)); return true;
        case 4: pp->setQueueCount(string2long(value)); return true;
        case 5: pp->setDelayCount(string2long(value)); return true;
        case 6: pp->setAppId(string2long(value)); return true;
        default: return false;
    }
}

const char *CloudAppJobDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *CloudAppJobDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CloudAppJob *pp = (CloudAppJob *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace cloudMGn

