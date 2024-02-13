#include "ExportFactory.h"
//All other acad includes here

void main() {

	ads_name ssPoly, ssPoint;
	long nbPoly = getSsPoly2D(ssPoly);
	if (nbPoly != 1) {
		print("Sélection invalide. Commande annulée");
		return;
	}
	long nbPoint = getSsPoint(ssPoint);
	if (nbPoint != 1) {
		print("Sélection invalide. Commande annulée");
	}

	Pointer<AcDbPolyline> poly = getPoly2DFromSs(ssPoly, 0, AcDb::kForWrite);
	Pointer<AcDbPoint> point = getPointFromSs(ssPoint, 0, AcDb::kForWrite);

	auto polyExporter = IExport::createExporter(poly);
	auto pointExporter = IExport::createExporter(point);
	if (polyExporter)
		polyExporter->exportEntity();
	if (pointExporter)
		pointExporter->exportEntity();
	return 0;
}