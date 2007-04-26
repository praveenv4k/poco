//
// DynamicAny.cpp
//
// $Id: //poco/Main/Foundation/src/DynamicAny.cpp#3 $
//
// Library: Foundation
// Package: Core
// Module:  DynamicAny
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/DynamicAny.h"


namespace Poco {


DynamicAny::DynamicAny():
	_pHolder(new DynamicAnyHolderImpl<int>(0))
{
}


DynamicAny::DynamicAny(const char* pVal): 
	_pHolder(new DynamicAnyHolderImpl<std::string>(pVal))
{
}


DynamicAny::DynamicAny(const DynamicAny& other):
	_pHolder(0)
{
	if (other._pHolder)
		_pHolder = other._pHolder->clone();
}


DynamicAny::~DynamicAny()
{
	delete _pHolder;
}


void DynamicAny::swap(DynamicAny& ptr)
{
	std::swap(_pHolder, ptr._pHolder);
}


const std::type_info& DynamicAny::type() const
{
    return _pHolder->type();
}


} // namespace Poco::Poco
