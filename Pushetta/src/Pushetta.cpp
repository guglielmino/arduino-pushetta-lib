/*
 * Copyright (C) 2014 Fabrizio Guglielmino <guglielmino@gumino.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Pushetta.h"


Pushetta::Pushetta(const String& _apikey){
  apikey = _apikey;
}


unsigned int Pushetta::pushMessage(const String& channelName, const String& message) {
  begin("curl");
  addParameter("-H");
  addParameter("Authorization: Token " + apikey);
  addParameter("-H");
  addParameter("Content-Type: application/json");
  addParameter("-X POST");
  addParameter("-d");

  String *body = new String("{ \"body\" : ");
  *body += "\"" + message + "\",";
  *body += "\"expire\" : \"2020-01-01\",";
  *body += "\"mime_type\" : \"text/plain\"}";

  addParameter((const String&)body);

  addParameter("http://api.pushetta.com/api/pushes/" + channelName + "/");

  return run();
}


boolean Pushetta::ready() {
  return running();
}

unsigned int Pushetta::getResult() {
  return exitValue();
}


