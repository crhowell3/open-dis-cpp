#include "dis6/warfare/BurstDescriptor.h"

using namespace DIS;

BurstDescriptor::BurstDescriptor()
    : _warhead(0), _fuse(0), _quantity(0), _rate(0) {}

BurstDescriptor::~BurstDescriptor() = default;

dis::EntityType& BurstDescriptor::getMunition() { return _munition; }

const dis::EntityType& BurstDescriptor::getMunition() const {
  return _munition;
}

void BurstDescriptor::setMunition(const dis::EntityType& pX) { _munition = pX; }

uint16_t BurstDescriptor::getWarhead() const { return _warhead; }

void BurstDescriptor::setWarhead(uint16_t pX) { _warhead = pX; }

uint16_t BurstDescriptor::getFuse() const { return _fuse; }

void BurstDescriptor::setFuse(uint16_t pX) { _fuse = pX; }

uint16_t BurstDescriptor::getQuantity() const { return _quantity; }

void BurstDescriptor::setQuantity(uint16_t pX) { _quantity = pX; }

uint16_t BurstDescriptor::getRate() const { return _rate; }

void BurstDescriptor::setRate(uint16_t pX) { _rate = pX; }

void BurstDescriptor::Marshal(DataStream& dataStream) const {
  _munition.Marshal(dataStream);
  dataStream << _warhead;
  dataStream << _fuse;
  dataStream << _quantity;
  dataStream << _rate;
}

void BurstDescriptor::Unmarshal(DataStream& dataStream) {
  _munition.Unmarshal(dataStream);
  dataStream >> _warhead;
  dataStream >> _fuse;
  dataStream >> _quantity;
  dataStream >> _rate;
}

bool BurstDescriptor::operator==(const BurstDescriptor& rhs) const {
  bool ivars_equal = true;

  if (!(_munition == rhs._munition)) {
    ivars_equal = false;
  }
  if (!(_warhead == rhs._warhead)) {
    ivars_equal = false;
  }
  if (!(_fuse == rhs._fuse)) {
    ivars_equal = false;
  }
  if (!(_quantity == rhs._quantity)) {
    ivars_equal = false;
  }
  if (!(_rate == rhs._rate)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int BurstDescriptor::getMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + _munition.GetMarshalledSize();  // _munition
  marshal_size = marshal_size + 2;                              // _warhead
  marshal_size = marshal_size + 2;                              // _fuse
  marshal_size = marshal_size + 2;                              // _quantity
  marshal_size = marshal_size + 2;                              // _rate
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
