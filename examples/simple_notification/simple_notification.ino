/*
 Send a simple pushetta notification

 Send a notification every 3 seconds to a channel named Pushetta, all subscribers
 of this channel get a notification every time pushMessage is called
 
 The circuit:
 - No circuit required
 
 created 2014
 by Fabrizio Guglielmino
 
 This example code is in the public domain.
 
 More information about Pushetta is available at: 
 http://www.pushetta.com
 
 */

#include <Pushetta.h>
#include <Bridge.h>

// create a variable of type SpacebrewYun and initialize it with the constructor
Pushetta p = Pushetta("-- YOUR API KEY HERE --");

// Notification interval
int interval = 3000;

void setup() {

}

void loop() { 
  // Send a (very original) message to a channel named "Pushetta"
  p.pushMessage("Pushetta", "Hello World");
  
  // wait interval millisedonds before send a messege again
  delay(interval);
}
