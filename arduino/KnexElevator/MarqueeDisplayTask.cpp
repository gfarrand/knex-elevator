// /////////////////////////////////////////////////////////////////////////////
//
// MIT License
//
// Copyright (c) 2017 gfarrand (grant.farrand@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// /////////////////////////////////////////////////////////////////////////////


// /////////////////////////////////////////////////////////////////////////////
// Include(s)
// /////////////////////////////////////////////////////////////////////////////
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>

#include "MarqueeDisplayTask.h"


////////////////////////////////////////////////////////////////////////////////
MarqueeDisplayTask::MarqueeDisplayTask(void)
    : ITask(__FUNCTION__, ITask::Defaults::Priority, 200)
{
    // Intentionally left empty
}


////////////////////////////////////////////////////////////////////////////////
MarqueeDisplayTask::~MarqueeDisplayTask(void)
{
    // Intentionally left empty
}


////////////////////////////////////////////////////////////////////////////////
void
MarqueeDisplayTask::Initialize(void)
{
    // Intentionally left empty for now
}


////////////////////////////////////////////////////////////////////////////////
void
MarqueeDisplayTask::Run(void)
{
    Serial.print("ENTER: ");
    Serial.println(__PRETTY_FUNCTION__);

    while (true)
    {
        char timeStampStringBuf[15+1];
        snprintf(timeStampStringBuf,
                 sizeof(timeStampStringBuf),
                 "[%09li]",
                 micros());
        Serial.print(timeStampStringBuf);
        Serial.print(" Hello from ");
        Serial.println(__PRETTY_FUNCTION__);

        // And print again in a second
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

