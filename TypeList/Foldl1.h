#pragma once

#include "TypeList.h"
#include "Foldl.h"

template< template< typename, typename > typename Z, typename T > struct Foldl1Def;
template< template< typename, typename > typename Z, typename T, typename ... Ts > struct Foldl1Def<Z, TypeList<T, Ts...>> { using Type = typename FoldlDef<Z, T, TypeList<Ts...> >::Type; };