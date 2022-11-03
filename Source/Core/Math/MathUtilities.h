/**
 *--------------------------------------------
 * MathUtilities.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#include "Core/CoreDefines.h"
#include "Core/CoreTypes.h"

/**
 * The most common math constants.
 */
#define PI                        (3.1415926535897932F)
#define KINDA_SMALL_NUMBER        (1e-4F)
#define SMALL_NUMBER              (1e-8F)
#define BIG_NUMBER                (3.4e38F)
#define EULUERS_NUMBER            (2.7182818284590452F)
#define GOLDEN_RATIO              (1.6180339887498948F)

#define DOUBLE_PI                 (3.1415926535897932384626433832795028)
#define DOUBLE_KINDA_SMALL_NUMBER (1e-4)
#define DOUBLE_SMALL_NUMBER       (1e-8)
#define DOUBLE_BIG_NUMBER         (3.4e+38)
#define DOUBLE_EULUERS_NUMBER     (2.7182818284590452353602874713526624)
#define DOUBLE_GOLDEN_RATIO       (1.6180339887498948482045868343656381)

/**
 * More PI-related constants.
 */
#define INV_PI                    (0.31830988618F)
#define TWO_PI                    (6.28318530717F)
#define HALF_PI                   (1.57079632679F)
#define PI_SQUARED                (9.86960440108F)

#define DOUBLE_INV_PI             (0.31830988618379067154)
#define DOUBLE_TWO_PI             (6.28318530717958647692)
#define DOUBLE_HALF_PI            (1.57079632679489661923)
#define DOUBLE_PI_SQUARED         (9.86960440108935861883)

/**
 * Common square roots.
 */
#define SQRT_2                    (1.41421356237F)
#define SQRT_3                    (1.73205080756F)
#define INV_SQRT_2                (0.70710678118F)
#define INV_SQRT_3                (0.57735026918F)
#define HALF_SQRT_2               (0.70710678118F)
#define HALF_SQRT_3               (0.86602540378F)

#define DOUBLE_SQRT_2             (1.4142135623730950488016887242097)
#define DOUBLE_SQRT_3             (1.7320508075688772935274463415059)
#define DOUBLE_INV_SQRT_2         (0.7071067811865475244008443621048)
#define DOUBLE_INV_SQRT_3         (0.5773502691896257645091487805019)
#define DOUBLE_HALF_SQRT_2        (0.7071067811865475244008443621048)
#define DOUBLE_HALF_SQRT_3        (0.8660254037844386467637231707529)

 /**
 * Structure for all math utility and helper functions.
 */
struct FMath
{
public:
	/**
	 * Gets the absolute value of a number.
	 *
	 * @param The number to get its absolute value.
	 *
	 * @return The absolute value.
	 */
	template<typename T>
	static SM_INLINE T Abs(T X)
	{
		return X < T(0) ? -X : X;
	}

	/**
	 * Gets the minimum between two numbers.
	 *
	 * @param A The first number.
	 * @param B The second number.
	 *
	 * @return The minimum.
	 */
	template<typename T>
	static SM_INLINE T Min(T A, T B)
	{
		return A < B ? A : B;
	}

	/**
	 * Gets the number with the smallest absolute value.
	 * It can be interpreted as getting the number which is the closest
	 *   to the number's axis origin.
	 *
	 * @param A The first number.
	 * @param B The second number.
	 *
	 * @return The number with the smallest absolute value.
	 */
	template<typename T>
	static SM_INLINE T MinAbs(T A, T B)
	{
		return FMath::Min(FMath::Abs(A), FMath::MaxAbs(B));
	}

	/**
	 * Gets the maximum between two numbers.
	 *
	 * @param A The first number.
	 * @param B The second number.
	 *
	 * @return The maximum.
	 */
	template<typename T>
	static SM_INLINE T Max(T A, T B)
	{
		return A > B ? A : B;
	}

	/**
	 * Gets the number with the biggest absolute value.
	 * It can be interpreted as getting the number which is the furthest
	 *   to the number's axis origin.
	 *
	 * @param A The first number.
	 * @param B The second number.
	 *
	 * @return The number with the biggest absolute value.
	 */
	template<typename T>
	static SM_INLINE T MaxAbs(T A, T B)
	{
		return FMath::Max(FMath::Abs(A), FMath::MaxAbs(B));
	}

	/**
	 * Clamps a value between two numbers; [MinRange, MaxRange].
	 *
	 * @param X The number to clamp.
	 * @param MinRange The lower part of the range.
	 * @param MaxRange The upper part of the range.
	 *
	 * @return The clamped value.
	 */
	template<typename T>
	static SM_INLINE T Clamp(T X, T MinRange, T MaxRange)
	{
		return FMath::Min(MaxRange, FMath::Max(MinRange, X));
	}

	template<typename T>
	static SM_INLINE bool AreNearlyEqual(T A, T B, T Tolerance = KINDA_SMALL_NUMBER)
	{
		return (FMath::Abs(A - B) <= Tolerance);
	}

public:
	/**
	 * Calculates a number's square root.
	 *
	 * @param X The number to calculate its square root.
	 *
	 * @return The square root.
	 */
	static float Sqrt(float X);

	/** @see 'FMath::Sqrt(float)'. */
	static double Sqrt(double X);

	/**
	 * Calculates the sine of an angle.
	 *
	 * @param X The angle (in radians).
	 *
	 * @return The sine.
	 */
	static float Sin(float X);

	/** @see 'FMath::Sin(float)'. */
	static double Sin(double X);

	/**
	 * Calculates the cosine of an angle.
	 *
	 * @param X The angle (in radians).
	 *
	 * @return The cosine.
	 */
	static float Cos(float X);

	/** @see 'FMath::Cos(float)'. */
	static double Cos(double X);

	/**
	 * Calculates the tangent of an angle.
	 *
	 * @param X The angle (in radians).
	 *
	 * @return The tangent.
	 */
	static float Tan(float X);

	/** @see 'FMath::Tan(float)'. */
	static double Tan(double X);

	/**
	 * Calculates the asin for a number.
	 *
	 * @param X The number.
	 *
	 * @return the asin (in radians).
	 */
	static float Asin(float X);

	/** @see 'FMath::Asin(float)'. */
	static double Asin(double X);

	/**
	 * Calculates the acos for a number.
	 *
	 * @param X The number.
	 *
	 * @return The acos (in radians).
	 */
	static float Acos(float X);

	/** @see 'FMath::Acos(float)'. */
	static double Acos(double X);

	/**
	 * Calculates the atan for a number.
	 *
	 * @param X The number.
	 *
	 * @return The atan (in radians).
	 */
	static float Atan(float X);

	/** @see 'FMath::Atan(float)'. */
	static double Atan(double X);
};