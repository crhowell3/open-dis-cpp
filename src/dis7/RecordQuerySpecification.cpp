#include <dis7/RecordQuerySpecification.h>

using namespace DIS;

RecordQuerySpecification::RecordQuerySpecification() : _numberOfRecords(0) {}

RecordQuerySpecification::~RecordQuerySpecification() { _records.clear(); }

unsigned int RecordQuerySpecification::getNumberOfRecords() const {
  return _records.size();
}

std::vector<FourByteChunk>& RecordQuerySpecification::getRecords() {
  return _records;
}

const std::vector<FourByteChunk>& RecordQuerySpecification::getRecords() const {
  return _records;
}

void RecordQuerySpecification::setRecords(
    const std::vector<FourByteChunk>& pX) {
  _records = pX;
}

void RecordQuerySpecification::marshal(DataStream& dataStream) const {
  dataStream << (unsigned int)_records.size();

  for (size_t idx = 0; idx < _records.size(); idx++) {
    FourByteChunk x = _records[idx];
    x.marshal(dataStream);
  }
}

void RecordQuerySpecification::unmarshal(DataStream& dataStream) {
  dataStream >> _numberOfRecords;

  _records.clear();
  for (size_t idx = 0; idx < _numberOfRecords; idx++) {
    FourByteChunk x;
    x.unmarshal(dataStream);
    _records.push_back(x);
  }
}

bool RecordQuerySpecification::operator==(
    const RecordQuerySpecification& rhs) const {
  bool ivarsEqual = true;

  for (size_t idx = 0; idx < _records.size(); idx++) {
    if (!(_records[idx] == rhs._records[idx])) ivarsEqual = false;
  }

  return ivarsEqual;
}

int RecordQuerySpecification::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 4;  // _numberOfRecords

  for (unsigned long long idx = 0; idx < _records.size(); idx++) {
    FourByteChunk listElement = _records[idx];
    marshalSize = marshalSize + listElement.getMarshalledSize();
  }

  return marshalSize;
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
