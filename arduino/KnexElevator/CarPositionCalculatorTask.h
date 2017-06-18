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
#ifndef __CAR_POSITION_CALCULATOR_TASK_H__
#define __CAR_POSITION_CALCULATOR_TASK_H__


// /////////////////////////////////////////////////////////////////////////////
// Include(s)
// /////////////////////////////////////////////////////////////////////////////
#include <Arduino_FreeRTOS.h>

#include "ITask.h"


////////////////////////////////////////////////////////////////////////////////
/// @brief
/// A thread for elevator car position calculation
////////////////////////////////////////////////////////////////////////////////
class CarPositionCalculatorTask : public ITask
{
    public:
        ////////////////////////////////////////////////////////////////////////
        /// @brief
        /// Overloaded constructor
        ///
        /// @param[in] thread_name  Name of this thread
        ////////////////////////////////////////////////////////////////////////
        CarPositionCalculatorTask(String thread_name);

        ////////////////////////////////////////////////////////////////////////
        /// @brief
        /// Basic destructor
        ////////////////////////////////////////////////////////////////////////
        virtual ~CarPositionCalculatorTask(void);

        ////////////////////////////////////////////////////////////////////////
        /// @see ITask::Initialize()
        ////////////////////////////////////////////////////////////////////////
        virtual void Initialize(void);

        ////////////////////////////////////////////////////////////////////////
        /// @brief
        /// Returns name of the thread
        ////////////////////////////////////////////////////////////////////////
        String get_name(void);

    private:
        ////////////////////////////////////////////////////////////////////////
        /// @see ITask::Run()
        ////////////////////////////////////////////////////////////////////////
        virtual void Run(void);

        ////////////////////////////////////////////////////////////////////////
        /// @brief
        /// Name of this thread
        ////////////////////////////////////////////////////////////////////////
        const String mc_thread_name;

    private:
        CarPositionCalculatorTask(void) = delete;
        CarPositionCalculatorTask(const CarPositionCalculatorTask&) = delete;
        CarPositionCalculatorTask& operator=(const CarPositionCalculatorTask&) = delete;
};


#endif // __CAR_POSITION_CALCULATOR_TASK_H__


////////////////////////////////////////////////////////////////////////////////
// END OF FILE
////////////////////////////////////////////////////////////////////////////////

