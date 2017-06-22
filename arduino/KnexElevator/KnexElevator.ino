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
#include <Arduino.h>
#include <stdint.h>

#include "Types.h"

using namespace Knex::Elevator;


// /////////////////////////////////////////////////////////////////////////////
// Function Prototypes
// /////////////////////////////////////////////////////////////////////////////
void printRawInputs(RawInputs & r_inputs);
void printRawOutputs(RawOutputs & r_outputs);


// /////////////////////////////////////////////////////////////////////////////
// Application Global Variable(s)
// /////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
void setup(void)
{
    // Debug console
    Serial.begin(115200);
    Serial.println("Serial console initialized");

    // Enable some debug pins
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    return;
}


////////////////////////////////////////////////////////////////////////////////
void
loop(void)
{
    // TODO: Wrap a pin toggler in something RAII-ish :)
    digitalWrite(8, HIGH);

    // -------------------------------------------------------------------------
    // Get inputs
    // -------------------------------------------------------------------------
    // TODO - actually get real values!
    {
        RawInputs inputs;

        inputs.mCallButtonStates[FLOOR_ONE][CALL_UP]   = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_ONE][CALL_DOWN] = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_TWO][CALL_UP]   = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_TWO][CALL_DOWN] = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_THREE][CALL_UP]   = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_THREE][CALL_DOWN] = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_FOUR][CALL_UP]   = CBTN_REQ_RELEASED;
        inputs.mCallButtonStates[FLOOR_FOUR][CALL_DOWN] = CBTN_REQ_RELEASED;

        inputs.mCarDistances[SHAFT_ONE][DIST_SENSOR_ID_BOTTOM] = 400;
        inputs.mCarDistances[SHAFT_ONE][DIST_SENSOR_ID_TOP]    = 400;
        inputs.mCarDistances[SHAFT_TWO][DIST_SENSOR_ID_BOTTOM] = 400;
        inputs.mCarDistances[SHAFT_TWO][DIST_SENSOR_ID_TOP]    = 400;

        printRawInputs(inputs);
    }


    // -------------------------------------------------------------------------
    // Crunch numbers
    // -------------------------------------------------------------------------
    // TODO - actually call functions to do a job!


    // -------------------------------------------------------------------------
    // Set outputs
    // -------------------------------------------------------------------------
    // TODO - actually map these outputs to hardware!
    {
        RawOutputs outputs;

        outputs.mCallButtonStates[FLOOR_ONE][CALL_UP]   = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_ONE][CALL_DOWN] = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_TWO][CALL_UP]   = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_TWO][CALL_DOWN] = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_THREE][CALL_UP]   = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_THREE][CALL_DOWN] = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_FOUR][CALL_UP]   = CBTN_RESP_SERVICED;
        outputs.mCallButtonStates[FLOOR_FOUR][CALL_DOWN] = CBTN_RESP_SERVICED;

        outputs.mServoDriveValues[SHAFT_ONE] = 0;
        outputs.mServoDriveValues[SHAFT_TWO] = 0;

        outputs.mMarqueeDisplayString = "****";

        printRawOutputs(outputs);
    }


    // So we don't flood the serial port
    delay(1000);

    // Loop is done, try again next time
    digitalWrite(8, LOW);
}


////////////////////////////////////////////////////////////////////////////////
void printRawInputs(Knex::Elevator::RawInputs & r_inputs)
{
    Serial.println("-- INPUTS --");
    Serial.print("Call Button States (U/D):  ");
    for (int floor_id = BOTTOM_FLOOR; floor_id <= TOP_FLOOR; floor_id += 1)
    {
        Serial.print(r_inputs.mCallButtonStates[floor_id][CALL_UP]);
        Serial.print("/");
        Serial.print(r_inputs.mCallButtonStates[floor_id][CALL_DOWN]);
        Serial.print(", ");
    }
    Serial.println("");

    Serial.print("Distance Values (B/T):");
    for (int shaft_id = FIRST_SHAFT; shaft_id <= LAST_SHAFT; shaft_id += 1)
    {
        Serial.print(r_inputs.mCarDistances[shaft_id][DIST_SENSOR_ID_BOTTOM]);
        Serial.print("/");
        Serial.print(r_inputs.mCarDistances[shaft_id][DIST_SENSOR_ID_TOP]);
        Serial.print(", ");
    }
    Serial.println("");
}


////////////////////////////////////////////////////////////////////////////////
void printRawOutputs(Knex::Elevator::RawOutputs & r_outputs)
{
    Serial.println("-- OUTPUTS --");
    Serial.print("Buttons: ");
    for (int floor_id = BOTTOM_FLOOR; floor_id <= TOP_FLOOR; floor_id += 1)
    {
        Serial.print(r_outputs.mCallButtonStates[floor_id][CALL_UP]);
        Serial.print("/");
        Serial.print(r_outputs.mCallButtonStates[floor_id][CALL_DOWN]);
        Serial.print(", ");
    }
    Serial.println("");

    Serial.print("Servos: ");
    for (int shaft_id = FIRST_SHAFT; shaft_id <= LAST_SHAFT; shaft_id += 1)
    {
        Serial.print(r_outputs.mServoDriveValues[shaft_id]);
        Serial.print(", ");
    }
    Serial.println("");

    Serial.print("Marquee: ");
    Serial.print("'");
    Serial.print(r_outputs.mMarqueeDisplayString);
    Serial.print("'");
    Serial.println("");
}


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

