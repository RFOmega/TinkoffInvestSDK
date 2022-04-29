#ifndef MARKETDATAERVICE_H
#define MARKETDATASERVICE_H

#include <QObject>
#include "customservice.h"
#include <grpcpp/grpcpp.h>
#include "marketdata.grpc.pb.h"
#include "servicereply.h"

using grpc::Channel;
using namespace tinkoff::public1::invest::api::contract::v1;

class MarketData: public CustomService
{
    Q_OBJECT
    Q_CLASSINFO("marketdata", "MarketData Service")

public:  
    MarketData(std::shared_ptr<Channel> channel, const QString &token);

public slots:
    //Метод запроса исторических свечей по инструменту
    ServiceReply GetCandles(const std::string &figi, int64_t fromseconds, int32_t fromnanos, CandleInterval interval = CandleInterval::CANDLE_INTERVAL_UNSPECIFIED);
    //Метод запроса последних цен по инструментам
    ServiceReply GetLastPrices(const std::vector<std::string> &figis);
    //Метод получения стакана по инструменту
    ServiceReply GetOrderBook(const std::string &figi, int32_t depth);
    //Метод запроса статуса торгов по инструментам
    ServiceReply GetTradingStatus(const std::string &figi);
    //Метод запроса последних обезличенных сделок по инструменту
    ServiceReply GetLastTrades(const std::string &figi, int64_t fromseconds, int32_t fromnanos);
    //Bi-directional стрим предоставления биржевой информации.
    ServiceReply MarketDataStream();

private:
    std::unique_ptr<MarketDataService::Stub> m_marketDataService;
    std::unique_ptr<MarketDataService::StreamedUnaryService> m_marketDataStreamService;

};

#endif // MARKETDATASERVICE_H