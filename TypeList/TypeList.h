#pragma once

template< typename ... Ts > struct TypeList {};

using EmptyTypeList = TypeList< void >;

#include "Utils.h"

#include "Cons.h"
#include "Null.h"
#include "Length.h"
#include "Head.h"
#include "Tail.h"
#include "Last.h"
#include "Init.h"
#include "Reverse.h"
#include "Concat.h"
#include "Map.h"
#include "Foldl.h"
#include "Scanl.h"
#include "Foldl1.h"
#include "Scanl1.h"
#include "Replicate.h"
#include "Elem.h"
#include "NotElem.h"