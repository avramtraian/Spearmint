/**
 *--------------------------------------------
 * Ray.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#include "MathUtilities.h"
#include "Vector3.h"

namespace SM
{

template<typename T>
struct TRay
{
public:
	TVector3<T> Origin;

	TVector3<T> Direction;

public:
	TRay();

	TRay(const TRay<T>& Other);

	TRay(const TVector3<T>& Origin, const TVector3<T>& Direction);
};

} // namespace SM

using FRay = SM::TRay<float>;

namespace SM
{

template<typename T>
TRay<T>::TRay()
	: Origin(T(0))
	, Direction(T(0))
{}

template<typename T>
TRay<T>::TRay(const TRay<T>& Other)
	: Origin(Other.Origin)
	, Direction(Other.Direction)
{}

template<typename T>
TRay<T>::TRay(const TVector3<T>& Origin, const TVector3<T>& Direction)
	: Origin(Origin)
	, Direction(Direction)
{}

} // namespace SM