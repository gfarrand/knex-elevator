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
#ifndef __TYPES_H__
#define __TYPES_H__


// /////////////////////////////////////////////////////////////////////////////
// Include(s)
// /////////////////////////////////////////////////////////////////////////////
#include <stdint.h>


// /////////////////////////////////////////////////////////////////////////////
// Namepsace(s)
// /////////////////////////////////////////////////////////////////////////////
namespace Knex {
namespace Elevator {


////////////////////////////////////////////////////////////////////////////////
/// @brief
/// Defines all floors in our system.
////////////////////////////////////////////////////////////////////////////////
enum BuildingFloors
{
    FLOOR_ONE = 0,
    FLOOR_TWO,
    FLOOR_THREE,
    FLOOR_FOUR,

    // Add support for more floors above this line
    NUM_FLOORS,

    BOTTOM_FLOOR = FLOOR_ONE,
    TOP_FLOOR = NUM_FLOORS - 1,
};

////////////////////////////////////////////////////////////////////////////////
/// @brief
/// Defines the elevator shafts in this system.
////////////////////////////////////////////////////////////////////////////////
enum ShaftId
{
    SHAFT_ONE = 0,
    SHAFT_TWO,

    // Add support for more shafts above this line
    NUM_SHAFTS,

    FIRST_SHAFT = SHAFT_ONE,
    LAST_SHAFT = NUM_SHAFTS - 1,
};

////////////////////////////////////////////////////////////////////////////////
/// @brief
/// Defines all possible elevator call directions we support.
///
/// @remarks
/// This is our representation of a person standing at floor X, and pushing the
/// corresponding button for "I want to go up".
////////////////////////////////////////////////////////////////////////////////
enum CallDirection
{
    CALL_DOWN = 0,
    CALL_UP = 1,

    // Add support for more call directions above this line
    NUM_CALL_DIRECTIONS
};

////////////////////////////////////////////////////////////////////////////////
/// @brief
/// Defines the possible request states the call buttons can be in.
////////////////////////////////////////////////////////////////////////////////
enum CallButtonRequestState
{
    CBTN_REQ_RELEASED = 0,  ///< User is not pressing the button
    CBTN_REQ_PRESSED = 1,   ///< User is currently pressing the button
};

////////////////////////////////////////////////////////////////////////////////
/// @brief
/// Defines all possible response states the call buttons can be in.
////////////////////////////////////////////////////////////////////////////////
enum CallButtonResponseState
{
    CBTN_RESP_PENDING = 0,  ///< System has not responded yet
    CBTN_RESP_ACKNOWLEDGED, ///< System has queued up user's request
    CBTN_RESP_SERVICED,     ///< Car has arrived, get on!
};

////////////////////////////////////////////////////////////////////////////////
/// @brief
/// Represents which distance sensor, per shaft, is in question.
///
/// @remarks
/// Each elevator shaft has 2 distance sensors, each measuring how far away the
/// car is.
////////////////////////////////////////////////////////////////////////////////
enum DistanceSensorId
{
    DIST_SENSOR_ID_BOTTOM = 0,
    DIST_SENSOR_ID_TOP,

    // Add support for more call directions above this line
    NUM_DISTANCE_SENSORS_PER_SHAFT
};


////////////////////////////////////////////////////////////////////////////////
struct RawInputs
{
    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////
    RawInputs(void)
        : mCallButtonStates()
        , mCarDistances()
    {
        // TODO: Anything special here?
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// A 2D array of CallButtonStates representing the instantaneous state of
    /// each call button in the system.
    ///
    /// @remarks
    /// The "middle" floors each have an "Up" and "Down" call button, but the
    /// floors on the extremes only have one (top floor has down, bottom floor
    /// has up).
    ////////////////////////////////////////////////////////////////////////////
    CallButtonRequestState mCallButtonStates[NUM_FLOORS][NUM_CALL_DIRECTIONS];

    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// An array of CallButtonStates representing the instantaneous state of
    /// each call button in the system.
    ///
    /// @remarks
    /// The top-most floor will never change the "Up" button state and the
    /// bottom-most floor will never change the "Down" button state due to the
    /// physical nature of the system... those buttons are not present.
    ////////////////////////////////////////////////////////////////////////////
    int16_t mCarDistances[NUM_SHAFTS][NUM_DISTANCE_SENSORS_PER_SHAFT];
};


////////////////////////////////////////////////////////////////////////////////
/// @brief
/// A type representing all possible environmental outputs.
////////////////////////////////////////////////////////////////////////////////
struct RawOutputs
{
    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////
    RawOutputs(void)
        : mCallButtonStates()
        , mServoDriveValues()
        , mMarqueeDisplayString("----")
    {
        // TODO: Anything special here?
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// A 2D array of CallButtonStates representing the instantaneous response
    /// state of each call button in the system.
    ///
    /// @remarks
    /// The "middle" floors each have an "Up" and "Down" call button, but the
    /// floors on the extremes only have one (top floor has down, bottom floor
    /// has up).
    ////////////////////////////////////////////////////////////////////////////
    CallButtonResponseState mCallButtonStates[NUM_FLOORS][NUM_CALL_DIRECTIONS];

    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// An array of CallButtonStates representing the instantaneous state of
    /// each call button in the system.
    ///
    /// @remarks
    /// The valid range for inputs are -10000 to +10000.  Any input value
    /// outside of this range will be clipped to that range.
    ///
    /// @remarks
    /// Each integer step represents 0.01% of full power in the given direction
    /// (positive numbers represent the direction of rotation such that the car
    /// moves "up", and the reverse is true for negative numbers.
    ////////////////////////////////////////////////////////////////////////////
    int16_t mServoDriveValues[NUM_SHAFTS];

    ////////////////////////////////////////////////////////////////////////////
    /// @brief
    /// A 4-character string to display on the Marquee.
    ///
    /// @remarks
    /// Only the first 4 characters are used from this string.
    ///
    /// @remarks
    /// Not all characters can be easily represented on the display... proceed
    /// with caution.
    ////////////////////////////////////////////////////////////////////////////
    String mMarqueeDisplayString;
};



} // END namespace Elevator {
} // END namespace Knex {


#endif // __TYPES_H__


////////////////////////////////////////////////////////////////////////////////
// END OF FILE
////////////////////////////////////////////////////////////////////////////////

