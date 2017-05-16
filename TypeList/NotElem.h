#pragma once

#include "TypeList.h"
#include "Utils.h"

template< typename T, typename U > struct NotElemDef;
template< typename T, typename U, typename ... Us > struct NotElemDef<T, TypeList<U, Us...>> : BoolConstant<!IsSame<T, U>::Value && NotElemDef<T, TypeList<Us...>>::Value> {};
template< typename T, typename U > struct NotElemDef<T, TypeList<U>> : BoolConstant<!IsSame<T, U>::Value> {};