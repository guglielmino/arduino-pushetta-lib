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


#ifndef PUSHETTA_H_
#define PUSHETTA_H_

#include "Arduino.h"

#include "Process.h"
#include "FileIO.h"

class Pushetta  {

  public:

    Pushetta(const String &_apikey);

    unsigned int pushMessage(const String &channelName, const String &message);
    boolean ready();
    unsigned int getResult();

  private:
    String apikey;
    Process proc;

    String URLEncode(const String& unencoded);
    void createShellFile();

};

#endif /* PUSHETTA_H_ */
