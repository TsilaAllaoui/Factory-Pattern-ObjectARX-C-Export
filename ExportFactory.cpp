#include "ExportFactory.h"
#include <entityLib.h>

PolylineExporter::PolylineExporter(AcDbPolyline* polyline)
{
	polyline_ = polyline;
}


bool PolylineExporter::exportEntity()
{
	auto filePath = acStrToStr(askForFilePath(false, _T("txt"), _T("Fichier où enregistrer la polyligne: ")));
	std::ofstream file(filePath);
	if (!file) {
		return false;
	}

	for (auto i = 0; i < polyline_->numVerts(); i++) {
		AcGePoint3d point;
		polyline_->getPointAt(i, point);
		file << point.x << " ," << point.y << " ," << point.z << std::endl;
	}
}

PointExporter::PointExporter(AcDbPoint* point)
{
	point_ = point;
}

bool PointExporter::exportEntity()
{
	auto filePath = acStrToStr(askForFilePath(false, _T("txt"), _T("Fichier où enregistrer le point: ")));
	std::ofstream file(filePath);
	if (!file) {
		return false;
	}
	file << point_->position().x << " ," << point_->position().y << " ," << point_->position().z << std::endl;
}

IExport* IExport::createExporter(AcDbEntity* entity)
{
	auto type = entityType(entity);
	if (AcDbPolyline::cast(entity)) {
		return new PolylineExporter(AcDbPolyline::cast(entity));
	}
	else if (AcDbPoint::cast(entity)) {
		return new PointExporter(AcDbPoint::cast(entity));
	}
	else {
		return nullptr;
	}
}
