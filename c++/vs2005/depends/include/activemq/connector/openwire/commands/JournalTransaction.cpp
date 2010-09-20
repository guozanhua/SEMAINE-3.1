/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/JournalTransaction.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for JournalTransaction
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
JournalTransaction::JournalTransaction()
{
    this->transactionId = NULL;
    this->type = 0;
    this->wasPrepared = false;
}

////////////////////////////////////////////////////////////////////////////////
JournalTransaction::~JournalTransaction()
{
    delete this->transactionId;
}

////////////////////////////////////////////////////////////////////////////////
JournalTransaction* JournalTransaction::cloneDataStructure() const {
    JournalTransaction* journalTransaction = new JournalTransaction();

    // Copy the data from the base class or classes
    journalTransaction->copyDataStructure( this );

    return journalTransaction;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseDataStructure::copyDataStructure( src );

    const JournalTransaction* srcPtr = dynamic_cast<const JournalTransaction*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "JournalTransaction::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getTransactionId() != NULL ) {
        this->setTransactionId( 
            dynamic_cast<TransactionId*>( 
                srcPtr->getTransactionId()->cloneDataStructure() ) );
    }
    this->setType( srcPtr->getType() );
    this->setWasPrepared( srcPtr->getWasPrepared() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char JournalTransaction::getDataStructureType() const {
    return JournalTransaction::ID_JOURNALTRANSACTION; 
}

////////////////////////////////////////////////////////////////////////////////
std::string JournalTransaction::toString() const {

    ostringstream stream;

    stream << "Begin Class = JournalTransaction" << std::endl;
    stream << " Value of JournalTransaction::ID_JOURNALTRANSACTION = 54" << std::endl; 
    stream << " Value of TransactionId is Below:" << std::endl;
    if( this->getTransactionId() != NULL ) {
        stream << this->getTransactionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Type = " << (int)this->getType() << std::endl;
    stream << " Value of WasPrepared = " << this->getWasPrepared() << std::endl;
    stream << BaseDataStructure::toString();
    stream << "End Class = JournalTransaction" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool JournalTransaction::equals( const DataStructure* value ) const {
    const JournalTransaction* valuePtr = dynamic_cast<const JournalTransaction*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getTransactionId() != NULL ) {
        if( !this->getTransactionId()->equals( valuePtr->getTransactionId() ) ) {
            return false;
        }
    } else if( valuePtr->getTransactionId() != NULL ) {
        return false;
    }
    if( this->getType() != valuePtr->getType() ) {
        return false;
    }
    if( this->getWasPrepared() != valuePtr->getWasPrepared() ) {
        return false;
    }
    if( !BaseDataStructure::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* JournalTransaction::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* JournalTransaction::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::setTransactionId(TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char JournalTransaction::getType() const {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::setType(unsigned char type ) {
    this->type = type;
}

////////////////////////////////////////////////////////////////////////////////
bool JournalTransaction::getWasPrepared() const {
    return wasPrepared;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::setWasPrepared(bool wasPrepared ) {
    this->wasPrepared = wasPrepared;
}

