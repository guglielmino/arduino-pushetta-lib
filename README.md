# arduino-pushetta-lib

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/guglielmino/arduino-pushetta-lib?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Pushetta is a Web API that provides an unificated way to send realtime notifications to multiple devices. Used with Arduino Yun it's possible to send alert, informations or any data in realtime to groups of subscribers (more on www.pushetta.com)

# Usage

To use Pushetta in Your sketch download sources and follow official instructions You can find http://arduino.cc/en/pmwiki.php?n=Guide/Libraries

After installig Pushetta lib You can try it with this simple sketck

```
#include <Bridge.h>
#include <Pushetta.h>

Pushetta pushetta("API KEY");

void setup() {
  Bridge.begin();
}

void loop() {
  pushetta.pushMessage("MyChannel", "Hello World"); // Send a message to "MyChannel" subscribers
  delay(1000);  // waits for a second
}
```

'API KEY' must be replaced with the one You can get on pushetta web site after signin (in the dashboard), and 'MyChannel' should be replaced with a channel name You made.

