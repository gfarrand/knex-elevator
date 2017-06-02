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
#ifndef __SERIAL_PORT_RESOURCE_H__
#define __SERIAL_PORT_RESOURCE_H__


// /////////////////////////////////////////////////////////////////////////////
// Include(s)
// /////////////////////////////////////////////////////////////////////////////
#include <Arduino_FreeRTOS.h>
#include <semphr.h>


////////////////////////////////////////////////////////////////////////////////
/// @brief
/// A locking mechanism around the serial port.
////////////////////////////////////////////////////////////////////////////////
class SerialPortResourceClass
{
    public:
        ////////////////////////////////////////////////////////////////////////
        /// @brief
        /// Basic constructor
        ////////////////////////////////////////////////////////////////////////
        SerialPortResourceClass(void);

        ////////////////////////////////////////////////////////////////////////
        /// @brief
        /// Basic destructor
        ////////////////////////////////////////////////////////////////////////
        ~SerialPortResourceClass(void);

        // TODO: Documentation
        void Acquire(void);
        void Release(void);


    private:
        SemaphoreHandle_t mMutex;
};

// Arduino method to make a Singleton
extern SerialPortResourceClass SerialPortResource;

#endif // __SERIAL_PORT_RESOURCE_H__


////////////////////////////////////////////////////////////////////////////////
// END OF FILE
////////////////////////////////////////////////////////////////////////////////

