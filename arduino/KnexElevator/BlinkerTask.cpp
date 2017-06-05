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
BlinkerTask::Initialize(void)
{
    Serial.print("ENTER: ");
    Serial.println(__PRETTY_FUNCTION__);

    // Setup the debug LED for writing
    pinMode(13, OUTPUT);
    pinMode(2, INPUT_PULLUP);

    // Fire up our task
    xTaskCreate(BlinkerTask::RunWrapper,  // Entry Point
                "BlinkerTask",            // Task Name
                128,                      // Stack Depth
                this,                     // Task Parameters
                2,                        // Priority
                NULL);                    // Storage for task handle

    Serial.print("LEAVE: ");
    Serial.println(__PRETTY_FUNCTION__);
}


////////////////////////////////////////////////////////////////////////////////
void
BlinkerTask::RunWrapper(void * pvParameters)
{
    // Entry point to the new task
    BlinkerTask* thisTask =
        reinterpret_cast<BlinkerTask*>(pvParameters);
    thisTask->Run();
}


////////////////////////////////////////////////////////////////////////////////
void
BlinkerTask::Run(void)
{
    Serial.print("ENTER: ");
    Serial.println(__PRETTY_FUNCTION__);

    while (true)
    {
        // Light the debug LED when the button is pressed
        int buttonState = digitalRead(2);
        int ledState = (LOW == buttonState) ? HIGH : LOW;
        digitalWrite(13, ledState);

        // Print on button press
        if (LOW == buttonState)
        {
            Serial.print("Button Pressed! ");
            Serial.println(__PRETTY_FUNCTION__);
        }

        // And check back again soon
        vTaskDelay(pdMS_TO_TICKS(250));
    }

    Serial.print("LEAVE: ");
    Serial.println(__PRETTY_FUNCTION__);
}


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

