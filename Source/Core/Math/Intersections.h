/**
 *--------------------------------------------
 * Intersections.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#include "Core/Math/Ray.h"

template<typename T>
SM_INLINE uint8 IntersectPlane(const SM::TRay<T>& Ray, const SM::TVector3<T>& PlaneNormal, T PlaneDistance, out T& Distance)
{
	T NormalDirection = PlaneNormal.Dot(Ray.Direction);
	if (FMath::AreNearlyEqual(NormalDirection, T(0)))
	{
		Distance = 0;
		return 0;
	}

	Distance = (-PlaneDistance - PlaneNormal.Dot(Ray.Origin)) / NormalDirection;
	return 1;
}

template<typename T>
SM_INLINE uint8 IntersectSphere(const SM::TRay<T>& Ray, const SM::TVector3<T>& SpherePosition, T SphereRadius, out T& Distance)
{
	T A = Ray.Direction.Dot(Ray.Direction);
	T B = 2 * (Ray.Origin.Dot(Ray.Direction) - Ray.Direction.Dot(SpherePosition));
	T C = Ray.Origin.Dot(Ray.Origin) + SpherePosition.Dot(SpherePosition) - SphereRadius * SphereRadius - 2 * SpherePosition.Dot(Ray.Origin);

	T Discriminant = B * B - 4 * A * C;
	if (Discriminant < T(0))
	{
		return 0;
	}

	T DiscriminantRoot = FMath::Sqrt(Discriminant);
	T OneOverTwoA = 1 / (2 * A);
	Distance = (-B - DiscriminantRoot) * OneOverTwoA;
	return 1;
}

template<typename T>
SM_INLINE uint8 IntersectSphere(const SM::TRay<T>& Ray, const SM::TVector3<T>& SpherePosition, T SphereRadius, out T* Distance0, out T* Distance1)
{
	T A = Ray.Direction.Dot(Ray.Direction);
	T B = Ray.Origin.Dot(Ray.Direction) - Ray.Direction.Dot(SpherePosition);
	T C = Ray.Origin.Dot(Ray.Origin) + SpherePosition.Dot(SpherePosition) - SphereRadius * SphereRadius - 2 * SpherePosition.Dot(Ray.Origin);

	T Discriminant = B * B - A * C;
	if (Discriminant < T(0))
	{
		return 0;
	}

	T DiscriminantRoot = FMath::Sqrt(Discriminant);
	T OneOverA = 1 / A;

	*Distance0 = (-B - DiscriminantRoot) * OneOverA;

	if (Discriminant < KINDA_SMALL_NUMBER)
	{
		if (Distance1)
		{
			*Distance1 = *Distance0;
		}
		return 1;
	}

	if (Distance1)
	{
		*Distance1 = (-B + DiscriminantRoot) * OneOverA;
	}
	return 2;
}