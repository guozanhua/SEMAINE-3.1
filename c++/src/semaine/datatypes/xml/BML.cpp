/*
 *  BML.cpp
 *  semaine
 *
 *  Created by Marc Schröder on 06.11.08.
 *  Copyright 2008 DFKI GmbH. All rights reserved.
 *
 */

#include "BML.h"

namespace semaine {
namespace datatypes {
namespace xml {

const std::string BML::version = "1.0";
const std::string BML::namespaceURI = "org.mindmakers.bml";
	
	// Elements
const std::string BML::E_BML = "bml";
const std::string BML::E_ROOT_TAGNAME = "bml";
const std::string BML::E_SPEECH = "speech";
const std::string BML::E_TEXT = "text";
const std::string BML::E_SYNC = "sync";
const std::string BML::E_DESCRIPTION = "description";
const std::string BML::E_HEAD = "head";
const std::string BML::E_GAZE = "gaze";
const std::string BML::E_GESTURE = "gesture";
const std::string BML::E_LOCOMOTION = "locomotion";
const std::string BML::E_FACE = "face";
const std::string BML::E_LIPS = "lips";

	// Attributes
const std::string BML::A_ID = "id";
const std::string BML::A_START = "start";
const std::string BML::A_END = "end";
const std::string BML::A_TYPE = "type";

} // namespace xml
} // namespace datatypes
} // namespace semaine

