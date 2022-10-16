#include "vagapi.h"

WEBResponse makerequest(String serverPath)
{
    HTTPClient http;

    http.begin(serverPath.c_str());
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0)
    {
        WEBResponse data;
        data.httpcode = httpResponseCode;
        data.response = http.getString();

        // Free resources
        http.end();

        return data;
    }
    else
    {
        WEBResponse data;
        data.httpcode = 0;
        data.response = "";
        return data;
    }
}

void Vagapi::setProduct(String product)
{
    this->_product = product;
}

void Vagapi::setTimespan(int timespan)
{
    this->_timespan = timespan;
}

String Vagapi::getStops(String stopName)
{
    String serverPath = _VAGURL + "/haltestellen.json/vgn?name=" + urlEncode(stopName);
    WEBResponse request = makerequest(serverPath);
    if (request.httpcode == 200)
    {
        return request.response;
    }
    else
    {
        return request.response;
    }
}

String Vagapi::getStopsGPS(double lat, double lon, int distance)
{   
    String serverPath = _VAGURL + "/haltestellen.json/vgn/location?lon=" + lon + "&lat=" + lat + "&radius=" + distance;
    Serial.println(distance);
    WEBResponse request = makerequest(serverPath);
    if (request.httpcode == 200)
    {
        return request.response;
    }
    else
    {
        return request.response;
    }

}

String Vagapi::getDepartures(int stopID, int limit)
{
    String serverPath = _VAGURL + "/abfahrten.json/vgn/" + stopID + "?timespan=" + _timespan + "&limitcount=" + limit + "&product=" + _product ;
    WEBResponse request = makerequest(serverPath);
    if (request.httpcode == 200)
    {
        return request.response;
    }
    else
    {
        return request.response;
    }
}