#ifndef STOPORDERSSERVICE_H
#define STOPORDERSSERVICE_H

#include <QObject>
#include "customservice.h"
#include <grpcpp/grpcpp.h>
#include "stoporders.grpc.pb.h"
#include "servicereply.h"

using grpc::Channel;
using namespace tinkoff::public1::invest::api::contract::v1;

class StopOrders: public CustomService
{
    Q_OBJECT
    Q_CLASSINFO("stoporders", "StopOrders Service")

public:  
    StopOrders(std::shared_ptr<Channel> channel, const QString &token);
    ~StopOrders();

public slots:
    //Метод выставления стоп-заявки
    ServiceReply PostStopOrder(const std::string &figi, int64_t quantity, int64_t units, int32_t nano, int64_t stopunits, int32_t stopnano, StopOrderDirection direction, const std::string &accountId, StopOrderExpirationType expirationType, StopOrderType stopOrderType, const std::string &orderId, int64_t expireSeconds, int32_t expireNanos);
    //Метод получения списка активных стоп заявок по счёту
    ServiceReply GetStopOrders(const std::string &accountId);
    //Метод отмены стоп-заявки
    ServiceReply CancelStopOrder(const std::string &accountId, const std::string &stopOrderId);

private:
    std::unique_ptr<StopOrdersService::Stub> m_stopOrdersService;

};

#endif // STOPORDERSSERVICE_H
