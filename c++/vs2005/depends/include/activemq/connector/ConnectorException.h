/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _ACTIVEMQ_CONNECTOR_CONNECTOREXCEPTION_H_
#define _ACTIVEMQ_CONNECTOR_CONNECTOREXCEPTION_H_

#include <activemq/exceptions/ActiveMQException.h>
#include <activemq/util/Config.h>

namespace activemq{
namespace connector{

    /*
     * Signals that an Connector exception of some sort has occurred.
     */
    class AMQCPP_API ConnectorException : public exceptions::ActiveMQException {
    public:

        /**
         * Default Constructor
         */
        ConnectorException() throw() {}

        /**
         * Copy Constructor
         * @param ex the exception to copy
         */
        ConnectorException( const exceptions::ActiveMQException& ex ) throw()
        : exceptions::ActiveMQException() {
            *(ActiveMQException*)this = ex;
        }

        /**
         * Copy Constructor
         * @param ex the exception to copy, which is an instance of this type
         */
        ConnectorException( const ConnectorException& ex ) throw()
        : exceptions::ActiveMQException() {
            *(exceptions::ActiveMQException*)this = ex;
        }

        /**
         * Constructor - Initializes the file name and line number where
         * this message occurred.  Sets the message to report, using an
         * optional list of arguments to parse into the message
         * @param file name where exception occurs
         * @param line number where the exception occurred.
         * @param cause The exception that was the cause for this one to be thrown.
         * @param message to report
         * @param list of primitives that are formatted into the message
         */
        ConnectorException( const char* file, const int lineNumber,
                            const std::exception* cause,
                            const char* msg, ... )
        throw() : exceptions::ActiveMQException( cause )
        {
            va_list vargs;
            va_start( vargs, msg );
            buildMessage( msg, vargs );

            // Set the first mark for this exception.
            setMark( file, lineNumber );
        }

        /**
         * Constructor
         * @param cause Pointer to the exception that caused this one to
         * be thrown, the object is cloned caller retains ownership.
         */
        ConnectorException( const std::exception* cause )
            throw() : exceptions::ActiveMQException( cause ) {}

        /**
         * Constructor
         * @param file name of the file were the exception occurred.
         * @param lineNumber line where the exception occurred
         * @param msg the message that was generated
         */
        ConnectorException( const char* file,
                            const int lineNumber,
                            const char* msg, ... ) throw()
        : exceptions::ActiveMQException() {

            va_list vargs;
            va_start( vargs, msg );
            buildMessage( msg, vargs );

            // Set the first mark for this exception.
            setMark( file, lineNumber );
        }

        /**
         * Clones this exception.  This is useful for cases where you need
         * to preserve the type of the original exception as well as the message.
         * All subclasses should override.
         */
        virtual ConnectorException* clone() const{
            return new ConnectorException( *this );
        }

        virtual ~ConnectorException() throw() {}

    };

}}

#endif /*_ACTIVEMQ_CONNECTOR_CONNECTOREXCEPTION_H_*/
