#pragma once

#include "Utils.h"

namespace TypeListTests
{
	// Cons
	static_assert(IsSame<TypeList<int>, typename ConsDef<int, EmptyTypeList>::Type >(), "ConsDef failed");
	static_assert(IsSame<TypeList<int, short, char>, typename ConsDef<int, TypeList<short, char>>::Type >(), "ConsDef failed");

	// Null
	static_assert(NullDef< EmptyTypeList >::Value, "NullDef failed");
	static_assert(!NullDef< TypeList< int > >::Value, "NullDef failed");
	static_assert(!NullDef< TypeList< int, short, char > >::Value, "NullDef failed");

	// Length
	static_assert(LengthDef< EmptyTypeList >::Value == 0, "LengthDef failed");
	static_assert(LengthDef< TypeList< int > >::Value == 1, "LengthDef failed");
	static_assert(LengthDef< TypeList< int, short, char > >::Value == 3, "LengthDef failed");

	// Head
	static_assert(IsSame<int, typename HeadDef<TypeList<int, short, char>>::Type >(), "HeadDef failed");

	// Tail
	static_assert(IsSame<TypeList<short, char>, typename TailDef<TypeList<int, short, char>>::Type >(), "TailDef failed");

	// Last
	static_assert(IsSame<char, typename LastDef<TypeList<int, short, char>>::Type >(), "LastDef failed");

	// Init
	static_assert(IsSame<TypeList<int, short>, typename InitDef<TypeList<int, short, char>>::Type>::Value, "InitDef failed");

	// Reverse
	static_assert(IsSame< TypeList<char, short, int>, typename ReverseDef<TypeList<int, short, char>>::Type >(), "ReverseDef failed");
	
	// Concat
	static_assert(IsSame< TypeList<int, short, char, int, short, char>, typename ConcatDef<TypeList<int, short, char>, TypeList<int, short, char>>::Type >(), "ConcatDef failed");

	// Map
	template< typename T > struct RRef { using Type = T&&; };
	template< typename T > struct RRef<T&> { using Type = T&&; };
	template< typename T > struct RRef<T&&> { using Type = T&&; };

	static_assert(IsSame< TypeList<int&&, short&&, char&&>, typename MapDef<RRef, TypeList<int, short, char>>::Type >(), "MapDef failed");

	template< typename T, typename U > struct ConstU { using Type = U; };
	template< typename T > using ConstInt = ConstU<T, int>;

	static_assert(IsSame< TypeList<int, int, int>, typename MapDef<ConstInt, TypeList<int, short, char>>::Type >(), "MapDef failed");

	// Foldl
	template< typename T, typename U > struct ConstT { using Type = T; };

	static_assert(IsSame< float, typename FoldlDef<ConstT, float, TypeList<int, short, char>>::Type >(), "FoldlDef failed");

	template< typename T, typename U > struct Consify { using Type = typename ConsDef<U, T>::Type; };

	static_assert(IsSame< TypeList<char, short, int>, typename FoldlDef< Consify, EmptyTypeList, TypeList<int, short, char>>::Type >(), "FoldlDef failed");

	// Scanl
	static_assert(IsSame< TypeList< float, float, float, float >, typename ScanlDef<ConstT, float, TypeList<int, short, char>>::Type >(), "ScanlDef failed");

	static_assert(IsSame< TypeList< EmptyTypeList, TypeList< int >, TypeList< short, int >, TypeList< char, short, int > >, typename ScanlDef< Consify, EmptyTypeList, TypeList<int, short, char> >::Type >(), "ScanlDef failed");
}