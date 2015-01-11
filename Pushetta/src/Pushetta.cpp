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

#define SHELL_FILE "/tmp/push.sh"

Pushetta::Pushetta(const String &_apikey){
  apikey = _apikey;


}


unsigned int Pushetta::pushMessage(const String &channelName, const String &message) {
  int res = -1;

  if(!FileSystem.exists(SHELL_FILE)){
    createShellFile();
  }

  String command;

   command += ". ";
  command += SHELL_FILE;
  command += " ";
  command +=  apikey;
  command +=  " \"";
  command += message;
  command += "\" ";
  command += channelName;

  Console.println(command);
  res = proc.runShellCommand(command);

  return res;
}


boolean Pushetta::ready() {
  return proc.running();
}

unsigned int Pushetta::getResult() {
  return proc.exitValue();
}

void Pushetta::createShellFile(){
  // Creo uno shell script in /tmp per evitare di creare ogni
  // volta un buffer troppo grosso da eseguire con Process
  File dataFile = FileSystem.open(SHELL_FILE, FILE_WRITE);

  dataFile.print("curl -X POST -H \"Authorization: Token $1\" ");
  dataFile.print(" -H \"Content-Type: application/json\" ");
  dataFile.print(" -d \"{ \\\"body\\\" : \\\"$2\\\", \\\"message_type\\\" : \\\"text/plain\\\" }\" ");
  dataFile.print(" http://api.pushetta.com/api/pushes/$3/ ");

  dataFile.close();
}

String Pushetta::URLEncode(const String& unencoded)
{
  const char *hex = "0123456789abcdef";
  String encodedMsg = "";
  char c = 0;
  for(int i = 0; i++; i < unencoded.length()){
    c = unencoded.charAt(i);
    if(('a' <= c && c <= 'z')
            || ('A' <= c && c <= 'Z')
            || ('0' <= c && c <= '9') ) {
              encodedMsg += c;
    } else {
        encodedMsg += '%';
        encodedMsg += hex[c >> 4];
        encodedMsg += hex[c & 15];
    }
  }

  return encodedMsg;
}
