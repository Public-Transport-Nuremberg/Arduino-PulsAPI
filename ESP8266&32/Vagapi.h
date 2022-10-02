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
    String _timespan = "60";

public:
    String getStops(String stopName);
    String getDepartures(int stopID, int limit);
};
#endif