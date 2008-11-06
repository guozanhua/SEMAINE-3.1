/*
 *  BMLReceiver.h
 *  semaine
 *
 *  Created by Marc Schröder on 03.11.08.
 *  Copyright 2008 DFKI GmbH. All rights reserved.
 *
 */


#ifndef SEMAINE_CMS_RECEIVER_BMLRECEIVER_H
#define SEMAINE_CMS_RECEIVER_BMLRECEIVER_H

#include <semaine/config.h>

#include <semaine/cms/receiver/XMLReceiver.h>



using namespace cms;
using namespace semaine::cms::exceptions;
using namespace semaine::cms::message;

namespace semaine {
namespace cms {
namespace receiver {

/**
 * An abstraction of the Receiver for BML.
 * @author marc
 *
 */
class BMLReceiver : public XMLReceiver
{
public:
	/**
	 * Create a receiver that will listen for all messages in the given Topic.
	 * @param topic the name of the JMS Topic to listen to.
	 */
	BMLReceiver(const std::string & topicName) throw(CMSException) :
		XMLReceiver(topicName)
	{}
	
	/**
	 * Create a receiver that will listen only to the messages in the given Topic
	 * that will pass the given messageSelector. 
	 * @param topicName the name of the JMS Topic to listen to.
	 * @param messageSelector a message selector expression, see e.g. http://java.sun.com/javaee/5/docs/api/javax/jms/Message.html
	 * for the detailed description.
	 */
	BMLReceiver(const std::string & topicName, const std::string & messageSelector)
	throw(CMSException) :
		XMLReceiver(topicName, messageSelector)
	{}


};

} // namespace receiver
} // namespace cms
} // namespace semaine


#endif

