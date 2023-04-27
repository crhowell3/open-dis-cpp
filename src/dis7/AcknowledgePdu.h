#pragma once

#include <dis7/EntityID.h>
#include <dis7/SimulationManagementFamilyPdu.h>
#include <dis7/opendis7_export.h>
#include <dis7/utils/DataStream.h>

namespace DIS {
// Section 7.5.6. Acknowledge the receipt of a start/resume, stop/freeze, or
// RemoveEntityPDU. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT AcknowledgePdu : public SimulationManagementFamilyPdu {
 protected:
  /** Identifier for originating entity(or simulation) */
  EntityID _originatingID;

  /** Identifier for the receiving entity(or simulation) */
  EntityID _receivingID;

  /** type of message being acknowledged */
  unsigned short _acknowledgeFlag;

  /** Whether or not the receiving entity was able to comply with the request */
  unsigned short _responseFlag;

  /** Request ID that is unique */
  unsigned int _requestID;

 public:
  AcknowledgePdu();
  virtual ~AcknowledgePdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getOriginatingID();
  const EntityID& getOriginatingID() const;
  void setOriginatingID(const EntityID& pX);

  EntityID& getReceivingID();
  const EntityID& getReceivingID() const;
  void setReceivingID(const EntityID& pX);

  unsigned short getAcknowledgeFlag() const;
  void setAcknowledgeFlag(unsigned short pX);

  unsigned short getResponseFlag() const;
  void setResponseFlag(unsigned short pX);

  unsigned int getRequestID() const;
  void setRequestID(unsigned int pX);

  virtual int getMarshalledSize() const;

  bool operator==(const AcknowledgePdu& rhs) const;
};
}  // namespace DIS

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
//
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
