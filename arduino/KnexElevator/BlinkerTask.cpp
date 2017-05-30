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
#include "BlinkerTask.h"


// /////////////////////////////////////////////////////////////////////////////
// Local Types
// /////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
BlinkerTask::BlinkerTask(void)
{
    // Intentionally left empty
}


////////////////////////////////////////////////////////////////////////////////
BlinkerTask::~BlinkerTask(void)
{
    // Intentionally left empty
}


////////////////////////////////////////////////////////////////////////////////
void
BlinkerTask::initialize(void)
{
    // Setup the debug LED for writing
    pinMode(13, OUTPUT);
    pinMode(2, INPUT_PULLUP);

    // Fire up our task
    xTaskCreate(BlinkerTask::runWrapper,  // Entry Point
                "Main",                   // Task Name
                128,                      // Stack Depth
                this,                     // Task Parameters
                2,                        // Priority
                NULL);                    // Storage for task handle
}



////////////////////////////////////////////////////////////////////////////////
void
BlinkerTask::runWrapper(void * pvParameters)
{
    // Entry point to the new task
    BlinkerTask* p_this = reinterpret_cast<BlinkerTask*>(pvParameters);
    p_this->run();
}

////////////////////////////////////////////////////////////////////////////////
void
BlinkerTask::run(void)
{
    while (true)
    {
        // Light the debug LED when the button is pressed
        int buttonState = digitalRead(2);
        int ledState = (LOW == buttonState) ? HIGH : LOW;
        digitalWrite(13, ledState);

        // And check back again in 5 milliseconds
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

