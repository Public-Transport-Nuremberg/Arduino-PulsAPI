# VAG Puls API for Arduino
 Exports a simple class with basic functions to interface the API.  
 Every function will return a json compatible string.

```c++
// Optional
#include <Arduino_JSON.h> // Import a JSON Parser, can be any JSON parser
// Required
#include <Vagapi.h> // Import the class
Vagapi vag;  // Use the class

JSONVar getStop_request = JSON.parse(vag.getStop("Opernhaus")); // Returns stops that match the seach
JSONVar getDepartures_request = JSON.parse(vag.getDepartures(704, 3)); // Returns departures of a given station
```