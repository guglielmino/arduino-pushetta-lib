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
<<<<<<< Updated upstream
  String auth = " -H \"Authorization: Token " + apikey + "\"";
  String contentType = " -H \"Content-Type: application/json\"";
  String body = " -d '{ \"body\" : \"" + message + "\", \"expire\" : \"2020-01-01\", \"message_type\" : \"text/plain\" }'";
  String url = " http://api.pushetta.com/api/pushes/" + channelName + "/";

  String command = "curl -X POST" + auth + contentType + body + url;
  Console.println(command);
  return runShellCommand(command);
  
=======
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

  addParameter("http://api.pushetta.com/api/pushes/" + URLEncode(channelName) + "/");

  return run();
>>>>>>> Stashed changes
}


boolean Pushetta::ready() {
  return running();
}

unsigned int Pushetta::getResult() {
  return exitValue();
}

String URLEncode(const char* msg)
{
    const char *hex = "0123456789abcdef";
    String encodedMsg = "";

<<<<<<< Updated upstream

=======
    while (*msg!='\0'){
        if( ('a' <= *msg && *msg <= 'z')
                || ('A' <= *msg && *msg <= 'Z')
                || ('0' <= *msg && *msg <= '9') ) {
            encodedMsg += *msg;
        } else {
            encodedMsg += '%';
            encodedMsg += hex[*msg >> 4];
            encodedMsg += hex[*msg & 15];
        }
        msg++;
    }
    return encodedMsg;
}
>>>>>>> Stashed changes
