#pragma once

#include "TypeList.h"
#include "Utils.h"

template< typename T, typename U > struct ElemDef;
template< typename T, typename U, typename ... Us > struct ElemDef<T, TypeList<U, Us...>> : BoolConstant<IsSame<T,U>::Value || ElemDef<T, TypeList<Us...>>::Value> {};
template< typename T, typename U > struct ElemDef<T, TypeList<U>> : IsSame<T, U> {};