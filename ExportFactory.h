#pragma once

#include <fmapHeaders.h>

#include <dbents.h>
#include "selectEntity.h"
#include "pointEntity.h"
#include <vector>
#include "layer.h"
#include "groupEntity.h"
#include "list.h"
#include "pointer.h"

class IExport
{
public:
	virtual ~IExport() = default;
	virtual bool exportEntity() = 0;
	static IExport* createExporter(AcDbEntity* entity);
};

class PolylineExporter : public IExport
{
public:
	PolylineExporter(AcDbPolyline* polyline);
	bool exportEntity();
private:
	Pointer<AcDbPolyline> polyline_;
};

class PointExporter : public IExport
{
public:
	PointExporter(AcDbPoint* point);
	bool exportEntity();
private:
	AcDbPoint* point_;
};

