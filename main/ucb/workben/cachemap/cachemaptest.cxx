/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_ucb.hxx"
#include "cachemapobject1.hxx"
#include "cachemapobject2.hxx"
#include "cachemapobject3.hxx"
#include "cachemapobjectcontainer2.hxx"

#ifndef _SOL_TIME_H_
#include "osl/time.h"
#endif
#include "rtl/ref.hxx"
#include "rtl/ustring.hxx"

#ifndef INCLUDED_CSTDLIB
#include <cstdlib>
#define INCLUDED_CSTDLIB
#endif
#ifndef INCLUDED_MEMORY
#include <memory>
#define INCLUDED_MEMORY
#endif
#ifndef INCLUDED_STDIO_H
#include <stdio.h> // <iostream> or <cstdio> do not work well on all platforms
#define INCLUDED_STDIO_H
#endif

using ucb::cachemap::Object1;
using ucb::cachemap::Object2;
using ucb::cachemap::Object3;
using ucb::cachemap::ObjectContainer1;
using ucb::cachemap::ObjectContainer2;
using ucb::cachemap::ObjectContainer3;

namespace {

// Give template function a dummy parameter, to work around MSVC++ bug:
template< typename Cont, typename ContRef, typename Obj >
sal_uInt32 test(Obj *)
{
    ContRef xCont(new Cont);
    rtl::OUString aPrefix(RTL_CONSTASCII_USTRINGPARAM("key"));
    sal_uInt32 nTimer = osl_getGlobalTimer();
    for (int i = 0; i < 100000; i += 5)
    {
        rtl::OUString
            aKey0(aPrefix
                      + rtl::OUString::valueOf(static_cast< sal_Int32 >(
                                                   i % 100)));
        rtl::Reference< Obj > xObj01(xCont->get(aKey0));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj01);
        }
        rtl::Reference< Obj > xObj02(xCont->get(aKey0));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj02);
        }

        rtl::OUString
            aKey1(aPrefix
                      + rtl::OUString::valueOf(static_cast< sal_Int32 >(
                                                   (i + 1) % 100)));
        rtl::Reference< Obj > xObj11(xCont->get(aKey1));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj11);
        }
        rtl::Reference< Obj > xObj12(xCont->get(aKey1));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj12);
        }

        rtl::OUString
            aKey2(aPrefix
                      + rtl::OUString::valueOf(static_cast< sal_Int32 >(
                                                   (i + 2) % 100)));
        rtl::Reference< Obj > xObj21(xCont->get(aKey2));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj21);
        }
        rtl::Reference< Obj > xObj22(xCont->get(aKey2));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj22);
        }

        rtl::OUString
            aKey3(aPrefix
                      + rtl::OUString::valueOf(static_cast< sal_Int32 >(
                                                   (i + 3) % 100)));
        rtl::Reference< Obj > xObj31(xCont->get(aKey3));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj31);
        }
        rtl::Reference< Obj > xObj32(xCont->get(aKey3));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj32);
        }

        rtl::OUString
            aKey4(aPrefix
                      + rtl::OUString::valueOf(static_cast< sal_Int32 >(
                                                   (i + 4) % 100)));
        rtl::Reference< Obj > xObj41(xCont->get(aKey4));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj41);
        }
        rtl::Reference< Obj > xObj42(xCont->get(aKey4));
        {for (int j = 0; j < 50; ++j)
            rtl::Reference< Obj > xRef(xObj42);
        }
    }
    return osl_getGlobalTimer() - nTimer;
}

}

int main()
{
    // Use the second set of measurements, to avoid startup inaccuracies:
    for (int i = 0; i < 2; ++i)
        printf("Version 1: %lu ms.\nVersion 2: %lu ms.\nVersion 3: %lu ms.\n",
               static_cast< unsigned long >(
                   test< ObjectContainer1,
                         rtl::Reference< ObjectContainer1 >,
                         Object1 >(0)),
               static_cast< unsigned long >(
                   test< ObjectContainer2,
                         std::auto_ptr< ObjectContainer2 >,
                         Object2 >(0)),
               static_cast< unsigned long >(
                   test< ObjectContainer3,
                         rtl::Reference< ObjectContainer3 >,
                         Object3 >(0)));
    return EXIT_SUCCESS;
}

// unxsols3.pro: Version 1: 9137 ms.
//               Version 2: 8634 ms.
//               Version 3: 3166 ms.
//
// wntmsci7.pro: Version 1: 3846 ms.
//               Version 2: 5598 ms.
//               Version 3: 2704 ms.
