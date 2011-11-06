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



#ifndef _CHART2_OBJECTNAME_PROVIDER_HXX
#define _CHART2_OBJECTNAME_PROVIDER_HXX

#include "ObjectIdentifier.hxx"
#include "TitleHelper.hxx"
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/chart2/XChartDocument.hpp>

//.............................................................................
namespace chart
{
//.............................................................................

//-----------------------------------------------------------------------------
/** Provides localized ui strings for the userinterface.
*/

class ObjectNameProvider
{
public:
    static rtl::OUString getName( ObjectType eObjectType, bool bPlural=false );
    static rtl::OUString getAxisName( const rtl::OUString& rObjectCID
                        , const ::com::sun::star::uno::Reference<
                            ::com::sun::star::frame::XModel >& xChartModel  );
    static rtl::OUString getGridName( const rtl::OUString& rObjectCID
                        , const ::com::sun::star::uno::Reference<
                            ::com::sun::star::frame::XModel >& xChartModel );
    static rtl::OUString getTitleName( const rtl::OUString& rObjectCID
                        , const ::com::sun::star::uno::Reference<
                            ::com::sun::star::frame::XModel >& xChartModel );
    static rtl::OUString getTitleNameByType( TitleHelper::eTitleType eType );
    
    static rtl::OUString getNameForCID(
        const rtl::OUString& rObjectCID,
        const ::com::sun::star::uno::Reference<
            ::com::sun::star::chart2::XChartDocument >& xChartDocument );

    static rtl::OUString getName_ObjectForSeries(
        ObjectType eObjectType,
        const rtl::OUString& rSeriesCID,
        const ::com::sun::star::uno::Reference<
            ::com::sun::star::chart2::XChartDocument >& xChartDocument );
    static rtl::OUString getName_ObjectForAllSeries( ObjectType eObjectType );

    /** Provides help texts for the various chart elements.
        The parameter rObjectCID has to be a ClassifiedIdentifier - see class ObjectIdentifier.
     */
    static rtl::OUString getHelpText( const rtl::OUString& rObjectCID, const ::com::sun::star::uno::Reference< ::com::sun::star::frame::XModel >& xChartModel, bool bVerbose=false );
    static rtl::OUString getHelpText( const rtl::OUString& rObjectCID, const ::com::sun::star::uno::Reference< ::com::sun::star::chart2::XChartDocument >& xChartDocument, bool bVerbose=false );

    /** This is used for showing the currently selected object in the status bar
        (command "Context")
     */
    static rtl::OUString getSelectedObjectText( const rtl::OUString & rObjectCID, const ::com::sun::star::uno::Reference< ::com::sun::star::chart2::XChartDocument >& xChartDocument );
};

//.............................................................................
} //namespace chart
//.............................................................................
#endif
