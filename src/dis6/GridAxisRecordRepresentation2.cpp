#include <dis6/GridAxisRecordRepresentation2.h>

using namespace DIS;

GridAxisRecordRepresentation2::GridAxisRecordRepresentation2()
    : GridAxisRecord(), _numberOfValues(0) {}

GridAxisRecordRepresentation2::~GridAxisRecordRepresentation2() {
  _dataValues.clear();
}

unsigned short GridAxisRecordRepresentation2::getNumberOfValues() const {
  return _dataValues.size();
}

std::vector<FourByteChunk>& GridAxisRecordRepresentation2::getDataValues() {
  return _dataValues;
}

const std::vector<FourByteChunk>& GridAxisRecordRepresentation2::getDataValues()
    const {
  return _dataValues;
}

void GridAxisRecordRepresentation2::setDataValues(
    const std::vector<FourByteChunk>& pX) {
  _dataValues = pX;
}

void GridAxisRecordRepresentation2::marshal(DataStream& dataStream) const {
  GridAxisRecord::marshal(
      dataStream);  // Marshal information in superclass first
  dataStream << (unsigned short)_dataValues.size();

  for (size_t idx = 0; idx < _dataValues.size(); idx++) {
    FourByteChunk x = _dataValues[idx];
    x.marshal(dataStream);
  }
}

void GridAxisRecordRepresentation2::unmarshal(DataStream& dataStream) {
  GridAxisRecord::unmarshal(
      dataStream);  // unmarshal information in superclass first
  dataStream >> _numberOfValues;

  _dataValues.clear();
  for (size_t idx = 0; idx < _numberOfValues; idx++) {
    FourByteChunk x;
    x.unmarshal(dataStream);
    _dataValues.push_back(x);
  }
}

bool GridAxisRecordRepresentation2::operator==(
    const GridAxisRecordRepresentation2& rhs) const {
  bool ivarsEqual = true;

  ivarsEqual = GridAxisRecord::operator==(rhs);

  for (size_t idx = 0; idx < _dataValues.size(); idx++) {
    if (!(_dataValues[idx] == rhs._dataValues[idx])) ivarsEqual = false;
  }

  return ivarsEqual;
}

int GridAxisRecordRepresentation2::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = GridAxisRecord::getMarshalledSize();
  marshalSize = marshalSize + 2;  // _numberOfValues

  for (unsigned long long idx = 0; idx < _dataValues.size(); idx++) {
    FourByteChunk listElement = _dataValues[idx];
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
