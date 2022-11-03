/**
 *--------------------------------------------
 * Vector4.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#include "MathUtilities.h"

namespace SM
{

template<typename T>
struct TVector2;
template<typename T>
struct TVector3;

/**
 *-------------------------------------------------------------------
 * A 4-component (X, Y, Z, W) vector, with floating point precision.
 *-------------------------------------------------------------------
 */
template<typename T>
struct TVector4
{
public:
	/** The vector's X component. */
	T X;

	/** The vector's X component. */
	T Y;

	/** The vector's Z component. */
	T Z;

	/** The vector's W component. */
	T W;

public:
	/** @return A vector with the components (0, 0, 0, 0). */
	static constexpr TVector4<T> Zero() { return TVector4<T>(T(0.0), T(0.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (1, 1, 1, 1). */
	static constexpr TVector4<T> One() { return TVector4<T>(T(1.0), T(1.0), T(1.0), T(1.0)); }

	/** @return A vector with the components (1, 0, 0, 0). */
	static constexpr TVector4<T> UnitX() { return TVector4<T>(T(1.0), T(0.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (0, 1, 0, 0). */
	static constexpr TVector4<T> UnitY() { return TVector4<T>(T(0.0), T(1.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (0, 0, 1, 0). */
	static constexpr TVector4<T> UnitZ() { return TVector4<T>(T(0.0), T(0.0), T(1.0), T(0.0)); }

	/** @return A vector with the components (0, 0, 0, 1). */
	static constexpr TVector4<T> UnitW() { return TVector4<T>(T(0.0), T(0.0), T(0.0), T(1.0)); }

public:
	/**
	 * Default constructor.
	 * Initializes all components with 0.
	 */
	SM_INLINE TVector4();

	/**
	 * Copy constructor.
	 * Initializes the components with the other's.
	 *
	 * @param Other The vector to copy.
	 */
	SM_INLINE TVector4(const TVector4<T>& Other);

	/**
	 * Constructor using an initializing value for each component.
	 *
	 * @param InX Initializing value for the X component.
	 * @param InY Initializing value for the Y component.
	 * @param InZ Initializing value for the Z component.
	 * @param InW Initializing value for the W component.
	 */
	SM_INLINE TVector4(T InX, T InY, T InZ, T InW);

	/**
	 * Constructor using a single value to initialize all components.
	 *
	 * @param Scalar Initializing value for the components.
	 */
	SM_INLINE explicit TVector4(T Scalar);

	/**
	 * Constructor using a 2-component vector (for X and Y). The Z and W components
	 *   are initialized with 0.
	 *
	 * @param Vector2 The 2-component vector.
	 */
	SM_INLINE explicit TVector4(const TVector2<T>& Vector2);

	/**
	 * Constructor using a 2-component vector (for X and Y) and separate
	 *   values for the Z and W components.
	 *
	 * @param Vector2 The 2-component vector.
	 * @param InZ The Z-component initializing value.
	 * @param InW The W-component initializing value.
	 */
	SM_INLINE TVector4(const TVector2<T>& Vector2, T InZ, T InW);

	/**
	 * Constructor using a 3-component vector (for X, Y and Z). The W-component
	 *   is initialized with 0.
	 *
	 * @param Vector3 The 3-component vector.
	 */
	SM_INLINE explicit TVector4(const TVector3<T>& Vector3);

	/**
	 * Constructor using a 3-component vector (for X, Y and Z) and a separate
	 *   value for the W-component.
	 *
	 * @param Vector3 The 3-component vector.
	 * @param InW The W-component initializing value.
	 */
	SM_INLINE TVector4(const TVector3<T>& Vector3, T InW);

	/**
	 * Copy/Assign operator.
	 *
	 * @param Other The vector to copy.
	 *
	 * @return Reference to this, after the copy.
	 */
	SM_INLINE TVector4<T>& operator=(const TVector4<T>& Other);

public:
	/**
	 * Addition operator. Adds two vectors.
	 *
	 * @param Other The vector to add.
	 *
	 * @return The result of the addition.
	 */
	SM_INLINE TVector4<T> operator+(const TVector4<T>& Other) const;

	/**
	 * Addition operator. Adds a vector to this.
	 *
	 * @param Other The vector to add.
	 *
	 * @return A reference to this, after the addition.
	 */
	SM_INLINE TVector4<T>& operator+=(const TVector4<T>& Other);

	/**
	 * Subtraction operator. Subtracts two vectors.
	 *
	 * @param Other The vector to subtract.
	 *
	 * @return The result of the subtraction.
	 */
	SM_INLINE TVector4<T> operator-(const TVector4<T>& Other) const;

	/**
	 * Subtraction operator. Subtracts a vector from this.
	 *
	 * @param Other The vector to subtract.
	 *
	 * @return A reference to this, after the subtraction.
	 */
	SM_INLINE TVector4<T>& operator-=(const TVector4<T>& Other);

	/**
	 * Multiplication operator. Multiplies a scalar to this.
	 *
	 * @param Scalar The scalar to multiply.
	 *
	 * @return The result of the multiplication.
	 */
	SM_INLINE TVector4<T> operator*(T Scalar) const;

	/**
	 * Multiplication operator. Multiplies this with a scalar.
	 *
	 * @param Scalar The scalar to multiply.
	 *
	 * @return A reference to this, after the multiplication.
	 */
	SM_INLINE TVector4<T>& operator*=(T Scalar);

public:
	SM_INLINE static TVector4<T> Clamp(const TVector4<T>& X, const TVector4<T>& Min, const TVector4<T>& Max);
};

} // namespace SM

/**
*------------------------------------------------------------
* A 4-component vector with single-floating point precision.
*------------------------------------------------------------
* @see 'TVector4<T>'.
*/
using FVector4 = SM::TVector4<float>;

namespace SM
{

template<typename T>
SM_INLINE TVector4<T>::TVector4()
	: X(T(0.0))
	, Y(T(0.0))
	, Z(T(0.0))
	, W(T(0.0))
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(const TVector4<T>& Other)
	: X(Other.X)
	, Y(Other.Y)
	, Z(Other.Z)
	, W(Other.W)
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(T InX, T InY, T InZ, T InW)
	: X(InX)
	, Y(InY)
	, Z(InZ)
	, W(InW)
{}

template<typename T>
SM_INLINE TVector4<T>::TVector4(T Scalar)
	: X(Scalar)
	, Y(Scalar)
	, Z(Scalar)
	, W(Scalar)
{}

template<typename T>
SM_INLINE TVector4<T>& TVector4<T>::operator=(const TVector4<T>& Other)
{
	X = Other.X;
	Y = Other.Y;
	Z = Other.Z;
	W = Other.W;
	return *this;
}

template<typename T>
SM_INLINE TVector4<T> TVector4<T>::operator+(const TVector4<T>& Other) const
{
	return TVector4<T>(X + Other.X, Y + Other.Y, Z + Other.Z, W + Other.W);
}

template<typename T>
SM_INLINE TVector4<T>& TVector4<T>::operator+=(const TVector4<T>& Other)
{
	X += Other.X;
	Y += Other.Y;
	Z += Other.Z;
	W += Other.W;
	return *this;
}

template<typename T>
SM_INLINE TVector4<T> TVector4<T>::operator-(const TVector4<T>& Other) const
{
	return TVector4<T>(X - Other.X, Y - Other.Y, Z - Other.Z, W - Other.W);
}

template<typename T>
SM_INLINE TVector4<T>& TVector4<T>::operator-=(const TVector4<T>& Other)
{
	X -= Other.X;
	Y -= Other.Y;
	Z -= Other.Z;
	W -= Other.W;
	return *this;
}

template<typename T>
SM_INLINE TVector4<T> TVector4<T>::operator*(T Scalar) const
{
	return TVector4<T>(X * Scalar, Y * Scalar, Z * Scalar, W * Scalar);
}

template<typename T>
SM_INLINE TVector4<T>& TVector4<T>::operator*=(T Scalar)
{
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	W *= Scalar;
	return *this;
}

template<typename T>
SM_INLINE TVector4<T> operator*(T Scalar, const TVector4<T>& Vector)
{
	return Vector * Scalar;
}

template<typename T>
SM_INLINE TVector4<T> TVector4<T>::Clamp(const TVector4<T>& X, const TVector4<T>& Min, const TVector4<T>& Max)
{
	TVector4<T> Result = TVector4<T>
		(
			FMath::Clamp(X.X, Min.X, Max.X),
			FMath::Clamp(X.Y, Min.Y, Max.Y),
			FMath::Clamp(X.Z, Min.Z, Max.Z),
			FMath::Clamp(X.W, Min.W, Max.W)
		);
	return Result;
}

} // namespace SM