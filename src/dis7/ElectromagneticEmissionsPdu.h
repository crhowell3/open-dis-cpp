#pragma once

#include <vector>

#include "dis7/DistributedEmissionsFamilyPdu.h"
#include "dis7/ElectromagneticEmissionSystemData.h"
#include "dis7/EntityID.h"
#include "dis7/EventIdentifier.h"
#include "dis7/Vector3Float.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Section 5.3.7.1. Information about active electronic warfare (EW) emissions
// and active EW countermeasures shall be communicated using an Electromagnetic
// Emission PDU. NOT COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT ElectromagneticEmissionsPdu
    : public DistributedEmissionsFamilyPdu {
 protected:
  /** ID of the entity emitting */
  EntityID _emittingEntityID;

  /** ID of event */
  EventIdentifier _eventID;

  /** This field shall be used to indicate if the data in the PDU represents a
   * state update or just data that has changed since issuance of the last
   * Electromagnetic Emission PDU [relative to the identified entity and
   * emission system(s)]. */
  unsigned char _stateUpdateIndicator;

  /** This field shall specify the number of emission systems being described in
   * the current PDU. */
  unsigned char _numberOfSystems;

  /** padding */
  unsigned short _paddingForEmissionsPdu;

  std::vector<ElectromagneticEmissionSystemData> _systems;

 public:
  ElectromagneticEmissionsPdu();
  virtual ~ElectromagneticEmissionsPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getEmittingEntityID();
  const EntityID& getEmittingEntityID() const;
  void setEmittingEntityID(const EntityID& pX);

  EventIdentifier& getEventID();
  const EventIdentifier& getEventID() const;
  void setEventID(const EventIdentifier& pX);

  unsigned char getStateUpdateIndicator() const;
  void setStateUpdateIndicator(unsigned char pX);

  unsigned char getNumberOfSystems() const;

  unsigned short getPaddingForEmissionsPdu() const;
  void setPaddingForEmissionsPdu(unsigned short pX);

  std::vector<ElectromagneticEmissionSystemData>& getSystems();
  const std::vector<ElectromagneticEmissionSystemData>& getSystems() const;
  void setSystems(const std::vector<ElectromagneticEmissionSystemData>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const ElectromagneticEmissionsPdu& rhs) const;
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
