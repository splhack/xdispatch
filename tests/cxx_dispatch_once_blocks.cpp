/*
* cxx_dispatch_once_blocks.cpp
* 
* Copyright (c) 2008-2009 Apple Inc.
* Copyright (c) 2011-2013 MLBA-Team.
* All rights reserved.
* 
* @LICENSE_HEADER_START@
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* @LICENSE_HEADER_END@
*/


#include <xdispatch/dispatch>
#include "cxx_tests.h"


/*
 A simple test for ensuring the once
 methods are properly working
 */

static xdispatch::once x_once_obj;

extern "C" void cxx_dispatch_once2_blocks(){
    MU_BEGIN_TEST(cxx_dispatch_once2_blocks);

    int counter = 0;
    int* counter_ptr = &counter;

    MU_ASSERT_EQUAL( counter, 0 );
    x_once_obj( ^{ (*counter_ptr)++; } );
    x_once_obj( ^{ (*counter_ptr)++; } );
    x_once_obj( ^{ (*counter_ptr)++; } );
    x_once_obj( ^{ (*counter_ptr)++; } );
    x_once_obj( ^{ (*counter_ptr)++; } );
    MU_ASSERT_EQUAL( counter, 1 );

    MU_PASS("");


    MU_END_TEST;
}

static dispatch_once_t once_obj;

extern "C" void cxx_dispatch_once3_blocks(){
    MU_BEGIN_TEST(cxx_dispatch_once3_blocks);


    int counter = 0;
    int* counter_ptr = &counter;

    MU_ASSERT_EQUAL( counter, 0 );
    dispatch_once( &once_obj, ^{ (*counter_ptr)++; } );
    dispatch_once( &once_obj, ^{ (*counter_ptr)++; } );
    dispatch_once( &once_obj, ^{ (*counter_ptr)++; } );
    dispatch_once( &once_obj, ^{ (*counter_ptr)++; } );
    dispatch_once( &once_obj, ^{ (*counter_ptr)++; } );
    MU_ASSERT_EQUAL( counter, 1 );

    MU_PASS("");

    MU_END_TEST;
}

