#pragma once

#include "dis7/EntityID.h"
#include "dis7/EntityInformationFamilyPdu.h"
#include "dis7/EventIdentifier.h"
#include "dis7/Vector3Float.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Information about elastic collisions in a DIS exercise shall be communicated
// using a Collision-Elastic PDU. Section 7.2.4. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT CollisionElasticPdu : public EntityInformationFamilyPdu {
 protected:
  /** This field shall identify the entity that is issuing the PDU and shall be
   * represented by an Entity Identifier record (see 6.2.28) */
  EntityID _issuingEntityID;

  /** This field shall identify the entity that has collided with the issuing
   * entity. This field shall be a valid identifier of an entity or server
   * capable of responding to the receipt of this Collision-Elastic PDU. This
   * field shall be represented by an Entity Identifier record (see 6.2.28). */
  EntityID _collidingEntityID;

  /** This field shall contain an identification generated by the issuing
   * simulation application to associate related collision events. This field
   * shall be represented by an Event Identifier record (see 6.2.34). */
  EventIdentifier _collisionEventID;

  /** some padding */
  short _pad;

  /** This field shall contain the velocity at the time the collision is
   * detected at the point the collision is detected. The velocity shall be
   * represented in world coordinates. This field shall be represented by the
   * Linear Velocity Vector record [see 6.2.95 item c)] */
  Vector3Float _contactVelocity;

  /** This field shall contain the mass of the issuing entity and shall be
   * represented by a 32-bit floating point number representing kilograms */
  float _mass;

  /** This field shall specify the location of the collision with respect to the
   * entity with which the issuing entity collided. This field shall be
   * represented by an Entity Coordinate Vector record [see 6.2.95 item a)]. */
  Vector3Float _locationOfImpact;

  /** These six records represent the six independent components of a positive
   * semi-definite matrix formed by pre-multiplying and post-multiplying the
   * tensor of inertia, by the anti-symmetric matrix generated by the moment
   * arm, and shall be represented by 32-bit floating point numbers
   * (see 5.3.4.4) */
  float _collisionIntermediateResultXX;

  /** tensor values */
  float _collisionIntermediateResultXY;

  /** tensor values */
  float _collisionIntermediateResultXZ;

  /** tensor values */
  float _collisionIntermediateResultYY;

  /** tensor values */
  float _collisionIntermediateResultYZ;

  /** tensor values */
  float _collisionIntermediateResultZZ;

  /** This record shall represent the normal vector to the surface at the point
   * of collision detection. The surface normal shall be represented in world
   * coordinates. This field shall be represented by an Entity Coordinate Vector
   * record [see 6.2.95 item a)]. */
  Vector3Float _unitSurfaceNormal;

  /** This field shall represent the degree to which energy is conserved in a
   * collision and shall be represented by a 32-bit floating point number. In
   * addition, it represents a free parameter by which simulation application
   * developers may “tune” their collision interactions. */
  float _coefficientOfRestitution;

 public:
  CollisionElasticPdu();
  virtual ~CollisionElasticPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getIssuingEntityID();
  const EntityID& getIssuingEntityID() const;
  void setIssuingEntityID(const EntityID& pX);

  EntityID& getCollidingEntityID();
  const EntityID& getCollidingEntityID() const;
  void setCollidingEntityID(const EntityID& pX);

  EventIdentifier& getCollisionEventID();
  const EventIdentifier& getCollisionEventID() const;
  void setCollisionEventID(const EventIdentifier& pX);

  short getPad() const;
  void setPad(short pX);

  Vector3Float& getContactVelocity();
  const Vector3Float& getContactVelocity() const;
  void setContactVelocity(const Vector3Float& pX);

  float getMass() const;
  void setMass(float pX);

  Vector3Float& getLocationOfImpact();
  const Vector3Float& getLocationOfImpact() const;
  void setLocationOfImpact(const Vector3Float& pX);

  float getCollisionIntermediateResultXX() const;
  void setCollisionIntermediateResultXX(float pX);

  float getCollisionIntermediateResultXY() const;
  void setCollisionIntermediateResultXY(float pX);

  float getCollisionIntermediateResultXZ() const;
  void setCollisionIntermediateResultXZ(float pX);

  float getCollisionIntermediateResultYY() const;
  void setCollisionIntermediateResultYY(float pX);

  float getCollisionIntermediateResultYZ() const;
  void setCollisionIntermediateResultYZ(float pX);

  float getCollisionIntermediateResultZZ() const;
  void setCollisionIntermediateResultZZ(float pX);

  Vector3Float& getUnitSurfaceNormal();
  const Vector3Float& getUnitSurfaceNormal() const;
  void setUnitSurfaceNormal(const Vector3Float& pX);

  float getCoefficientOfRestitution() const;
  void setCoefficientOfRestitution(float pX);

  virtual int getMarshalledSize() const;

  bool operator==(const CollisionElasticPdu& rhs) const;
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
