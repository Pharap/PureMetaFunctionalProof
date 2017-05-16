#pragma once

#include "TypeList.h"

template< template< typename, typename > typename Z, typename U, typename T > struct FoldlDef;
template< template< typename, typename > typename Z, typename U, typename T, typename ... Ts > struct FoldlDef<Z, U, TypeList<T, Ts...>> { using Type = typename FoldlDef<Z, typename Z<U, T>::Type, TypeList<Ts...> >::Type; };
template< template< typename, typename > typename Z, typename U, typename T > struct FoldlDef<Z, U, TypeList<T>> { using Type = typename Z<U, T>::Type; };