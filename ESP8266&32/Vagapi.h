#ifndef VAGAPI_H
#define VAGAPI_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

struct WEBResponse
{
    int httpcode;
    String response;
};

class Vagapi
{

private:
    String _VAGURL = "https://start.vag.de/dm/api/v1";
    String _product = "Bus,Tram,UBahn";
    int _timespan = 60;

public:
    void setProduct(String product);
    void setTimespan(int timespan);

    String getStops(String stopName);
    String getStopsGPS(double lat, double lon, int distance = 500);
    String getDepartures(int stopID, int limit);
};
#endif