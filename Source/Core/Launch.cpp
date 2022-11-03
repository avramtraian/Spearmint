/**
 *--------------------------------------------
 * Launch.cpp <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#include "World/World.h"
#include "Renderer/Renderer.h"
#include <cstdlib>
#include <cstdio>


internal uint32 GetPixelSize(FImage Image)
{
	uint32 Result = Image.Width * Image.Height * (uint32)sizeof(uint32);
	return Result;
}

internal FImage AllocateImage(uint32 Width, uint32 Height)
{
	FImage Result = {};
	Result.Width = Width;
	Result.Height = Height;

	// TODO(Traian): Implement a memory arena.
	Result.Pixels = (uint32*)malloc(GetPixelSize(Result));
	return Result;
}

#pragma pack(push, 1)
struct FBitmapImageHeader
{
	uint16  FileType;
	uint32  FileSize;
	uint16  Reserved0;
	uint16  Reserved1;
	uint32  BitmapOffset;
	uint32  HeaderSize;
	int32   Width;
	int32   Height;
	uint16  Planes;
	uint16  BitsPerPixel;
	uint32  Compression;
	uint32  SizeOfBitmap;
	int32   HorizontalResolution;
	int32   VerticalResolution;
	uint32  ColorsUsed;
	uint32  ColorsImportant;
};
#pragma pack(pop)

internal void WriteImage(FImage Image, const char* FileName)
{
	uint32 PixelSize = GetPixelSize(Image);

	FBitmapImageHeader Header = {};

	Header.FileType = 0x4D42;
	Header.FileSize = sizeof(FBitmapImageHeader) + PixelSize;
	Header.BitmapOffset = sizeof(FBitmapImageHeader);
	Header.HeaderSize = sizeof(FBitmapImageHeader) - 14;
	Header.Width = Image.Width;
	Header.Height = Image.Height;
	Header.Planes = 1;
	Header.BitsPerPixel = 32;
	Header.Compression = 0;
	Header.SizeOfBitmap = PixelSize;

	FILE* OutputFile;
	fopen_s(&OutputFile, FileName, "wb");
	if (OutputFile)
	{
		fwrite(&Header, sizeof(FBitmapImageHeader), 1, OutputFile);
		fwrite(Image.Pixels, PixelSize, 1, OutputFile);
		fclose(OutputFile);
	}
}

internal int32 GuardedMain(char** Args, uint32 ArgCount)
{
	FImage Image = AllocateImage(1200, 900);

	FRenderer Renderer;

	FWorld World;
	World.Camera.Position = { 0, -10, 1 };
	World.Camera.Target = { 0, 0, 0 };
	World.Camera.AspectRatio = (float)Image.Width / (float)Image.Height;
	World.Camera.VerticalFOV = PI * 0.75F;

	FMaterial Materials[2] = {};
	*((FMaterialDefault*)Materials[0].AbstractMaterialData) = { FVector3(1, 1, 1) };
	*((FMaterialDefault*)Materials[1].AbstractMaterialData) = { FVector3(1, 0, 0) };

	World.MaterialCount = ArrayCount(Materials);
	World.Materials = Materials;

	FPlane Plane = {};
	Plane.Normal = { 0, 0, 1 };
	Plane.Distance = 0;
	Plane.MaterialIndex = 0;

	World.PlaneCount = 1;
	World.Planes = &Plane;
	
	FSphere Spheres[2] = {};
	Spheres[0].Position = { 0, 0, 1 };
	Spheres[0].Radius = 1;
	Spheres[0].MaterialIndex = 1;
	Spheres[1].Position = { -3, 0, 2 };
	Spheres[1].Radius = 2;
	Spheres[1].MaterialIndex = 1;

	World.SphereCount = ArrayCount(Spheres);
	World.Spheres = Spheres;

	Renderer.SetWorld(&World);
	Renderer.SetImageTarget(&Image);

	Renderer.Render();
	WriteImage(Image, "Scene.bmp");
	return 0;
}

int main(int ArgCount, char** Args)
{
	return (int)(GuardedMain(Args, (uint32)ArgCount));
}