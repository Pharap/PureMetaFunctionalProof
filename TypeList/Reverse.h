#pragma once

#include "TypeList.h"

template< typename T > struct ReverseDef;
template< typename ... Ts > struct ReverseDef< TypeList< Ts... > >
{
private:
	template< typename T, typename U > struct ReverseHelper;
	template< typename T, typename ... Ts > struct ReverseHelper< TypeList< T, Ts... >, EmptyTypeList > { using Type = typename ReverseHelper< TypeList< Ts... >, TypeList< T > >::Type; }; // Shift T, Erase void
	template< typename T, typename ... Ts, typename ... Us > struct ReverseHelper< TypeList< T, Ts... >, TypeList< Us... > > { using Type = typename ReverseHelper< TypeList< Ts... >, TypeList< T, Us... > >::Type; }; // Shift T to front
	template< typename T, typename ... Us > struct ReverseHelper< TypeList< T >, TypeList< Us... > > { using Type = TypeList< T, Us... >; }; // The final product

public:
	using Type = typename ReverseHelper< TypeList< Ts... >, EmptyTypeList >::Type;
};