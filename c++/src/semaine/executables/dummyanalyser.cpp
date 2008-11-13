// exceptions
#include <iostream>
#include <list>

#include <semaine/config.h>

#include <semaine/util/XMLTool.h>
#include <semaine/components/Component.h>
#include <semaine/system/ComponentRunner.h>

#include <semaine/components/dummy/DummyAnalyser.h>

int main () {
	try {
		semaine::util::XMLTool::startupXMLTools();

		std::list<semaine::components::Component *> comps;
		
		comps.push_back(new semaine::components::dummy::DummyAnalyser());
		
		semaine::system::ComponentRunner cr(comps);
		cr.go();
		cr.waitUntilCompleted();
		
		semaine::util::XMLTool::shutdownXMLTools();
	} catch (cms::CMSException & ce) {
		ce.printStackTrace();
	} catch (std::exception & e) {
		std::cerr << e.what();
	}
}