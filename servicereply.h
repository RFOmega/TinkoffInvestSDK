#ifndef SERVICEREPLY_H
#define SERVICEREPLY_H

#include <QObject>
#include <QMetaType>
#include "google/protobuf/message.h"
#include "tinkoffinvestsdk_export.h"

class TINKOFFINVESTSDK_EXPORT ServiceReply
{

public:
    ServiceReply();
    ServiceReply(const std::shared_ptr<google::protobuf::Message> protoMsg);
    const std::shared_ptr<google::protobuf::Message> replyPtr();

private:
    std::shared_ptr<google::protobuf::Message> m_replyPtr;

};

Q_DECLARE_METATYPE(ServiceReply);

#endif // SERVICEREPLY_H
