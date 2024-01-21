#include "dis6/warfare/DetonationPdu.h"

using namespace DIS;

DetonationPdu::DetonationPdu()
    : WarfareFamilyPdu(),
      _munitionID(),
      _eventID(),
      _velocity(),
      _locationInWorldCoordinates(),
      _burstDescriptor(),
      _locationInEntityCoordinates(),
      _detonationResult(0),
      _numberOfArticulationParameters(0),
      _pad(0) {
  setPduType(3);
}

DetonationPdu::~DetonationPdu() { _articulationParameters.clear(); }

EntityID& DetonationPdu::GetMunitionId() { return _munitionID; }

const EntityID& DetonationPdu::GetMunitionId() const { return _munitionID; }

void DetonationPdu::SetMunitionId(const EntityID& pX) { _munitionID = pX; }

EventID& DetonationPdu::GetEventId() { return _eventID; }

const EventID& DetonationPdu::GetEventId() const { return _eventID; }

void DetonationPdu::SetEventId(const EventID& pX) { _eventID = pX; }

Vector3Float& DetonationPdu::GetVelocity() { return _velocity; }

const Vector3Float& DetonationPdu::GetVelocity() const { return _velocity; }

void DetonationPdu::SetVelocity(const Vector3Float& pX) { _velocity = pX; }

Vector3Double& DetonationPdu::GetLocationInWorldCoordinates() {
  return _locationInWorldCoordinates;
}

const Vector3Double& DetonationPdu::GetLocationInWorldCoordinates() const {
  return _locationInWorldCoordinates;
}

void DetonationPdu::SetLocationInWorldCoordinates(const Vector3Double& pX) {
  _locationInWorldCoordinates = pX;
}

BurstDescriptor& DetonationPdu::GetBurstDescriptor() {
  return _burstDescriptor;
}

const BurstDescriptor& DetonationPdu::GetBurstDescriptor() const {
  return _burstDescriptor;
}

void DetonationPdu::SetBurstDescriptor(const BurstDescriptor& pX) {
  _burstDescriptor = pX;
}

Vector3Float& DetonationPdu::GetLocationInEntityCoordinates() {
  return _locationInEntityCoordinates;
}

const Vector3Float& DetonationPdu::GetLocationInEntityCoordinates() const {
  return _locationInEntityCoordinates;
}

void DetonationPdu::SetLocationInEntityCoordinates(const Vector3Float& pX) {
  _locationInEntityCoordinates = pX;
}

uint8_t DetonationPdu::getDetonationResult() const { return _detonationResult; }

void DetonationPdu::setDetonationResult(uint8_t pX) { _detonationResult = pX; }

uint8_t DetonationPdu::getNumberOfArticulationParameters() const {
  return _articulationParameters.size();
}

int16_t DetonationPdu::getPad() const { return _pad; }

void DetonationPdu::setPad(int16_t pX) { _pad = pX; }

std::vector<ArticulationParameter>& DetonationPdu::GetArticulationParameters() {
  return _articulationParameters;
}

const std::vector<ArticulationParameter>&
DetonationPdu::GetArticulationParameters() const {
  return _articulationParameters;
}

void DetonationPdu::SetArticulationParameters(
    const std::vector<ArticulationParameter>& pX) {
  _articulationParameters = pX;
}

void DetonationPdu::Marshal(DataStream& dataStream) const {
  WarfareFamilyPdu::marshal(
      data_stream);  // Marshal information in superclass first
  _munitionID.marshal(dataStream);
  _eventID.marshal(dataStream);
  _velocity.marshal(dataStream);
  _locationInWorldCoordinates.marshal(dataStream);
  _burstDescriptor.marshal(dataStream);
  _locationInEntityCoordinates.marshal(dataStream);
  dataStream << _detonationResult;
  dataStream << (uint8_t)_articulationParameters.size();
  dataStream << _pad;

  for (size_t idx = 0; idx < _articulationParameters.size(); idx++) {
    ArticulationParameter x = _articulationParameters[idx];
    x.marshal(dataStream);
  }
}

void DetonationPdu::Unmarshal(DataStream& dataStream) {
  WarfareFamilyPdu::unmarshal(
      data_stream);  // unmarshal information in superclass first
  _munitionID.unmarshal(dataStream);
  _eventID.unmarshal(dataStream);
  _velocity.unmarshal(dataStream);
  _locationInWorldCoordinates.unmarshal(dataStream);
  _burstDescriptor.unmarshal(dataStream);
  _locationInEntityCoordinates.unmarshal(dataStream);
  dataStream >> _detonationResult;
  dataStream >> _numberOfArticulationParameters;
  dataStream >> _pad;

  _articulationParameters.clear();
  for (size_t idx = 0; idx < _numberOfArticulationParameters; idx++) {
    ArticulationParameter x;
    x.unmarshal(dataStream);
    _articulationParameters.push_back(x);
  }
}

bool DetonationPdu::operator==(const DetonationPdu& rhs) const {
  bool ivars_equal = true;

  ivarsEqual = WarfareFamilyPdu::operator==(rhs);

  if (!(_munitionID == rhs._munitionID)) {
    ivars_equal = false;
  }
  if (!(_eventID == rhs._eventID)) {
    ivars_equal = false;
  }
  if (!(_velocity == rhs._velocity)) {
    ivars_equal = false;
  }
  if (!(_locationInWorldCoordinates == rhs._locationInWorldCoordinates)) {
    ivars_equal = false;
  }
  if (!(_burstDescriptor == rhs._burstDescriptor)) {
    ivars_equal = false;
  }
  if (!(_locationInEntityCoordinates == rhs._locationInEntityCoordinates)) {
    ivars_equal = false;
  }
  if (!(_detonationResult == rhs._detonationResult)) {
    ivars_equal = false;
  }
  if (!(_pad == rhs._pad)) {
    ivars_equal = false;
  }

  for (size_t idx = 0; idx < _articulationParameters.size(); idx++) {
    if (!(_articulationParameters[idx] == rhs._articulationParameters[idx]))
      ivarsEqual = false;
  }

  return ivars_equal;
}

int DetonationPdu::getMarshalledSize() const {
  int marshal_size = 0;

  marshalSize = WarfareFamilyPdu::getMarshalledSize();
  marshalSize = marshalSize + _munitionID.getMarshalledSize();  // _munitionID
  marshalSize = marshalSize + _eventID.getMarshalledSize();     // _eventID
  marshalSize = marshalSize + _velocity.getMarshalledSize();    // _velocity
  marshalSize =
      marshalSize + _locationInWorldCoordinates
                        .getMarshalledSize();  // _locationInWorldCoordinates
  marshalSize =
      marshalSize + _burstDescriptor.getMarshalledSize();  // _burstDescriptor
  marshalSize =
      marshalSize + _locationInEntityCoordinates
                        .getMarshalledSize();  // _locationInEntityCoordinates
  marshal_size = marshal_size + 1;             // _detonationResult
  marshal_size = marshal_size + 1;  // _numberOfArticulationParameters
  marshal_size = marshal_size + 2;  // _pad

  for (uint64_t idx = 0; idx < _articulationParameters.size(); idx++) {
    ArticulationParameter listElement = _articulationParameters[idx];
    marshalSize = marshalSize + listElement.getMarshalledSize();
  }

  return marshal_size;
}

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
