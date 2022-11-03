/**
 *--------------------------------------------
 * VectorCommon.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace SM
{

template<typename T>
SM_INLINE TVector2<T>::TVector2(const TVector3<T>& Vector3)
	: X(Vector3.X)
	, Y(Vector3.Y)
{}

template<typename T>
SM_INLINE TVector2<T>::TVector2(const TVector4<T>& Vector4)
	: X(Vector4.X)
	, Y(Vector4.Y)
{}

template<typename T>
SM_INLINE TVector3<T>::TVector3(const TVector2<T>& Vector2)
	: X(Vector2.X)
	, Y(Vector2.Y)
	, Z(T(0.0))
{}

template<typename T>
SM_INLINE TVector3<T>::TVector3(const TVector2<T>& Vector2, T InZ)
	: X(Vector2.X)
	, Y(Vector2.Y)
	, Z(InZ)
{}

template<typename T>
SM_INLINE TVector3<T>::TVector3(const TVector4<T>& Vector4)
	: X(Vector4.X)
	, Y(Vector4.Y)
	, Z(Vector4.Z)
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(const TVector2<T>& Vector2)
	: X(Vector2.X)
	, Y(Vector2.Y)
	, Z(T(0.0))
	, W(T(0.0))
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(const TVector2<T>& Vector2, T InZ, T InW)
	: X(Vector2.X)
	, Y(Vector2.Y)
	, Z(InZ)
	, W(InW)
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(const TVector3<T>& Vector3)
	: X(Vector3.X)
	, Y(Vector3.Y)
	, Z(Vector3.Z)
	, W(T(0.0))
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(const TVector3<T>& Vector3, T InW)
	: X(Vector3.X)
	, Y(Vector3.Y)
	, Z(Vector3.Z)
	, W(InW)
{}

} // namespace SM