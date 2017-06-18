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

#include "CarPositionCalculatorTask.h"


////////////////////////////////////////////////////////////////////////////////
CarPositionCalculatorTask::CarPositionCalculatorTask(String thread_name)
    : ITask(thread_name.c_str(), ITask::Defaults::Priority, 200)
    , mc_thread_name(thread_name)
{
    // Intentionally left empty
}


////////////////////////////////////////////////////////////////////////////////
CarPositionCalculatorTask::~CarPositionCalculatorTask(void)
{
    // Intentionally left empty
}


////////////////////////////////////////////////////////////////////////////////
void
CarPositionCalculatorTask::Initialize(void)
{
    // Nothing to initialize yet - will utilize I2C bus
}


////////////////////////////////////////////////////////////////////////////////
String
CarPositionCalculatorTask::get_name(void)
{
   return mc_thread_name;
}


////////////////////////////////////////////////////////////////////////////////
void
CarPositionCalculatorTask::Run(void)
{
    Serial.print("ENTER: ");
    Serial.print(__PRETTY_FUNCTION__);
    Serial.print("->");
    Serial.println(mc_thread_name);

    while (true)
    {
        char timeStampStringBuf[15+1];
        snprintf(timeStampStringBuf,
                 sizeof(timeStampStringBuf),
                 "[%09li]",
                 micros());
        Serial.print(timeStampStringBuf);
        Serial.print(" Hello from ");
        Serial.print(__PRETTY_FUNCTION__);
        Serial.print("->");
        Serial.println(mc_thread_name);

        // And print again in a second
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

