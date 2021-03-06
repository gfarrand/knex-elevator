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
// Include File(s)
// /////////////////////////////////////////////////////////////////////////////
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <stdint.h>

#include "BlinkerTask.h"
#include "DataAcquisitionTask.h"
#include "MarqueeDisplayTask.h"


// /////////////////////////////////////////////////////////////////////////////
// Function Prototypes
// /////////////////////////////////////////////////////////////////////////////


// /////////////////////////////////////////////////////////////////////////////
// Application Global Variable(s)
// /////////////////////////////////////////////////////////////////////////////

// Application Tasks
BlinkerTask gvBlinkerTask;
DataAcquisitionTask gvDataAcquisitionTask;
MarqueeDisplayTask gvMarqueeDisplayTask;


////////////////////////////////////////////////////////////////////////////////
void setup(void)
{
    // Debug console
    Serial.begin(115200);
    Serial.println("Serial console initialized");

    // Initialize application tasks
    gvBlinkerTask.Initialize();
    gvDataAcquisitionTask.Initialize();
    gvMarqueeDisplayTask.Initialize();

    // And start them running
    gvBlinkerTask.Start();
    gvDataAcquisitionTask.Start();
    gvMarqueeDisplayTask.Start();

    // FreeRTOS task scheduler takes over from here.
    Serial.println("FreeRTOS Scheduler Running...");
    return;
}


////////////////////////////////////////////////////////////////////////////////
void
loop(void)
{
    // NTD
    // Task scheduler is doing all the magic
}


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

