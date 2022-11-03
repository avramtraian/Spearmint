/**
 *--------------------------------------------
 * Renderer.cpp <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#include "Renderer.h"

inline uint32 BGRAPackFloat4(FVector4 Unpacked)
{
	uint8 R = (uint8)(Unpacked.X * 255.0F);
	uint8 G = (uint8)(Unpacked.Y * 255.0F);
	uint8 B = (uint8)(Unpacked.Z * 255.0F);
	uint8 A = (uint8)(Unpacked.W * 255.0F);
	uint32 Result = (A << 24) | (R << 16) | (G << 8) | (B << 0);
	return Result;
}

FRenderer::FRenderer()
	: World(nullptr)
	, ImageTarget(nullptr)
{}

void FRenderer::SetWorld(const FWorld* InWorld)
{
	World = InWorld;

	CameraData.AxisZ = (World->Camera.Target - World->Camera.Position).GetNormal();
	CameraData.AxisX = FVector3::CrossProduct({ 0, 0, -1 }, CameraData.AxisZ).GetNormal();
	CameraData.AxisY = FVector3::CrossProduct(CameraData.AxisX, CameraData.AxisZ).GetNormal();

	// CameraData.FilmHeight = 2 * FMath::Tan(World->Camera.VerticalFOV * 0.5F);
	CameraData.FilmHeight = 1;
	CameraData.FilmWidth = CameraData.FilmHeight * World->Camera.AspectRatio;
	CameraData.FilmCenter = World->Camera.Position + CameraData.AxisZ;
}

void FRenderer::SetImageTarget(const FImage* InImageTarget)
{
	ImageTarget = InImageTarget;
}

void FRenderer::Render()
{
	uint32* Pixel = ImageTarget->Pixels;
	for (uint32 Y = 0; Y < ImageTarget->Height; ++Y)
	{
		for (uint32 X = 0; X < ImageTarget->Width; ++X)
		{
			FVector4 Color = PerPixel(X, Y);
			Color = FVector4::Clamp(Color, FVector4(0.0F), FVector4(1.0F));
			*Pixel++ = BGRAPackFloat4(Color);
		}
	}
}

FVector4 FRenderer::PerPixel(uint32 PixelX, uint32 PixelY)
{
	float FilmX = ((float)PixelX / (float)ImageTarget->Width) - 0.5F;
	float FilmY = ((float)PixelY / (float)ImageTarget->Height) - 0.5F;

	FRay Ray;
	Ray.Origin = World->Camera.Position;
	Ray.Direction = CameraData.FilmCenter + (FilmX * CameraData.FilmWidth * CameraData.AxisX) + (FilmY * CameraData.FilmHeight * CameraData.AxisY) - World->Camera.Position;
	Ray.Direction = Ray.Direction.GetNormal();

	FVector4 Result = FVector4(0.0F);

	FHitPayload Payload = TraceRay(Ray);
	if (Payload.HitDistance > 0)
	{
		const FMaterial* AbstractMaterial = World->Materials + Payload.MaterialIndex;
		const FMaterialDefault* Material = (const FMaterialDefault*)(AbstractMaterial->AbstractMaterialData);

		FVector3 LightDirection = { -1, 1, -1 };
		LightDirection = LightDirection.GetNormal();

		float LightIntensity = FMath::Max(0.075F, (-LightDirection) | Payload.WorldNormal);
		Result = FVector4(Material->Color * LightIntensity, 1);
	}
	else
	{
		Result = { 0, 0, 0, 1 };
	}

	return Result;
}

FRenderer::FHitPayload FRenderer::TraceRay(const FRay& Ray)
{
	float ClosestHitDistance = BIG_NUMBER;
	uint32 ObjectIndex = UINT32_MAX;

	for (uint32 PlaneIndex = 0; PlaneIndex < World->PlaneCount; ++PlaneIndex)
	{
		const FPlane* Plane = World->Planes + PlaneIndex;

		float HitDistance;
		if (IntersectPlane(Ray, Plane->Normal, Plane->Distance, HitDistance))
		{
			if ((HitDistance > 0) && (HitDistance < ClosestHitDistance))
			{
				ClosestHitDistance = HitDistance;
				ObjectIndex = PlaneIndex;
			}
		}
	}

	for (uint32 SphereIndex = 0; SphereIndex < World->SphereCount; ++SphereIndex)
	{
		const FSphere* Sphere = World->Spheres + SphereIndex;
	
		float HitDistance;
		if (IntersectSphere(Ray, Sphere->Position, Sphere->Radius, HitDistance))
		{
			if ((HitDistance > 0) && (HitDistance < ClosestHitDistance))
			{
				ClosestHitDistance = HitDistance;
				ObjectIndex = World->PlaneCount + SphereIndex;
			}
		}
	}

	if (ObjectIndex != UINT32_MAX)
	{
		return ClosestHit(Ray, ClosestHitDistance, ObjectIndex);
	}

	return Miss(Ray);
}

FRenderer::FHitPayload FRenderer::ClosestHit(const FRay& Ray, float HitDistance, uint32 ObjectIndex)
{
	FHitPayload Result = {};
	Result.HitDistance = HitDistance;
	Result.ObjectIndex = ObjectIndex;
	Result.WorldPosition = Ray.Origin + Ray.Direction * HitDistance;

	if (ObjectIndex < World->PlaneCount)
	{
		const FPlane* Plane = World->Planes + ObjectIndex;
		Result.WorldNormal = Plane->Normal;
		Result.MaterialIndex = Plane->MaterialIndex;
	}
	else
	{
		const FSphere* Sphere = World->Spheres + (ObjectIndex - World->PlaneCount);
		Result.WorldNormal = FVector3(Result.WorldPosition - Sphere->Position).GetNormal();
		Result.MaterialIndex = Sphere->MaterialIndex;
	}

	return Result;
}

FRenderer::FHitPayload FRenderer::Miss(const FRay& Ray)
{
	FHitPayload Result = {};
	Result.HitDistance = -1;
	Result.ObjectIndex = UINT32_MAX;
	return Result;
}