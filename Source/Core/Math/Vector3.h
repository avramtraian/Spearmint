/**
 *--------------------------------------------
 * Vector3.h <-> Spearmint
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
struct TVector4;

/**
 *----------------------------------------------------------------
 * A 3-component (X, Y, Z) vector, with floating point precision.
 *----------------------------------------------------------------
 */
template<typename T>
struct TVector3
{
public:
	/** The vector's X component. */
	T X;

	/** The vector's X component. */
	T Y;

	/** The vector's X component. */
	T Z;

public:
	/** @return A vector with the components (0, 0, 0). */
	static constexpr TVector3<T> Zero() { return TVector3<T>(T(0.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (1, 1, 1). */
	static constexpr TVector3<T> One() { return TVector3<T>(T(1.0), T(1.0), T(1.0)); }

	/** @return A vector with the components (1, 0, 0). */
	static constexpr TVector3<T> Forward() { return TVector3<T>(T(1.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (-1, 0, 0). */
	static constexpr TVector3<T> Backward() { return TVector3<T>(T(-1.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (0, 1, 0). */
	static constexpr TVector3<T> Right() { return TVector3<T>(T(0.0), T(1.0), T(0.0)); }

	/** @return A vector with the components (0, -1, 0). */
	static constexpr TVector3<T> Left() { return TVector3<T>(T(0.0), T(-1.0), T(0.0)); }

	/** @return A vector with the components (0, 0, 1). */
	static constexpr TVector3<T> Up() { return TVector3<T>(T(0.0), T(0.0), T(1.0)); }

	/** @return A vector with the components (0, 0, -1). */
	static constexpr TVector3<T> Down() { return TVector3<T>(T(0.0), T(0.0), T(-1.0)); }

	/** @return A vector with the components (1, 0, 0). */
	static constexpr TVector3<T> UnitX() { return TVector3<T>(T(1.0), T(0.0), T(0.0)); }

	/** @return A vector with the components (0, 1, 0). */
	static constexpr TVector3<T> UnitY() { return TVector3<T>(T(1.0), T(1.0), T(0.0)); }

	/** @return A vector with the components (0, 0, 1). */
	static constexpr TVector3<T> UnitZ() { return TVector3<T>(T(1.0), T(0.0), T(1.0)); }

public:
	/**
	 * Default constructor.
	 * Initializes all components with 0.
	 */
	SM_INLINE TVector3();

	/**
	 * Copy constructor.
	 * Initializes the components with the other's.
	 *
	 * @param Other The vector to copy.
	 */
	SM_INLINE TVector3(const TVector3& Other);

	/**
	 * Constructor using an initializing value for each component.
	 *
	 * @param InX Initializing value for the X component.
	 * @param InY Initializing value for the Y component.
	 * @param InZ Initializing value for the Z component.
	 */
	SM_INLINE TVector3(T InX, T InY, T InZ);

	/**
	 * Constructor using a single value to initialize all components.
	 *
	 * @param Scalar Initializing value for the components.
	 */
	SM_INLINE explicit TVector3(T Scalar);

	/**
	 * Constructor using a 2-component vector (for X and Y). The Z-component
	 *   is initialized with 0.
	 *
	 * @param Vector2 The 2-component vector.
	 */
	SM_INLINE explicit TVector3(const TVector2<T>& Vector2);

	/**
	 * Constructor using a 2-component vector (for X and Y) and a separate
	 *   value for the Z-component.
	 *
	 * @param Vector2 The 2-component vector.
	 * @param InZ The Z-component initializing value.
	 */
	SM_INLINE TVector3(const TVector2<T>& Vector2, T InZ);

	/**
	 * Constructor using a 4-component vector, using just the X, Y and Z
	 *   components. The W-component is ignored/unused.
	 *
	 * @param Vector4 The 4-component vector.
	 */
	SM_INLINE explicit TVector3(const TVector4<T>& Vector4);

	/**
	 * Copy/Assign operator.
	 *
	 * @param Other The vector to copy.
	 *
	 * @return Reference to this, after the copy.
	 */
	SM_INLINE TVector3<T>& operator=(const TVector3<T>& Other);

public:
	/**
	 * Addition operator. Adds two vectors.
	 *
	 * @param Other The vector to add.
	 *
	 * @return The result of the addition.
	 */
	SM_INLINE TVector3<T> operator+(const TVector3<T>& Other) const;

	/**
	 * Addition operator. Adds a vector to this.
	 *
	 * @param Other The vector to add.
	 *
	 * @return A reference to this, after the addition.
	 */
	SM_INLINE TVector3<T>& operator+=(const TVector3<T>& Other);

	/**
	 * Subtraction operator. Subtracts two vectors.
	 *
	 * @param Other The vector to subtract.
	 *
	 * @return The result of the subtraction.
	 */
	SM_INLINE TVector3<T> operator-(const TVector3<T>& Other) const;

	/**
	 * Subtraction operator. Subtracts a vector from this.
	 *
	 * @param Other The vector to subtract.
	 *
	 * @return A reference to this, after the subtraction.
	 */
	SM_INLINE TVector3<T>& operator-=(const TVector3<T>& Other);

	/**
	 * Multiplication operator. Multiplies a scalar to this.
	 *
	 * @param Scalar The scalar to multiply.
	 *
	 * @return The result of the multiplication.
	 */
	SM_INLINE TVector3<T> operator*(T Scalar) const;

	/**
	 * Multiplication operator. Multiplies this with a scalar.
	 *
	 * @param Scalar The scalar to multiply.
	 *
	 * @return A reference to this, after the multiplication.
	 */
	SM_INLINE TVector3<T>& operator*=(T Scalar);

	/**
	 * 
	 */
	SM_INLINE TVector3<T> operator-() const;

public:
	/** @return The square of the vector's length. */
	SM_INLINE T LengthSquared() const;

	/** @return The vector's length. */
	SM_INLINE T Length() const;

	/**
	 * Calculates the dot product between two vectors.
	 *
	 * @param A The first vector.
	 * @param B The second vector.
	 *
	 * @return The dot product.
	 */
	SM_INLINE static T DotProduct(const TVector3<T>& A, const TVector3<T>& B);

	/**
	 * Calculates the dot product between this and another vector.
	 *
	 * @param Other The vector to calculate the dot product with.
	 *
	 * @return The dot product.
	 */
	SM_INLINE T Dot(const TVector3<T>& Other) const;

	/**
	 * Calculates the dot product between this and another vector.
	 *
	 * @param Other The vector to calculate the dot product with.
	 *
	 * @return The dot product.
	 */
	SM_INLINE T operator|(const TVector3<T>& Other) const;

	/**
	 * Calculates the cross product between two vectors.
	 *
	 * @param A The first vector.
	 * @param B The second vector.
	 *
	 * @return The cross product.
	 */
	SM_INLINE static TVector3<T> CrossProduct(const TVector3<T>& A, const TVector3<T>& B);

	/**
	 * Calculates the cross product between this and another vector.
	 *
	 * @param Other The vector to calculate the cross product with.
	 *
	 * @return The cross product.
	 */
	SM_INLINE TVector3<T> Cross(const TVector3<T>& Other) const;

	/**
	 * Calculates the cross product between this and another vector.
	 *
	 * @param Other The vector to calculate the cross product with.
	 *
	 * @return The cross product.
	 */
	SM_INLINE TVector3<T> operator^(const TVector3<T>& Other) const;

	/**
	* Assigns to this the cross product between this and another vector.
	*
	* @param Other The vector to calculate the cross product with.
	*
	* @return Reference to this, after the assignment.
	*/
	SM_INLINE TVector3<T>& operator^=(const TVector3<T>& Other);

	/**
	 * Checks if a vector is normalized (has length 1).
	 *
	 * @param Tolerance The maximum allowed difference between the squared length
	 *   of the vector and 1, in order to consider the vector as normalized. Default
	 *   value of 'KINDA_SMALL_NUMBER'.
	 *
	 * @return True if the vector is normalized; False otherwise.
	 */
	SM_INLINE bool IsNormalized(T Tolerance = KINDA_SMALL_NUMBER) const;

	/**
	 * Calculates the normal for this vector.
	 * The normal is a vector with the same direction as this, but unit length (1).
	 *
	 * @return The vector's normal.
	 */
	SM_INLINE TVector3<T> GetNormal() const;

	/**
	 * Calculates the normal for this vector, only if the vector is not already normalized.
	 *
	 * @param Tolerance The maximum allowed difference between the squared length
	 *   of the vector and 1, in order to consider the vector as already normalized. Default
	 *   value of 'KINDA_SMALL_NUMBER'.
	 *
	 * @return The vector's normal.
	 */
	SM_INLINE TVector3<T> GetNormalIf(T Tolerance = KINDA_SMALL_NUMBER) const;

	/**
	 * Calculates the normal for this vector, only if it is possible.
	 *
	 * @param Threshold The maximum value for the vector's squared length for which the vector's
	 *   normal is undefined (as the length is close to 0).
	 * @param ResultIfError The vector that will be returned if the normal is undefined.
	 *   NOTE: ResultIfError should already be a normalized vector.
	 *
	 * @return The vector's normal, if possible; Otherwise, 'ResultIfError'.
	 */
	SM_INLINE TVector3<T> GetSafeNormal(T Threshold, const TVector3<T>& ResultIfError) const;

	/**
	 * Calculates the normal for this vector, only if it is possible and the vector is not already
	 *   normalized.
	 *
	 * @param Threshold The maximum value for the vector's squared length for which the vector's
	 *   normal is undefined (as the length is close to 0).
	 * @param ResultIfError The vector that will be returned if the normal is undefined.
	 *   NOTE: ResultIfError should already be a normalized vector.
	 * @param Tolerance The maximum allowed difference between the squared length
	 *   of the vector and 1, in order to consider the vector as already normalized. Default
	 *   value of 'KINDA_SMALL_NUMBER'.
	 *
	 * @return The vector's normal, if possible; Otherwise, 'ResultIfError'.
	 */
	SM_INLINE TVector3<T> GetSafeNormalIf(T Threshold, const TVector3<T>& ResultIfError, T Tolerance) const;
};

} // namespace SM

/**
*------------------------------------------------------------
* A 3-component vector with single-floating point precision.
*------------------------------------------------------------
* @see 'TVector3<T>'.
*/
using FVector3 = SM::TVector3<float>;

namespace SM
{

template<typename T>
SM_INLINE TVector3<T>::TVector3()
	: X(T(0.0))
	, Y(T(0.0))
	, Z(T(0.0))
{}

template<typename T>
SM_INLINE TVector3<T>::TVector3(const TVector3& Other)
	: X(Other.X)
	, Y(Other.Y)
	, Z(Other.Z)
{}

template<typename T>
SM_INLINE TVector3<T>::TVector3(T InX, T InY, T InZ)
	: X(InX)
	, Y(InY)
	, Z(InZ)
{}

template<typename T>
SM_INLINE TVector3<T>::TVector3(T Scalar)
	: X(Scalar)
	, Y(Scalar)
	, Z(Scalar)
{}

template<typename T>
SM_INLINE TVector3<T>& TVector3<T>::operator=(const TVector3<T>& Other)
{
	X = Other.X;
	Y = Other.Y;
	Z = Other.Z;
	return *this;
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::operator+(const TVector3<T>& Other) const
{
	return TVector3<T>(X + Other.X, Y + Other.Y, Z + Other.Z);
}

template<typename T>
SM_INLINE TVector3<T>& TVector3<T>::operator+=(const TVector3<T>& Other)
{
	X += Other.X;
	Y += Other.Y;
	Z += Other.Z;
	return *this;
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::operator-(const TVector3<T>& Other) const
{
	return TVector3<T>(X - Other.X, Y - Other.Y, Z - Other.Z);
}

template<typename T>
SM_INLINE TVector3<T>& TVector3<T>::operator-=(const TVector3<T>& Other)
{
	X -= Other.X;
	Y -= Other.Y;
	Z -= Other.Z;
	return *this;
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::operator*(T Scalar) const
{
	return TVector3<T>(X * Scalar, Y * Scalar, Z * Scalar);
}

template<typename T>
SM_INLINE TVector3<T>& TVector3<T>::operator*=(T Scalar)
{
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	return *this;
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::operator-() const
{
	return TVector3<T>(-X, -Y, -Z);
}

template<typename T>
SM_INLINE TVector3<T> operator*(T Scalar, const TVector3<T>& Vector)
{
	return Vector * Scalar;
}

template<typename T>
SM_INLINE T TVector3<T>::LengthSquared() const
{
	return (X * X) + (Y * Y) + (Z * Z);
}

template<typename T>
SM_INLINE T TVector3<T>::Length() const
{
	return FMath::Sqrt(LengthSquared());
}

template<typename T>
SM_INLINE T TVector3<T>::DotProduct(const TVector3<T>& A, const TVector3<T>& B)
{
	return (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z);
}

template<typename T>
SM_INLINE T TVector3<T>::Dot(const TVector3<T>& Other) const
{
	return DotProduct(*this, Other);
}

template<typename T>
SM_INLINE T TVector3<T>::operator|(const TVector3<T>& Other) const
{
	return Dot(Other);
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::CrossProduct(const TVector3<T>& A, const TVector3<T>& B)
{
	return TVector3<T>
		(
			A.Y * B.Z - A.Z * B.Y,
			A.Z * B.X - A.X * B.Z,
			A.X * B.Y - A.Y * B.X
		);
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::Cross(const TVector3<T>& Other) const
{
	return CrossProduct(*this, Other);
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::operator^(const TVector3<T>& Other) const
{
	return Cross(Other);
}

template<typename T>
SM_INLINE TVector3<T>& TVector3<T>::operator^=(const TVector3<T>& Other)
{
	(*this) = (*this) ^ Other;
	return *this;
}

template<typename T>
SM_INLINE bool TVector3<T>::IsNormalized(T Tolerance) const
{
	return FMath::Abs(LengthSquared() - T(1.0)) <= Tolerance;
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::GetNormal() const
{
	return (*this) * (T(1.0) / Length());
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::GetNormalIf(T Tolerance) const
{
	T SquaredLength = LengthSquared();

	if (FMath::Abs(SquaredLength - T(1.0)) > Tolerance)
	{
		return (*this) * (T(1.0) / FMath::Sqrt(SquaredLength));
	}

	return (*this);
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::GetSafeNormal(T Threshold, const TVector3<T>& ResultIfError) const
{
	T SquaredLength = LengthSquared();

	if (SquaredLength >= Threshold)
	{
		return (*this) * (T(1.0) / FMath::Sqrt(SquaredLength));
	}

	return ResultIfError;
}

template<typename T>
SM_INLINE TVector3<T> TVector3<T>::GetSafeNormalIf(T Threshold, const TVector3<T>& ResultIfError, T Tolerance) const
{
	T SquaredLength = LengthSquared();

	if (FMath::Abs(SquaredLength - T(1.0)) > Tolerance)
	{
		if (SquaredLength >= Threshold)
		{
			return (*this) * (T(1.0) / FMath::Sqrt(SquaredLength));
		}

		return ResultIfError;
	}

	return (*this);
}

} // namespace SM